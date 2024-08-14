#include <Firebase_ESP_Client.h>
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"
#include <Arduino.h>
#include <ArduinoJson.h>

class RealtimeDBClass
{
private:
    String uid;

public:
    FirebaseData fbdo;
    FirebaseAuth auth;
    FirebaseConfig config;
    void init()
    {
        config.api_key = API_KEY;
        config.database_url = DATABASE_URL;
        auth.user.email = USER_EMAIL;
        auth.user.password = USER_PASSWORD;

        Firebase.reconnectWiFi(true);
        fbdo.setResponseSize(4096);
        config.token_status_callback = tokenStatusCallback;
        config.max_token_generation_retry = 5;

        Firebase.begin(&config, &auth);

        Serial.println("Getting User UID");
        while ((auth.token.uid) == "")
        {
            Serial.print('.');
            delay(1000);
        }

        uid = auth.token.uid.c_str();
        Serial.print("User UID: ");
        Serial.print(uid);
    }

    void SensorDataUpdate(String name, int value)
    {
        if (Firebase.ready())
        {
            if (Firebase.RTDB.setInt(&fbdo, "Sosamala/SensorData/" + name, value))
            {
                Serial.println("PASSED");
                Serial.println("PATH: " + fbdo.dataPath());
                Serial.println("TYPE: " + fbdo.dataType());
            }
            else
            {
                Serial.println("FAILED");
                Serial.println("REASON: " + fbdo.errorReason());
            }
        }
    }

    void StatusUpdate(String name, bool value)
    {
        if (Firebase.ready())
        {
            if (Firebase.RTDB.setBool(&fbdo, "Sosamala/Status/" + name, value))
            {
                Serial.println("PASSED");
                Serial.println("PATH: " + fbdo.dataPath());
                Serial.println("TYPE: " + fbdo.dataType());
            }
            else
            {
                Serial.println("FAILED");
                Serial.println("REASON: " + fbdo.errorReason());
            }
        }
    }

    bool StatusRead(String name)
    {
        if (Firebase.RTDB.getBool(&fbdo, "Sosamala/Status/" + name))
        {
            bool read_data = fbdo.boolData();
            return read_data;
        }
        else
        {
            Serial.println(fbdo.errorReason());

            return false;
        }
    }

    bool SuperiorRead(String name)
    {
        if (Firebase.RTDB.getBool(&fbdo, "Sosamala/Superior/" + name))
        {
            bool read_data = fbdo.boolData();
            return read_data;
        }
        else
        {
            Serial.println(fbdo.errorReason());

            return false;
        }
    }
};

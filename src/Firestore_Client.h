#include <Firebase_ESP_Client.h>
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"
#include <Arduino.h>
#include <ArduinoJson.h>

class FirestoreClass
{
private:
    String uid;
    unsigned long dataMillis = 0;

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

    void StatusUpdate(String name, bool value)
    {
        bool taskCompleted = false;

        if (Firebase.ready())
        {
            dataMillis = millis();

            if (!taskCompleted)
            {
                taskCompleted = true;

                FirebaseJson content;

                content.set("fields/" + name + "/booleanValue", value);

                String documentPath = "/Sosamala/Status";

                if (Firebase.Firestore.patchDocument(&fbdo, FIREBASE_PROJECT_ID, "", documentPath.c_str(), content.raw(), name))
                    Serial.printf("ok\n%s\n\n", fbdo.payload().c_str());
                else
                    Serial.println(fbdo.errorReason());
            }
        }
    }

    void RawDataUpdate(String name, int value)
    {
        bool taskCompleted = false;

        if (Firebase.ready())
        {
            dataMillis = millis();

            if (!taskCompleted)
            {
                taskCompleted = true;

                FirebaseJson content;

                content.set("fields/" + name + "/integerValue", value);

                String documentPath = "/Sosamala/Sensor_Data";

                if (Firebase.Firestore.patchDocument(&fbdo, FIREBASE_PROJECT_ID, "", documentPath.c_str(), content.raw(), name))
                    Serial.printf("ok\n%s\n\n", fbdo.payload().c_str());
                else
                    Serial.println(fbdo.errorReason());
            }
        }
    }

    void StatusRead(bool *dispenserStatus, bool *mistingStatus)
    {
        String documentPath = "/Sosamala/Status"; // Specify the path to the "Status" document

        if (Firebase.Firestore.getDocument(&fbdo, FIREBASE_PROJECT_ID, "", documentPath.c_str(), ""))
        {
            String jsonStr = fbdo.payload();
            Serial.println("Document content:");
            Serial.println(jsonStr);

            // Parse the JSON data
            StaticJsonDocument<512> doc; // Adjust the buffer size as needed
            DeserializationError error = deserializeJson(doc, jsonStr);

            if (!error)
            {
                // Access the "Dispenser" field and store it in a variable
                *dispenserStatus = doc["fields"]["Dispenser"]["booleanValue"];

                // Access the "Misting_Nozzles" field and store it in a variable
                *mistingStatus = doc["fields"]["Misting_Nozzles"]["booleanValue"];
            }
            else
            {
                Serial.print("JSON parsing error: ");
                Serial.println(error.c_str());
            }
        }
        else
        {
            Serial.println(fbdo.errorReason());
        }
    }
};

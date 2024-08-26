#include "FirebaseRealtimeDB.h"
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

void FirebaseRealtimeDB::init()
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

    UID = auth.token.uid.c_str();
    Serial.print("User UID: ");
    Serial.print(UID);
}

void FirebaseRealtimeDB::Update(String path, const String &value)
{
    if (Firebase.ready())
    {
        if (Firebase.RTDB.setString(&fbdo, path, value))
        {
            Serial.println("PASSED");
            Serial.print("PATH: ");
            Serial.println(fbdo.dataPath());
            Serial.print("TYPE: ");
            Serial.println(fbdo.dataType());
        }
        else
        {
            Serial.println("FAILED");
            Serial.print("REASON: ");
            Serial.println(fbdo.errorReason());
        }
    }
}

void FirebaseRealtimeDB::Delete(String name)
{
    if (Firebase.ready())
    {
        if (Firebase.RTDB.deleteNode(&fbdo, name))
        {
            Serial.println("PASSED");
            Serial.print("PATH: ");
            Serial.println(fbdo.dataPath());
            Serial.print("TYPE: ");
            Serial.println(fbdo.dataType());
        }
        else
        {
            Serial.println("FAILED");
            Serial.print("REASON: ");
            Serial.println(fbdo.errorReason());
        }
    }
}

String FirebaseRealtimeDB::Read(String name)
{
    if (Firebase.ready())
    {
        if (Firebase.RTDB.getString(&fbdo, name))
        {
            Serial.println("PASSED");
            Serial.print("PATH: ");
            Serial.println(fbdo.dataPath());
            Serial.print("TYPE: ");
            Serial.println(fbdo.dataType());
            return fbdo.stringData();
        }
        else
        {
            Serial.println("FAILED");
            Serial.print("REASON: ");
            Serial.println(fbdo.errorReason());
            return "";
        }
    }
    else
    {
        Serial.println("Firebase not ready");
        return "";
    }
}
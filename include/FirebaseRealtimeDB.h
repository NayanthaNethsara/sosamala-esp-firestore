#ifndef FIREBASE_REALTIMEDB_H
#define FIREBASE_REALTIMEDB_H

#include <Firebase_ESP_Client.h>

class FirebaseRealtimeDB
{
private:
    const char *USER_EMAIL = "USER_EMAIL";
    const char *USER_PASSWORD = "USER_PASSWORD";
    const char *API_KEY = "API_KEY";
    const char *DATABASE_URL = "DATABASE_URL";
    const char *FIREBASE_PROJECT_ID = "FIREBASE_PROJECT_ID";
    FirebaseData fbdo;
    FirebaseAuth auth;
    FirebaseConfig config;
    String UID;

public:
    void init();
    void Update(String path, const String &value);
    void Delete(String name);
    String Read(String name);
};

#endif // FIREBASE_REALTIMEDB_H

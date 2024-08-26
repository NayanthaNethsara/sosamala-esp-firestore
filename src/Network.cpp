#include "Network.h"
#include <WiFi.h>

void Network::init()
{
    if (_ssid == "" || _password == "")
    {
        Serial.println("Please authenticate first");
        return;
    }
    else
    {
        Serial.println("Authenticating...");
        WiFi.begin(_ssid.c_str(), _password.c_str());
        while (WiFi.status() != WL_CONNECTED)
        {
            delay(1000);
            Serial.println("Connecting to WiFi..");
        }
        Serial.println("Connected to the WiFi network");
        Serial.print("IP Address: ");
        Serial.println(WiFi.localIP());
    }
}

void Network::authenticate(String ssid, String password)
{
    _ssid = ssid;
    _password = password;

    WiFi.disconnect();
    Serial.println("Disconnected from the current network");
    _isConnected = false;
    _autoReconnect = false;
    Serial.println("Auto-reconnect is disabled");
}

bool Network::isConnected()
{
    if (WiFi.status() == WL_CONNECTED)
    {
        _isConnected = true;
    }
    else
    {
        _isConnected = false;
    }
    return _isConnected;
}

void Network::setAutoReconnect(bool status)
{
    WiFi.setAutoReconnect(status);
    _autoReconnect = status;
    if (_autoReconnect)
    {
        Serial.println("Auto-reconnect is enabled");
    }
    else
    {
        Serial.println("Auto-reconnect is disabled");
    }
};

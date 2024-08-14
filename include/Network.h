#include <WiFi.h>

#define WIFI_SSID "Nayaa"
#define WIFI_PASSWORD "Lancer2003"

void initWiFi()
{
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to WiFi ..");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print('.');
        delay(1000);
    }
    Serial.println(WiFi.localIP());
    Serial.println();
}

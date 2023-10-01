#include "DHT.h"
#include "Network.h"
#include "Firebase_Client.h"

#define DHT11PIN 4

DHT dht;

unsigned long sendDataPrevMillis = 0;
bool signupOK = false;

int moisture, temperature, humidity;
const int sensor_pin = A6;
bool dispenserStatus, mistingStatus;

void setup()
{

  dht.setup(DHT11PIN);

  Serial.begin(115200);

  initWiFi();
  initFirebase();
}

void loop()
{
  if (Firebase.isTokenExpired())
  {
    Firebase.refreshToken(&config);
    Serial.println("Refresh token");
  }

  int sensor_analog = analogRead(sensor_pin);

  moisture = (100 - ((sensor_analog / 4095.00) * 100));
  humidity = dht.getHumidity();
  temperature = dht.getTemperature();
  Firestore_Read(&dispenserStatus, &mistingStatus);
  Serial.println("Dispenser Status: ");
  Serial.print(dispenserStatus);
  delay(5000);
  // Firestore_Update();
}

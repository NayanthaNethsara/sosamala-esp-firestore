#include "Network.h"
#include "userconfig.h"
#include "Realtime_Client.h"
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <ESP32Servo.h>

#define DHT11PIN 4
#define DHTTYPE DHT11
#define MOTOR 22
const int sensor_pin = A6;
Servo myservo;

DHT dht(DHT11PIN, DHTTYPE);

const long interval = 5000;
unsigned long previousMillis = 0;

int moisture = 50, temperature = 27, humidity = 70;

bool dispenserStatus, mistingStatus, lightStatus, soilSuperior, mistSuperior, servostatus;
int servoPin = 2;

RealtimeDBClass FireReal;

void setup()
{

  dht.begin();

  Serial.begin(115200);

  initWiFi();

  FireReal.init();
  myservo.attach(servoPin);

  pinMode(MOTOR, OUTPUT);
}

void loop()
{
  unsigned long currentMillis = millis();

  if (Firebase.isTokenExpired())
  {
    Firebase.refreshToken(&FireReal.config);
    Serial.println("Refresh token");
  }

  // myservo.write(0);
  // delay(1500);
  // myservo.write(90);
  // delay(1500);

  int sensor_analog = analogRead(sensor_pin);

  moisture = (100 - ((sensor_analog / 4095.00) * 100));
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();

  Serial.println("\n");

  Serial.print("Humidity: ");
  Serial.println(humidity);

  Serial.print("Temperature: ");
  Serial.println(temperature);

  Serial.print("Moisture: ");
  Serial.println(moisture);

  Serial.println("\n");
  delay(2000);
  dispenserStatus = FireReal.StatusRead("Dispenser");
  mistingStatus = FireReal.StatusRead("MistingNozzle");
  lightStatus = FireReal.StatusRead("Light");
  servostatus = FireReal.StatusRead("Camera");

  if (servostatus)
  {

    myservo.write(0);
  }
  else
  {
    myservo.write(0);
  }
  Serial.println("\n");
  Serial.print("Misting Status: ");
  Serial.println(mistingStatus);

  mistingStatus ? digitalWrite(MOTOR, HIGH) : digitalWrite(MOTOR, LOW);

  if (currentMillis - previousMillis >= interval)
  {
    FireReal.SensorDataUpdate("Humidity", humidity);
    FireReal.SensorDataUpdate("Temperature", temperature);
    FireReal.SensorDataUpdate("Moisture", moisture);

    soilSuperior = FireReal.SuperiorRead("Soil");
    mistSuperior = FireReal.SuperiorRead("Mist");

    if (soilSuperior)
    {
      if (moisture < 40)
      {
        FireReal.StatusUpdate("Dispenser", true);
      }
      else
      {
        FireReal.StatusUpdate("Dispenser", false);
      }
    }

    if (mistSuperior)
    {
      if (humidity < 40)
      {
        FireReal.StatusUpdate("Dispenser", true);
      }
      else
      {
        FireReal.StatusUpdate("Dispenser", false);
      }
    }
    previousMillis = currentMillis;
  }
}

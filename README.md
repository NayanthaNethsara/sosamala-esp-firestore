🌱 Greenhouse Automation System using ESP32 & Firebase

# Greenhouse Automation System

Welcome to the Greenhouse Automation System project! 🌿 This is a versatile IoT solution designed to automate and monitor greenhouse environments, created specifically for university students interested in cutting-edge technology. This project leverages the powerful ESP32 module and Firebase Realtime Database to sync sensor data and control various actuators like water motors and misting nozzles, making it an ideal starting point for students and enthusiasts alike.

## 🚀 Project Overview

This project is designed to facilitate the real-time monitoring and automation of greenhouse conditions, ensuring optimal growth for plants. By using the ESP32 microcontroller, which comes with built-in Wi-Fi and Bluetooth capabilities, the system can collect data from various sensors and push it to the cloud via Firebase Realtime Database. The data can then be accessed remotely, allowing for real-time decision-making and automation.

### Key Features

- Real-time Data Sync: The system collects data from various sensors, such as temperature, humidity, and soil moisture, and syncs it with Firebase in real time.
- Automated Control: Actuators like water motors and misting nozzles can be automatically controlled based on predefined conditions or remotely via a mobile app or web interface.
- Cloud-Based Monitoring: Data is stored in Firebase Realtime Database, allowing you to monitor and control your greenhouse from anywhere in the world.
- Scalability: While this project is designed for greenhouses, the underlying technology can be easily adapted for other applications, such as smart homes, industrial monitoring, or any IoT-based data synchronization needs.

## 🛠️ Hardware Requirements

- ESP32 Module: The core of the system, responsible for sensor data collection and cloud communication.
- Sensors: Various sensors like DHT11/DHT22 for temperature and humidity, soil moisture sensors, etc.
- Actuators: Devices like water motors, misting nozzles, and fans to control the greenhouse environment.
- Power Supply: Adequate power supply for the ESP32 and connected components.

## 🗂️ Software Requirements

- PlatformIO: For programming the ESP32 module.
- Firebase Account: For storing and syncing data in the Realtime Database.
- Firebase SDK: To integrate Firebase with the ESP32 module.

## 📈 How It Works

1. Sensor Data Collection: The ESP32 collects data from various sensors in the greenhouse.
2. Data Sync to Firebase: The collected data is then pushed to the Firebase Realtime Database.
3. Remote Monitoring & Control: Users can monitor the data in real-time and control actuators through a mobile app or web interface.
4. Automated Actions: Based on the sensor data, predefined actions (like turning on the water motor when soil moisture is low) are automatically triggered.

## 💡 Potential Use Cases

- Greenhouse Automation: Monitor and automate the greenhouse environment for optimal plant growth.
- Smart Irrigation Systems: Automate watering based on soil moisture data.
- Environmental Monitoring: Use the system for real-time monitoring of environmental conditions in various settings.
- Home Automation: Adapt the project for controlling home appliances and systems remotely.

## 📚 Getting Started

1. Clone this repository.
   ```bash
   git clone https://github.com/NayanthaNethsara/sosamala-esp-firestore.git
   ```
2. Set up your Firebase account and configure the Realtime Database.
3. Flash the ESP32 with the provided code using PlatformIO.
4. Connect your sensors and actuators according to the schematic provided.
5. Enjoy automated, cloud-based control of your greenhouse! 🌿
   Feel free to tweak this as per your specific project details or branding!

## Class Explanation

# Network Class

The `Network` class is responsible for managing network connectivity. It provides methods to initialize the network, authenticate with a specific network, check if the device is connected to the network, and enable/disable auto-reconnect functionality.

## Methods

- `void init()`: This method initializes the network. It can be used to set up any necessary configurations or resources related to network connectivity.

Example:

```cpp
Network network;
network.init();
```

- `void authenticate(String ssid, String password)`: This method is used to authenticate with a specific network by providing the SSID (network name) and password as parameters.

Example:

```cpp
Network network;
network.authenticate("MyNetwork", "MyPassword");
```

- `bool isConnected()`: This method checks if the device is currently connected to the network. It returns a boolean value indicating the connection status.

Example:

```cpp
Network network;
bool connected = network.isConnected();
if (connected) {
    // Device is connected to the network
} else {
    // Device is not connected to the network
}
```

- `void setAutoReconnect(bool status)`: This method enables or disables the auto-reconnect functionality. When enabled, the device will automatically attempt to reconnect to the network if the connection is lost.

Example:

```cpp
Network network;
network.setAutoReconnect(true);
```

# FirebaseRealtimeDB Class

The `FirebaseRealtimeDB` class is designed to interact with the Firebase Realtime Database. It provides methods to initialize the Firebase client, update data in the database, delete data, and read data.

## Properties

- `USER_EMAIL`: This property holds the user's email address used for authentication with Firebase.
- `USER_PASSWORD`: This property holds the user's password used for authentication with Firebase.
- `API_KEY`: This property holds the API key required for accessing the Firebase services.
- `DATABASE_URL`: This property holds the URL of the Firebase Realtime Database.
- `FIREBASE_PROJECT_ID`: This property holds the ID of the Firebase project.

## Methods

- `void init()`: This method initializes the Firebase client by setting up the necessary configurations and establishing a connection to the Firebase services.

Example:

```cpp
FirebaseRealtimeDB db;
db.init();
```

- `void Update(String path, const String &value)`: This method is used to update data in the Firebase Realtime Database. It takes a path (location in the database) and a value as parameters.

Example:

```cpp
FirebaseRealtimeDB db;
db.Update("/users/123", "John Doe");
```

- `void Delete(String name)`: This method is used to delete data from the Firebase Realtime Database. It takes the name of the data to be deleted as a parameter.

Example:

```cpp
FirebaseRealtimeDB db;
db.Delete("John Doe");
```

- `String Read(String name)`: This method is used to read data from the Firebase Realtime Database. It takes the name of the data to be read as a parameter and returns the corresponding value.

Example:

```cpp
FirebaseRealtimeDB db;
String value = db.Read("John Doe");
```

Remember to update the documentation as you make changes or add new features to the classes.

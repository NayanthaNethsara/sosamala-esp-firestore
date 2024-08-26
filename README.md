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

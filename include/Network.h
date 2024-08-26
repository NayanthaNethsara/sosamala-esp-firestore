#ifndef NETWORK_H
#define NETWORK_H

class Network
{
public:
    void init();
    void authenticate(String ssid, String password);
    bool isConnected();
    void setAutoReconnect(bool status);

private:
    String _ssid;
    String _password;
    bool _isConnected;
    bool _autoReconnect;
};

#endif // NETWORK_H
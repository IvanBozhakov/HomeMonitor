#include <WiFi.h>

class WiFiConnection {
  private:
    const char* ssid;
    const char* password;

  public:
    WiFiConnection(const char* wifi_ssid, const char* wifi_password) {
      ssid = wifi_ssid;
      password = wifi_password;
    }

    void connect() {
      Serial.begin(115200);
      Serial.println("Connecting to WiFi...");

      WiFi.begin(ssid, password);

      while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting...");
      }

      Serial.println("Connected to WiFi");
      Serial.print("IP Address: ");
      Serial.println(WiFi.localIP());
    }

    bool isConnected() {
      return WiFi.status() == WL_CONNECTED;
    }

    IPAddress getIPAddress() {
      return WiFi.localIP();
    }
};

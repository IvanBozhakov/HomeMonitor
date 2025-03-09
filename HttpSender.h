#ifndef HTTPPSENDER_H
#define HTTPPSENDER_H

#include <HTTPClient.h>
#include <WiFi.h>

class HttpSender {
  private:
    const char* serverUrl;

  public:
    HttpSender(const char* url) {
      serverUrl = url;
    }

    bool post(const String& payload) {
      HTTPClient http;

      if (WiFi.status() == WL_CONNECTED) {
        http.begin(serverUrl);
        http.addHeader("Content-Type", "application/json");

        int httpCode = http.POST(payload); 
        
        if (httpCode > 0) {
          String response = http.getString();
          Serial.println("Response: " + response);
        } else {
          Serial.printf("Error sending POST request: %d\n", httpCode);
        }

        http.end();
        return httpCode > 0;
      } else {
        Serial.println("WiFi not connected.");
        return false;
      }
    }
};

#endif

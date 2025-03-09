#ifndef SENSORS_DTO_H
#define SENSORS_DTO_H

#include <Arduino.h>
#include <ArduinoJson.h>

class SensorsDto {
  private:
    float temperature;
    float humidity;
    bool isGasDetected;
    bool isMotionDetected;

  public:
    SensorsDto() {
      temperature = 0.0;
      humidity = 0.0;
      isGasDetected = false;
      isMotionDetected = false;
    }

    void setTemperature(float temp) {
      temperature = temp;
    }

    void setHumidity(float hum) {
      humidity = hum;
    }

    void setIsGasDetected(bool gasDetected) {
      isGasDetected = gasDetected;
    }

    void setIsMotionDetected(bool motionDetected) {
      isMotionDetected = motionDetected;
    }

    String toJson() {
      JsonDocument doc;
      doc["temperature"] = temperature;
      doc["humidity"] = humidity;
      doc["isGasDetected"] = isGasDetected;
      doc["isMotionDetected"] = isMotionDetected;
      
      String jsonString;
      serializeJson(doc, jsonString);
      return jsonString;
  }
};

#endif

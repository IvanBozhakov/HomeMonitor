#ifndef MQ2_SENSOR_H
#define MQ2_SENSOR_H

#include <Arduino.h>

class MQ2Sensor {
  
  private:
    uint8_t sensorPin;
    
  public:
    MQ2Sensor(uint8_t pin) : sensorPin(pin) {}
    
    void begin() {
        pinMode(sensorPin, INPUT);
        Serial.print("Wait for the MQ2 to warm up");
        delay(20000);
    }
    
    bool isGasDetected() {
       int gasState = digitalRead(sensorPin);
       return gasState == LOW;
    }
};

#endif 

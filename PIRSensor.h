#ifndef PIR_SENSOR_H
#define PIR_SENSOR_H

#include <Arduino.h>

class PIRSensor {
  
  private:
    int pirPin; 
    unsigned long lastMotionTime;
    unsigned long motionDelay;

  public:
    PIRSensor(int pin) {
      pirPin = pin;
      lastMotionTime = 0;
      motionDelay = 5000;  
    }

    void begin() {
      pinMode(pirPin, INPUT);
      delay(1000);   
    }
    
    bool isMotionDetected() {
      int sensorState = digitalRead(pirPin);
      unsigned long currentMillis = millis();
      
      if (
          sensorState == HIGH &&
          currentMillis - lastMotionTime >= motionDelay
        ) {
         lastMotionTime = currentMillis;
          return true;
      }

      return false;
    }
};

#endif

#ifndef DHT_SENSOR_H
#define DHT_SENSOR_H

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

class DHTSensor {
  private:
    DHT* dht;
    uint8_t dhtPin;
    
  public:
    DHTSensor(uint8_t pin, int type) : dhtPin(pin) {
      dht = new DHT(dhtPin, type);
    }  

    ~DHTSensor() {
      delete dht;
    }
    
    void begin() {
        dht->begin();
    }
    
    float getTemperature() {
        return dht->readTemperature();
    }
    
    float getHumidity() {
        return dht->readHumidity();
    }
};

#endif

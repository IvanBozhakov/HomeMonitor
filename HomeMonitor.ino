#include <Arduino.h>
#include <config.h>
#include <DHTSensor.h>
#include <MQ2Sensor.h>
#include <PIRSensor.h>
#include <WiFiConnection.h>
#include <HttpSender.h>
#include <SensorsDto.h>

DHTSensor dhtSensor(DHT_SENSOR_PIN, DHT_TYPE);
MQ2Sensor mq2Sensor(MQ2_SENSOR_PIN);
PIRSensor pirSensor(PIR_PIN);

WiFiConnection wifi(WIFI_SSID, WIFI_PASSWORD);
HttpSender httpSender(SERVER_ENDPOINT);


void setup() {
    Serial.begin(115200);
    dhtSensor.begin();
    mq2Sensor.begin();
    pirSensor.begin();
    wifi.connect();
}

void loop() { 
    SensorsDto sensors;
    // DHT
    float temperature = dhtSensor.getTemperature();
    float humidity = dhtSensor.getHumidity();

    if (!isnan(temperature) && !isnan(humidity)) {
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.print(" °C  Humidity: ");
        Serial.print(humidity);
        Serial.println(" %");
        sensors.setTemperature(temperature);
        sensors.setHumidity(humidity);
    } 
  
    // MQ-2
    if (mq2Sensor.isGasDetected()) {
      Serial.println("Gas detected!");
      sensors.setIsGasDetected(true);
    }

    // PIR
    if (pirSensor.isMotionDetected()) {
      Serial.println("Motion Detected!");
      sensors.setIsMotionDetected(true);
    }

    Serial.println(sensors.toJson());

    httpSender.post(sensors.toJson());

    delay(INTERVAL); 
}

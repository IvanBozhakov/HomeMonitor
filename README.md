# Sensor Configuration for ESP32

This project is designed to interface with various sensors (DHT11, MQ2, and PIR) using an ESP32. The `config.h` file contains the configuration settings necessary to connect to Wi-Fi and define the sensor pin assignments for the ESP32. 

### Table of Contents
1. [Introduction](#introduction)
2. [Configuration](#configuration)
    - [Sensor Pin Assignments](#sensor-pin-assignments)
    - [Wi-Fi Credentials](#wi-fi-credentials)
    - [Server Endpoint](#server-endpoint)
    - [Installing Libraries](#installing-libraries-arduinojson-and-adafruit_sensor)
3. [Usage](#usage)
4. [License](#license)

---

## Introduction

The `config.h` file serves as the central location for defining hardware pin assignments, Wi-Fi credentials, and server endpoint settings. This file is included in your main program to enable communication between the sensors (DHT11, MQ2, PIR) and your ESP32 board. 


## Configuration

Rename **config.h.local** to **config.h**

### Sensor Pin Assignments

In the `config.h` file, you define the pin numbers for the sensors connected to the ESP32. These pins correspond to the GPIO pins on the ESP32, and each sensor has a specific function:

```cpp
#define DHT_TYPE DHT11            // Type of DHT sensor (DHT11 in this case)
#define DHT_SENSOR_PIN 27         // GPIO pin where DHT11 is connected
#define MQ2_SENSOR_PIN 25         // GPIO pin where MQ2 gas sensor is connected
#define PIR_PIN 26                // GPIO pin where PIR motion sensor is connected
```

### Wi-Fi Credentials
```cpp
#define WIFI_SSID "xxxxxx"             // Your Wi-Fi network's SSID
#define WIFI_PASSWORD "********"      // Your Wi-Fi network's password
```

### Installing Libraries: ArduinoJson and Adafruit_Sensor
For properly running enviorment you have to install  **ArduinoJson** and **Adafruit_Sensor** libraries in your project, you’ll need to install them in the Arduino IDE. Follow these steps:

#### 1. **ArduinoJson**:
   - Open the Arduino IDE.
   - Go to the **Sketch** menu and select **Include Library** > **Manage Libraries...**.
   - In the Library Manager, type **"ArduinoJson"** into the search bar.
   - Find the library **ArduinoJson** by Benoit Blanchon and click the **Install** button.

#### 2. **Adafruit_Sensor**:
   - Open the Arduino IDE.
   - Go to the **Sketch** menu and select **Include Library** > **Manage Libraries...**.
   - In the Library Manager, type **"Adafruit Sensor"** into the search bar.
   - Find the **Adafruit Sensor** library by Adafruit and click the **Install** button.

### Server Endpoint
```cpp
#define SERVER_ENDPOINT "http://127.0.0.1" // The URL endpoint to send sensor data
```

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.




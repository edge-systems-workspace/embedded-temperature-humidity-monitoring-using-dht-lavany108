/**
* @file main.cpp
 * @brief Arduino sketch for reading temperature and humidity from a DHT11 sensor.
 *
 * This sketch uses the DHT library to interface with a DHT11 temperature and
 * humidity sensor. Readings are printed to the Serial console at 9600 baud.
 *
 * Requirements:
 *  - Arduino core
 *  - DHT sensor library (https://github.com/adafruit/DHT-sensor-library or equivalent)
 *
 * Usage:
 *  - Connect the DHT11 data pin to the digital pin defined by @ref DHTPIN.
 *  - Power the sensor with 3.3V/5V and connect ground.
 *  - Open the Serial Monitor at 9600 baud to view readings.
 *
 * @author Lavanya
 * @date 2026-02-28
 * @version 1.0
 */
#include <Arduino.h>
#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
void setup() {
    Serial.begin(9600);
    dht.begin();
    Serial.println("DHT11 initialized");
}
void loop() {
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Failed to read from DHT sensor!");
        delay(2000);
        return;
    }

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print(" % | ");
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    delay(2000);
}
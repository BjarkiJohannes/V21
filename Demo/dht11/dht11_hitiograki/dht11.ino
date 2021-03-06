#include <dht.h>

//DHT11 is connected to pin 8
dht DHT;

#define sensorPin 8

//Raspberry Pi is connected to Serial 0
#define serialPi Serial    // Serial.begin(9600);

void setup() {
  serialPi.begin(9600);  //Arduino to serial monitor
}

void loop() {
  
  //Read sensor data
  int sensorData = DHT.read11(sensorPin);
  float temperature = DHT.temperature;
  float humidity = DHT.humidity;
  
  //Send temperature and humidity data to Raspberry Pi
  serialPi.print("<");
  serialPi.print(temperature);
  serialPi.print(",");
  serialPi.print(humidity);
  serialPi.println(">");
  
  // Serial.println(DHT.temperature);
  
  //Wait for 1 seconds
  delay(1000);
}

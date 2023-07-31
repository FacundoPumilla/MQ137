#include <Arduino.h>

#define MQ137_ANALOG_PIN A0

// Reemplazar por el valor arrojado al calibrar sensor
#define MQ137_R0 26.21f

#include <MQ137.h>

MQ137 mq137(MQ137_ANALOG_PIN, MQ137_R0, true);

void setup() {
  Serial.begin(115200);
  delay(5000);
  mq137.begin();
}

void loop() {
  Serial.print("PPM de amonio ->\t");
  Serial.println(mq137.getPPM());
  delay(1000);
}

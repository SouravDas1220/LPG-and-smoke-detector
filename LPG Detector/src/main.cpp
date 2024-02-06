#include <Arduino.h>
#include <MQ2.h>
#define led 7
int pin = A0;
float lpg, co, smoke;

MQ2 mq2(pin);

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  mq2.begin();
}

void loop()
{
  float *values = mq2.read(true);
  lpg = mq2.readLPG();
  co = mq2.readCO();
  smoke = mq2.readSmoke();
  if (lpg >= 200 || co >= 6)
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
  delay(1000);
}

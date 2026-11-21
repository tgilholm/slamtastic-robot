#include <Arduino.h>
#include "config.h"
#include "Encoder.h"

Encoder encoder_1(PIN_ENCODER_1A, PIN_ENCODER_1B);
Encoder encoder_2(PIN_ENCODER_2A, PIN_ENCODER_2B);

void setup()
{
  Serial.begin(9600);
  encoder_1.init();
  encoder_2.init();
}

void loop()
{
  Serial.print("Encoder 1 Channel A: ");
  Serial.println(encoder_1.readChannelA());

  Serial.print("Encoder 1 Channel B: ");
  Serial.println(encoder_1.readChannelB());

  Serial.print("Encoder 2 Channel A: ");
  Serial.println(encoder_2.readChannelA());

  Serial.print("Encoder 2 Channel B: ");
  Serial.println(encoder_2.readChannelB());
  delay(500);
}
#include <Arduino.h>
#include <IRremote.h>

#define PIN_IR_RECV 12
#define SPEED 40

#define PIN_DIR1 7
#define PIN_DIR2 8
#define PIN_PWM1 6
#define PIN_PWM2 5

#define CMD_UP 0x46
#define CMD_DOWN 0x15
#define CMD_LEFT 0x44
#define CMD_RIGHT 0x43
#define CMD_OK 0x40

void setup()
{
  Serial.begin(9600);
  IrReceiver.begin(PIN_IR_RECV, ENABLE_LED_FEEDBACK);
  Serial.println("IR Receiver Ready");

  pinMode(PIN_DIR1, OUTPUT);
  pinMode(PIN_DIR2, OUTPUT);

  pinMode(PIN_PWM1, OUTPUT);
  pinMode(PIN_PWM2, OUTPUT);
}

void handleIR()
{
  uint16_t command = IrReceiver.decodedIRData.command;

  switch (command)
  {
  case CMD_UP:
    // flipped relative to bot
    Serial.println("Driving forward");
    digitalWrite(PIN_DIR1, LOW);
    digitalWrite(PIN_DIR2, LOW);
    analogWrite(PIN_PWM1, SPEED);
    analogWrite(PIN_PWM2, SPEED);
    break;

  case CMD_DOWN:
    Serial.println("Reversing");

    digitalWrite(PIN_DIR1, HIGH);
    digitalWrite(PIN_DIR2, HIGH);
    analogWrite(PIN_PWM1, SPEED);
    analogWrite(PIN_PWM2, SPEED);
    break;

  case CMD_LEFT:
    Serial.println("Turning left");

    digitalWrite(PIN_DIR1, HIGH);
    digitalWrite(PIN_DIR2, LOW);
    analogWrite(PIN_PWM1, SPEED);
    analogWrite(PIN_PWM2, SPEED);
    break;

  case CMD_RIGHT:
    Serial.println("Turning right");

    digitalWrite(PIN_DIR1, LOW);
    digitalWrite(PIN_DIR2, HIGH);
    analogWrite(PIN_PWM1, SPEED);
    analogWrite(PIN_PWM2, SPEED);
    break;

  case CMD_OK:
    Serial.println("Stopping");
    analogWrite(PIN_PWM1, 0);
    analogWrite(PIN_PWM2, 0);
    break;
  }
}

void loop()
{

  if (IrReceiver.decode())
  {
    handleIR();
    IrReceiver.resume();
  }
}
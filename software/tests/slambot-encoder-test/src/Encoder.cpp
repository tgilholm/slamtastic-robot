#include "Encoder.h"

void Encoder::init()
{
    pinMode(pin_channel_a, INPUT_PULLUP);
    pinMode(pin_channel_b, INPUT_PULLUP);
}

int Encoder::readChannelA()
{
    return digitalRead(pin_channel_a);
}

int Encoder::readChannelB()
{
    return digitalRead(pin_channel_b);
}
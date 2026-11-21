#ifndef ENCODER_H
#define ENCODER_H
#include "Arduino.h"

class Encoder
{
public:
    Encoder(const uint8_t a_channel, const uint8_t b_channel) : pin_channel_a(a_channel), pin_channel_b(b_channel) {}

    void init();
    int readChannelA();
    int readChannelB();

private:
    uint8_t pin_channel_a;
    uint8_t pin_channel_b;
};

#endif
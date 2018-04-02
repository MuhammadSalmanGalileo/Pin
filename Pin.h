/*
 * Pin.h
 *
 * Arduino Library for the pin management
 *
 * (c) Muhammad Salman Galileo
 * 2/4/2018
 * 
 * salman.galileo@gmail.com
 *
 */

#ifndef PIN_h
#define PIN_h

#include <Arduino.h>

class Pin
{
    protected:
        uint8_t timer; // PWM status
        uint8_t bit; // bit to write
        uint8_t port; // port representation
        volatile uint8_t *reg; // register
        volatile uint8_t *out;
        volatile uint8_t *in;

    public:
        Pin(uint8_t pin);
        Pin(uint8_t pin, uint8_t mode);
       
        void changePin(uint8_t pin);

        void pinMode(uint8_t mode);

        void digitalWrite(uint8_t val);

        uint8_t digitalRead();
};

#endif
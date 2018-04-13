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
        
        // event implementation
        uint8_t buttonState;
        uint8_t lastButtonState;

        unsigned long lastDebounceTime = 0;
        unsigned long debounceDelay = 50;
    public:
        static const uint8_t EDGE = 0;
        static const uint8_t RISING_EDGE = 1;
        static const uint8_t FALLING_EDGE = 2;
        Pin(uint8_t pin);
        Pin(uint8_t pin, uint8_t mode);
       
        void changePin(uint8_t pin);

        void pinMode(uint8_t mode);

        void digitalWrite(uint8_t val);

        uint8_t digitalRead();

        void digitalWriteToggle();

        bool isRisingEdge();

        bool isFallingEdge();

        bool isEdge();
};

#endif
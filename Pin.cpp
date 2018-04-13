/*
 * Pin.cpp
 *
 * Arduino Library for the pin management
 *
 * (c) Muhammad Salman Galileo
 * 2/4/2018
 * 
 * salman.galileo@gmail.com
 *
 */

#include "Pin.h"

Pin::Pin(uint8_t pin)
{
    this->changePin(pin);
}

Pin::Pin(uint8_t pin, uint8_t mode)
{
    this->changePin(pin);
    this->pinMode(mode);
}

void Pin::pinMode(uint8_t mode)
{
    if (port == NOT_A_PIN) return;

    if (mode == INPUT) 
    { 
		*reg &= ~bit;
		*out &= ~bit;
	}
    else if (mode == INPUT_PULLUP)
    {
		*reg &= ~bit;
		*out |= bit;
	}
    else
    {
		*reg |= bit;
	}
}

void Pin::changePin(uint8_t pin)
{
	timer = digitalPinToTimer(pin);
    bit = digitalPinToBitMask(pin);
	port = digitalPinToPort(pin);
	reg = portModeRegister(port);
	out = portOutputRegister(port);
    in = portInputRegister(port);
    buttonState = this->digitalRead();
    lastButtonState = buttonState;
}

void Pin::digitalWrite(uint8_t val)
{
    if (port == NOT_A_PIN) return;

    if (val == LOW) 
    {
		*out &= ~bit;
	}
    else
    {
		*out |= bit;
	}
}

void Pin::digitalWriteToggle()
{
    if (port == NOT_A_PIN) return;

	*out ^= bit;
}

uint8_t Pin::digitalRead()
{
    if (port == NOT_A_PIN) return;

    if (*in & bit) 
        return HIGH;
	else
        return LOW;
}

bool Pin::isRisingEdge()
{
    if(this->isEdge())
        return (buttonState == HIGH);
    return false;
}

bool Pin::isFallingEdge()
{
    if(this->isEdge())
        return (buttonState == LOW);
    return false;
}

bool Pin::isEdge()
{
    buttonState = this->digitalRead();
    bool buff = (buttonState != lastButtonState);
    lastButtonState = buttonState;
    return buff;
}
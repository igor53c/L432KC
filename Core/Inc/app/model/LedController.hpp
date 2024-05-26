#ifndef LEDCONTROLLER_HPP
#define LEDCONTROLLER_HPP

#include "main.h"

class LedController
{
public:
	LedController(GPIO_TypeDef* port, uint16_t pin);
	void update(uint32_t elapsedTime);
	void toggleLed();

private:
	GPIO_TypeDef* port;
	uint16_t pin;
	uint32_t lastToggleTime;
	bool state;
};

#endif // LEDCONTROLLER_HPP

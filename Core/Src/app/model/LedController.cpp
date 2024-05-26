#include "app/model/LedController.hpp"
#include "app/util/DebugLogger.hpp"

LedController::LedController(GPIO_TypeDef* port, uint16_t pin)
: port(port), pin(pin), lastToggleTime(0), state(false)
{
}

void LedController::toggleLed()
{
	HAL_GPIO_TogglePin(port, pin);
	state = !state;
	//LOG("Pin toggled at elapsed time: %lu ms\r\n", lastToggleTime)
	;
}

void LedController::update(uint32_t elapsedTime)
{
	if((elapsedTime - lastToggleTime) >= 300)
	{
		toggleLed();
		lastToggleTime = elapsedTime;
	}
}

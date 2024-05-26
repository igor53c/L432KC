#ifndef APP_HPP
#define APP_HPP

#include "app/model/LedController.hpp"
#include "app/model/TimerManager.hpp"
#include "app/util/DebugLogger.hpp"

class App
{
public:
	App(TIM_HandleTypeDef* htim, UART_HandleTypeDef* huart);
	void init();
	void loop();
	~App();

	TimerManager timerManager;

private:
	LedController* ledController;
};

#endif // APP_HPP

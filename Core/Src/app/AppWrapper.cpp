#include "app/App.hpp"

extern TIM_HandleTypeDef htim2;
extern UART_HandleTypeDef huart2;

App* app = nullptr;

extern "C" void App_Init()
{
	app = new App(&htim2, &huart2);
	app->init();
}

extern "C" void App_Loop()
{
	app->loop();
}

extern "C" void App_Deinit()
{
	delete app;
	app = nullptr;
}

extern "C" void App_TIM2_IRQHandler()
{
	app->timerManager.handleInterrupt();
}

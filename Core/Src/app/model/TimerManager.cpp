#include "app/model/TimerManager.hpp"

TimerManager::TimerManager(TIM_HandleTypeDef* htim)
: htim(htim), elapsedTime(0)
{
	HAL_TIM_Base_Start_IT(htim);
}

void TimerManager::handleInterrupt()
{
	elapsedTime++;
}

uint32_t TimerManager::getElapsedTime() const
{
	return elapsedTime;
}

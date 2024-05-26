#ifndef TIMERMANAGER_HPP
#define TIMERMANAGER_HPP

#include "main.h"

class TimerManager
{
public:
	TimerManager(TIM_HandleTypeDef* htim);
	void handleInterrupt();
	uint32_t getElapsedTime() const;

private:
	TIM_HandleTypeDef* htim;
	volatile uint32_t elapsedTime;
};

#endif // TIMERMANAGER_HPP

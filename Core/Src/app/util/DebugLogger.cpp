#include "app/util/DebugLogger.hpp"

DebugLogger& DebugLogger::getInstance()
{
	static DebugLogger instance;
	return instance;
}

DebugLogger::DebugLogger() : huart(nullptr)
{
}

void DebugLogger::init(UART_HandleTypeDef* huart)
{
	this->huart = huart;

	log("DebugLogger Initialized\r\n");
}

void DebugLogger::log(const char* format, ...)
{
	if(huart)
	{
		char buffer[128];
		va_list args;
		va_start(args, format);
		vsnprintf(buffer, sizeof(buffer), format, args);
		va_end(args);
		HAL_UART_Transmit(huart, (uint8_t*)buffer, strlen(buffer), HAL_MAX_DELAY);
	}
}

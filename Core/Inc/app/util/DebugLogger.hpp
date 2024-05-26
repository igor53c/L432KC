#ifndef DEBUGLOGGER_HPP
#define DEBUGLOGGER_HPP

#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

class DebugLogger
{
public:
	static DebugLogger& getInstance();
	void init(UART_HandleTypeDef* huart);
	void log(const char* format, ...);

private:
	DebugLogger();
	DebugLogger(const DebugLogger&) = delete;
	DebugLogger& operator=(const DebugLogger&) = delete;

	UART_HandleTypeDef* huart;
};

#define LOG(format, ...) DebugLogger::getInstance().log(format, ##__VA_ARGS__)

#endif // DEBUGLOGGER_HPP

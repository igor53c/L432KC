#include "app/App.hpp"
#include "app/util/MemoryMonitor.hpp"

App::App(TIM_HandleTypeDef* htim, UART_HandleTypeDef* huart)
: timerManager(htim),
				ledController(new LedController(LD3_GPIO_Port, LD3_Pin))
{
	DebugLogger::getInstance().init(huart);

	LOG("\r\nApp Constructor Initialized\r\n");
}

void allocateArrayOnStack(MemoryMonitor& monitor)
{
	int array[300] = {0};

	monitor.printMemoryUsage();
}

void App::init()
{
	LOG("App Initialized\r\n");

	MemoryMonitor& monitor = MemoryMonitor::getInstance();

	void* ptr1 = monitor.monitoredMalloc(100);
	void* ptr2 = monitor.monitoredMalloc(200);

	LOG("Total allocated memory: %d bytes\r\n", monitor.getTotalAllocatedMemory());
	LOG("Current allocated memory: %d bytes\r\n", monitor.getCurrentAllocatedMemory());

	monitor.monitoredFree(ptr1);
	monitor.monitoredFree(ptr2);

	LOG("Total allocated memory: %d bytes\r\n", monitor.getTotalAllocatedMemory());
	LOG("Current allocated memory: %d bytes\r\n", monitor.getCurrentAllocatedMemory());

	monitor.printMemoryUsage();

	allocateArrayOnStack(monitor);
}

void App::loop()
{
	ledController->update(timerManager.getElapsedTime());
}

App::~App()
{
	delete ledController;
}

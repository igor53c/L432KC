#include "app/util/MemoryMonitor.hpp"
#include "app/util/DebugLogger.hpp"

MemoryMonitor& MemoryMonitor::getInstance()
{
	static MemoryMonitor instance;
	return instance;
}

MemoryMonitor::MemoryMonitor()
: totalAllocatedMemory(0), currentAllocatedMemory(0)
{
}

void* MemoryMonitor::monitoredMalloc(size_t size)
{
	void* ptr = malloc(size);
	if(ptr != nullptr)
	{
		totalAllocatedMemory += size;
		currentAllocatedMemory += size;
		allocationMap[ptr] = size; // Track allocation size
	}
	return ptr;
}

void MemoryMonitor::monitoredFree(void* ptr)
{
	if(ptr != nullptr && allocationMap.find(ptr) != allocationMap.end())
	{
		size_t size = allocationMap[ptr];
		currentAllocatedMemory -= size;
		allocationMap.erase(ptr); // Remove from map
		free(ptr);
	}
}

size_t MemoryMonitor::getTotalAllocatedMemory() const
{
	return totalAllocatedMemory;
}

size_t MemoryMonitor::getCurrentAllocatedMemory() const
{
	return currentAllocatedMemory;
}

void MemoryMonitor::printMemoryUsage() const
{
	struct mallinfo mi = mallinfo();

	// Heap size
	unsigned int heapSize = mi.uordblks;
	// Stack pointer
	unsigned int stackPointer = reinterpret_cast<unsigned int>(__builtin_frame_address(0));
	// Stack size
	unsigned int stackSize = reinterpret_cast<unsigned int>(&_estack) - stackPointer;
	// BSS segment size
	unsigned int bssSize = reinterpret_cast<unsigned int>(&_ebss) - reinterpret_cast<unsigned int>(&_sbss);
	// Data segment size
	unsigned int dataSize = reinterpret_cast<unsigned int>(&_edata) - reinterpret_cast<unsigned int>(&_sdata);
	// Total RAM size (64KB + 16KB = 80KB)
	unsigned int totalRamSize = 64 * 1024 + 16 * 1024;
	// Total used RAM
	unsigned int totalUsedRam = heapSize + stackSize + bssSize + dataSize;
	// Total free RAM
	unsigned int totalFreeRam = totalRamSize - totalUsedRam;

	LOG("Total space allocated from system: %d bytes\r\n", mi.arena);
	LOG("Total free space: %d bytes\r\n", mi.fordblks);
	LOG("Total allocated space: %d bytes\r\n", mi.uordblks);
	LOG("Heap size: %u bytes\r\n", heapSize);
	LOG("Used stack size: %u bytes\r\n", stackSize);
	LOG("Free stack size: %u bytes\r\n", reinterpret_cast<unsigned int>(&_estack) - stackPointer);
	LOG("BSS size: %u bytes\r\n", bssSize);
	LOG("Data size: %u bytes\r\n", dataSize);
	LOG("Total used RAM: %u bytes\r\n", totalUsedRam);
	LOG("Total free RAM: %u bytes\r\n", totalFreeRam);
	LOG("Total RAM: %u bytes\r\n", totalRamSize);

	// Add log messages to check the values of the symbols
	LOG("_end: %p\r\n", &_end);
	LOG("_estack: %p\r\n", &_estack);
	LOG("_sbss: %p\r\n", &_sbss);
	LOG("_ebss: %p\r\n", &_ebss);
	LOG("_sdata: %p\r\n", &_sdata);
	LOG("_edata: %p\r\n", &_edata);
}

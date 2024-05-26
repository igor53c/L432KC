#ifndef MEMORY_MONITOR_HPP
#define MEMORY_MONITOR_HPP

#include <cstdlib>
#include <cstddef>
#include <unordered_map>
#include <malloc.h>

extern char _end;
extern char _estack;
extern char _sbss;
extern char _ebss;
extern char _sdata;
extern char _edata;

class MemoryMonitor
{
public:
	static MemoryMonitor& getInstance();

	void* monitoredMalloc(size_t size);
	void monitoredFree(void* ptr);

	size_t getTotalAllocatedMemory() const;
	size_t getCurrentAllocatedMemory() const;

	void printMemoryUsage() const;

private:
	MemoryMonitor();
	MemoryMonitor(const MemoryMonitor&) = delete;
	MemoryMonitor& operator=(const MemoryMonitor&) = delete;

	size_t totalAllocatedMemory;
	size_t currentAllocatedMemory;
	std::unordered_map<void*, size_t> allocationMap; // Map for tracking allocation sizes
};

#endif // MEMORY_MONITOR_HPP

#pragma once
#include <string>
#include <chrono>

class HandHistory {
public:
	HandHistory();
	// process a Hand History file give by filePath and returns the time of latest hand
	std::chrono::system_clock processFile(std::string filePath);

private:

protected:

};
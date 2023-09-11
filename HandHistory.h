#pragma once
#include <string>
#include <chrono>
#include <vector>

class HandHistory {
public:
	HandHistory();
	// process a Hand History file give by filePath and returns the time of latest hand
	std::chrono::system_clock processFile(std::string filePath);
	// return a vector of all hand history files
	std::vector<std::string> getFiles();
private:

protected:

};
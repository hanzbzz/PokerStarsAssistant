#pragma once
#include <string>
#include <chrono>
#include <vector>
#include <QString>
#include <filesystem>

extern QString folderPath;
extern int refreshRate;

class HandHistory {
public:
	HandHistory();
	// process hands and returns the timestamp of a last hand played
	// if <all> parameter is se to true process all hands, otherwise process only hands which happend since last refresh
	std::chrono::system_clock::time_point processHands(bool all);

	// process single hand history file and return the timestamp of the last hand played
	// if <all> parameter is set to true process all hands, otherwise process only hands which happend since last refresh
	std::chrono::system_clock::time_point processHandHistoryFile(std::filesystem::directory_entry handHistoryFile, bool all);
private:

protected:

};
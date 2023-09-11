#include "HandHistory.h"
#include <vector>
#include <string>
#include <filesystem>
#include <chrono>

HandHistory::HandHistory() {

}

std::chrono::system_clock::time_point HandHistory::processHands(bool all) {
	for (auto handHistoryFile : std::filesystem::directory_iterator(folderPath.toStdString())) {
		if (all) {
			processHandHistoryFile(handHistoryFile, true);
		}
		else {
			auto now = std::chrono::system_clock().now();
			auto lastWriteTime = handHistoryFile.last_write_time();
			// subtract lastWriteTime from now and convert it to seconds
			int secondsSinceLastWrite = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch() - lastWriteTime.time_since_epoch()).count();
			// add one second to compenstate for overhead
			if ((secondsSinceLastWrite) <= (refreshRate + 1)) {
				processHandHistoryFile(handHistoryFile, false);

			}
		}
	}
	return std::chrono::system_clock::now();
}
std::chrono::system_clock::time_point HandHistory::processHandHistoryFile(std::filesystem::directory_entry handHistoryFile, bool all) {
	return std::chrono::system_clock::now();
}
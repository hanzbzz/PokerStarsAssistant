#include "HandHistory.h"
#include <vector>
#include <string>
#include <filesystem>
#include <chrono>
#include <regex>
#include <iostream>
#include <fstream>
#include <sstream>

HandHistory::HandHistory() {

}

std::chrono::system_clock::time_point HandHistory::processHands(bool all) {
	for (auto handHistoryFileHandle : std::filesystem::directory_iterator(folderPath.toStdString())) {
		if (all) {
			processHandHistoryFile(handHistoryFileHandle, true);
		}
		else {
			auto now = std::chrono::system_clock().now();
			auto lastWriteTime = handHistoryFileHandle.last_write_time();
			// subtract lastWriteTime from now and convert it to seconds
			int secondsSinceLastWrite = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch() - lastWriteTime.time_since_epoch()).count();
			// add one second to compenstate for overhead
			if ((secondsSinceLastWrite) <= (refreshRate + 1)) {
				processHandHistoryFile(handHistoryFileHandle, false);

			}
		}
	}
	return std::chrono::system_clock::now();
}
std::chrono::system_clock::time_point HandHistory::processHandHistoryFile(std::filesystem::directory_entry handHistoryFileHandle, bool all) {
	std::ifstream handHistoryFile;
	std::string line;
	std::regex rHandStart("PokerStars Hand #[0-9]+: Tournament #[0-9]+, .* ([0-9]{4}/[0-9]{2}/[0-9]{2} [0-9]{2}:[0-9]{2}:[0-9]{2} [A-Z]{2,3}) .*");
	std::regex rHandEnd("[*]{3} SUMMARY [*]{3}");
	std::smatch match;

	handHistoryFile.open(handHistoryFileHandle);
	while (std::getline(handHistoryFile, line)) {
		if (std::regex_match(line, match, rHandStart)) {
			std::stringstream hand;
			while (!std::regex_match(line, match, rHandEnd)) {
				std::getline(handHistoryFile, line);
				hand << line << "\n";
			}
			//processHand(hand);
		}
	}
	return std::chrono::system_clock::now();
}
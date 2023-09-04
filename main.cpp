#include "MainWindow.h"
#include <Qapplication>

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	MainWindow mainWindow;
	QSize mainWindowSize = mainWindow.size();
	auto sizes = mainWindow.calculatePlayerInfoPositions(9);
	int i = 0;
	for (auto position : sizes) {
		mainWindow.renderPlayerInfo(position,i);
		i++;
	}



	mainWindow.show();
	return app.exec();
}
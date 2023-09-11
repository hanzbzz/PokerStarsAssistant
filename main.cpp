#include "MainWindow.h"
#include "HandHistory.h"
#include <Qapplication>

QString folderPath = "No path selected. Select one in Settings->Select hand history folder";
int refreshRate = 30;


int main(int argc, char** argv) {
	QApplication app(argc, argv);
	MainWindow mainWindow;
	mainWindow.show();
	return app.exec();
}
#include "MainWindow.h"
#include <Qapplication>

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	MainWindow mainWindow;
	mainWindow.show();
	return app.exec();
}
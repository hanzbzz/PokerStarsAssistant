#include "MainWindow.h"
#include <Qapplication>

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	Window mainWindow;
	mainWindow.show();
	return app.exec();
}
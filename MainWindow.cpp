#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
	QWidget(parent) {
	setFixedSize(800, 500);
	QVBoxLayout* mainLayout = new QVBoxLayout;
	createMenu();
	mainLayout->setMenuBar(menuBar);
	setLayout(mainLayout);
}

void MainWindow::createMenu() {
	menuBar = new QMenuBar();

	settingsMenu = new QMenu(tr("Settings"), this);

	selectFolder = settingsMenu->addAction(tr("Select hand history folder"));
	setRefreshRate = settingsMenu->addAction(tr("Set refresh rate"));
	menuBar->addMenu(settingsMenu);

}


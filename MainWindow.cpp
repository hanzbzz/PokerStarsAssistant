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

	fileMenu = new QMenu(tr("Settings"), this);

	selectFolder = fileMenu->addAction(tr("Select hand history folder"));
	menuBar->addMenu(fileMenu);

}
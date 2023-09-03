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

	QMenu* settingsMenu = new QMenu(tr("Settings"));

	QAction* selectFolder = settingsMenu->addAction(tr("Select hand history folder"));
	QAction* setRefreshRate = settingsMenu->addAction(tr("Set refresh rate"));
	menuBar->addMenu(settingsMenu);
}
void MainWindow::paintEvent(QPaintEvent* e) {
	QPainter painter(this);
	QPen pen;

	pen.setColor(Qt::black);
	pen.setWidth(2);

	painter.setPen(pen);
	
	QSize size = this->minimumSize();
	QPoint* center = new QPoint(size.width() / 2, size.height() / 2);

	painter.drawEllipse(*center, 350, 175);
}

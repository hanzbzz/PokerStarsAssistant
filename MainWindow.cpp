#include "MainWindow.h"
#include <Map>
#include <sstream>
#include <string>
#include <QLabel>
#include <QFileDialog>

MainWindow::MainWindow(QWidget* parent) :
	QWidget(parent) {
	setFixedSize(800, 500);
	mainLayout = new QVBoxLayout(parent);
	
	createMenu();
	mainLayout->setMenuBar(menuBar);

	renderFolderPath();

	setLayout(mainLayout);
}

void MainWindow::createMenu() {
	menuBar = new QMenuBar(this);

	QMenu* settingsMenu = new QMenu(tr("Settings"),menuBar);

	QAction* selectFolder = settingsMenu->addAction(tr("Select hand history folder"));
	QAction* setRefreshRate = settingsMenu->addAction(tr("Set refresh rate"));

	QObject::connect(selectFolder, SIGNAL(triggered()), this, SLOT(selectFolderDialog()));

	menuBar->addMenu(settingsMenu);
}


void::MainWindow::selectFolderDialog() {
	
	QFileDialog dialog(this);
	dialog.setFileMode(QFileDialog::Directory);
	if (dialog.exec()) {
		folderPath = dialog.selectedFiles()[0];
	}
	folderPathLabel->setText(folderPath);
}

void MainWindow::renderFolderPath() {

	QVBoxLayout* folderPathLayout = new QVBoxLayout();

	QLabel* folderPathTitleLabel = new QLabel();
	folderPathTitleLabel->setText("Path to hand history folder:");
	folderPathTitleLabel->setStyleSheet("font-size:20pt;");
	folderPathLayout->addWidget(folderPathTitleLabel);
	folderPathLayout->setAlignment(folderPathTitleLabel, Qt::AlignHCenter);

	folderPathLabel = new QLabel();
	folderPathLabel->setText(folderPath);
	folderPathLayout->addWidget(folderPathLabel);
	folderPathLayout->setAlignment(folderPathLabel, Qt::AlignHCenter);

	mainLayout->addLayout(folderPathLayout);
	mainLayout->setAlignment(folderPathLayout, Qt::AlignCenter);
}



void MainWindow::renderPlayerInfo(QPoint pos,int i) {
	
	std::map<std::string, double> playerStats{ {"RPP", i}, {"XDD", 78}, {"XEE", 14} };

	// move along the y axis so stats are stacked on top of each other
	int moveBy = 0;

	for (auto [key, value] : playerStats) {
		QLabel* stat = new QLabel(this);
		
		std::stringstream ss;
		ss << key << ": " << value;
		QString labelText = QString::fromStdString(ss.str());

		stat->setText(labelText);
		stat->setMaximumSize(60, 20);
		stat->setStyleSheet("border: 1px solid black");
		stat->move(pos.x(), pos.y() + moveBy);
		stat->raise();

		moveBy += 20;
	}
}

std::vector<QPoint>  MainWindow::calculatePlayerInfoPositions(int numPlayers) {
	QSize size = this->size();
	int height = size.height();
	int width = size.width();
	if (numPlayers == 6) {
		return std::vector<QPoint>{
			QPoint(100, height / 2),
			QPoint(100, height / 2 - 90),
			QPoint(width / 2 - 30, 40),
			QPoint(width - 160, height / 2 - 90),
			QPoint(width - 160, height / 2),
			QPoint(width / 2 - 30, height - 70),
			
		};
	}
	if (numPlayers == 8) {
		return std::vector<QPoint>{ 
			QPoint(40, height / 2 - 30),
			QPoint(width / 5, height / 6),
			QPoint(width / 2 - 30, 40),
			QPoint(4 * (width / 5 ) - 30, height / 6),
			QPoint(width - 100, height / 2 - 30),
			QPoint(4 * (width / 5) - 30, 5 * (height / 6) - 30),
			QPoint(width / 2 - 30, height - 70),
			QPoint(width / 5, 5 * (height / 6) - 30)
		};
	}
	if (numPlayers == 9) {
		return std::vector<QPoint>{
			QPoint(40, height / 2 - 30),
			QPoint(width / 5, height / 6),
			QPoint(width / 2 - 80, 40),
			QPoint(width / 2 + 20, 40),
			QPoint(4 * (width / 5) - 30, height / 6),
			QPoint(width - 100, height / 2 - 30),
			QPoint(4 * (width / 5) - 30, 5 * (height / 6) - 30),
			QPoint(width / 2 - 30, height - 70),
			QPoint(width / 5, 5 * (height / 6) - 30)
		};
	}

}

MainWindow::~MainWindow() {

}
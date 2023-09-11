#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QLabel>

class MainWindow : public QWidget
{
	Q_OBJECT
public:
	explicit MainWindow(QWidget* parent = 0);
	// render specific player information at given position
	void renderPlayerInfo(QPoint,int);
	// returns vector of QPoints giving the position where to render the player statistics
	std::vector<QPoint> calculatePlayerInfoPositions(int);
	//destuctor
	~MainWindow();
private:
	// creates top menu bar
	void createMenu();
	// renders label with path to handhistory file
	void renderFolderPath();

	QVBoxLayout* mainLayout;
	QMenuBar* menuBar;
	QLabel* folderPathLabel;
	QString folderPath = "No path selected. Select one in Settings->Select hand history folder";
	
protected:
signals:
public slots:
	// select the folder where hand history files are stored
	void selectFolderDialog();

};

#endif // WINDOW_H
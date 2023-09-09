#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMenuBar>
#include <QVBoxLayout>

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

	QVBoxLayout* mainLayout;
	QMenuBar* menuBar;
protected:
signals:
public slots:
};

#endif // WINDOW_H
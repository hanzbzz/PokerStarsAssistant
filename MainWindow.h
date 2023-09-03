#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>

class MainWindow : public QWidget
{
	Q_OBJECT
public:
	explicit MainWindow(QWidget* parent = 0);
private:
	// creates top menu bar
	void createMenu();

	QMenuBar* menuBar;
	QMenu* fileMenu;
	QAction* selectFolder;
signals:
public slots:
};

#endif // WINDOW_H
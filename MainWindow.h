#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QFrame>
#include <Qpainter>

class MainWindow : public QWidget
{
	Q_OBJECT
public:
	explicit MainWindow(QWidget* parent = 0);
private:
	// creates top menu bar
	void createMenu();

	QMenuBar* menuBar;
protected:
	// paint the table view
	void paintEvent(QPaintEvent* event);
signals:
public slots:
};

#endif // WINDOW_H
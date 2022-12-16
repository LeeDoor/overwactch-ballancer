#pragma once

#include <QMainWindow>
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

public slots:
	void addPlayerButton(); // opens dialog to get data about new player,
	// creates a widget with a player
	// and adds a player to a list
	void addActPlayerButton();	// opens dialog to get data about new player,
	// creates a widget with a player
	// and adds an active player to a list


private:
	std::shared_ptr<EditProfileDialog> playerDialog;
	Ui::MainWindowClass ui;
};

#pragma once

#include <QMainWindow>
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

	void updateLists();

public slots:
	//edits player stats and updates lists
	void editPlayerButton(std::shared_ptr<Player> player);

	void addPlayerButton(); // opens dialog to get data about new player,
	// creates a widget with a player
	// and adds a player to a list
	void addActPlayerButton();	// opens dialog to get data about new player,
	// creates a widget with a player
	// and adds an active player to a list

	//deletes a player selected in main list.
	//if this player is in active player list,
	//deletes from there too
	void deletePlayerButton();
	//deletes player from active player list. 
	//DOESNT delete this player from global player list.
	void deleteActivePlayerButton();

	//sets delete button for all players activate or not
	void allPlDelButAct(bool isAct);
	//sets delete button for active players activate or not
	void actPlDelButAct(bool isAct);
private:
	std::shared_ptr<EditProfileDialog> playerDialog;
	Ui::MainWindowClass ui;
};

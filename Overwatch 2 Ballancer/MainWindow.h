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

	//updates node on screen according to player's name
	void updateNodesWithPlayer(std::string name);
	//deletes node on screen according to player's name
	void deleteNodesWithPlayer(std::string name);

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

	//asks user a path file and acts
	void importAllJsonButton();
	void importActJsonButton();
	//void exportJsonButton();
private:
	std::shared_ptr<EditProfileDialog> playerDialog;
	Ui::MainWindowClass ui;

	//map. needed to faster update nodes on screen
	//without updating every single node in list.
	//player's name is a key to faster finding. 
	//value is a pair of nodes. first element is global
	//element, it always is. second element is active player
	//list. it is not always there.
	std::unordered_map
		<std::string,
		std::pair<
		std::weak_ptr<QListWidgetItem>,
		std::weak_ptr<QListWidgetItem>
		>> playersNodes;
};

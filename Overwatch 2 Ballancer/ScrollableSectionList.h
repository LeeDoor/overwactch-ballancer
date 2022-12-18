#pragma once

#include <QWidget>
#include "ui_ScrollableSectionList.h"
#include "EditProfileDialog.h"
#include "PlayerNode.h"

class ScrollableSectionList : public QWidget
{
	Q_OBJECT

public:
	ScrollableSectionList(QWidget *parent = nullptr);
	~ScrollableSectionList();

	//adds a widget with this player
	std::weak_ptr<QListWidgetItem> addPlayerWidget(std::weak_ptr<Player> player);
	//updates current item from list
	void updatePlayerWidget(QListWidgetItem* item);
	//deletes current item from list
	void deletePlayerWidget(QListWidgetItem* item);
	//updates list with this vector of players
	void updateList(std::vector<std::weak_ptr<Player>> players);
	void updateList(std::vector<std::shared_ptr<Player>> players);
	void clearList();

	//returns a pointer to selected player
	std::shared_ptr<Player> getSelectedPlayer();
	//returns a pointer to a player in given item
	PlayerNode* getPlayerNodeWithItem(QListWidgetItem* item);

public slots:
	void onPlayerClickedSlot(QListWidgetItem* item);
	void isPlayerSelectedSlot();

signals:
	void onPlayerClicked(std::shared_ptr<Player> player);
	void onPlayerSelected(bool isSelected);

private:
	Ui::ScrollableSectionListClass ui;
};

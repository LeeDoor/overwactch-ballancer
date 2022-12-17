#pragma once

#include <QWidget>
#include "ui_ScrollableSectionList.h"
#include "EditProfileDialog.h"

class ScrollableSectionList : public QWidget
{
	Q_OBJECT

public:
	ScrollableSectionList(QWidget *parent = nullptr);
	~ScrollableSectionList();

	//adds a widget with this player
	void addPlayerWidget(std::weak_ptr<Player> player);
	//updates list with this vector of players
	void updateList(std::vector<std::weak_ptr<Player>> players);
	void updateList(std::vector<std::shared_ptr<Player>> players);
	void clearList();

	//returns a pointer to selected player
	std::shared_ptr<Player> getSelectedPlayer();
	//returns a pointer to a player in given item
	std::shared_ptr<Player> getPlayerWithItem(QListWidgetItem* item);

public slots:
	void onPlayerClickedSlot(QListWidgetItem* item);
	void isPlayerSelectedSlot();

signals:
	void onPlayerClicked(std::shared_ptr<Player> player);
	void onPlayerSelected(bool isSelected);

private:
	Ui::ScrollableSectionListClass ui;
};

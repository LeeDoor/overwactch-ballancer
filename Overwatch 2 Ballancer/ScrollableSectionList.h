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

	void addPlayerWidget(std::weak_ptr<Player> player);
	void updateList(std::vector<std::weak_ptr<Player>> players);
	void updateList(std::vector<std::shared_ptr<Player>> players);
	void clearList();

	std::shared_ptr<Player> getSelectedPlayer();
	std::shared_ptr<Player> getPlayerWithItem(QListWidgetItem* item);

public slots:
	void onPlayerClickedSlot(QListWidgetItem* item);

signals:
	void onPlayerClicked(std::shared_ptr<Player> player);

private:
	Ui::ScrollableSectionListClass ui;
};

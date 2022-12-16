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
	void updateList(std::vector<std::shared_ptr<Player>> players);
	void clearList();

public slots:
	void onPlayerClicked(QListWidgetItem* index);
	//void importJSON();
	//void exportJSON();
private:
	Ui::ScrollableSectionListClass ui;
};

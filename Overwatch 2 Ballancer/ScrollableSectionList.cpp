#include "ScrollableSectionList.h"
#include "PlayerNode.h"
#include "EditProfileDialog.h"
#include <qlistwidget.h>
#include "PlayerLists.h"

ScrollableSectionList::ScrollableSectionList(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

ScrollableSectionList::~ScrollableSectionList()
{}

void ScrollableSectionList::addPlayerWidget(std::weak_ptr<Player> player) {
	PlayerNode* node = new PlayerNode(player, this);
	QListWidgetItem* item = new QListWidgetItem();
	item->setSizeHint(node->sizeHint());
	ui.listWidget->addItem(item);
	ui.listWidget->setItemWidget(item, node);
}

void ScrollableSectionList::updateList(std::vector<std::shared_ptr<Player>> players) {
	clearList();
	for (auto player : players) {
		addPlayerWidget(player);
	}
}

void ScrollableSectionList::clearList() {
	ui.listWidget->clear();
}

void ScrollableSectionList::onPlayerClicked(QListWidgetItem* item) {
	(dynamic_cast<PlayerNode*>(ui.listWidget->itemWidget(item)))->editParamsButton();
}
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

std::weak_ptr<QListWidgetItem> ScrollableSectionList::addPlayerWidget(std::weak_ptr<Player> player) {
	PlayerNode* node = new PlayerNode(player, this);
	QListWidgetItem* item = new QListWidgetItem();
	item->setSizeHint(node->sizeHint());
	ui.listWidget->addItem(item);
	ui.listWidget->setItemWidget(item, node);
	return std::make_shared<QListWidgetItem>(*item);
}

void ScrollableSectionList::updatePlayerWidget(QListWidgetItem* item) {
	getPlayerNodeWithItem(item)->setParams();
}

void ScrollableSectionList::deletePlayerWidget(QListWidgetItem* item) {
	ui.listWidget->removeItemWidget(item);
}

void ScrollableSectionList::updateList(std::vector<std::shared_ptr<Player>> players) {
	clearList();
	for (auto player : players) {
		addPlayerWidget(player);
	}
}

void ScrollableSectionList::updateList(std::vector<std::weak_ptr<Player>> players) {
	clearList();
	for (auto player : players) {
		addPlayerWidget(player);
	}
}

void ScrollableSectionList::clearList() {
	ui.listWidget->clear();
}

std::shared_ptr<Player> ScrollableSectionList::getSelectedPlayer() {
	auto items = ui.listWidget->selectedItems();
	if (items.size() == 0) {
		return nullptr;
	}
	QListWidgetItem* item = items[0];
	return getPlayerNodeWithItem(item)->player();
}

PlayerNode* ScrollableSectionList::getPlayerNodeWithItem(QListWidgetItem* item) {
	QWidget* widget1 = ui.listWidget->itemWidget(item);
	PlayerNode* widget2 = dynamic_cast<PlayerNode*>(widget1);
	return widget2;
}

void ScrollableSectionList::onPlayerClickedSlot(QListWidgetItem* item) {
	std::shared_ptr<Player> player = getPlayerNodeWithItem(item)->player();
	QMetaObject::invokeMethod(this, "onPlayerClicked", Qt::DirectConnection, Q_ARG(std::shared_ptr<Player>, player));
}
//QMetaObject::invokeMethod(task, "doTask", Q_ARG(int, param));

void ScrollableSectionList::isPlayerSelectedSlot() {
	QList<QListWidgetItem*> selects = ui.listWidget->selectedItems();
	QMetaObject::invokeMethod(this, "onPlayerSelected", Qt::DirectConnection, Q_ARG(bool, selects.size() != 0));
}
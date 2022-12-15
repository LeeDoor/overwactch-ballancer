#include "ScrollableSectionList.h"
#include "PlayerNode.h"
#include "EditProfileDialog.h"
#include <qlistwidget.h>
ScrollableSectionList::ScrollableSectionList(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	playerDialog = new EditProfileDialog();
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

void ScrollableSectionList::addPlayerButton() {
	playerDialog->exec();
	std::shared_ptr<Player> data = playerDialog->getData();
	addPlayerWidget(data);
}


void ScrollableSectionList::onPlayerClicked(QListWidgetItem* item) {
	(dynamic_cast<PlayerNode*>(ui.listWidget->itemWidget(item)))->editParamsButton();
}
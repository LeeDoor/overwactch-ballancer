#include "ScrollableSectionList.h"
#include "PlayerNode.h"
#include "EditProfileDialog.h"
#include <qlistwidget.h>
ScrollableSectionList::ScrollableSectionList(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

ScrollableSectionList::~ScrollableSectionList()
{}

void ScrollableSectionList::addPlayerWidget(Player player) {
	PlayerNode* node = new PlayerNode(player, this);
	QListWidgetItem* item = new QListWidgetItem();
	item->setSizeHint(node->sizeHint());
	ui.listWidget->addItem(item);
	ui.listWidget->setItemWidget(item, node);
}

void ScrollableSectionList::addPlayerButton() {
	playerDialog = new EditProfileDialog();
	playerDialog->open();
	connect(playerDialog, &EditProfileDialog::accepted, this, &ScrollableSectionList::dialogClosedAddPlayer);
}

void ScrollableSectionList::dialogClosedAddPlayer() {
	Player data = playerDialog->getData();
	addPlayerWidget(data);
}
#include "ScrollableSectionList.h"
#include "PlayerNode.h"
#include <qlistwidget.h>
ScrollableSectionList::ScrollableSectionList(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

ScrollableSectionList::~ScrollableSectionList()
{}

void ScrollableSectionList::addPlayer(QString name, QPixmap* logo) {
	PlayerNode* node = new PlayerNode(name, logo, this);
	QListWidgetItem* item = new QListWidgetItem();
	item->setSizeHint(node->sizeHint());
	ui.listWidget->addItem(item);
	ui.listWidget->setItemWidget(item, node);
}
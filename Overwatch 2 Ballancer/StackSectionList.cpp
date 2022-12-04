#include "StackSectionList.h"
#include "PlayerNode.h"
StackSectionList::StackSectionList(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

StackSectionList::~StackSectionList()
{}

void StackSectionList::addPlayer(QString name, QPixmap* logo) {
	PlayerNode* node = new PlayerNode(name, logo);
	ui.verticalLayout->addWidget(node);
}
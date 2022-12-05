#include "ScrollableSectionList.h"

ScrollableSectionList::ScrollableSectionList(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	stack = new StackSectionList();
	ui.scrollArea->setWidget(stack);
}

ScrollableSectionList::~ScrollableSectionList()
{}

void ScrollableSectionList::addPlayer(QString name, QPixmap* logo) {
	stack->addPlayer(name, logo);
}
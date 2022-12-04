#include "ScrollableSectionList.h"

ScrollableSectionList::ScrollableSectionList(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	stack = new StackSectionList();
	ui.scrollArea->setWidget(stack);

	QPixmap* map = new QPixmap(50, 50);
	map->fill(QColor("red"));
	addPlayer(QString("bababa1"), map);
	addPlayer(QString("bababa2"), map);
	addPlayer(QString("bababa3"), map);
	addPlayer(QString("bababa4"), map);
	addPlayer(QString("bababa5"), map);
	addPlayer(QString("bababa6"), map);
	addPlayer(QString("pogiloypawuk#2415"), map);
	addPlayer(QString("bababa1"), map);
	addPlayer(QString("bababa2"), map);
	addPlayer(QString("bababa3"), map);
}

ScrollableSectionList::~ScrollableSectionList()
{}

void ScrollableSectionList::addPlayer(QString name, QPixmap* logo) {
	stack->addPlayer(name, logo);
}
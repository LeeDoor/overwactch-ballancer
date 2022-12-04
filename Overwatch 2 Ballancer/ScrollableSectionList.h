#pragma once

#include <QWidget>
#include "ui_ScrollableSectionList.h"
#include "StackSectionList.h"

class ScrollableSectionList : public QWidget
{
	Q_OBJECT

public:
	ScrollableSectionList(QWidget *parent = nullptr);
	~ScrollableSectionList();

	void addPlayer(QString name, QPixmap* logo);
private:
	Ui::ScrollableSectionListClass ui;
	StackSectionList* stack;
};

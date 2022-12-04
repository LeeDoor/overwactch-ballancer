#pragma once

#include <QWidget>
#include "ui_ScrollableSectionList.h"

class ScrollableSectionList : public QWidget
{
	Q_OBJECT

public:
	ScrollableSectionList(QWidget *parent = nullptr);
	~ScrollableSectionList();

private:
	Ui::ScrollableSectionListClass ui;
};

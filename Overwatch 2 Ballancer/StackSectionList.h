#pragma once

#include <QWidget>
#include "ui_StackSectionList.h"

class StackSectionList : public QWidget
{
	Q_OBJECT

public:
	StackSectionList(QWidget *parent = nullptr);
	~StackSectionList();

	void addPlayer(QString name, QPixmap* logo);
private:
	Ui::StackSectionListClass ui;
};

#pragma once

#include <QWidget>
#include "ui_PlayerList.h"

class PlayerList : public QWidget
{
	Q_OBJECT

public:
	PlayerList(QWidget *parent = nullptr);
	~PlayerList();

	void addPlayer(QString name, QPixmap logo);

private:
	Ui::PlayerListClass ui;
};

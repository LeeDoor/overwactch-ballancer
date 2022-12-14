#pragma once

#include <QWidget>
#include "ui_PlayerNode.h"
#include "Player.h"

class PlayerNode : public QWidget
{
	Q_OBJECT

public:
	PlayerNode(Player player, QWidget* parent = nullptr);
	PlayerNode(QWidget *parent = nullptr);
	~PlayerNode();

	void setName(QString name);
	void setLogo(QPixmap* logo);
	void setParams(Player player);
private:
	Ui::PlayerNodeClass ui;
};

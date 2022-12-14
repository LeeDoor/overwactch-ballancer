#pragma once

#include <QWidget>
#include "ui_PlayerNode.h"
#include "Player.h"
#include "EditProfileDialog.h"

class PlayerNode : public QWidget
{
	Q_OBJECT

public:
	PlayerNode(std::weak_ptr<Player> player, QWidget* parent = nullptr);
	PlayerNode(QWidget *parent = nullptr);
	~PlayerNode();

	std::shared_ptr<Player> player();

	void setName(QString name);
	void setLogo(QPixmap* logo);
	void setParams();
private:
	std::shared_ptr<EditProfileDialog> _dialog;
	std::weak_ptr<Player> _player;
	Ui::PlayerNodeClass ui;
};

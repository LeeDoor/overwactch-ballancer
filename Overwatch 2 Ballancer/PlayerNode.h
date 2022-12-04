#pragma once

#include <QWidget>
#include "ui_PlayerNode.h"

class PlayerNode : public QWidget
{
	Q_OBJECT

public:
	PlayerNode(QWidget *parent = nullptr);
	~PlayerNode();

private:
	Ui::PlayerNodeClass ui;
};

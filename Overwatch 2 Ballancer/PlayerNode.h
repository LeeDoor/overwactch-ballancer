#pragma once

#include <QWidget>
#include "ui_PlayerNode.h"

class PlayerNode : public QWidget
{
	Q_OBJECT

public:
	PlayerNode(QString name, QPixmap* logo, QWidget* parent = nullptr);
	PlayerNode(QWidget *parent = nullptr);
	~PlayerNode();

	void setName(QString name);
	void setLogo(QPixmap* logo);
	void setParams(QString name, QPixmap* logo);
private:
	Ui::PlayerNodeClass ui;
};

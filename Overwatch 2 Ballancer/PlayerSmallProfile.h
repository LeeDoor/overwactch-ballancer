#pragma once

#include <QWidget>
#include "ui_PlayerSmallProfile.h"

class PlayerSmallProfile : public QWidget
{
	Q_OBJECT

public:
	PlayerSmallProfile(QWidget *parent = nullptr);
	~PlayerSmallProfile();

	void setPlayerStats(QString name, QPixmap logo);
private:
	Ui::PlayerSmallProfileClass ui;
};

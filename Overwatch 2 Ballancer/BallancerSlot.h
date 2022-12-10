#pragma once

#include <QWidget>
#include "ui_BallancerSlot.h"

class BallancerSlot : public QWidget
{
	Q_OBJECT

public:
	BallancerSlot(QWidget *parent = nullptr);
	~BallancerSlot();

private:
	Ui::BallancerSlotClass ui;
};

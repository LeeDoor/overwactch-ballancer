#pragma once

#include <QWidget>
#include "ui_BallancerSlot.h"
#include "BallanceSlotData.h"

class BallancerSlot : public QWidget
{
	Q_OBJECT

public:
	BallancerSlot(QWidget *parent = nullptr);
	~BallancerSlot();

	void setStats(BallanceSlotData data);
private:
	Ui::BallancerSlotClass ui;
};

#pragma once

#include <QWidget>
#include "ui_Ballancer.h"
#include "BallancerSlot.h"

class Ballancer : public QWidget
{
	Q_OBJECT

public:
	Ballancer(QWidget *parent = nullptr);
	~Ballancer();
	void addSlot(BallanceSlotData data);
private:
	Ui::BallancerClass ui;
};

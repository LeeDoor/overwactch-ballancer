#include "BallancerSlot.h"

BallancerSlot::BallancerSlot(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

BallancerSlot::~BallancerSlot()
{}


void BallancerSlot::setStats(BallanceSlotData data) {
	
	ui.dispertionLabel->setText(QString::number(data.disp()));
	ui.offclassLabel->setText(QString::number(data.offp()));
	ui.subclassCoupleLabel->setText(QString::number(data.subPair()) + "/" + QString::number(data.teamsAm()));
	ui.LowrankCoupleLabel->setText(QString::number(data.lowPair()) + "/" + QString::number(data.teamsAm()));
}
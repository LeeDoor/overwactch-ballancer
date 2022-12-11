#include "Ballancer.h"

Ballancer::Ballancer(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	addSlot(BallanceSlotData(61273, 077, 236, 1044, 2000));
	addSlot(BallanceSlotData(61223, 077, 236, 1044, 2000));
	addSlot(BallanceSlotData(61273, 075, 2376, 1044, 2000));
	addSlot(BallanceSlotData(61273, 077, 236, 1044, 2000));
	addSlot(BallanceSlotData(61273, 077, 236, 1044, 2000));
}

Ballancer::~Ballancer()
{}

void Ballancer::addSlot(BallanceSlotData data) {
	QListWidgetItem* item = new QListWidgetItem();
	BallancerSlot* slot = new BallancerSlot();
	slot->setStats(data);
	item->setSizeHint(slot->sizeHint());
	ui.listWidget->addItem(item);
	ui.listWidget->setItemWidget(item, slot);
}
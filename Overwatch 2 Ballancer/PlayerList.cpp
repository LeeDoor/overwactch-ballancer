#include "PlayerList.h"
#include "PlayerSmallProfile.h"
PlayerList::PlayerList(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QPixmap px;
	addPlayer("bababa", px);
	addPlayer("bababa2", px);
	addPlayer("bababa3", px);
}

void PlayerList::addPlayer(QString name, QPixmap logo) {
	QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui.verticalLayout->layout());
	PlayerSmallProfile* prof = new PlayerSmallProfile(ui.verticalLayout->widget());
	layout->insertWidget(0, prof);
	prof->setPlayerStats(name, logo);
}

PlayerList::~PlayerList()
{}

#include "PlayerSmallProfile.h"

PlayerSmallProfile::PlayerSmallProfile(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

PlayerSmallProfile::~PlayerSmallProfile()
{}


void PlayerSmallProfile::setPlayerStats(QString name, QPixmap logo) {
	ui.nameLabel->setText(name);
	ui.divisionIcon->setPixmap(logo);
}
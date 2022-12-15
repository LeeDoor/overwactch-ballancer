#include "EditProfileDialog.h"

EditProfileDialog::EditProfileDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.acceptButton, &QPushButton::clicked, this, &EditProfileDialog::accept);
	connect(ui.cancelButton, &QPushButton::clicked, this, &EditProfileDialog::reject);
}

EditProfileDialog::~EditProfileDialog()
{}

std::shared_ptr<Player> EditProfileDialog::getData() {
	std::shared_ptr<Player> player = std::make_shared<Player>();
	player->identity.isCaptain = ui.captainCheckBox->isChecked();
	player->identity.isFullFlex = ui.fullFlexCheckBox->isChecked();
	player->identity.isSquire = ui.squireCheckBox->isChecked();
	player->identity.name = ui.nameLineEdit->text().toStdString();

	player->stats.dps.isActive = ui.isActiveDpsCheckBox->isChecked();
	player->stats.dps.primary = ui.firstPropDpsCheckBox->isChecked();
	player->stats.dps.secondary = ui.secondPropDpsCheckBox->isChecked();
	player->stats.dps.rank = ui.rankDpsLineEdit->text().toShort();

	player->stats.tank.isActive = ui.isActiveTankCheckBox->isChecked();
	player->stats.tank.primary = ui.firstPropTankCheckBox->isChecked();
	player->stats.tank.secondary = ui.secondPropTankCheckBox->isChecked();
	player->stats.tank.rank = ui.rankTankLineEdit->text().toShort();

	player->stats.support.isActive = ui.isActiveSupCheckBox->isChecked();
	player->stats.support.primary = ui.firstPropSupCheckBox->isChecked();
	player->stats.support.secondary = ui.secondPropSupCheckBox->isChecked();
	player->stats.support.rank = ui.rankSupLineEdit->text().toShort();
	return player;
}

void EditProfileDialog::resetData() {
	ui.captainCheckBox->setChecked(false);
	ui.fullFlexCheckBox->setChecked(false);
	ui.squireCheckBox->setChecked(false);
	ui.nameLineEdit->setText("");

	ui.isActiveDpsCheckBox->setChecked(false);
	ui.firstPropDpsCheckBox->setChecked(false);
	ui.secondPropDpsCheckBox->setChecked(false);
	ui.rankDpsLineEdit->setText("");

	ui.isActiveTankCheckBox->setChecked(false);
	ui.firstPropTankCheckBox->setChecked(false);
	ui.secondPropTankCheckBox->setChecked(false);
	ui.rankTankLineEdit->setText("");

	ui.isActiveSupCheckBox->setChecked(false);
	ui.firstPropSupCheckBox->setChecked(false);
	ui.secondPropSupCheckBox->setChecked(false);
	ui.rankSupLineEdit->setText("");
}

void EditProfileDialog::setData(std::shared_ptr<Player> player) {
	ui.captainCheckBox->setChecked(player->identity.isCaptain);
	ui.fullFlexCheckBox->setChecked(player->identity.isFullFlex);
	ui.squireCheckBox->setChecked(player->identity.isSquire);
	ui.nameLineEdit->setText(player->identity.name.c_str());

	ui.isActiveDpsCheckBox->setChecked(player->stats.dps.isActive);
	ui.firstPropDpsCheckBox->setChecked(player->stats.dps.primary);
	ui.secondPropDpsCheckBox->setChecked(player->stats.dps.secondary);
	ui.rankDpsLineEdit->setText(std::to_string(player->stats.dps.rank).c_str());

	ui.isActiveTankCheckBox->setChecked(player->stats.tank.isActive);
	ui.firstPropTankCheckBox->setChecked(player->stats.tank.primary);
	ui.secondPropTankCheckBox->setChecked(player->stats.tank.secondary);
	ui.rankTankLineEdit->setText(std::to_string(player->stats.tank.rank).c_str());

	ui.isActiveSupCheckBox->setChecked(player->stats.support.isActive);
	ui.firstPropSupCheckBox->setChecked(player->stats.support.primary);
	ui.secondPropSupCheckBox->setChecked(player->stats.support.secondary);
	ui.rankSupLineEdit->setText(std::to_string(player->stats.support.rank).c_str());
}
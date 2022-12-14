#include "EditProfileDialog.h"

EditProfileDialog::EditProfileDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

EditProfileDialog::~EditProfileDialog()
{}

Player EditProfileDialog::getData() {
	Player player;
	player.identity.isCaptain = ui.captainCheckBox->isChecked();
	player.identity.isFullFlex = ui.fullFlexCheckBox->isChecked();
	player.identity.isSquire = ui.squireCheckBox->isChecked();
	player.identity.name = ui.nameLineEdit->text().toStdString();

	player.stats.dps.isActive = ui.isActiveDpsCheckBox->isChecked();
	player.stats.dps.primary = ui.firstPropDpsCheckBox->isChecked();
	player.stats.dps.secondary = ui.secondPropDpsCheckBox->isChecked();
	player.stats.dps.rank = ui.rankDpsLineEdit->text().toShort();

	player.stats.tank.isActive = ui.isActiveTankCheckBox->isChecked();
	player.stats.tank.primary = ui.firstPropTankCheckBox->isChecked();
	player.stats.tank.secondary = ui.secondPropTankCheckBox->isChecked();
	player.stats.tank.rank = ui.rankTankLineEdit->text().toShort();

	player.stats.support.isActive = ui.isActiveSupCheckBox->isChecked();
	player.stats.support.primary = ui.firstPropSupCheckBox->isChecked();
	player.stats.support.secondary = ui.secondPropSupCheckBox->isChecked();
	player.stats.support.rank = ui.rankSupLineEdit->text().toShort();
	return player;
}

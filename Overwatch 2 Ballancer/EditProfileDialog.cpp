#include "EditProfileDialog.h"
#include <sstream>
#include <ctime>

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
	player->identity.uuid = generateId();

	player->stats.classes.dps.isActive = ui.isActiveDpsCheckBox->isChecked();
	player->stats.classes.dps.primary = ui.firstPropDpsCheckBox->isChecked();
	player->stats.classes.dps.secondary = ui.secondPropDpsCheckBox->isChecked();
	player->stats.classes.dps.rank = ui.rankDpsLineEdit->text().toShort();
	
	player->stats.classes.tank.isActive = ui.isActiveTankCheckBox->isChecked();
	player->stats.classes.tank.primary = ui.firstPropTankCheckBox->isChecked();
	player->stats.classes.tank.secondary = ui.secondPropTankCheckBox->isChecked();
	player->stats.classes.tank.rank = ui.rankTankLineEdit->text().toShort();
	
	player->stats.classes.support.isActive = ui.isActiveSupCheckBox->isChecked();
	player->stats.classes.support.primary = ui.firstPropSupCheckBox->isChecked();
	player->stats.classes.support.secondary = ui.secondPropSupCheckBox->isChecked();
	player->stats.classes.support.rank = ui.rankSupLineEdit->text().toShort();


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

	ui.isActiveDpsCheckBox->setChecked(player->stats.classes.dps.isActive);
	ui.firstPropDpsCheckBox->setChecked(player->stats.classes.dps.primary);
	ui.secondPropDpsCheckBox->setChecked(player->stats.classes.dps.secondary);
	ui.rankDpsLineEdit->setText(std::to_string(player->stats.classes.dps.rank).c_str());
	
	ui.isActiveTankCheckBox->setChecked(player->stats.classes.tank.isActive);
	ui.firstPropTankCheckBox->setChecked(player->stats.classes.tank.primary);
	ui.secondPropTankCheckBox->setChecked(player->stats.classes.tank.secondary);
	ui.rankTankLineEdit->setText(std::to_string(player->stats.classes.tank.rank).c_str());

	ui.isActiveSupCheckBox->setChecked(player->stats.classes.support.isActive);
	ui.firstPropSupCheckBox->setChecked(player->stats.classes.support.primary);
	ui.secondPropSupCheckBox->setChecked(player->stats.classes.support.secondary);
	ui.rankSupLineEdit->setText(std::to_string(player->stats.classes.support.rank).c_str());
}

std::string EditProfileDialog::generateId() {
	std::stringstream str;
	for (int i = 0; i < 8; ++i) str << getChar(); 
	for (int j = 0; j < 3; ++j) {
		str << '-';
		for (int i = 0; i < 4; ++i) str << getChar();
	}
	str << '-';
	for (int i = 0; i < 12; ++i) str << getChar();
	return str.str();
}

char EditProfileDialog::getChar() {
	int val = rand() % 36;
	if (val < 10) {
		return '0' + val;
	}
	else return 'a' + val - 10;
}
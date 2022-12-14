#include "PlayerNode.h"

PlayerNode::PlayerNode(Player player, QWidget *parent)
	: PlayerNode(parent)
{
	setParams(player);
}
PlayerNode::PlayerNode(QWidget *parent)
	: QWidget(parent) {
	ui.setupUi(this);
}

PlayerNode::~PlayerNode()
{}

void PlayerNode::setName(QString name) {
	ui.nick->setText(name);
}
void PlayerNode::setLogo(QPixmap* logo) {
	ui.logo->setPixmap(*logo);
}
void PlayerNode::setParams(Player player) {
	//ui.logo->setPixmap(*logo);
	ui.nick->setText(QString(player.identity.name.c_str()));
}
#include "PlayerNode.h"

PlayerNode::PlayerNode(QString name, QPixmap* logo, QWidget *parent)
	: PlayerNode(parent)
{
	setParams(name, logo);
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
void PlayerNode::setParams(QString name, QPixmap* logo) {
	ui.logo->setPixmap(*logo);
	ui.nick->setText(name);
}
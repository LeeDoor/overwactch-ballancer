#include "PlayerNode.h"

PlayerNode::PlayerNode(std::weak_ptr<Player> player, QWidget *parent)
	: PlayerNode(parent)
{
	_player = player;
	setParams();
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
void PlayerNode::setParams() {
	//ui.logo->setPixmap(*logo);
	ui.nick->setText(QString(_player.lock()->identity.name.c_str()));
}

std::shared_ptr<Player> PlayerNode::player() {
	return _player.lock();
}
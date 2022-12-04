#include "PlayerNode.h"

PlayerNode::PlayerNode(QString name, QPixmap* logo, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.nick->setText(name);
	ui.logo->setPixmap(*logo);
}

PlayerNode::~PlayerNode()
{}

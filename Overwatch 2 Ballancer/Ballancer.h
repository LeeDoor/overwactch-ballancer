#pragma once

#include <QWidget>
#include "ui_Ballancer.h"

class Ballancer : public QWidget
{
	Q_OBJECT

public:
	Ballancer(QWidget *parent = nullptr);
	~Ballancer();

private:
	Ui::BallancerClass ui;
};

#pragma once

#include <QWidget>
#include "ui_BallancerStack.h"

class BallancerStack : public QWidget
{
	Q_OBJECT

public:
	BallancerStack(QWidget *parent = nullptr);
	~BallancerStack();

private:
	Ui::BallancerStackClass ui;
};

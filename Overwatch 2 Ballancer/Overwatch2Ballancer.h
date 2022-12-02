#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Overwatch2Ballancer.h"

class Overwatch2Ballancer : public QMainWindow
{
    Q_OBJECT

public:
    Overwatch2Ballancer(QWidget *parent = nullptr);
    ~Overwatch2Ballancer();

private:
    Ui::Overwatch2BallancerClass ui;
};

#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);


	QPixmap* map = new QPixmap(50, 50);
	map->fill(QColor("red"));
	ui.allPlayers->addPlayer(QString("bababa1"), map);
	ui.allPlayers->addPlayer(QString("bababa2"), map);
	ui.allPlayers->addPlayer(QString("bababa3"), map);
	ui.allPlayers->addPlayer(QString("bababa4"), map);
	ui.allPlayers->addPlayer(QString("bababa5"), map);
	ui.allPlayers->addPlayer(QString("bababa6"), map);
	ui.allPlayers->addPlayer(QString("pogiloypawuk#2415"), map);
	ui.allPlayers->addPlayer(QString("bababa1"), map);
	ui.allPlayers->addPlayer(QString("bababa2"), map);
	ui.allPlayers->addPlayer(QString("bababa3"), map);

	ui.activePlayers->addPlayer(QString("bababa1"), map);
	ui.activePlayers->addPlayer(QString("bababa2"), map);
	ui.activePlayers->addPlayer(QString("bababa3"), map);
}

MainWindow::~MainWindow()
{}

#include "MainWindow.h"
#include <qrandom.h>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	QRandomGenerator gen;
	QPixmap* map = new QPixmap(50, 50);
	Player player;
	player.identity.name = "beza";
	map->fill(QColor("red"));
	for (int i = 0; i < 100; ++i) {
		map->fill(QColor(gen.bounded(255), gen.bounded(255), gen.bounded(255)));
		ui.allPlayers->addPlayerWidget(player);
	}
	for(int i = 0;i < 50; ++i)ui.activePlayers->addPlayerWidget(player);
}

MainWindow::~MainWindow()
{}
#include "MainWindow.h"
#include <qrandom.h>
#include "PlayerLists.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	playerDialog = std::make_shared<EditProfileDialog>();
}

MainWindow::~MainWindow()
{}

void MainWindow::addPlayerButton() {
	playerDialog->resetData();
	playerDialog->exec();
	std::shared_ptr<Player> data = playerDialog->getData();
	if (PlayerLists::addPlayer(data))
		ui.allPlayers->addPlayerWidget(data);
}

void MainWindow::addActPlayerButton() {
	playerDialog->resetData();
	playerDialog->exec();
	std::shared_ptr<Player> data = playerDialog->getData();
	if (PlayerLists::addActivePlayer(data))
		ui.activePlayers->addPlayerWidget(data);
}
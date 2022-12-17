#include "MainWindow.h"
#include <qrandom.h>
#include "PlayerLists.h"
#include "PlayerNode.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	playerDialog = std::make_shared<EditProfileDialog>();
	connect(ui.allPlayers, &ScrollableSectionList::onPlayerClicked, this, &MainWindow::editPlayerButton);
	connect(ui.activePlayers, &ScrollableSectionList::onPlayerClicked, this, &MainWindow::editPlayerButton);
}

MainWindow::~MainWindow()
{}

void MainWindow::updateLists() {
	ui.allPlayers->updateList(PlayerLists::allPlayers);
	ui.activePlayers->updateList(PlayerLists::actPlayers);
}

void MainWindow::editPlayerButton(std::shared_ptr<Player> player) {
	playerDialog->setData(player);
	playerDialog->exec();
	PlayerLists::editPlayer(player->identity.name, playerDialog->getData());
	updateLists();
}

void MainWindow::addPlayerButton() {
	playerDialog->resetData();
	playerDialog->exec();
	std::shared_ptr<Player> data = playerDialog->getData();
	PlayerLists::addPlayer(data);
	updateLists();
}

void MainWindow::addActPlayerButton() {
	playerDialog->resetData();
	playerDialog->exec();
	std::shared_ptr<Player> data = playerDialog->getData();
	PlayerLists::addActivePlayer(data);
	updateLists();
}

void MainWindow::deletePlayerButton() {
	auto player = ui.allPlayers->getSelectedPlayer();
	PlayerLists::removePlayer(player);
	updateLists();
}

void MainWindow::deleteActivePlayerButton() {
	auto player = ui.activePlayers->getSelectedPlayer();
	if (!player) return;
	PlayerLists::removeActPlayer(player);
	updateLists();
}

void MainWindow::allPlDelButAct(bool isAct) {
	ui.AllDeleteButton->setEnabled(isAct);
}
void MainWindow::actPlDelButAct(bool isAct) {
	ui.ActDeleteButton->setEnabled(isAct);
}
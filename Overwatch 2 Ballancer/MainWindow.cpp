#include "MainWindow.h"
#include <qrandom.h>
#include <QMessageBox>
#include <QFileDialog>
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

void MainWindow::updateNodesWithPlayer(std::string pk) {
	auto pair = playersNodes[pk];
	ui.allPlayers->updatePlayerWidget(pair.first.get());
	if (pair.second) {
		ui.activePlayers->updatePlayerWidget(pair.second.get());
	}
}														 

void MainWindow::deleteNodesWithPlayer(std::string pk) {
	auto pair = playersNodes[pk];
	ui.allPlayers->deletePlayerWidget(pair.first.get());
	if (pair.second) {
		ui.activePlayers->deletePlayerWidget(pair.second.get());
	}
}

void MainWindow::addPlayer(std::shared_ptr<Player> player) {
	if (!PlayerLists::addPlayer(player))return; // if player not added(existing), leaving func
	std::pair<
		std::shared_ptr<QListWidgetItem>,
		std::shared_ptr<QListWidgetItem>
	> pair;
	pair.first = ui.allPlayers->addPlayerWidget(player);

	playersNodes[player->PK()] = pair;
}

void MainWindow::addActivePlayer(std::shared_ptr<Player> player) {
	std::shared_ptr<Player> playerToAdd = PlayerLists::addActivePlayer(player);
	if (!playerToAdd)return;

	auto el = playersNodes.find(player->PK());
	if (el != playersNodes.end()) {
		playersNodes[player->PK()].second = ui.activePlayers->addPlayerWidget(playerToAdd);// this player has wrong ptr
		return;
	}
	std::pair<
		std::shared_ptr<QListWidgetItem>,
		std::shared_ptr<QListWidgetItem>
	> pair;
	pair.first = ui.allPlayers->addPlayerWidget(player);
	pair.second = ui.activePlayers->addPlayerWidget(player);
	playersNodes[player->PK()] = pair;
}
void MainWindow::editPlayer(std::string pk, std::shared_ptr<Player> player) {
	updateNodesWithPlayer(PlayerLists::editPlayer(pk, player)->PK());
}

void MainWindow::deletePlayer(std::shared_ptr<Player> player) {
	deleteNodesWithPlayer(player->PK());
	playersNodes.erase(player->PK());
	PlayerLists::removePlayer(player);
}

void MainWindow::deleteActivePlayer(std::shared_ptr<Player> player) {
	auto iter = playersNodes[player->PK()];
	ui.activePlayers->deletePlayerWidget(iter.second.get());
	playersNodes[player->PK()].second = nullptr;
	PlayerLists::removeActPlayer(player);
}




/// <summary>///////////////////////////
/// SLOTS
/// </summary>//////////////////////////



void MainWindow::editPlayerButton(std::shared_ptr<Player> player) {
	playerDialog->setData(player);
	playerDialog->exec();
	if (playerDialog->result() == QDialog::Accepted) {
		editPlayer(player->PK(), playerDialog->getData());
	}
}

void MainWindow::addPlayerButton() {
	playerDialog->resetData();
	playerDialog->exec();
	std::shared_ptr<Player> data = playerDialog->getData();
	if (playerDialog->result() == QDialog::Accepted) {
		auto data = playerDialog->getData();
		addPlayer(data);
	}
}

void MainWindow::addActPlayerButton() {
	playerDialog->resetData();
	playerDialog->exec();
	std::shared_ptr<Player> data = playerDialog->getData();
	if (playerDialog->result() == QDialog::Accepted) {
		auto data = playerDialog->getData();
		addActivePlayer(data);
	}
}

void MainWindow::deletePlayerButton() {
	auto player = ui.allPlayers->getSelectedPlayer();
	deletePlayer(player);
}

void MainWindow::deleteActivePlayerButton() {
	auto player = ui.activePlayers->getSelectedPlayer();
	deleteActivePlayer(player);
}

void MainWindow::allPlDelButAct(bool isAct) {
	ui.AllDeleteButton->setEnabled(isAct);
}
void MainWindow::actPlDelButAct(bool isAct) {
	ui.ActDeleteButton->setEnabled(isAct);
}

void MainWindow::importAllJsonButton() {
	QString dir = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("JSON (*.json)"));
	if (dir.isNull()) return;
	JSONParser json;
	std::unique_ptr<JSON> list = json.deserializePlayer(dir.toStdString());
	auto mass = listFromJSON(std::move(list));
	for (auto p : mass) {
		addPlayer(p);
	}
}

void MainWindow::importActJsonButton() {
	QString dir = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("JSON (*.json)"));
	if (dir.isNull()) return;
	JSONParser json;
	std::unique_ptr<JSON> list = json.deserializePlayer(dir.toStdString());
	auto mass = listFromJSON(std::move(list));
	for (auto p : mass) {
		addActivePlayer(p);
	}
}

std::vector<std::shared_ptr<Player>> MainWindow::listFromJSON(std::unique_ptr<JSON> json) {
	std::vector<std::shared_ptr<Player>> players;
	std::transform(json->players.begin(), json->players.end(), std::back_inserter(players),
		[](std::pair<const std::string, Player> p) { return std::make_shared<Player>(p.second); });
	return players;
}

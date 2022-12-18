#include "MainWindow.h"
#include <qrandom.h>
#include <QMessageBox>
#include <QFileDialog>
#include "PlayerLists.h"
#include "PlayerNode.h"
#include "JSONParser.h"

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

void MainWindow::updateNodesWithPlayer(std::string name) {
	auto pair = playersNodes[name];
	ui.allPlayers->updatePlayerWidget(pair.first.lock().get());
	if (pair.second.lock()) {
		ui.activePlayers->updatePlayerWidget(pair.second.lock().get());
	}
}														 

void MainWindow::deleteNodesWithPlayer(std::string name) {
	auto pair = playersNodes[name];
	ui.allPlayers->deletePlayerWidget(pair.first.lock().get());
	if (pair.second.lock()) {
		ui.activePlayers->deletePlayerWidget(pair.second.lock().get());
	}
}

void MainWindow::editPlayerButton(std::shared_ptr<Player> player) {
	playerDialog->setData(player);
	playerDialog->exec();
	if (playerDialog->result() == QDialog::Accepted) {
		auto data = playerDialog->getData();
		if (*data == *player)return;
		PlayerLists::editPlayer(player->identity.name, playerDialog->getData());
		updateLists();
	}
}

void MainWindow::addPlayerButton() {
	playerDialog->resetData();
	playerDialog->exec();
	std::shared_ptr<Player> data = playerDialog->getData();
	if (playerDialog->result() == QDialog::Accepted) {
		auto data = playerDialog->getData();
		if (!PlayerLists::addPlayer(data))return; // if player not added(existing), leaving func
		std::pair<
			std::weak_ptr<QListWidgetItem>,
			std::weak_ptr<QListWidgetItem>
		> pair;
		pair.first = ui.allPlayers->addPlayerWidget(data);

		playersNodes[data->identity.name] = pair;
	}
}

void MainWindow::addActPlayerButton() {
	playerDialog->resetData();
	playerDialog->exec();
	std::shared_ptr<Player> data = playerDialog->getData();
	if (playerDialog->result() == QDialog::Accepted) {
		auto data = playerDialog->getData();
		PlayerLists::addActivePlayer(data);

		auto el = playersNodes.find(data->identity.name);
		if (el != playersNodes.end()) {
			el->second.second = ui.activePlayers->addPlayerWidget(data);
			return;
		}
		std::pair<
			std::weak_ptr<QListWidgetItem>,
			std::weak_ptr<QListWidgetItem>
		> pair;
		pair.first = ui.allPlayers->addPlayerWidget(data);
		pair.second = ui.activePlayers->addPlayerWidget(data);
		playersNodes[data->identity.name] = pair;
	}
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

void MainWindow::importAllJsonButton() {
	QString dir = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("JSON (*.json)"));
	if (dir.isNull()) return;
	try {
		PlayerLists::updateAllWithJson(dir.toStdString());
		updateLists();
	}
	catch (...) {
		QMessageBox b;
		b.critical(this, "ERROR", "error occured while parsing file. maybe it is not a json file or it's structure is wrong?");
		b.show();
	}
}

void MainWindow::importActJsonButton() {
	QString dir = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("JSON (*.json)"));
	if (dir.isNull()) return;
	try {
		PlayerLists::updateActWithJson(dir.toStdString());
		updateLists();
	}
	catch (...) {
		QMessageBox b;
		b.critical(this, "ERROR", "error occured while parsing file. maybe it is not a json file or it's structure is wrong?");
		b.show();
	}
}
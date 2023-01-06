#pragma once

#include <QDialog>
#include <QMainWindow>
#include "ui_EditProfileDialog.h"
#include "Player.h"

class EditProfileDialog : public QDialog
{
	Q_OBJECT

public:
	EditProfileDialog(QWidget* parent = nullptr);
	~EditProfileDialog();

	std::shared_ptr<Player> getData();

	void resetData();
	void setData(std::shared_ptr<Player> player);
private:
	char generateChar();
	std::string generateId();

	Ui::EditProfileDialogClass ui;
};

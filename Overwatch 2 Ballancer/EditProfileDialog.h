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

	Player getData();
private:
	Ui::EditProfileDialogClass ui;
};

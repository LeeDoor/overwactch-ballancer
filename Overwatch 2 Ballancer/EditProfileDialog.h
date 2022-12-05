#pragma once

#include <QWidget>
#include "ui_EditProfileDialog.h"

class EditProfileDialog : public QWidget
{
	Q_OBJECT

public:
	EditProfileDialog(QWidget *parent = nullptr);
	~EditProfileDialog();

private:
	Ui::EditProfileDialogClass ui;
};

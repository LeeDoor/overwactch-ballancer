#pragma once

#include <QWidget>
#include "ui_ScrollableSectionList.h"
#include "EditProfileDialog.h"

class ScrollableSectionList : public QWidget
{
	Q_OBJECT

public:
	ScrollableSectionList(QWidget *parent = nullptr);
	~ScrollableSectionList();

	void addPlayerWidget(Player player);

public slots:
	void addPlayerButton(); // opens dialog to get data 
							// about new player and connects function 
							// below to FINISHED signal of the dialog
	void dialogClosedAddPlayer(); // when dialog is closed adds player
								  // to list

	//void importJSON();
	//void exportJSON();
private:
	Ui::ScrollableSectionListClass ui;
	EditProfileDialog* playerDialog;
};

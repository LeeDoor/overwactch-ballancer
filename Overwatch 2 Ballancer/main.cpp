#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include "JSONParser.h"
#include "BallanceCounter.h"
#include <ctime>
#define add(n, a, b) pls->push_back(stat(n, a, b))

PLAYER_TYPE stat(std::string name, Roles role, int rank) {
	PLAYER_TYPE pl = std::make_shared<Player>();
	switch (role)
	{
	case Tank:
		pl->stats.classes.tank.priority = 2;
		break;
	case Dps:
		pl->stats.classes.dps.priority = 2;
		break;
	case Support:
		pl->stats.classes.support.priority = 2;
		break;
	}
	pl->mainRole()->rank = rank;
	pl->identity.name = name;
	return pl;
}

int main(int argc, char *argv[])
{
	BallanceCounter a;
	PLAYERS_TYPE pls = std::make_shared<std::vector<PLAYER_TYPE>>();

	add("Roles::Dps, 4000", Roles::Dps, 4000); // 300
	add("Roles::Tank, 3000", Roles::Tank, 3000); // 200
	add("Roles::Support, 2000", Roles::Support, 2000); // 100


	add("Roles::Tank, 1000", Roles::Tank, 1000);
	add("Roles::Tank, 1000", Roles::Tank, 1000);
	add("Roles::Dps, 1000", Roles::Dps, 1000);
	add("Roles::Support, 1000", Roles::Support, 1000);
	add("Roles::Support, 1000", Roles::Support, 1000);
	add("Roles::Dps, 1000", Roles::Dps, 1000);
	add("Roles::Tank, 1000", Roles::Tank, 1000);
	add("Roles::Tank, 1000", Roles::Tank, 1000);
	add("Roles::Tank, 1000", Roles::Tank, 1000);


	add("Roles::Tank, 300", Roles::Tank, 300);    
	add("Roles::Support, 200", Roles::Support, 200); 
	add("Roles::Support, 100", Roles::Support, 100);

	a.ballance(pls);
    /*srand(time(NULL));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();*/
}

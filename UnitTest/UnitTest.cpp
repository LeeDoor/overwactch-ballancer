#include "pch.h"
#include "CppUnitTest.h"
#include "../Overwatch 2 Ballancer/BallanceCounter.h"
#include "../Overwatch 2 Ballancer/Team.h"
#include "../Overwatch 2 Ballancer/Team.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		bool isAverage(double given, double should) {
			return given > should - 5 && given < should + 5;
		}
		TEST_METHOD(TeamRoleTest)
		{
			Team t;

			std::shared_ptr<Player> dps1 = std::make_shared<Player>();
			std::shared_ptr<Player> dps2 = std::make_shared<Player>();
			t.addDps(dps1);
			t.addDps(dps2);

			std::shared_ptr<Player> sup1 = std::make_shared<Player>();
			std::shared_ptr<Player> sup2 = std::make_shared<Player>();
			t.addSupport(sup1);
			t.addSupport(sup2);

			std::shared_ptr<Player> tank = std::make_shared<Player>();
			t.addTank(tank);

			dps1->stats.classes.dps.rank = 200;
			dps2->stats.classes.dps.rank = 200;
			sup1->stats.classes.support.rank = 200;
			sup2->stats.classes.support.rank = 200;
			tank->stats.classes.tank.rank = 1100;
			double r = t.getAverageRank();
			Assert::IsTrue(isAverage(r, 380), L"wrong average rank 1");

			dps1->stats.classes.dps.rank = 1000;
			dps2->stats.classes.dps.rank = 1000;
			sup1->stats.classes.support.rank = 2000;
			sup2->stats.classes.support.rank = 2000;
			tank->stats.classes.tank.rank = 300;
			r = t.getAverageRank();
			Assert::IsTrue(isAverage(r, 1260), L"wrong average rank 2");

			dps1->stats.classes.dps.rank = 254;
			dps2->stats.classes.dps.rank = 2166;
			sup1->stats.classes.support.rank = 6365;
			sup2->stats.classes.support.rank = 1346;
			tank->stats.classes.tank.rank = 2023;
			r = t.getAverageRank();
			Assert::IsTrue(isAverage(r, 2430.8), L"wrong average rank 3");
		}

		TEST_METHOD(TeamOffclassAmountTest)
		{
			Team t;

			std::shared_ptr<Player> dps1 = std::make_shared<Player>();
			std::shared_ptr<Player> dps2 = std::make_shared<Player>();
			t.addDps(dps1);
			t.addDps(dps2);

			std::shared_ptr<Player> sup1 = std::make_shared<Player>();
			std::shared_ptr<Player> sup2 = std::make_shared<Player>();
			t.addSupport(sup1);
			t.addSupport(sup2);

			std::shared_ptr<Player> tank = std::make_shared<Player>();
			t.addTank(tank);

			dps1->identity.isOffclass = true;
			dps2->identity.isOffclass = true;
			sup1->identity.isOffclass = true;
			sup2->identity.isOffclass = true;
			tank->identity.isOffclass = true;
			Assert::IsTrue(t.getOffclassAmount() == 5, L"wrong average rank 1");

			dps1->identity.isOffclass = true;
			dps2->identity.isOffclass = true;
			sup1->identity.isOffclass = true;
			sup2->identity.isOffclass = true;
			tank->identity.isOffclass = false;
			Assert::IsTrue(t.getOffclassAmount() == 4, L"wrong average rank 2");

			dps1->identity.isOffclass = false;
			dps2->identity.isOffclass = false;
			sup1->identity.isOffclass = false;
			sup2->identity.isOffclass = false;
			tank->identity.isOffclass = false;
			Assert::IsTrue(t.getOffclassAmount() == 0, L"wrong average rank 3");

			dps1->identity.isOffclass = true;
			dps2->identity.isOffclass = false;
			sup1->identity.isOffclass = true;
			sup2->identity.isOffclass = false;
			tank->identity.isOffclass = false;
			Assert::IsTrue(t.getOffclassAmount() == 2, L"wrong average rank 4");
		}

		TEST_METHOD(TeamOffclassDoubleTest)
		{
			Team t;

			std::shared_ptr<Player> dps1 = std::make_shared<Player>();
			std::shared_ptr<Player> dps2 = std::make_shared<Player>();
			t.addDps(dps1);
			t.addDps(dps2);

			std::shared_ptr<Player> sup1 = std::make_shared<Player>();
			std::shared_ptr<Player> sup2 = std::make_shared<Player>();
			t.addSupport(sup1);
			t.addSupport(sup2);

			std::shared_ptr<Player> tank = std::make_shared<Player>();
			t.addTank(tank);

			dps1->identity.isOffclass = true;
			dps2->identity.isOffclass = true;
			sup1->identity.isOffclass = true;
			sup2->identity.isOffclass = true;
			tank->identity.isOffclass = true;
			Assert::IsTrue(t.getOffclassDouble() == 2, L"wrong average rank 1");

			dps1->identity.isOffclass = true;
			dps2->identity.isOffclass = true;
			sup1->identity.isOffclass = true;
			sup2->identity.isOffclass = true;
			tank->identity.isOffclass = false;
			Assert::IsTrue(t.getOffclassDouble() == 2, L"wrong average rank 2");

			dps1->identity.isOffclass = false;
			dps2->identity.isOffclass = false;
			sup1->identity.isOffclass = false;
			sup2->identity.isOffclass = false;
			tank->identity.isOffclass = false;
			Assert::IsTrue(t.getOffclassDouble() == 0, L"wrong average rank 3");

			dps1->identity.isOffclass = true;
			dps2->identity.isOffclass = false;
			sup1->identity.isOffclass = true;
			sup2->identity.isOffclass = false;
			tank->identity.isOffclass = false;
			Assert::IsTrue(t.getOffclassDouble() == 0, L"wrong average rank 4");
		}
	};
}

#include <iostream>
#include <QtCore/QCoreApplication>

#include "Utils.h"
#include "Farm.h"


int main( int argc, char *argv[] )
{
	QCoreApplication app(argc, argv);

	utils::Utils utils;
	Farm farm;

	bool noQuit = true;
	do {
		utils.printMenu();
		switch ( utils.getInput()) {
			case static_cast<int>(utils::MenuPoints::ADD_CHICKEN):
				farm.addChicken();
				break;
			case static_cast<int>(utils::MenuPoints::KILL_CHICKEN):
				qDebug() << "Which chicken kill?";
				farm.killChicken(utils.getInput());
				break;
			case static_cast<int>(utils::MenuPoints::LIST_CHICKEN_EGGS):
				farm.listChikensAndEgss();
				break;
			case static_cast<int>(utils::MenuPoints::LIST_CHICKENS_INTERVAL):
				farm.listEggInterval();
				break;
			case static_cast<int>(utils::MenuPoints::LAY_EGG_NOW):
				farm.layAnEgg(utils.getInput());
				break;
			case static_cast<int>(utils::MenuPoints::KILL_ALL_CHICKEN):
				farm.killAllChicken();
				break;
			case static_cast<int>(utils::MenuPoints::EXIT):
				noQuit = false;
				break;
			default:
				break;
		}
	}
	while ( noQuit );


	return 0;
}
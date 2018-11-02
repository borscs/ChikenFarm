#pragma once
#include <QDebug>

namespace utils
{

enum class MenuPoints: int
{
	ADD_CHICKEN = 1,
	KILL_CHICKEN,
	LIST_CHICKEN_EGGS,
	LIST_CHICKENS_INTERVAL,
	LAY_EGG_NOW,
	KILL_ALL_CHICKEN,
	EXIT,

};

class Utils
{
public:
	int getInput()
	{
		QTextStream qTextStream(stdin);
		return qTextStream.read(1).toInt();
	}
	void printMenu()
	{
		qDebug() << "CHICKEN FARM v1.0";
		qDebug() << "1: Add chicken";
		qDebug() << "2: Kill chicken";
		qDebug() << "3: List chickens' eggs";
		qDebug() << "4: List chickens' intervals";
		qDebug() << "5: Lay an egg";
		qDebug() << "6: Kill all chickens";
		qDebug() << "7: Quit";
	}
};
}
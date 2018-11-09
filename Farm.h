#pragma once

#include <QThread>
#include <QMap>
#include <QPair>
#include "Chicken.h"

struct ThreadAndChicken{
	QThread *qThread;
	Chicken *chicken;

};

class Farm: public QObject
{
public:
	void addChicken();
	void killChicken( const int &id );
	void listChickensAndEgss();
	void listEggInterval();
	void layAnEgg( const int &id );
	void killAllChicken();

private:
	QMap<int, ThreadAndChicken > chickens;
	int numberOfChicken = 0;

};


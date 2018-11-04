#pragma once

#include <QThread>
#include <QMap>
#include <QPair>
#include "Chicken.h"

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
	QPair<QThread *, Chicken *> addQThreadAndChicken( QThread *qThread, Chicken *chicken );

private:
	QMap<int, QPair<QThread *, Chicken * >> chickens;
	int numberOfChicken = 1;

};


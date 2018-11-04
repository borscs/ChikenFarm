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
	void listChikensAndEgss();
	void listEggInterval();
	void layAnEgg( const int &id );
	void killAllChicken();

private:
	QPair<QThread *, Chicken *> addQThreadAndChicken( QThread *qThread, Chicken *chicken );
	bool killedChicken( const int &id );

private:
	QList<int> killeddChicekns;
	QMap<int, QPair<QThread *, Chicken * >> chickens;
	int numberOfChicken = 1;

};


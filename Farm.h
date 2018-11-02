#pragma once

#include <QThread>
#include <QMap>
#include <QPair>
#include "Chicken.h"

class Farm: public  QObject{
public:
	void addChicken();

private:
	QPair<QThread *, Chicken *> addQthradAndChicken( QThread *qThread, Chicken *chicken);

private:
	QMap<int, QPair<QThread *, Chicken * >> chickens;
	int numberOfChicken = 1;

};


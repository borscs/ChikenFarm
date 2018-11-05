#include "Chicken.h"

#include <QDebug>
#include <QDateTime>
#include <QRandomGenerator>
#include <QThread>
#include "qtimer.h"

Chicken::Chicken( int chickenId )
	: chickenId(chickenId)
{
	QRandomGenerator generator;
	generator.seed(static_cast<quint32>(QDateTime::currentMSecsSinceEpoch()));
	eggInterval = ( float ) generator.bounded(10, 115) / 10 + 1;

	qDebug() << "Chicken: " << chickenId << "Interval:" << eggInterval;
}
void Chicken::initChickenSlot()
{
	qTime = new QTimer();
	qTime->setInterval(eggInterval * 1000);
	QObject::connect(qTime, &QTimer::timeout, this, &Chicken::eggCountPlusOne);

	qTime->start();
}
Chicken::~Chicken()
{
	delete qTime;
}
int Chicken::getEggCount() const
{
	return eggCount;
}
void Chicken::layAnEgg()
{
	eggCount++;
	qDebug() << "ChickenID:" << chickenId << " Total eggs: " << eggCount;
}
float Chicken::getEggInterval() const
{
	return eggInterval;
}
int Chicken::getChickenId() const
{
	return chickenId;
}
void Chicken::eggCountPlusOne()
{
	eggCount++;
}

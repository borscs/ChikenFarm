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


	qDebug() << "Chicken: " << chickenId << "interval:" << eggInterval;

}
void Chicken::initChikenSlot()
{
	qTime = new QTimer();
	qTime->setInterval(eggInterval * 1000);
	QObject::connect(qTime, &QTimer::timeout, this, &Chicken::eggCountPlusOne);

	qTime->start();

	qDebug() << "ChickeID:" << chickenId << " Total eggs: " << eggCount;
}
Chicken::~Chicken()
{
	delete qTime;
}
int Chicken::getEggCount() const
{
	return eggCount;
}
void Chicken::eggCountPlusOne()
{
	eggCount++;
}
float Chicken::getEggInterval() const
{
	return eggInterval;
}
int Chicken::getChickenId() const
{
	return chickenId;
}

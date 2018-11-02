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

	qDebug() << eggInterval;
	qDebug() << "Chicken: " << chickenId;

}
void Chicken::initChikenSlot()
{
	qTime = new QTimer();
	qTime->setInterval(eggInterval * 1000);
	QObject::connect(qTime, &QTimer::timeout, this, eggCount++);
	qTime->start();

	qDebug() << "ChickeID:" << chickenId << " Total eggs: " << eggCount;
}
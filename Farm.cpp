#include "Farm.h"

#include <QDebug>
#include <ctime>
#include <QList>

void Farm::addChicken()
{
	numberOfChicken++;
	auto *chicken = new Chicken(numberOfChicken);
	auto *qThread = new QThread;
	qDebug() << qThread;
	chickens.insert(numberOfChicken, addQThreadAndChicken(qThread, chicken));

	chicken->moveToThread(qThread);
	connect(qThread, &QThread::started, chicken, &Chicken::initChickenSlot);
	qThread->start(QThread::NormalPriority);

}
void Farm::killChicken( const int &id )
{

	if ( !(chickens.find(id) != chickens.end())) {

		qDebug() << "No this  chiekjn in farm, Try ather one";
	}
	else {
		qDebug() << chickens.value(id) << endl;
		qDebug() << chickens.value(id).first;
		chickens.value(id).first->quit();
		chickens.value(id).first->wait();

		delete chickens.take(id).second;
		delete chickens.take(id).first;
	}
}

QPair<QThread *, Chicken *> Farm::addQThreadAndChicken( QThread *qThread, Chicken *chicken )
{
	QPair<QThread *, Chicken *> chickenData;
	chickenData.first = qThread;
	chickenData.second = chicken;

	return chickenData;
}

void Farm::listChickensAndEgss()
{
	for ( auto it:chickens ) {
		qDebug() << "----Chicken: " << it.second->getChickenId() << " Eggs: " << it.second->getEggCount();
	}
}
void Farm::listEggInterval()
{
	for ( auto it: chickens ) {
		qDebug() << "----Chicken: " << it.second->getChickenId() << " Interval: " << it.second->getEggInterval();
	}
}
void Farm::layAnEgg( const int &id )
{
	for ( auto it: chickens ) {
		if ( id == it.second->getChickenId()) {
			it.second->layAnEgg();
		}
	}
}
void Farm::killAllChicken()
{
	for ( auto it: chickens.keys()) {
		killChicken(it);
	}
}

#include "Farm.h"

#include <QDebug>
#include <ctime>
#include <QList>

void Farm::addChicken()
{
	numberOfChicken++;
	auto *chicken = new Chicken(numberOfChicken);
	auto *qThread = new QThread;
	ThreadAndChicken qThreadAndChicken;
	qThreadAndChicken.qThread = qThread;
	qThreadAndChicken.chicken = chicken;
	chickens.insert(numberOfChicken, qThreadAndChicken);

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

		chickens.value(id).qThread->quit();
		chickens.value(id).qThread->wait();

		delete chickens.take(id).qThread;
		delete chickens.take(id).chicken;

	}
}
void Farm::listChickensAndEgss()
{
	for ( auto it:chickens ) {
		qDebug() << "----Chicken: " << it.chicken->getChickenId() << " Eggs: " << it.chicken->getEggCount();
	}
}
void Farm::listEggInterval()
{
	for ( auto it: chickens ) {
		qDebug() << "----Chicken: " << it.chicken->getChickenId() << " Interval: " << it.chicken->getEggInterval();
	}
}
void Farm::layAnEgg( const int &id )
{
	for ( auto it: chickens ) {
		if ( id == it.chicken->getChickenId()) {
			it.chicken->layAnEgg();
		}
	}
}
void Farm::killAllChicken()
{
	for ( auto it: chickens.keys()) {
		qDebug() << "Killed chicken id: " << it;
		killChicken(it);
	}
}


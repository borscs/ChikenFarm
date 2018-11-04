#include "Farm.h"

#include <QDebug>
#include <ctime>
#include <QList>

void Farm::addChicken()
{
	auto *chicken = new Chicken(numberOfChicken);
	auto *qThread = new QThread;
	qDebug() << qThread;
	chickens.insert(numberOfChicken, addQThreadAndChicken(qThread, chicken));

	chicken->moveToThread(qThread);
	connect(qThread, &QThread::started, chicken, &Chicken::initChikenSlot);
	qThread->start(QThread::NormalPriority);


	numberOfChicken++;
}
void Farm::killChicken( const int &id )
{

	if ( !(chickens.find(id) != chickens.end()) && killedChicken(id)) {

		qDebug() << "No this  chiekjn in fa7rm, Try ather one";
	}
	else {
		qDebug() << chickens.value(id) << endl;
		qDebug() << chickens.value(id).first;
		chickens.value(id).first->quit();
		chickens.value(id).first->wait();

		QPair<QThread *, Chicken *> deletedChikensData = chickens.take(id);
		delete deletedChikensData.first;
		delete deletedChikensData.second;
	}
}

QPair<QThread *, Chicken *> Farm::addQThreadAndChicken( QThread *qThread, Chicken *chicken )
{
	QPair<QThread *, Chicken *> chickenData;
	chickenData.first = qThread;
	chickenData.second = chicken;

	return chickenData;
}
bool Farm::killedChicken( const int &id )
{

	bool in = false;
	for ( auto i: killeddChicekns ) {
		if ( id == i ) {
			in = true;
		}
	}
	if ( !in ) {
		killeddChicekns.push_back(id);
	}
	return in;

}
void Farm::listChikensAndEgss()
{
	for ( auto it:chickens ) {
		qDebug() << "----Chiken: " << it.second->getChickenId() << " Eggs: " << it.second->getEggCount();
	}

}
void Farm::listEggInterval()
{
	for ( auto it: chickens ) {
		qDebug() << "----Chiken: " << it.second->getChickenId() << " Interval: " << it.second->getEggInterval();
	}

}
void Farm::layAnEgg(const int &id)
{

}

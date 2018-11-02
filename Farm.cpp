#include "Farm.h"

#include <QDebug>
#include <ctime>

void Farm::addChicken()
{
	auto *chicken = new Chicken(numberOfChicken);
	auto *qThread = new QThread;

	chickens.insert(numberOfChicken, addQthradAndChicken(qThread, chicken));

	chicken->moveToThread(qThread);
	connect(qThread, &QThread::started, chicken, &Chicken::initChikenSlot);
	qThread->start(QThread::NormalPriority);


	numberOfChicken++;
}
void Farm::killChicken( const int &id )
{

	if (!(chickens.find(id) != chickens.end())) {

		qDebug() << "No this  chiekjn in farm, Try ather one";
	}
	else {
		chickens.value(id).first->quit();
		chickens.value(id).first->wait();

		delete chickens.value(id).first;
		delete chickens.value(id).second;
	}
}
QPair<QThread *, Chicken *> Farm::addQthradAndChicken( QThread *qThread, Chicken *chicken )
{
	QPair<QThread *, Chicken *> chickenData;
	chickenData.first = qThread;
	chickenData.second = chicken;

	return chickenData;
}

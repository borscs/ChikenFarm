#pragma  once

#include <QtCore/QObject>
#include <QTimer>

class Chicken: public QObject
{
public:
	Chicken( int chickenId );


public:
	void initChikenSlot();

private:
	float eggInterval;
	int chickenId;
	int eggCount = 0;
	QTimer *qTime;

};

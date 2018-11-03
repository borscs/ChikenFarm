#pragma  once

#include <QtCore/QObject>
#include <QTimer>

class Chicken: public QObject
{
public:
	Chicken( int chickenId );
	~Chicken();

public:
	void initChikenSlot();
	int getEggCount() const;

private:
	float eggInterval;
	int chickenId;
	int eggCount = 0;

private:
	QTimer *qTime;

};

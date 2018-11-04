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
	float getEggInterval() const;
	int getChickenId() const;

private:
	void eggCountPlusOne();

private:
	float eggInterval;
	int chickenId;
	int eggCount = 0;
	QTimer *qTime;

};

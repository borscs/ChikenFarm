#pragma  once

#include <QtCore/QObject>
#include <QTimer>

class Chicken: public QObject
{
public:
	Chicken( int chickenId );
	~Chicken();

public:
	int getEggCount() const;
	int getChickenId() const;
	float getEggInterval() const;
	void layAnEgg();
	void initChickenSlot();
	void eggCountPlusOne();

private:
	float eggInterval;
	int chickenId;
	int eggCount = 0;
	QTimer *qTime;

};

#pragma once

#include <QPushButton>
#include <QString>

class Coin  : public QPushButton
{
	Q_OBJECT

public:

	Coin(QString defaultPath,int index,int staus);
	~Coin();
	int Index;
	int CurX = 0;
	int status = 0;
	bool isCoinCliked = true;
	int PosX = 0;
	int PoSY = 0;
	QString DefaultPath = "";
	QTimer* timer_1;
	QTimer* timer_2;
	QPixmap map;
	QPixmap tempMap;
	
signals:
	void coinFlip();
	void end();
public slots:
	void startAni(bool);
};

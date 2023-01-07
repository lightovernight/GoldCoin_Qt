#pragma once

#include <QWidget>
#include <QVector>
#include <QLabel>
#include<QtMultimedia/QMediaPlayer>
#include<QtMultimedia/QMediaPlaylist>
#include "Coin.h"
#include "mapInfo.h"
class GameWidgt  : public QWidget
{
	Q_OBJECT

public:
	//GameWidgt(QWidget *parent);
	GameWidgt();
	~GameWidgt();
	void gameOver();
	//是否由金币正在翻转，如果是则禁用所有金币
	int ifFlip;
	void startGame(int index);
	void paintEvent(QPaintEvent*);
	QLabel* winLabel;
	mapInfo gameMap;
	QMediaPlayer* sound;
	QVector<Coin*> coin;
signals:
	void clickedBackBtn(void);
};

#pragma once

#include <QWidget>
#include"MyPushButton.h"
#include<QLabel>
class LevelChoose  : public QWidget
{
	Q_OBJECT

public:
	LevelChoose(QWidget *parent = nullptr);
	~LevelChoose();
	static int index;
signals:
	void clickedBackBtn(void);
	void clickedLevelBtn(void);
};

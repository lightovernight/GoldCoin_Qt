#include "Coin.h"
#include <QTimer>
#include <QDebug>

//map是由14帧金币动画构成的一个整体图片，每帧长宽96
Coin::Coin(QString defaultPath,int index,int staus)
{
	
	this->DefaultPath = defaultPath;
	this->status = staus;
	this->Index = index;
	this->map.load(DefaultPath);
	//初始图画
	if (this->status == 0) {
		this->CurX = 0;
		this->tempMap = map.copy(this->CurX, 0, 96, 96);
	}
	else {
		this->CurX = 1248;
		this->tempMap = map.copy(this->CurX, 0, 96, 96);
	}
		
	this->setFixedSize(tempMap.width(),tempMap.height());
	this->setIconSize(QSize(tempMap.width(), tempMap.height()));
	this->setIcon(QIcon(tempMap));
	this->setStyleSheet("QPushButton{border : 0px;}");
	this->timer_1 = new QTimer;
	this->timer_2 = new QTimer;
	//设置定时器逐渐读取部分图片，实现动画效果
	connect(timer_1, &QTimer::timeout, this, [=]() {
			CurX += 96;
			if (this->CurX > 1248) {
				this->status = 1;
				this->timer_1->stop();
				if (this->isCoinCliked)
					emit this->coinFlip();
				else
					emit this->end();
				
				return;
			}
			this->tempMap = map.copy(this->CurX, 0, 96, 96);
			this->setIcon(QIcon(this->tempMap));
			
		});
	connect(timer_2, &QTimer::timeout, this, [=]() {

		CurX -= 96;
		if (this->CurX < 0) {

			this->status = 0;
			timer_2->stop();
			if (this->isCoinCliked)
				//是鼠标启动发送翻转信号
				emit this->coinFlip();
			else
				//非鼠标启动则发出结束信号，标志整个周期结束
				emit this->end();
			
			return;
		}
		this->tempMap = map.copy(this->CurX, 0, 96, 96);
		this->setIcon(QIcon(this->tempMap));

		});

}
//金币动画开启
void Coin::startAni(bool nocliked) {


	this->isCoinCliked = !nocliked;
	if (!this->status)
		this->timer_1->start(17);
	else
		this->timer_2->start(17);

}




Coin::~Coin()
{}

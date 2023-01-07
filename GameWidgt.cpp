#include "GameWidgt.h"
#include "LevelChoose.h"
#include "MyPushButton.h"
#include <QDebug>
#include <QPainter>
#include <QTimer>
#include <QPropertyAnimation>



GameWidgt::GameWidgt()
{
	this->winLabel = new QLabel(this);
	this->sound = new QMediaPlayer(this);
	this->sound->setMedia(QUrl("qrc:/resource/coinFlip.mp3"));
	QPixmap map(":/resource/Win.png");
	this->winLabel->setPixmap(map);
	this->winLabel->setGeometry((this->width() - this->winLabel->width()) / 2, 0, map.width(), map.height());
	this->setFixedSize(640, 781);
	this->ifFlip = 0;
	MyPushButton* backBtn = new MyPushButton(":/resource/back.png");
	backBtn->setParent(this);
	backBtn->PosX = this->width() - backBtn->width() - 10;
	backBtn->PoSY = this->height() - backBtn->height() - 20;
	backBtn->move(backBtn->PosX, backBtn->PoSY);
	connect(backBtn, &QPushButton::clicked, this, [=]() {

		backBtn->sound->play();
		emit this->clickedBackBtn();
		
		});



}



GameWidgt::~GameWidgt()
{}

void GameWidgt::gameOver()
{

	for (QVector<Coin*>::Iterator ite = this->coin.begin(); ite != this->coin.end(); ite++) {


		if ((*ite)->status)
			return;
	}
	QPropertyAnimation* Ani = new QPropertyAnimation(this->winLabel,"geometry");
	Ani->setStartValue(QRect((this->width() - this->winLabel->width()) / 2, -100, this->winLabel->width(), this->winLabel->height()));
	Ani->setEasingCurve(QEasingCurve::OutBounce);
	Ani->setDuration(500);
	Ani->setEndValue(QRect((this->width() - this->winLabel->width()) / 2, 50, this->winLabel->width(), this->winLabel->height()));
	this->winLabel->show();
	Ani->start();
	//禁用所有按钮
	this->ifFlip = 1;
	
	
	

	

}

void GameWidgt::startGame(int index)
{
	//初始化状态
	this->ifFlip = 0;
	this->winLabel->hide();
	for (QVector<Coin*>::Iterator ite = this->coin.begin(); ite != this->coin.end(); ite++) {

		delete *ite;

	}

	
	   this->coin.clear();
	   for (int i = 0; i < 16; i++) {


		   int rol = i % 4;
		   int col = i / 4;
		   Coin* coinBtn = new Coin(":/resource/CoinAni.png", i, this->gameMap.arry[index-1][rol][col]);
		   coinBtn->setParent(this);
		   coinBtn->PosX = i % 4 * 96 + (this->width() - 384) / 2;
		   coinBtn->PoSY = i / 4 * 96 + (this->height() - 384) / 2;
		   coinBtn->move(coinBtn->PosX, coinBtn->PoSY);
		   this->coin.append(coinBtn);
		   //金币点击播放动画
		   connect(coinBtn, &QPushButton::clicked, coinBtn, [=]() {
			   //判断是否由金币翻转
			   if (this->ifFlip)
				   return;

				   this->sound->play();
				   QTimer::singleShot(100, [=]() {

					   coinBtn->startAni(false);
					   this->ifFlip = 1;

					   });
					   
					   
				   
			   });

		   connect(coinBtn, &Coin::end, this, [=]() {

			   //周期结束，并判断游戏是否胜利 
			   this->ifFlip = 0;
			   this->gameOver();
			   });
		   

	   }
	   //金币翻转结束发出信号，实现周围金币翻转
	   for (int i = 0; i < 16; i++) {
			 //连接右边金币
		   if (i < 15 && (i + 1) % 4) {
			   connect(coin.at(i), &Coin::coinFlip, coin.at(i+1), [=]() {

				   coin.at(i + 1)->startAni(true);

				   });
		   }
		   //连接左边金币
		   if (i > 0 && i % 4) {

			   connect(coin.at(i), &Coin::coinFlip, coin.at(i-1), [=]() {

				   coin.at(i - 1)->startAni(true);

				   });

		   }
		   //连接上面金币
		   if (i > 3) {

			   connect(coin.at(i), &Coin::coinFlip, coin.at(i - 4), [=]() {

				   coin.at(i - 4)->startAni(true);

				   });
		   }
		   //连接下面金币
		   if (i < 12) {
			   connect(coin.at(i), &Coin::coinFlip, coin.at(i + 4), [=]() {

				   coin.at(i + 4)->startAni(true);

				   });

		   }
	   }


}

void GameWidgt::paintEvent(QPaintEvent*)
{
	QPainter painter(this);
	QFont font;
	font.setFamily("华文新魏");
	font.setPointSize(27);
	painter.setFont(font);
    painter.drawText(QPoint(30, 750), QString("Level %1").arg(LevelChoose::index ));
	QPixmap map(":/resource/coinback.png");
	for (int i = 0; i < 16; i++) {

		painter.drawPixmap(i % 4 * 96 + (this->width() - 384) / 2, i / 4 * 96 + (this->height() - 384) / 2, QPixmap(":/resource/coinback.png"));
		
	}
	
}

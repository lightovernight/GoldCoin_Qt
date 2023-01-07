#include "LevelChoose.h"
#include "GameWidgt.h"
#include<QMenuBar>
#include<QPainter>
#include<QPushButton>
#include<QDebug>
#include<QLabel>

int LevelChoose::index = 0;

LevelChoose::LevelChoose(QWidget *parent)
	: QWidget(parent)
{
	this->setFixedSize(640, 781);
	MyPushButton* backBtn = new MyPushButton(":/resource/back.png");
	backBtn->setParent(this);
	backBtn->PosX = this->width() - backBtn->width() - 10;
	backBtn->PoSY = this->height() - backBtn->height() - 20;
	backBtn->move(backBtn->PosX, backBtn->PoSY);
	//无法直接调用父类stack widget，所以发送自定义信号
	connect(backBtn, &QPushButton::clicked, this, [=]() {

		backBtn->sound->play();
		emit this->clickedBackBtn();

			
		});

	for (int i = 0; i < 16; i++) {
		MyPushButton* levelBtn = new MyPushButton(":/resource/level.png","",NO_STYLE);
		levelBtn->setParent(this);
		levelBtn->PosX = i % 4 * 150 + 40;
		levelBtn->PoSY = i / 4 * 150 + 40;
		levelBtn->move(levelBtn->PosX, levelBtn->PoSY);
		QLabel* levelLab = new QLabel(QString::number(i + 1), this);
		levelLab->setFixedSize(levelBtn->width(), levelBtn->height());
		levelLab->move(levelBtn->PosX, levelBtn->PoSY);
		//设置对齐方式
		levelLab->setAlignment(Qt::AlignVCenter| Qt::AlignHCenter);
		QFont font;
		font.setPointSize(20);
		levelLab->setFont(font);
		//让鼠标事件穿透Label
		levelLab->setAttribute(Qt::WA_TransparentForMouseEvents);
		connect(levelBtn, &QPushButton::clicked, this, [=]() {

			LevelChoose::index = i + 1;
			levelBtn->sound->play();
			emit this->clickedLevelBtn();
			
			});
		
	    
	}
		

		

	

	
}





LevelChoose::~LevelChoose()
{}



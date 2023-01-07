#include "MyPushButton.h"




MyPushButton::MyPushButton(QString defaultPath, QString activePath, Style btnstyle)
	{

	this->sound = new QMediaPlayer(this);
	this->sound->setMedia(QUrl("qrc:/resource/btnSound.wav"));
	this->DefaultPath = defaultPath;
	this->ActivePath = activePath;
	this->btnStyle = btnstyle;
	QPixmap pix(DefaultPath);
	this->setFixedSize(pix.width(), pix.height());
	this->setIcon(QIcon(pix));
	this->setStyleSheet("QPushButton{border : 0px;}");
	this->setIconSize(QSize(pix.width(), pix.height()));


	}
	

//按下动画
void MyPushButton::zoom1()
{
	if (this->btnStyle == PUSH_BUTTON_STYLE) {
		QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");
		animation->setDuration(100);
		animation->setStartValue(QRect(this->PosX, this->PoSY, this->width(), this->height()));
		animation->setEasingCurve(QEasingCurve::OutCirc);
		animation->setEndValue(QRect(this->PosX, this->PoSY + 10, this->width(), this->height()));
		animation->start();
		return;
	}
	

}
//弹起动画
void MyPushButton::zoom2()
{
	if (this->btnStyle == PUSH_BUTTON_STYLE) {
		QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");
		animation->setDuration(100);
		animation->setStartValue(QRect(this->PosX, this->PoSY + 10, this->width(), this->height()));
		animation->setEasingCurve(QEasingCurve::OutCirc);
		animation->setEndValue(QRect(this->PosX, this->PoSY, this->width(), this->height()));
		animation->start();
		return;
	}
}

MyPushButton::~MyPushButton()
{

}

void MyPushButton::mousePressEvent(QMouseEvent* e)
{
	this->zoom1();
	QPushButton::mousePressEvent(e);

}

void MyPushButton::mouseReleaseEvent(QMouseEvent* e)
{
	this->zoom2();
	QPushButton::mouseReleaseEvent(e);

}

#pragma once
#include<QPushButton>
#include<QString>
#include<QPropertyAnimation>
#include<QtMultimedia/QMediaPlayer>
#include<QtMultimedia/QMediaPlaylist>
enum Style
{
	NO_STYLE, PUSH_BUTTON_STYLE,FLIP_STYLE
};

class MyPushButton : public QPushButton
{
	Q_OBJECT;
public:
	MyPushButton(QString defaultPath, QString activePath = "",Style btnstyle = PUSH_BUTTON_STYLE);
	void zoom1();
	void zoom2();
	~MyPushButton();
	void mousePressEvent(QMouseEvent*);
	void mouseReleaseEvent(QMouseEvent*);
	int PosX;
	int PoSY;
	Style btnStyle;
	QMediaPlayer* sound;
private:

	QString DefaultPath;
	QString ActivePath;

};


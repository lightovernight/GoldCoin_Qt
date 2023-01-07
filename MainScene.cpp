#include "MainScene.h"
#include<Qpainter>
#include<QPixmap>
#include<QDebug>
#include<QTimer>
#include"MyPushButton.h"
#include"LevelChoose.h"
#include"GameWidgt.h"


     







MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainSceneClass())
{
    ui->setupUi(this);
    this->setFixedSize(640,801);
    this->setWindowTitle("翻金币");
    connect(ui->quit, &QAction::triggered, this, &QWidget::close);
    this->setWindowIcon(QIcon(":/resource/Coin.png"));
    MyPushButton* startBtn = new MyPushButton(":/resource/start.png");
    startBtn->setParent(this);
    startBtn->PosX = (this->width() - startBtn->width()) / 2;
    startBtn->PoSY = (this->height() + startBtn->height()) / 2;
    startBtn->move(startBtn->PosX, startBtn->PoSY);
    GameWidgt* game = new GameWidgt();
    //窗口切换使用的stack widget，因为WIN11窗口隐藏关闭有动画效果
    ui->stackedWidget->addWidget(game);
    connect(startBtn, &QPushButton::clicked, this, [=]() {

        startBtn->sound->play();
        QTimer::singleShot(250, [=]() {
            startBtn->hide();
            ui->stackedWidget->setCurrentIndex(1);
            });

        });
    //连接每个窗口的返回按钮
    connect(ui->page_2, &LevelChoose::clickedBackBtn, this, [=]() {

        QTimer::singleShot(250, [=]() {

            startBtn->show();
            ui->stackedWidget->setCurrentIndex(0);

            });
        });
    connect(ui->page_2, &LevelChoose::clickedLevelBtn, this, [=]() {

        game->startGame(LevelChoose::index);
        ui->stackedWidget->setCurrentIndex(2);
        
        
           
            });
    connect(game, &GameWidgt::clickedBackBtn, this, [=]() {

        QTimer::singleShot(250, [=]() {

            ui->stackedWidget->setCurrentIndex(1);
             

            });
        
        });
    
    
    
}

void MainScene::paintEvent(QPaintEvent* event)
{

    QPainter painter(this);
    painter.drawPixmap(0, 0, this->width(), this->height(), QPixmap(":/resource/background.jpg"));
   
}

MainScene::~MainScene()
{
    delete ui;
}

#pragma once

#include <QtWidgets/QMainWindow>
#include "LevelChoose.h"
#include "ui_MainScene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainSceneClass; };
QT_END_NAMESPACE

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* event);
    ~MainScene();
    LevelChoose* levelChoose = NULL;

private:
    Ui::MainSceneClass *ui;
};

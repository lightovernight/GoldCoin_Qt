/********************************************************************************
** Form generated from reading UI file 'MainScene.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCENE_H
#define UI_MAINSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include "LevelChoose.h"

QT_BEGIN_NAMESPACE

class Ui_MainSceneClass
{
public:
    QAction *quit;
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    LevelChoose *page_2;
    QMenuBar *menuBar;
    QMenu *menus;

    void setupUi(QMainWindow *MainSceneClass)
    {
        if (MainSceneClass->objectName().isEmpty())
            MainSceneClass->setObjectName(QString::fromUtf8("MainSceneClass"));
        MainSceneClass->resize(640, 801);
        quit = new QAction(MainSceneClass);
        quit->setObjectName(QString::fromUtf8("quit"));
        quit->setIconVisibleInMenu(true);
        centralWidget = new QWidget(MainSceneClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 640, 781));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        stackedWidget->addWidget(page);
        page_2 = new LevelChoose();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);
        MainSceneClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainSceneClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 22));
        menus = new QMenu(menuBar);
        menus->setObjectName(QString::fromUtf8("menus"));
        MainSceneClass->setMenuBar(menuBar);

        menuBar->addAction(menus->menuAction());
        menus->addAction(quit);

        retranslateUi(MainSceneClass);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainSceneClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainSceneClass)
    {
        MainSceneClass->setWindowTitle(QCoreApplication::translate("MainSceneClass", "MainScene", nullptr));
        quit->setText(QCoreApplication::translate("MainSceneClass", "\351\200\200\345\207\272", nullptr));
        menus->setTitle(QCoreApplication::translate("MainSceneClass", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainSceneClass: public Ui_MainSceneClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCENE_H

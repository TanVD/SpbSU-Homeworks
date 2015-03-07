/********************************************************************************
** Form generated from reading UI file 'progressSlider.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESSSLIDER_H
#define UI_PROGRESSSLIDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProgressSlider
{
public:
    QWidget *centralWidget;
    QProgressBar *progressBar;
    QSlider *horizontalSlider;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProgressSlider)
    {
        if (ProgressSlider->objectName().isEmpty())
            ProgressSlider->setObjectName(QStringLiteral("ProgressSlider"));
        ProgressSlider->resize(400, 300);
        centralWidget = new QWidget(ProgressSlider);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(30, 20, 331, 81));
        progressBar->setValue(0);
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(40, 170, 311, 31));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setOrientation(Qt::Horizontal);
        ProgressSlider->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ProgressSlider);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 25));
        ProgressSlider->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ProgressSlider);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ProgressSlider->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ProgressSlider);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ProgressSlider->setStatusBar(statusBar);

        retranslateUi(ProgressSlider);

        QMetaObject::connectSlotsByName(ProgressSlider);
    } // setupUi

    void retranslateUi(QMainWindow *ProgressSlider)
    {
        ProgressSlider->setWindowTitle(QApplication::translate("ProgressSlider", "ProgressSlider", 0));
    } // retranslateUi

};

namespace Ui {
    class ProgressSlider: public Ui_ProgressSlider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESSSLIDER_H

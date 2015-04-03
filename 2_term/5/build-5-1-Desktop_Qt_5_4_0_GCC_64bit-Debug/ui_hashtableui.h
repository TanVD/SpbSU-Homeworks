/********************************************************************************
** Form generated from reading UI file 'hashtableui.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HASHTABLEUI_H
#define UI_HASHTABLEUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HashTableUI
{
public:
    QWidget *centralWidget;
    QSpinBox *moduleSpinBox;
    QPushButton *moduleButton;
    QPushButton *statisticButton;
    QComboBox *comboBox;
    QLineEdit *valueLineEdit;
    QPushButton *executeButton;
    QLabel *label;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HashTableUI)
    {
        if (HashTableUI->objectName().isEmpty())
            HashTableUI->setObjectName(QStringLiteral("HashTableUI"));
        HashTableUI->resize(400, 300);
        centralWidget = new QWidget(HashTableUI);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        moduleSpinBox = new QSpinBox(centralWidget);
        moduleSpinBox->setObjectName(QStringLiteral("moduleSpinBox"));
        moduleSpinBox->setGeometry(QRect(200, 190, 131, 31));
        moduleSpinBox->setMinimum(1);
        moduleSpinBox->setMaximum(1000000000);
        moduleSpinBox->setValue(10000);
        moduleButton = new QPushButton(centralWidget);
        moduleButton->setObjectName(QStringLiteral("moduleButton"));
        moduleButton->setGeometry(QRect(330, 190, 61, 31));
        statisticButton = new QPushButton(centralWidget);
        statisticButton->setObjectName(QStringLiteral("statisticButton"));
        statisticButton->setGeometry(QRect(20, 190, 131, 31));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(280, 10, 101, 31));
        valueLineEdit = new QLineEdit(centralWidget);
        valueLineEdit->setObjectName(QStringLiteral("valueLineEdit"));
        valueLineEdit->setGeometry(QRect(20, 50, 311, 31));
        executeButton = new QPushButton(centralWidget);
        executeButton->setObjectName(QStringLiteral("executeButton"));
        executeButton->setGeometry(QRect(330, 50, 61, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(210, 170, 67, 17));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        HashTableUI->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(HashTableUI);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        HashTableUI->setStatusBar(statusBar);

        retranslateUi(HashTableUI);

        comboBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(HashTableUI);
    } // setupUi

    void retranslateUi(QMainWindow *HashTableUI)
    {
        HashTableUI->setWindowTitle(QApplication::translate("HashTableUI", "HashTableUI", 0));
        moduleButton->setText(QApplication::translate("HashTableUI", "Ok", 0));
        statisticButton->setText(QApplication::translate("HashTableUI", "statistic", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("HashTableUI", "add", 0)
         << QApplication::translate("HashTableUI", "remove", 0)
         << QApplication::translate("HashTableUI", "find", 0)
        );
        executeButton->setText(QApplication::translate("HashTableUI", "Ok", 0));
        label->setText(QApplication::translate("HashTableUI", "Module", 0));
    } // retranslateUi

};

namespace Ui {
    class HashTableUI: public Ui_HashTableUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HASHTABLEUI_H

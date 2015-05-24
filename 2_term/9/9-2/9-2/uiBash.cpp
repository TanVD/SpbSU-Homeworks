#include "uiBash.h"
#include "ui_uiBash.h"
#include <QTextCodec>
#include <QScrollBar>

uiBash::uiBash(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::uiBash)
{
    ui->setupUi(this);
    ui->centralWidget->setLayout(ui->gridLayout);
    QList<QAction*> list = ui->menuPanel->actions();
    connect(ui->menuPanel->actions()[1], SIGNAL(triggered()), this, SLOT(getNextPage()));
    connect(ui->menuPanel->actions()[2], SIGNAL(triggered()), this, SLOT(getPreviousPage()));
    connect(ui->menuPanel->actions()[3], SIGNAL(triggered()), this, SLOT(getRandomPage()));
    ask = new BashAsker;
    getMainPage();
}


void uiBash::getMainPage()
{
    QString html = ask->getMainPage();
    QStringList citList = ParseCitations::parseFromHtmlQuotes(html);
    for (int i = 0; i < citList.length(); i++)
    {
        ui->textEdit->append("№" + QString::number(i + 1) + " on list<br>" + citList[i] + "<br>");
    }
    ui->textEdit->verticalScrollBar()->setSliderPosition(0);
    //doesnt work the proper way
}

uiBash::~uiBash()
{
    delete ui;
}

void uiBash::getNextPage()
{
    QString html = ask->getNextPage();
    QStringList citList = ParseCitations::parseFromHtmlQuotes(html);
    ui->textEdit->clear();
    for (int i = 0; i < citList.length(); i++)
    {
        ui->textEdit->append(citList[i] + "<br>" + "№" + QString::number(i) + "on list" + "<br>");
    }
    ui->textEdit->verticalScrollBar()->setSliderPosition(0);
}

void uiBash::getPreviousPage()
{
    QString html = ask->getPreviousPage();
    QStringList citList = ParseCitations::parseFromHtmlQuotes(html);
    ui->textEdit->clear();
    for (int i = 0; i < citList.length(); i++)
    {
        ui->textEdit->append(citList[i] + "<br>" + "№" + QString::number(i) + "on list" + "<br>");
    }
    ui->textEdit->verticalScrollBar()->setSliderPosition(0);
}

void uiBash::getRandomPage()
{
    QString html = ask->getRandomPage();
    QStringList citList = ParseCitations::parseFromHtmlQuotes(html);
    ui->textEdit->clear();
    for (int i = 0; i < citList.length(); i++)
    {
        ui->textEdit->append(citList[i] + "<br>" + "№" + QString::number(i) + "on list" + "<br>");
    }
    ui->textEdit->verticalScrollBar()->setSliderPosition(0);
}


#pragma once
#include <QMainWindow>
#include "bashAsker.h"
#include "parseCitations.h"

namespace Ui {
class uiBash;
}

class uiBash : public QMainWindow
{
    Q_OBJECT

public:
    explicit uiBash(QWidget *parent = 0);
    ~uiBash();
private slots:
    void getNextPage();
    void getPreviousPage();
    void getRandomPage();
    void getMainPage();

private:
    Ui::uiBash *ui;
    BashAsker* ask;
};


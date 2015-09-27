#pragma once
#include <QObject>
#include <QEvent>
#include <QKeyEvent>
#include <QTime>

const int undefined = 0;

class KeyManager : public QObject
{
    Q_OBJECT
public:
    explicit KeyManager(QObject *parent = 0);

protected:
    bool eventFilter(QObject *obj, QEvent *event);

signals:
    void newButtonPressed(char button, int msec);
private:
    char currentButton;
    int msecPressed;
    QTime timer;
};

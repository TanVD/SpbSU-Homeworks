#pragma once
#include <QObject>
#include <QEvent>
#include <QKeyEvent>
#include <QTime>
#include <QString>
#include "AvatarControl.h"

const int undefined = 0;

class KeyControl : public AvatarControl
{
    ///QString includes keys in specific oreder "L(eft)R(ight)U(p)D(own)F(aster)S(lower)F(ire)"
public:
    explicit KeyControl(QString keys, QObject *parent = 0);
    QString getKeys();
    char getCurrentButton();
    void blockControls(bool blocked);

public:
    void newButtonPushed(QEvent *event);

private:
    Command getCommandFromKey(char button);
    QString keys;
    char currentButton;
    int msecPressed;
    QTime timer;
    bool controlsBlocked;
};

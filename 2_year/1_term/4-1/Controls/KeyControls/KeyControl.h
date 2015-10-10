#pragma once
#include <QObject>
#include <QEvent>
#include <QKeyEvent>
#include <QTime>
#include <QString>
#include "AvatarControl.h"

const int undefined = 0;

/**
 * @brief The KeyControl class Class represents control by keys of Avatar
 */

class KeyControl : public AvatarControl
{
    ///QString includes keys in specific oreder "L(eft)R(ight)U(p)D(own)F(aster)S(lower)F(ire)C(hange weapon)"
    ///For example ADWSQE 1 represents A for L(eft), D for R(ight) and etc. (Of course you can choose any othe bunch of keys
public:
    explicit KeyControl(QString keys);

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

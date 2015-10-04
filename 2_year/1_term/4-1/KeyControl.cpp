#include "KeyControl.h"

KeyControl::KeyControl(QString keys, QObject *parent) :
    keys(keys), currentButton(undefined), msecPressed(undefined)
{}

QString KeyControl::getKeys()
{
    return keys;
}

char KeyControl::getCurrentButton()
{
    return currentButton;
}

void KeyControl::blockControls(bool blocked)
{
    controlsBlocked = blocked;
}

void KeyControl::newButtonPushed(QEvent *event)
{
    if (controlsBlocked)
    {
        return;
    }
    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        char buttonPressed = keyEvent->key();
        //Стоит вставить обработчик события, что новая клавиша нажата не отпуская старую
        currentButton = buttonPressed;
        timer.start();
    }
    else if (event->type() == QEvent::KeyRelease)
    {
        msecPressed = timer.elapsed();
        timer.start();
        emit newCommand(getCommandFromKey(currentButton), msecPressed);
        msecPressed = undefined;
        currentButton = undefined;
    }
}

Command KeyControl::getCommandFromKey(char button)
{
    if (button == keys[0])
    {
        return leftAvatar;
    }
    if (button == keys[1])
    {
        return rightAvatar;
    }
    if (button == keys[2])
    {
        return upGun;
    }
    if (button == keys[3])
    {
        return downGun;
    }
    if (button == keys[4])
    {
        return fasterBullet;
    }
    if (button == keys[5])
    {
        return slowerBullet;
    }
    if (button == keys[6])
    {
        return fire;
    }
}



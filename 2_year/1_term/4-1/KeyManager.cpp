#include "KeyManager.h"

KeyManager::KeyManager(QObject *parent) : QObject(parent),
    currentButton(undefined), msecPressed(undefined)
{}

bool KeyManager::eventFilter(QObject *obj, QEvent *event)
{
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
        emit newButtonPressed(currentButton, msecPressed);
        msecPressed = undefined;
        currentButton = undefined;
    }
    else
    {
        return QObject::eventFilter(obj, event);
    }
    return true;
}



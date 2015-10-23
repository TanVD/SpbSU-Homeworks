#include "KeyManager.h"

KeyManager::KeyManager(QList<KeyControl*> controls, FramesUpdater *updater, QObject *parent)
    : QObject(parent), controls(controls), updater(updater)
{
    connect(updater, &FramesUpdater::update, this, &KeyManager::repressButton);
}


bool KeyManager::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        char buttonPressed = keyEvent->key();
        foreach(KeyControl *control, controls)
        {
            if (control->getKeys().contains(buttonPressed))
            {
                control->newButtonPushed(event);
            }
        }
    }
    else if (event->type() == QEvent::KeyRelease)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        char buttonPressed = keyEvent->key();
        foreach(KeyControl *control, controls)
        {
            if (control->getKeys().contains(buttonPressed))
            {
                control->newButtonPushed(event);
            }
        }
    }
    else
    {
        return QObject::eventFilter(obj, event);
    }
    return true;
}

void KeyManager::repressButton()
{
    foreach(KeyControl *control, controls)
    {
        char button = control->getCurrentButton();
        if (button != 0 && button != control->getKeys()[6] && button != control->getKeys()[7])
        {
            QKeyEvent eventRelease(QEvent::KeyRelease, button, Qt::KeyboardModifier::NoModifier);
            control->newButtonPushed(&eventRelease);
            QKeyEvent eventPushed(QEvent::KeyPress, button, Qt::KeyboardModifier::NoModifier);
            control->newButtonPushed(&eventPushed);
        }
    }
}

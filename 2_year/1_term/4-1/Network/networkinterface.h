#pragma once
#include <QObject>
#include "AvatarControl.h"
#include "Avatar.h"
#include "FramesUpdater.h"

/**
 * @brief The NetworkGeneral class Used to send and receive states
 * of away avatar
 */

class NetworkGeneral : public QObject
{
    Q_OBJECT

public:
    NetworkGeneral();

    void setControl(AvatarControl *control, Avatar *avatar, FramesUpdater *updater);

public slots:
    virtual void sendTextMessage(QString stringToCode) = 0;

signals:
    void newMessage(QString stringFromNetwork);

private:
    AvatarControl *control;
    Avatar *avatar;
    int updation;

private slots:
    void broadcastCommand(Command command);
    void broadcastUpdate();

};

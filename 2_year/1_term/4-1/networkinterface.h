#pragma once
#include <QObject>
#include "AvatarControl.h"
#include "Avatar.h"
#include "FramesUpdater.h"

class NetworkGeneral  : public QObject
{
    Q_OBJECT

public:
    void setControl(AvatarControl *control, Avatar *avatar, FramesUpdater *updater);

public slots:
    virtual void sendTextMessage(QString stringToCode) = 0;

signals:
    void newMessage(QString stringFromNetwork);

private:
    AvatarControl *control;
    Avatar *avatar;
    static int updation;

private slots:
    void commandToBroadcast(Command command);
    void updateByBroadcast();


};

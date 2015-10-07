#pragma once
#include "AvatarControl.h"
#include "ClientNetwork.h"
#include "ServerNetwork.h"
#include "networkinterface.h"
#include <QStringList>
#include <QString>


class NetworkControl : public AvatarControl
{
public:
    NetworkControl(NetworkGeneral *interface);
    void blockControls(bool blocked);

public slots:
    void newMessage(QString message);

private:
    bool blocked;
    ClientNetwork *client;
    NetworkGeneral *interface;
};


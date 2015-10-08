#pragma once
#include "AvatarControl.h"
#include "ClientNetwork.h"
#include "ServerNetwork.h"
#include "networkinterface.h"
#include <QStringList>
#include <QString>

/**
 * @brief The NetworkControl class Class represents network type of
 * control of avatar
 */

class NetworkControl : public AvatarControl
{
public:
    explicit NetworkControl(NetworkGeneral *network);
    void blockControls(bool blocked);

public slots:
    /**
     * @brief newMessage NetworkGeneral will send new message in this slot
     */
    void newMessage(QString message);

private:
    bool blocked;
    ClientNetwork *client;
    NetworkGeneral *network;
};


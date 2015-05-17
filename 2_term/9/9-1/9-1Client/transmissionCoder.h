#pragma once
#include <QTcpSocket>
#include <unreliableTransmission.h>

class TransmissionCoder
{
public:
    static QString decodeFromTransmission(QTcpSocket* connection, quint16 &blockSize);
    static QByteArray codeForTransmission(const QString &stringToCode);
};



#pragma once
#include <QTcpSocket>
#include <unreliableTransmission.h>

class TransmissionCoder
{
public:
    /**
     * @brief decodeFromTransmission Decodes byte transmission in QString
     * @param connection Socket which get incoming connection
     * @return QString if decoding was successful, else exception "Unreliable connection" type
     */
    static QString decodeFromTransmission(QTcpSocket* connection, quint16 &blockSize);

    /**
     * @brief codeForTransmission Code QString in byte array for transmission
     * @param stringToCode String to code
     * @return QByteArray - coded string
     */
    static QByteArray codeForTransmission(const QString &stringToCode);
};

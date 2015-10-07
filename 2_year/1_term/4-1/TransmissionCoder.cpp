#include "TransmissionCoder.h"
QString TransmissionCoder::decodeFromTransmission(QTcpSocket *connection, quint16 &blockSize)
{
    QDataStream in(connection);
    in.setVersion(QDataStream::Qt_4_0);

    if (blockSize == 0) {
        if (connection->bytesAvailable() < (int)sizeof(quint16))
            throw new UnreliableTransmission;

        in >> blockSize;
    }

    if (connection->bytesAvailable() < blockSize)
        throw new UnreliableTransmission;

    QString newText;
    in >> newText;
    return newText;
}

QByteArray TransmissionCoder::codeForTransmission(const QString &stringToCode)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out << stringToCode;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    return block;
}

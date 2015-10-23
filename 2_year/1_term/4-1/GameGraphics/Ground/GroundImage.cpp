#include "GroundImage.h"

GroundImage::GroundImage(FramesUpdater *updater) :
    GameGraphicsItem(updater)
{
    qsrand(time(nullptr));
    trajectory.append(QPoint(-510, 10));
    for (int i = -500; i < 500; i += 40)
    {
        int difference = qrand() % 50;

        if (qAbs(trajectory.last().y() + difference) > 200)
        {
            int sign = (trajectory.last().y() + difference)/qAbs(trajectory.last().y() + difference);
            trajectory.append(QPoint(i, (qrand() % 100) * sign));
        }
        else
        {
            trajectory.append(QPoint(i, trajectory.last().y() + difference));
        }
    }
}

GroundImage::GroundImage(FramesUpdater *updater, QString trajectorySerialized)
    : GameGraphicsItem(updater)
{
    QStringList list = trajectorySerialized.split("|");
    QList<QPoint> result;
    for (int i = 0; i < list.length() - 1; i += 2)
    {
        QPoint current;
        current.setX(list[i].toInt());
        current.setY(list[i + 1].toInt());
        result.append(current);
    }
    trajectory = result;

}

void GroundImage::prepareToUpdate()
{

}

void GroundImage::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    for (int i = 0; i < trajectory.length() - 1; i++)
    {
        painter->drawLine(trajectory[i], trajectory[i + 1]);
    }
}

QRectF GroundImage::boundingRect() const
{
    return QRectF();
}

QList<QPoint> GroundImage::getTrajectory()
{
    return trajectory;
}

QPainterPath GroundImage::shape() const
{
    QPainterPath path;
    for (int i = 0; i < trajectory.length() - 1; i++)
    {
        path.moveTo(trajectory[i]);
        path.lineTo(trajectory[i + 1]);
    }
    return path;
}

QString GroundImage::serializeToString()
{
    QString result;
    for (int i = 0; i < trajectory.length(); i++)
    {
        result += QString::number(trajectory[i].x()) + "|" + QString::number(trajectory[i].y()) + "|";
    }
    return result;
}


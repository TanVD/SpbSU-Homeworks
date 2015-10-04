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


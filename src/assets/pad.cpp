#include "pad.h"

#include <QDebug>

Pad::Pad(QGraphicsScene *screen, int posX, int posY, int width, int height)
{
    pad = new QGraphicsRectItem();
    parent = screen;
    pad->setZValue(2);
    setPosX(posX);
    setPosY(posY);
    setSize(width, height);
    updatePad();
}
// bewegt das Pad
void Pad::move(direction d, int speed)
{
    switch(d)
    {
        case Up:
        {
            if(PosY-speed > 0) setPosY(PosY-speed);
            break;
        }
        case Down:
        {
            if((PosY+Height)-speed < parent->height()) setPosY(PosY+speed);
            break;
        }

    }
}
// updated das Pad in der QGraphicsScene
void Pad::updatePad()
{
    parent->removeItem(pad);
    pad->setRect(PosX, PosY, Width, Height);
    pad->setBrush(*padBrush);
    parent->addItem(pad);
}
void Pad::setPosX(int pos)
{
    PosX = pos;
    updatePad();
}
int Pad::posX()
{
    return PosX;
}
void Pad::setPosY(int pos)
{
    PosY = pos;
    updatePad();
}
int Pad::posY()
{
    return PosY;
}
void Pad::setSize(int width, int height)
{
    Width = width;
    Height = height;
    updatePad();
}
int Pad::width()
{
    return Width;
}
int Pad::height()
{
    return Height;
}
void Pad::setColor(QColor color)
{
    padBrush->QBrush::setColor(color);
    updatePad();
}
QColor Pad::color()
{
    return padBrush->color();
}

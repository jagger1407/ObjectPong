#include "ball.h"
#include <QDebug>

Ball::Ball(QGraphicsScene *screen, int posX, int posY, int size)
{
    ball = new QGraphicsEllipseItem();
    parent = screen;
    ball->setZValue(1);
    setPosX(posX);
    setPosY(posY);
    setSize(size);
    updateBall();
}
// bewegt den Ball
void Ball::move()
{
    if(invertX) setPosX(PosX-Vel);
    else setPosX(PosX+Vel);
    if(invertY) setPosY(PosY-Vel);
    else setPosY(PosY+Vel);
}
// reagiert auf Kollisionen mit der Wand und den Pads, gibt zurück ob jemand ein Punkt erzielt hat
Ball::Goal Ball::checkCollision()
{
    if(PosX+Size+Vel >= parent->width()) return Goal2;
    else if(PosX-Vel <= 0) return Goal1;
    if(ball->collidingItems() != QList<QGraphicsItem*>())
    {
        invertX ^= 1;
        if(invertX) setPosX(PosX-15);
        else setPosX(PosX+25);
    }
    if((!invertY && PosY+Size+Vel >= parent->height()) || (invertY && PosY-Vel <= 0)) invertY ^= 1;

    return NoGoal;
}
// updated den Ball in der QGraphicsScene
void Ball::updateBall()
{
    parent->removeItem(ball);
    ball->setRect(PosX, PosY, Size, Size);
    ball->setBrush(*ballBrush);
    parent->addItem(ball);
}
void Ball::setPosX(int pos)
{
    PosX = pos;
    updateBall();
}
int Ball::posX()
{
    return PosX;
}
void Ball::setPosY(int pos)
{
    PosY = pos;
    updateBall();
}
int Ball::posY()
{
    return PosY;
}
void Ball::setSize(int size)
{
    Size = size;
    updateBall();
}
int Ball::size()
{
    return Size;
}
void Ball::setColor(QColor color)
{
    ballBrush->QBrush::setColor(color);
    updateBall();
}
QColor Ball::color()
{
    return ballBrush->color();
}
void Ball::setVel(int vel)
{
    Vel = vel;
}
int Ball::vel()
{
    return Vel;
}

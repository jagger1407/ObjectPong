#ifndef BALL_H
#define BALL_H

#include <QGraphicsWidget>
#include <QGraphicsScene>


/**
 * @todo write docs
 */
class Ball
{
public:
    /**
     * Default constructor
     */
    Ball(QGraphicsScene *screen, int posX, int posY, int size);
    int posX();
    int posY();
    int size();
    int vel();
    QColor color();
    void setPosX(int pos);
    void setPosY(int pos);
    void setSize(int size);
    void setColor(QColor color);
    void setVel(int vel);
    bool invertX;
    bool invertY;
    void move();
    enum Goal
    { NoGoal, Goal1, Goal2 };
    Goal checkCollision();
private:
    QGraphicsEllipseItem *ball;
    void updateBall();
    int PosX;
    int PosY;
    int Size;
    int Vel;
    QGraphicsScene *parent;
    QBrush *ballBrush = new QBrush(QColor::fromRgb(255,255,255));
};

#endif // BALL_H

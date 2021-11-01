#ifndef PAD_H
#define PAD_H

#include <QGraphicsWidget>
#include <QGraphicsScene>

/**
 * @todo write docs
 */
class Pad
{
public:
    /**
     * Default constructor
     */
    Pad(QGraphicsScene *screen, int posX, int posY, int width, int height);
    enum direction
    { Up, Down };
    int posX();
    int posY();
    int width();
    int height();
    QColor color();
    void setPosX(int pos);
    void setPosY(int pos);
    void setSize(int width, int height);
    void setColor(QColor color);
    void move(direction d, int speed);
private:
    QGraphicsRectItem *pad;
    void updatePad();
    int PosX;
    int PosY;
    int Width;
    int Height;
    QGraphicsScene *parent;
    QBrush *padBrush = new QBrush(QColor::fromRgb(255,255,255));
};

#endif // PAD_H

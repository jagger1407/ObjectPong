#ifndef PONG_H
#define PONG_H

#include <QMainWindow>
#include <QScopedPointer>
#include "gamewindow.h"

namespace Ui {
class Pong;
}

class Pong : public QMainWindow
{
    Q_OBJECT

public:
    explicit Pong(QWidget *parent = nullptr);
    ~Pong() override;
private slots:
    /** Initializes the Game Window. */
    void initBtn_Click();

private:
    QScopedPointer<Ui::Pong> ui;
    GameWindow *game;
};

#endif // PONG_H

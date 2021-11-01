#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QScopedPointer>
#include <QDialog>
#include <QGraphicsWidget>
#include <QTimer>
#include <QRandomGenerator>
#include "assets/ball.h"
#include "assets/pad.h"

namespace Ui
{
class GameWindow;
}

/**
 * @todo write docs
 */
class GameWindow : public QDialog
{
    Q_OBJECT
public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow() override;
    QGraphicsScene *scene;
private:
    /** Used to access Window Elements. */
    QScopedPointer<Ui::GameWindow> ui;
    QTimer *globalTimer;
    Ball *ball;
    Pad *pad1;
    Pad *pad2;
    QRandomGenerator *rand;
    bool W;
    bool S;
    bool U;
    bool D;
    void GameWindow_Load();
    void GameWindow_Close();
    void result(QString player);
    void incScore(bool player);
private slots:
    void startBtn_Clicked();
    void mainGameLoop();
    void restartGame();
protected:
    void showEvent(QShowEvent *event) override
    {
        QWidget::showEvent(event);
        GameWindow_Load();
    }
    void closeEvent(QCloseEvent *event) override
    {
        QWidget::closeEvent(event);
        GameWindow_Close();
    }
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
};

#endif // GAMEWINDOW_H

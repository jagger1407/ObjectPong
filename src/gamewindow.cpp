#include "gamewindow.h"
#include "ui_gamewindow.h"

#include <QDebug>

GameWindow::GameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
}
GameWindow::~GameWindow() = default;

// Wird beim laden des Fensters ausgeführt
void GameWindow::GameWindow_Load()
{
    scene = new QGraphicsScene(this);
    ui->startBtn->setVisible(true);
    ui->resLabel->setVisible(false);
    globalTimer = new QTimer(this);
    globalTimer->setInterval(17);
    connect(globalTimer, SIGNAL(timeout()), this, SLOT(mainGameLoop()));
    scene->setSceneRect(0, 0, ui->graphicsView->width()-5, ui->graphicsView->height()-5);
    rand = new QRandomGenerator();
}
// Wird bei schließen des Fensters ausgeführt
void GameWindow::GameWindow_Close()
{
    if(globalTimer->isActive()) globalTimer->stop();
    ui->resLabel->setVisible(false);
    scene->clear();
}
// Sieger der Runde wird ausgegeben
void GameWindow::result(QString player)
{
    globalTimer->stop();
    QTimer *wait = new QTimer(this);
    wait->setInterval(3000);
    wait->setSingleShot(true); // stellt ein, dass Timer nur einmal ticken soll
    connect(wait, SIGNAL(timeout()), this, SLOT(restartGame()));
    wait->start();
    ui->resLabel->setText(player);
    // Ändert Farbe
    QPalette temp = ui->resLabel->palette();
    temp.setColor(QPalette::WindowText, QColor::fromRgb(0,255,0));
    ui->resLabel->setPalette(temp);
    ui->resLabel->setVisible(true);
}
// Punktestand wird updated
void GameWindow::incScore(bool player)
{
    int score;
    if(!player)
        {
            QString tmpStr = ui->label_P1->text();
            score = tmpStr.split(": ")[1].toInt()+1;
            tmpStr = tmpStr.split(": ")[0] + ": " + QString::number(score);
            ui->label_P1->setText(tmpStr);
        }
        else
        {
            QString tmpStr = ui->label_P2->text();
            score = tmpStr.split(": ")[1].toInt()+1;
            tmpStr = tmpStr.split(": ")[0] + ": " + QString::number(score);
            ui->label_P2->setText(tmpStr);
        }
}
// Fügt Ball und Pads hinzu und startet Spiel
void GameWindow::startBtn_Clicked()
{
    ui->startBtn->setVisible(false);
    int midX = ui->graphicsView->width() / 2;
    int midY = ui->graphicsView->height() / 2;
    pad1 = new Pad(scene, 10, midY, 20, 75);
    pad2 = new Pad(scene, scene->width()-30, midY, 20, 75);
    ball = new Ball(scene, midX-10, midY-10, 20);
    ball->setVel(rand->bounded(5, 6));

    globalTimer->start();
}
// Haupt-Spiellogik
void GameWindow::mainGameLoop()
{
    // Spielereingabe
    if(W) pad1->move(Pad::Up, 5);
    else if (S) pad1->move(Pad::Down, 5);
    if(U) pad2->move(Pad::Up, 5);
    else if (D) pad2->move(Pad::Down, 5);
    //Spiellogik
    ui->graphicsView->setScene(scene);
    ball->move();
    switch (ball->checkCollision())
    {
        case Ball::NoGoal:
            break;
        case Ball::Goal1:
        {
            incScore(1);
            result("Spieler 2 gewinnt");
            break;
        }
        case Ball::Goal2:
        {
            incScore(0);
            result("Spieler 1 gewinnt");
            break;
        }
    }
}
// Startet eine neue Runde
void GameWindow::restartGame()
{
    scene->clear();
    ui->resLabel->setVisible(false);
    startBtn_Clicked();
}
// guckt nach Tastatureingaben
void GameWindow::keyPressEvent(QKeyEvent* event)
{
    if(event->key() == Qt::Key_W) W = true;
    if (event->key() == Qt::Key_S) S = true;
    if(event->key() == Qt::Key_I) U = true;
    if (event->key() == Qt::Key_K) D = true;
}
void GameWindow::keyReleaseEvent(QKeyEvent* event)
{
    if(event->key() == Qt::Key_W) W = false;
    if (event->key() == Qt::Key_S) S = false;
    if(event->key() == Qt::Key_I) U = false;
    if (event->key() == Qt::Key_K) D = false;
}


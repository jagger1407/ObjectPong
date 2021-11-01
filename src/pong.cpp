#include "pong.h"
#include "ui_pong.h"

Pong::Pong(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pong)
{
    ui->setupUi(this);
    game = new GameWindow(this);
}

Pong::~Pong() = default;

void Pong::initBtn_Click()
{
    game->show();
}


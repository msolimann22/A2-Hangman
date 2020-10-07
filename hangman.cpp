#include "hangman.h"
#include "ui_hangman.h"

Hangman::Hangman(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Hangman)
{
    ui->setupUi(this);
}

Hangman::~Hangman()
{
    delete ui;
}


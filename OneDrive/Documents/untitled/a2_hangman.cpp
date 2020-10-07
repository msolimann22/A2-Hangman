#include "a2_hangman.h"
#include "ui_a2_hangman.h"

A2_Hangman::A2_Hangman(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::A2_Hangman)
{
    ui->setupUi(this);
}

A2_Hangman::~A2_Hangman()
{
    delete ui;
}


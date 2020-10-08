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

void Hangman::keyPressEvent(QKeyEvent *event)
{
    for (int i = 0; i < 30; i++)
    {
        guessedChar[i] = '0';
        back = -1;
    }
    int flag = 0, flagguessed = 0;
    for (int j = 0; j < back + 1; j++){
        if(event->key() == guessedChar[j]){
            flagguessed = 1;}
    if (flagguessed == 0)
    {
    for(int i=0; i<guessWord.length() ; i++){
        if(event->key() == guessWord.at(i) ){
            ui->TextBox->setText("guessed correctly");
            flag = 1;
        }
    }
    back++;
    guessedChar[back] = event->key();

    if(flag==0){
        ui->TextBox->setText("guessed incorrectly");

    }
    }

    }
}


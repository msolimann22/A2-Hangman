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

    int flag = 0;

    for(int i=0; i<guessWord.length() ; i++){
        if(event->key() == guessWord.at(i) ){
            ui->TextBox->setText("guessed correctly");
            flag = 1;
        }
    }

    if(flag==0){
        ui->TextBox->setText("guessed incorrectly");
    }



}


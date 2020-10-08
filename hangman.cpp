#include "hangman.h"
#include "ui_hangman.h"

Hangman::Hangman(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Hangman)
{
    ui->setupUi(this);
    //initilaizing member variables
    for (int i = 0; i < 30; i++){
        guessedChar[i] = '0';
    }
    back = -1;
}

Hangman::~Hangman()
{
    delete ui;
}

void Hangman::keyPressEvent(QKeyEvent *event)
{

    int flag = 0, flagguessed = 0;

    for (int j = 0; j < back + 1; j++){
        if(event->key() == guessedChar[j]){
            flagguessed = 1;
        }
    }


    //if he didn't guess the character before
    if (flagguessed == 0){

        //we add the character to the guessedChar array
        back++;
        guessedChar[back] = event->key();

        //looping through guessword
        for(int i=0; i<guessWord.length() ; i++){

            if(event->key() == guessWord.at(i) ){
                flag = 1;
            }

        }



        if(flag==0){
            //ADD CODE TO DRAW SHAPES HERE !!!!!!!!
            ui->TextBox->setText("guessed incorrectly");
        }else{
            //ADD CODE TO DRAW CHARACTERS AND WORD HERE !!!!!!!!!!!!!
            ui->TextBox->setText("guessed correctly");
        }
    }

}


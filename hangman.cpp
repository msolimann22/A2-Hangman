#include "hangman.h"
#include "ui_hangman.h"

Hangman::Hangman(QWidget *parent): QMainWindow(parent), ui(new Ui::Hangman)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(scene);
        ui->graphicsView->setScene(scene);
          //Drawing of Shapes
        QBrush BlueBrush(Qt::blue);
        QBrush BlackBrush(Qt::black);
        QPen BluePen(Qt::blue);

          BluePen.setWidth(6);

             scene ->setSceneRect(-200,-200,300,300);
             ellipse = scene -> addEllipse(-150,-150,200,200,BluePen,BlueBrush);
              line[0]= scene->addLine(0,0,100,100, BluePen); //Line 1
              line[1]= scene->addLine(0,0,100,100, BluePen); //Line 2
              line[2]= scene->addLine(0,0,100,100, BluePen); //Line 3
              line[3]= scene->addLine(0,0,100,100, BluePen); //Line 4
              line[4]= scene->addLine(0,0,100,100, BluePen); //Line 5

              ui ->graphicsView->setRenderHint(QPainter::Antialiasing);

             line[0]->setRotation(45);
             line[1]->setRotation(45);
             line[2]->setRotation(45);
             line[3]->setRotation(45);
             line[4]->setRotation(45);







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
           for (int i=0; i<=5; i++)
            {
               if(i > 4)
           {
                   line[i]= Hangman::disappear();
               break;
               }
            else
            {ellipse= Hangman::disappear();
                   break;}
           }
            ui->TextBox->setText("guessed incorrectly");
        }
        else{
            //ADD CODE TO DRAW CHARACTERS AND WORD HERE !!!!!!!!!!!!!
            ui->TextBox->setText("guessed correctly");
        }

    }

}
QGraphicsItem* Hangman::disappear()
{
    Hangman::hide();
}



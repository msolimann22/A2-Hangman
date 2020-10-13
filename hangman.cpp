#include "hangman.h"
#include "ui_hangman.h"

Hangman::Hangman(QWidget *parent): QMainWindow(parent), ui(new Ui::Hangman)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(scene);
<<<<<<< HEAD
        ui->graphicsView->setScene(scene);
          //Drawing of Shapes
        QBrush BlueBrush(Qt::blue);
        QBrush BlackBrush(Qt::black);
        QPen BluePen(Qt::blue);
        QPen BlackPen(Qt::black);

          BluePen.setWidth(6);

           /*  scene ->setSceneRect(-200,-200,300,300);
             ellipse = scene -> addEllipse(-70,-190,100,100,BluePen,BlueBrush);
              line[0]= scene->addLine(-150,-90,100,90, BluePen); //Line 1
              line[1]= scene->addLine(-150,-90,20,80, BluePen); //Line 2
              line[2]= scene->addLine(75,-80,20,80, BluePen); //Line 3
              line[3]= scene->addLine(-10,10,50,100, BluePen); //Line 4
              line[4]= scene->addLine(10,25,50,100, BluePen); //Line 5
              ui ->graphicsView->setRenderHint(QPainter::Antialiasing);
               line[0]->setRotation(53);
             line[1]->setRotation(60);
             line[2]->setRotation(300);
            // line[3]->setRotation(45);
             line[4]->setRotation(65);

*/





=======
    ui->graphicsView->setScene(scene);
    //Drawing of Shapes
    QBrush BlueBrush(Qt::blue);
    QBrush BlackBrush(Qt::black);
    QPen BluePen(Qt::blue);

    BluePen.setWidth(6);

    ellipse = scene -> addEllipse(-70,-190,100,100,BluePen,BlueBrush);
    line[0]= scene->addLine(-150,-90,100,90, BluePen); //Line 1
    line[1]= scene->addLine(-150,-90,20,80, BluePen); //Line 2
    line[2]= scene->addLine(75,-80,20,80, BluePen); //Line 3
    line[3]= scene->addLine(-10,10,50,100, BluePen); //Line 4
    line[4]= scene->addLine(10,25,50,100, BluePen); //Line 5
    ui ->graphicsView->setRenderHint(QPainter::Antialiasing);
    line[0]->setRotation(53);
    line[1]->setRotation(60);
    line[2]->setRotation(300);
    //line[3]->setRotation(45);
    line[4]->setRotation(65);


    for(int i = 0; i < guessWord.length(); i++){
        ui->TextBox->setText(ui->TextBox->text() + "*");
    }
>>>>>>> d8a4b068262e6e718fa6c2e8de9c37bbd0eed945
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
        ui->TextBox_2->setText(ui->TextBox_2->text() + " " + QString(QChar(guessedChar[back])));

        //looping through guessword
        for(int i=0; i<guessWord.length() ; i++){

            if(event->key() == guessWord.at(i) ){
                flag = 1;
                QString text = ui->TextBox->text();
                text[i] = event->key();
                ui->TextBox->setText(text);
            }

        }



        if(flag==0){
            //ADD CODE TO DRAW SHAPES HERE !!!!!!!!

            for (int i= 6;i>= 1;i--)
            {
                if (i==6)
                {
                   scene->removeItem(line[4]);
                   break;
                }
                if (i==5)
                {
                   scene->removeItem(line[3]);
                   break;
                }
                if (i==4)
                {
                   scene->removeItem(line[2]);
                   break;
                }
                if (i==3)
                {
                   scene->removeItem(line[1]);
                   break;
                }
                if (i==2)
                {
                   scene->removeItem(line[0]);
                   break;
                }
                if (i==1)
                {
                   scene->removeItem(ellipse);
                   break;
                }
            }
            ui->label->setText("guessed incorrectly");
        }else{
            //ADD CODE TO DRAW CHARACTERS AND WORD HERE !!!!!!!!!!!!!
           //ui->TextBox->setText(ui->TextBox->text() + " " + QString(QChar(guessedChar[back])) );
            ui->label->setText("guessed correctly");
        }
    }

}


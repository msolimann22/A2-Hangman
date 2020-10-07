#include "a2_hangman.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    A2_Hangman w;
    w.show();
    return a.exec();
}

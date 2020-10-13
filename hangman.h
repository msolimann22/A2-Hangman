#ifndef HANGMAN_H
#define HANGMAN_H
#include <QMainWindow>
#include <QObject>
#include <QKeyEvent>
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QPainter>
#include <QGraphicsItemAnimation>

QT_BEGIN_NAMESPACE
namespace Ui { class Hangman; }
QT_END_NAMESPACE

class Hangman : public QMainWindow
{
    Q_OBJECT

public:
    Hangman(QWidget *parent = nullptr);
    ~Hangman();
    QGraphicsItem* disappear();

private:
    Ui::Hangman* ui;
    const QString guessWord = "ICECREAM"; //must be capitalized, this is the word that the user guesses
    char guessedChar[30];
    int back; //points to the last char in the array
    int pos2;
    QGraphicsScene* scene;
    QGraphicsItem* line[5];
    QGraphicsItem* ellipse;
private slots:
    void keyPressEvent(QKeyEvent *event);

    void on_label_2_linkActivated(const QString &link);
};
#endif // HANGMAN_H

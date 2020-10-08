#ifndef HANGMAN_H
#define HANGMAN_H


#include <QMainWindow>
#include <QKeyevent>
#include <QObject>
QT_BEGIN_NAMESPACE
namespace Ui { class Hangman; }
QT_END_NAMESPACE

class Hangman : public QMainWindow, QObject
{
    Q_OBJECT

public:
    Hangman(QWidget *parent = nullptr);
    ~Hangman();

private:
    Ui::Hangman *ui;
private slots:
    void keyPressEvent(QKeyEvent *event);
};
#endif // HANGMAN_H

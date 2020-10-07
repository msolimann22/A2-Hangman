#ifndef A2_HANGMAN_H
#define A2_HANGMAN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class A2_Hangman; }
QT_END_NAMESPACE

class A2_Hangman : public QMainWindow
{
    Q_OBJECT

public:
    A2_Hangman(QWidget *parent = nullptr);
    ~A2_Hangman();

private:
    Ui::A2_Hangman *ui;
};
#endif // A2_HANGMAN_H

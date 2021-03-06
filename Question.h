#ifndef QUESTION_H
#define QUESTION_H

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QTextEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QDialog>
#include <QLabel>

class Question : public QDialog
{
    Q_OBJECT
private :
    int type_question;
    QString question;
    QString reponse_1;
    QString reponse_2;
    QString reponse_3;
    QString reponse_4;
    QString reponse_juste;
    int nb_question;

    QTextEdit *affiche_question;
    //QLabel *affiche_question;
    QPushButton *affiche_reponse_1;
    QPushButton *affiche_reponse_2;
    QPushButton *affiche_reponse_3;
    QPushButton *affiche_reponse_4;
    QFile *fichier;
public:
    explicit Question(int,QWidget *parent = 0);
    int getNb_bonne_rep();
    void setNb_bonne_rep(int);
    static int nb_bonne_rep;
    void check_reponse(QString str);
    void end_game();
    void reset_game();
    void select_file(int type);
    void read_question_reponse(QFile *fichier);
    void affiche_questions();
    void affiche_reponses();

signals:
    void game_over();
public slots:
    void slotreponse_1();
    void slotreponse_2();
    void slotreponse_3();
    void slotreponse_4();
};

#endif // QUESTION_H

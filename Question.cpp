#include "Question.h"
#include <QWidget>
#include <QDialog>
#include <QDebug>
#include <QLabel>
#include <QMessageBox>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cercle_widget.h"
#include "score.h"


/*##################################################################################################################"*/
/*Les fichiers contenants les questions sont rédigé comme suit :                                                     */
/*nombre de question dans le fichier                                                                                 */
/*-                                                                                                                  */
/*Question                                                                                                           */
/*                                                                                                                   */
/*Reponse A                                                                                                          */
/*Reponse B                                                                                                          */
/*Reponse C                                                                                                          */
/*Reponse D                                                                                                          */
/*                                                                                                                   */
/*Reponse juste                                                                                                      */
/*-                                                                                                                  */
/*##################################################################################################################"*/

Question::Question(int type, QWidget *parent) : QDialog(parent)
{
    srand(time(NULL));
    reponse = 0;
    tour_fini = 0;
    //qDebug() <<"constructeur appelé";
    type_question = type;
    QFile *fichier;

    switch (type) {
    case 1:
    { fichier = new QFile(":/ressource/questions_1.txt");}
        break;
    case 2:
    { fichier = new QFile(":/ressource/questions_2.txt");}
        break;
    case 3:
    { fichier = new QFile(":/ressource/questions_3.txt");}
        break;
    case 4 :
    { fichier = new QFile(":/ressource/questions_4.txt");}
        break;
    case 5 :
    { fichier = new QFile(":/ressource/questions_5.txt");}
        break;
    default:
        QMessageBox msgBox;
        msgBox.setText("Aucun fichier ne peut être trouvé");
        msgBox.exec();
        this->close();
        break;}

    //qDebug() <<"bloque case passé";
    QGridLayout *lay = new QGridLayout;
    lay->setSpacing(25);
    //affiche_reponse_1 = new QPushButton("reponse_1");
    //lay->addWidget(affiche_reponse_1);

    setLayout(lay);
    //qDebug() <<"On essai d'ouvrir le fichier";

    if(fichier->open(QIODevice::ReadOnly | QIODevice::Text))

    {
        //qDebug() <<"le fichier est ouvert";


        QString nb_question_string = fichier->readLine();
        nb_question = nb_question_string.toInt();
        fichier->readLine();
        int n = rand()%nb_question;
        n = n*9;
        while (n > 0) {fichier->readLine(); --n;}
        //qDebug() << "le nombre de question est" << nb_question;
        //qDebug() << "n =" << n;
        question = fichier->readLine();
        fichier->readLine();
        reponse_1 = fichier->readLine();
        reponse_2 = fichier->readLine();
        reponse_3 = fichier->readLine();
        reponse_4 = fichier->readLine();
        fichier->readLine();
        reponse_juste = fichier->readLine();
        fichier->close();




        affiche_question = new QTextEdit(question);
        affiche_question->setDisabled(true);
        QColor couleur = (0,255,0,255);
        affiche_question->setTextColor(couleur);
        affiche_question->setMaximumHeight(75);

        affiche_reponse_1 = new QPushButton(reponse_1);
        affiche_reponse_2 = new QPushButton(reponse_2);
        affiche_reponse_3 = new QPushButton(reponse_3);
        affiche_reponse_4 = new QPushButton(reponse_4);


        lay->addWidget(affiche_question,0,0,1,2);
        lay->addWidget(affiche_reponse_1,1,0);
        lay->addWidget(affiche_reponse_2,1,1);
        lay->addWidget(affiche_reponse_3,2,0);
        lay->addWidget(affiche_reponse_4,2,1);

        setLayout(lay);

        connect(affiche_reponse_1,SIGNAL(clicked()),this,SLOT(slotreponse_1()));
        connect(affiche_reponse_2,SIGNAL(clicked()),this,SLOT(slotreponse_2()));
        connect(affiche_reponse_3,SIGNAL(clicked()),this,SLOT(slotreponse_3()));
        connect(affiche_reponse_4,SIGNAL(clicked()),this,SLOT(slotreponse_4()));

    }
    else {
        QMessageBox msgBox;
        msgBox.setText("Le fichier ne peut pas être ouvert");
        msgBox.exec();
        this->close();
    }


}
void Question::check_reponse(QString str){
    QString texte_msg_box;
    Score::nb_tour_effectue++;
    if (str == reponse_juste){
        texte_msg_box = "Bonne réponse";
        Score::nb_bonne_rep++;
    }
    else
    {
        texte_msg_box = "Mauvaise réponse";
    }
    qDebug() << Score::nb_bonne_rep;
    qDebug() << Score::nb_tour_effectue;
    texte_msg_box += "\nNombre de bonnes reponses: "+QString::number(Score::nb_bonne_rep);
    texte_msg_box += "\nNombre de tours joués :"+QString::number(Score::nb_tour_effectue);
    QMessageBox msgBox;
    msgBox.setText(texte_msg_box);
    msgBox.exec();
    this->close();
}

//afficher les réponses

void Question::slotreponse_1(){
    check_reponse(affiche_reponse_1->text());
}


void Question::slotreponse_2(){
    check_reponse(affiche_reponse_2->text());
}

void Question::slotreponse_3(){
    check_reponse(affiche_reponse_3->text());
}

void Question::slotreponse_4(){
    check_reponse(affiche_reponse_4->text());
}

int Question::getTour()
{
    return tour_fini;
}

int Question::getReponse()
{
    return reponse;
}


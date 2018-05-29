#ifndef MYSCENE_H
#define MYSCENE_H

#include <QtWidgets>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QVector>
#include <QtDebug>
#include <QPixmap>
#include <QRect>

#include "Animal.h"



class MyScene : public QGraphicsScene {
	
	Q_OBJECT

public :

    // Constructeur
	MyScene(QObject * parent = 0);
    //destructeur
	~MyScene(){};

    void combat();
	
public slots:
	void update();
	void peuplement();
	void start();
	void refresh();
	
    void slot_nb_animaux(int);
    void slot_taille_y(int);
    void slot_taille_x(int);
    void slot_energie(int);
    void slot_vitesse(int);


private:
	vector <Animal*>tab_anim;

	vector <QGraphicsPixmapItem*> tab_animGraph;
	QTimer * timer;

    int nb_animaux = 10;//nb d'animaux initial
    int taille_x = 50;//x initial
    int taille_y = 50;//y initial
    int energie = 100;//energie initiale
    int vitesse = 50;//vitesse initiale
    bool demarrage = false;
	
};
#endif

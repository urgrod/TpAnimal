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
	// Créaton d'un Vecteur d'animaux
	vector <Animal*>tab_anim;

	// Créaton d'un Vecteur d'animaux héritant des différents constructeurs de QGrapgicsPixmaItem
	vector <QGraphicsPixmapItem*> tab_animGraph;
	//Variable timer
	QTimer * timer;

	//Initialisation des différentes variables nécéssaire au démarrage de la scène
	//On affecte à chaque variable une valeur de départ, pour que la scène puisse ce lancer sans modification des sliders.
    int nb_animaux = 10;//Nombre d'animaux de départ
    int taille_x = 50;//Taille x de départ
    int taille_y = 50;//Taille y de départ
    int energie = 100;//Energie de départ
    int vitesse = 50;//Vitesse de départ

	//Variable booleene initialisée à false ici.
    bool demarrage = false;
	
};
#endif

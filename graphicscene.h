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

	// Constructeur et Destructeur
	MyScene(QObject * parent = 0);
	~MyScene(){};
	
public slots:
	//Fonction de déplacement des différents animaux
	void update();
	//Fonction de peuplement de la scène
	void peuplement();
	//Permet de débuter le programme
	void start();
	//Permet de "rafraichir" partielement la scène
	void refresh();
	
	//Modifications des différents sliders:
	void slot_nb_animaux(int);//Gestion du nombre d'animaux
	void slot_taille_y(int);//Gestion la taille en y 
	void slot_taille_x(int);//Gestion de la taille en x
	void slot_energie(int);//Gestion de l'énergie
	void slot_vitesse(int);//Gestion de la vitesse


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

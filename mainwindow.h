#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include "graphicscene.h"

#include <QtWidgets>
#include <QGroupBox>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QTimer>
#include <QSlider>
#include <QLabel>

class FenetrePrincipale : public QMainWindow {
	
	Q_OBJECT

public: 
	//Constructeur et Destructeur de la Fenetre Principale
	FenetrePrincipale();
	~FenetrePrincipale();
	//Méthode
	QGroupBox * BuildGroupBoxControle();


public slots :

	//Les différents Slots : 
	void slot_pleinecran();;


private:
	QWidget * widget_general;//Widget general
	QMenu * menuFichier;//

	QGroupBox *qgroup_box;//Creation du Group Box

	QBoxLayout * qbox_layout_principale;//Création du layout principale



	QGraphicsScene * myscene;
	QGraphicsView * myview;//vue de la scene 


	//Créations de tout les label et slider pour les animaux, l'energie etc
	QSlider* nb_animaux_slider;
  	QLabel* nb_animaux_label;

  	QSlider* energie_slider;
  	QLabel* energie_label;
  	
  	QLabel* taille_map_label;
  	QSlider* taille_x_slider;
  	QSlider* taille_y_slider;

  	QSlider* vitesse_slider;
  	QLabel * vitesse_label;

  	//Création des boutons
  	QPushButton *bouton_start;
  	QPushButton * bouton_quitter;
  	QPushButton *bouton_refresh;

  	//CheckBox pour le plein ecran
	QCheckBox *plein_ecran;
};
#endif

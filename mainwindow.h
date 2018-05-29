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
    //constructeur
	FenetrePrincipale();
    //destructeur
	~FenetrePrincipale();

    QGroupBox * BuildGroupBoxControle();


public slots :
	void slot_pleinecran();;

private:
    QWidget * widget_general;
    QMenu * menuFichier;
    QGroupBox *qgroup_box;
    QBoxLayout * qbox_layout_principale;
	QGraphicsScene * myscene;
    QGraphicsView * myview;
	QSlider* nb_animaux_slider;
  	QLabel* nb_animaux_label;
  	QSlider* energie_slider;
  	QLabel* energie_label;
    QLabel* taille_map_label;
  	QSlider* taille_x_slider;
  	QSlider* taille_y_slider;
  	QSlider* vitesse_slider;
  	QLabel * vitesse_label;
  	QPushButton *bouton_start;
  	QPushButton * bouton_quitter;
  	QPushButton *bouton_refresh;
	QCheckBox *plein_ecran;
};
#endif

#include "mainwindow.h"
#include "graphicscene.h"

FenetrePrincipale::FenetrePrincipale(): QMainWindow(){

    this ->setWindowTitle("Le folle aventure de Tux");

	widget_general = new QWidget;
	QHBoxLayout * qbl_general = new QHBoxLayout;
	widget_general->setLayout(qbl_general);
	this->setCentralWidget(widget_general);

     //creation du background et de la map
	myscene = new MyScene(this);
	myscene->setBackgroundBrush(QColor(223, 175, 44));
	myview = new QGraphicsView(myscene, this);

	qbl_general->addWidget(BuildGroupBoxControle());
	qbl_general->addWidget(myview);
}
// -------------------------------------------------------------------------------------------- //

//Destructeur
FenetrePrincipale::~FenetrePrincipale() {
}
// -------------------------------------------------------------------------------------------- //


//fonctiosn permettant de constuire le panel de controle
//entree: --
//sortie: panel de controle
QGroupBox * FenetrePrincipale::BuildGroupBoxControle(){

	QGroupBox * qgroup_box = new QGroupBox(tr("Parametres de départ :"));

    //layout avec les differents boutons
    QHBoxLayout * qbox_layout_boutons = new QHBoxLayout;
    QHBoxLayout * qbox_layout_energie = new QHBoxLayout;
    QHBoxLayout * qbox_layout_vitesse = new QHBoxLayout;
    QHBoxLayout * qbox_layout_animaux = new QHBoxLayout;
    QHBoxLayout * qbox_layout_map = new QHBoxLayout;
    QVBoxLayout * qbox_layout_conteneur = new QVBoxLayout;
	
    bouton_start = new QPushButton("Debut");
    bouton_quitter = new QPushButton("Quitter");
    plein_ecran = new QCheckBox("Plein Ecran",this);

    nb_animaux_label = new QLabel("Nombres d'animaux (Entre 2 et 500) :",this);
  	nb_animaux_slider = new QSlider(Qt::Horizontal);
    nb_animaux_slider->setRange(2, 500);

    taille_map_label = new QLabel("Taille de votre map (Y:50-600 et X:50-900):",this);
	
    //taille y
	taille_y_slider = new QSlider(Qt::Horizontal);
	taille_y_slider->setRange(50, 600);

    //taille x
	taille_x_slider = new QSlider(Qt::Horizontal);
	taille_x_slider->setRange(50, 900);

    //slider de l'energie des animaux
    energie_label = new QLabel("Energie Inital(1 à 500 Points de vie) :",this);
  	energie_slider = new QSlider(Qt::Horizontal);
    energie_slider->setRange(1, 500);

    //slider de la vitesse de simulation
    vitesse_label = new QLabel("Vitesse de l'Animal(Rapide => Lent):",this);
	vitesse_slider = new QSlider(Qt::Horizontal);
    vitesse_slider->setRange(1, 500);

    //ajout des boutons
    qbox_layout_boutons->addWidget(bouton_start);
	qbox_layout_boutons->addWidget(bouton_quitter);
	qbox_layout_boutons->addWidget(plein_ecran);

    //ajout des slider
	qbox_layout_animaux->addWidget(nb_animaux_label);
	qbox_layout_animaux->addWidget(nb_animaux_slider);
	qbox_layout_map->addWidget(taille_map_label);
	qbox_layout_map->addWidget(taille_x_slider);
	qbox_layout_map->addWidget(taille_y_slider);
	qbox_layout_energie->addWidget(energie_label);
	qbox_layout_energie->addWidget(energie_slider);
	qbox_layout_vitesse->addWidget(	vitesse_label);
	qbox_layout_vitesse->addWidget(vitesse_slider);


    qbox_layout_conteneur->addLayout(qbox_layout_animaux);
	qbox_layout_conteneur->addLayout(qbox_layout_map);
	qbox_layout_conteneur->addLayout(qbox_layout_energie);
	qbox_layout_conteneur->addLayout(qbox_layout_vitesse);
	qbox_layout_conteneur->addLayout(qbox_layout_boutons);

    //ajout du layout au layout principal
    qgroup_box->setLayout(qbox_layout_conteneur);



    //differents connect
	connect(bouton_quitter, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
	connect(bouton_start, SIGNAL(clicked()),myscene, SLOT(start()));
	connect(bouton_refresh, SIGNAL(clicked()),myscene, SLOT(refresh()));
	connect(plein_ecran, SIGNAL(clicked()), this, SLOT(slot_pleinecran()));
	connect(nb_animaux_slider, SIGNAL(valueChanged(int)),myscene,SLOT(slot_nb_animaux(int)));
	connect(taille_y_slider, SIGNAL(valueChanged(int)), myscene,SLOT(slot_taille_y(int)));
	connect(taille_x_slider, SIGNAL(valueChanged(int)), myscene,SLOT(slot_taille_x(int)));
	connect(energie_slider, SIGNAL(valueChanged(int)), myscene,SLOT(slot_energie(int)));
	connect(vitesse_slider,SIGNAL(valueChanged(int)),myscene,SLOT(slot_vitesse(int)));


	return qgroup_box;
}
// -------------------------------------------------------------------------------------------- //


//fonctions permettant de passer la simulation en full screen
//entree: --
//sortie: --
void FenetrePrincipale::slot_pleinecran() {

  this->setWindowState(this->windowState() ^ Qt::WindowFullScreen);
}
// -------------------------------------------------------------------------------------------- //

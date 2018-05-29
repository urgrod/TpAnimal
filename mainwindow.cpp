#include "mainwindow.h"
#include "graphicscene.h"

//***PARTIE GESTION DE LA FENETRE PRINCIPALE : ***//

//Constructeur de la Fenetre Principale :
FenetrePrincipale::FenetrePrincipale(): QMainWindow(){
	//Titre du programme
    this ->setWindowTitle("Le folle aventure des gazelles");

	//Creation du Widget et du Layout "globale"
	widget_general = new QWidget;
	QHBoxLayout * qbl_general = new QHBoxLayout;

	//Initialisation du widget et du layout
	widget_general->setLayout(qbl_general);
	this->setCentralWidget(widget_general);

	 // Création de la scène et du background
	myscene = new MyScene(this);
	myscene->setBackgroundBrush(QColor(223, 175, 44));
	myview = new QGraphicsView(myscene, this);

	// Ajout des contrôles
	qbl_general->addWidget(BuildGroupBoxControle());
	qbl_general->addWidget(myview);
}

// Création du Groupe Box Contrôle
QGroupBox * FenetrePrincipale::BuildGroupBoxControle(){

	//Création du Groupe Box Globale : 
	QGroupBox * qgroup_box = new QGroupBox(tr("Parametres de départ :"));

	// Layout contenant les différents boutons
	QHBoxLayout * qbox_layout_boutons = new QHBoxLayout;

	// Layout contenant les différents sliders : 
	QHBoxLayout * qbox_layout_animaux = new QHBoxLayout;//Création d'un layout animal

	QHBoxLayout * qbox_layout_map = new QHBoxLayout;//Création d'un layout map

	QHBoxLayout * qbox_layout_energie = new QHBoxLayout;//Création d'un layout energie
	QHBoxLayout * qbox_layout_vitesse = new QHBoxLayout;//Créaton d'un layout vitesse 
	QVBoxLayout * qbox_layout_conteneur = new QVBoxLayout;//Création d'un layout conteneur
	

	//Pour chaque Bouton et chaque layout, on va initialiser un titre(label) et un bouton ou/slider: 


	bouton_start = new QPushButton("Start");//Création du bouton start
	bouton_refresh = new QPushButton("Refresh");//Création du bouton Refresh

	bouton_quitter = new QPushButton("Quittez");
	plein_ecran = new QCheckBox("Plein Ecran",this);//Création d'un CheckBox plein ecran

	nb_animaux_label = new QLabel("Nombres d'animaux (Entre 10 et 50) :",this);
	//Creation du 1er Slider : Slider pour modifier le nombre d'animal
  	nb_animaux_slider = new QSlider(Qt::Horizontal);
  	//Pour chaque slider, on défini un minimum et un maximum de valeur
	nb_animaux_slider->setRange(10, 50);

	taille_map_label = new QLabel("Taille de votre map (Y:50-600 puis X:50-900):",this);
	
	taille_y_slider = new QSlider(Qt::Horizontal);
	taille_y_slider->setRange(50, 600);

	taille_x_slider = new QSlider(Qt::Horizontal);
	taille_x_slider->setRange(50, 900);

	energie_label = new QLabel("Energie Inital(50 à 300 Points) :",this);

  	energie_slider = new QSlider(Qt::Horizontal);
	energie_slider->setRange(50, 300);

	vitesse_label = new QLabel("Vitesse de l'Animal(Très rapide->Lent):",this);

	vitesse_slider = new QSlider(Qt::Horizontal);
	vitesse_slider->setRange(50, 200);

	 //On ajoute tous les widgets label, slider et bouton à leurs layouts respectifs  
	qbox_layout_boutons->addWidget(bouton_start);
	qbox_layout_boutons->addWidget(bouton_refresh);
	qbox_layout_boutons->addWidget(bouton_quitter);
	qbox_layout_boutons->addWidget(plein_ecran);

	qbox_layout_animaux->addWidget(nb_animaux_label);
	qbox_layout_animaux->addWidget(nb_animaux_slider);

	qbox_layout_map->addWidget(taille_map_label);
	qbox_layout_map->addWidget(taille_x_slider);
	qbox_layout_map->addWidget(taille_y_slider);

	qbox_layout_energie->addWidget(energie_label);
	qbox_layout_energie->addWidget(energie_slider);

	qbox_layout_vitesse->addWidget(	vitesse_label);
	qbox_layout_vitesse->addWidget(vitesse_slider);

	//On ajoute les différents layouts
	qbox_layout_conteneur->addLayout(qbox_layout_animaux);

	qbox_layout_conteneur->addLayout(qbox_layout_map);

	qbox_layout_conteneur->addLayout(qbox_layout_energie);

	qbox_layout_conteneur->addLayout(qbox_layout_vitesse);

	qbox_layout_conteneur->addLayout(qbox_layout_boutons);

	//On ajoute le layout principal à la groupe box
	qgroup_box->setLayout(qbox_layout_conteneur);	



 	//Connection des différents slider/boutons 
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

//Slot plein ecran qui permet de modifier l'état de la fenetre pour l'affichage en plein ecran.
void FenetrePrincipale::slot_pleinecran() {

  // Change l'état de la fenêtre
  this->setWindowState(this->windowState() ^ Qt::WindowFullScreen);
}

//Destructeur
FenetrePrincipale::~FenetrePrincipale() {
}

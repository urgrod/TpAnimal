#include "mainwindow.h"
#include "graphicscene.h"
#include "Animal.h"
#include "Lion.h"
#include "Gazelle.h"

//constructeur
MyScene::MyScene(QObject * parent): QGraphicsScene(parent){

  int MAX_X = 800;
  int MAX_Y = 500;

  this->setSceneRect(0, 0, MAX_X, MAX_Y);

// initialisation du timer
  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()),this,SLOT(update()));
  timer->start(vitesse);
}
// -------------------------------------------------------------------------------------------- //


//fonction permettant de mettre a jour les animaux a chaque tour
//entree: --
//sortie: --
void MyScene::update() {

  if (demarrage == false){
    return;
  }

  for(int i=0;i<tab_anim.size();i++){

    int x = tab_animGraph[i]->x();
    int y = tab_animGraph[i]->y();

    int energie = tab_anim[i]->getEnergie();

    int orientation = rand() % 4;

    //si les animaux ont de la vie ils peuvent bouger
    if(energie >0){
        switch(orientation) {

        case 0:
          if (x > 10) x=x-11;
            tab_animGraph[i]->setX(x);
            tab_anim[i]->SetEnergie(energie-1);//on diminue l'energie de 1 a chaque deplacement
          break;

        case 1:
          if (x < taille_x - 10) x=x+11;
            tab_animGraph[i]->setX(x);
            tab_anim[i]->SetEnergie(energie-1);
          break;

        case 2:
          if (y > 10) y=y-11;
            tab_animGraph[i]->setY(y);
            tab_anim[i]->SetEnergie(energie-1);
          break;

        case 3:
          if (y < taille_y - 10) y=y+11;
            tab_animGraph[i]->setY(y);
            tab_anim[i]->SetEnergie(energie-1);
          break;
      }
    }
    //lorsque l'animal a plus de vie on affiche une tombe
    else if(energie == 0){
      tab_animGraph[i]->setPixmap(QPixmap("tombe.png"));
      tab_animGraph.erase(tab_animGraph.begin(), tab_animGraph.end());  
    }
  }
}
// -------------------------------------------------------------------------------------------- //

//fonction permettant aux lions de manger les gazelles
//entree:
//sortie:
void MyScene::combat(){

}

//fonction permettant de peupler les animaux sur la map
//entree: --
//sortie: --
void MyScene::peuplement(){
  
  int x,y;

  for (int i = 0; i < nb_animaux; ++i){ 

    //positionnement aleatoire des animaux sur la map
    x=rand()%taille_x;
    y=rand()%taille_y;

    //on affiche equipropablement les lions et gazelle
    if (i%2 == 0){

      //creation des gazelles
      QPixmap img_gaz =QPixmap("Windows_logo.png").scaled(50,50);
      tab_anim.push_back(new Gazelle(x, y, energie, img_gaz));
      tab_animGraph.push_back(new QGraphicsPixmapItem(tab_anim[i]->getImg_anim()));

      //on place les animaux sur la map
      tab_animGraph[i]->setPos(tab_anim[i]->getX(),tab_anim[i]->getY());
    }
    else{

      //creation des lions
      QPixmap img_lion = QPixmap("linux_PNG30.png").scaled(50,50);
      tab_anim.push_back(new Lion(x, y, energie, img_lion));
      tab_animGraph.push_back(new QGraphicsPixmapItem(tab_anim[i]->getImg_anim()));
      tab_animGraph[i]->setPos(tab_anim[i]->getX(),tab_anim[i]->getY());
    }
    this->addItem(tab_animGraph[i]);
  }
}
// -------------------------------------------------------------------------------------------- //

//fonction permettant de lancer la simulation
//entree: --
//sortie: --
void MyScene::start(){

  peuplement();
  demarrage = true;
}
// -------------------------------------------------------------------------------------------- //

//fonction permettant de changer le nombre d'animaux
//entree: nouveaux nombre d'animaux
//sortie:--
void MyScene::slot_nb_animaux(int anim){
  nb_animaux = anim;
}
// -------------------------------------------------------------------------------------------- //

//fonction permettant de changer la taille en y
//entree: nouveaulle taille en y
//sortie:--
void MyScene::slot_taille_y(int y){
  taille_y = y;
}
// -------------------------------------------------------------------------------------------- //

//fonction permettant de changer la taille en x
//entree: nouvelle taille en x
//sortie:--
void MyScene::slot_taille_x(int x){
 taille_x = x;
}
// -------------------------------------------------------------------------------------------- //

//fonction permettant de changer l'energie des animaux
//entree: nouvelle taille en energie
//sortie:--
void MyScene::slot_energie(int energie_init){
 energie = energie_init;
}
// -------------------------------------------------------------------------------------------- //

//fonction permettant de changer la vitesse de la simulation
//entree:nouvelle vitesse de la simulation
//sortie:--
void MyScene::slot_vitesse(int vitesse_init){
  vitesse = vitesse_init;
  timer->setInterval(vitesse);
}
// -------------------------------------------------------------------------------------------- //

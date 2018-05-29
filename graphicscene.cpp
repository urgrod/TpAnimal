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

  //Boucle if qui nous permet de lancer notre scène lorsque la variable demarrage passe à true 
  if (demarrage == false){
    return;
  }

  //Boucle for qui va parcourir le tableau de vecteur animal dans lequel on va modifier des variables x,y,energie... 
  for(int i=0;i<tab_anim.size();i++){

    //On utilise un deuxieme vecteur de tab_anim pour gérer l'affichage graphique de nos animaux.
    //On modifie les coordonnées graphiques de l'animal
    int x = tab_animGraph[i]->x();
    int y = tab_animGraph[i]->y();

    //On Modifie l'energie de l'anmial à l'aide de ma classe Animal.
    int energie = tab_anim[i]->getEnergie();

    // On utilise une variable orientation qui va nous permettre de gérer de manière aléatoire les déplacements des différents animaux.
    int orientation = rand() % 4;

    //Tant que les animaux on de l'energie, on parcours la boucle
    if(energie >0){
        switch(orientation) {//On commence à étudier les différents déplacement

        case 0://Cas 0 : Si la position en x pixel est supérieur à 10, alors on décremente le x de 11pixel
          if (x > 10) x=x-11;
            tab_animGraph[i]->setX(x);//On récupere la nouvelle postion en x 
            tab_anim[i]->SetEnergie(energie-1);//Et puis on décremente l'energie de 1 . 
          break;

        //On traite ensuite tout les différents cas en fonction de la taille de la map en x et en y, pour gérer chaque déplacement. 
        case 1:
          if (x < taille_x - 10) x=x+11;
            tab_animGraph[i]->setX(x);
            tab_anim[i]->SetEnergie(energie-1);
          break;

        case 2://Idem que le cas 0 mais avec la variable y 
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
    //Lorsque l'animal n'a plus d'énergie, on sort du switch et on affiche une image d'animal mort.
    else if(energie == 0){
      tab_animGraph[i]->setPixmap(QPixmap("mort.png"));
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

//***FONCTION PEUPLEMENT ***//

void MyScene::peuplement(){
  
  int x,y;//Initialisation d'une variable x,y et energie

  //On regarde le nombre d'animaux 
  for (int i = 0; i < nb_animaux; ++i){ 

    x=rand()%taille_x;//Postion en x aléatoire en fonction de la taille de la map en x
    y=rand()%taille_y;//Position en y aléatoire en fonction de la taille de la map en y

    //On affiche ensuite une image de lion ou de gazelle une fois sur 2 pour pouvoir remplir note scène.
    if (i%2 == 0){

      //On affecte à la variable img_gaz l'image correspondante
      QPixmap img_gaz =QPixmap("gazelle.png");

      //On créer ensuite une nouvelle Gazelle avec une position en x, en y, avec une énergie et son image.
      tab_anim.push_back(new Gazelle(x, y, energie, img_gaz));

      //Création de l'image en graphique à l'aide du vecteur graphique.
      tab_animGraph.push_back(new QGraphicsPixmapItem(tab_anim[i]->getImg_anim()));

      //On récupére ensuite la position de l'animal en x et en y pour gérer la postion en graphique
      tab_animGraph[i]->setPos(tab_anim[i]->getX(),tab_anim[i]->getY());
    }
    else{//Sinon

      //On affecte à la variable img_lion l'image correspondante
      QPixmap img_lion = QPixmap("lion.png");
      //On créer ensuite un nouveau Lion avec une position en x, en y, avec une énergie et son image.
      tab_anim.push_back(new Lion(x, y, energie, img_lion));
      tab_animGraph.push_back(new QGraphicsPixmapItem(tab_anim[i]->getImg_anim()));
      tab_animGraph[i]->setPos(tab_anim[i]->getX(),tab_anim[i]->getY());
    }
    this->addItem(tab_animGraph[i]);
  }
}
// -------------------------------------------------------------------------------------------- //

//***FONCTION START ***//
void MyScene::start(){

  //Fonction qui va permettre de lancer le programme lorsque la varible démarrage passe à true (Lorsque l'on clique sur le boutton Start)
  peuplement();
  demarrage = true;
}
// -------------------------------------------------------------------------------------------- //


//**TENTATIVE DE FONCTION REFRESH **//
void MyScene::refresh(){

}
// -------------------------------------------------------------------------------------------- //


//***************SLOTS POUR GERER LES DIFFÉRENTS SLIDERS ****************************//

void MyScene::slot_nb_animaux(int anim){//Slot pour changer le nombre d'animaux
  nb_animaux = anim;
}
// -------------------------------------------------------------------------------------------- //


void MyScene::slot_taille_y(int y){//Slot pour modifier la taille de la scene en x
  taille_y = y;
}
// -------------------------------------------------------------------------------------------- //

void MyScene::slot_taille_x(int x){//Slot pour modifier la taille de la scene en y
 taille_x = x;
}
// -------------------------------------------------------------------------------------------- //

void MyScene::slot_energie(int energie_init){//Slot pour modifier l'énergie
 energie = energie_init;
}
// -------------------------------------------------------------------------------------------- //

void MyScene::slot_vitesse(int vitesse_init){//Slot pour modifier la vitesse
  vitesse = vitesse_init;
  timer->setInterval(vitesse);
}
// -------------------------------------------------------------------------------------------- //

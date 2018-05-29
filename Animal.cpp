#include "Animal.h"


/*Créations des différents getters et setters pour pouvoir 
récupérer les postions,l'energie ou encore les images correspondant à chaque animal dans notre scène.*/

//Getter de x
int Animal::getX(){
	return x;
}

//Getter de y 
int Animal::getY(){
	return y;
}

//Getter d'energie
int Animal::getEnergie(){
	return energie;
}

//Getter de l'image
QPixmap Animal::getImg_anim(){
	return img_anim;
}

//Setter de x
void Animal::SetX(int x){
	(*this).x = x;
}

//Setter de y
void Animal::SetY(int y){
	(*this).y = y;
}

//Setter d'energie
void Animal::SetEnergie(int energie){
	(*this).energie = energie;
}

//Setter de l'image
void Animal::SetImg_anim(QPixmap img_anim){
	(*this).img_anim = img_anim;
}

//Constructeur d'Animal
Animal::Animal(int x_init, int y_init, int energie_init,QPixmap img_init){
	x = x_init;
	y = y_init;
	energie = energie_init;
	img_anim = img_init;	
}

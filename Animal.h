#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <cstdlib>
#include <QGraphicsPixmapItem>
	

using namespace std;

class Animal{
private:

	int x; //Position de l'animal en x
	int y; //Position de l'animal en y
	int energie;//Energie de l'animal
	QPixmap img_anim; //Image de l'animal 

public:
	//constructeur
	Animal();
	Animal(int x, int y, int energie,QPixmap img_anim);

	//Getters
	int getX();
	int getY();
	int getEnergie();
	QPixmap getImg_anim();

	//Setters
	void SetX(int x);
	void SetY(int y);
	void SetEnergie(int energie);
	void SetImg_anim(QPixmap img_anim);
	
	//destructeur
	virtual ~Animal(){}	;
};
#endif
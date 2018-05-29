#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <cstdlib>
#include <QGraphicsPixmapItem>
	

using namespace std;

class Animal{
private:

    int x;
    int y;
    int energie;
    QPixmap img_anim;

public:
	//constructeur
	Animal();
	Animal(int x, int y, int energie,QPixmap img_anim);

    //destructeur
    virtual ~Animal(){}	;

    //Setters
    void SetX(int x);
    void SetY(int y);
    void SetEnergie(int energie);
    void SetImg_anim(QPixmap img_anim);

	//Getters
	int getX();
	int getY();
	int getEnergie();
	QPixmap getImg_anim();

};
#endif

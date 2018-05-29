#ifndef LION_H
#define LION_H

#include "Animal.h"
#include "graphicscene.h"
#include <typeinfo>
#include <iostream>
#include <cstdlib>
#include <QGraphicsPixmapItem>

using namespace std;


class Lion: public Animal
{
private:

	static const char lettre ='L';

public:

	//Constructeur
	Lion(){}
	Lion(int x, int y, int energie,QPixmap img_lion): Animal(x,y,energie,img_lion){}

	//Destructeur
	virtual ~Lion(){}
	//Getter de lettre
	virtual char getLettre();
};
#endif
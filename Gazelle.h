#ifndef GAZELLE_H
#define GAZELLE_H

#include "Animal.h"
#include "graphicscene.h"
#include <iostream>
#include <cstdlib>
#include <typeinfo>

using namespace std;

class Gazelle: public Animal
{
	
private:
    static const char lettre = 'G';


public:
	//Constructeur
	Gazelle(){}
	Gazelle(int x, int y, int energie,QPixmap img_gaz): Animal(x,y,energie,img_gaz){}
	
	//Destructeur
	virtual ~Gazelle(){}

    //getter
	virtual char getLettre();
};
#endif

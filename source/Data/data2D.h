#ifndef DATA2D_H
#define DATA2D_H

#include "../debug.h"

#include <iostream>
#include <fstream>
using namespace std;

class Data2D {
	private:
		float 	Val;
		float 	Val2;
	public:
		
		//Constructeur Default
		Data2D();
		
		//Constructeur Init
		Data2D(const float valeur, const float valeur2);
		
		//Constructeur Copie
		Data2D(const Data2D &e);
		
		//Deconstructeur	
		~Data2D();
		
		
		//GETTER SETTER
		float getValeur() const;
		void setValeur(const float valeur);

		float getValeur2() const;
		void setValeur2(const float valeur);
		
		
		//OPPERATOR SURCHARGE
	    Data2D& operator=(const Data2D& t2);

	    friend bool operator==(const Data2D& t1, const Data2D& t2);
 
        friend bool operator<(const Data2D& t1, const Data2D& t2);

        friend bool operator>(const Data2D& t1, const Data2D& t2);

     	friend std::ostream& operator<<(std::ostream& s, const Data2D& t1);
};
#endif
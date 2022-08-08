#ifndef DATA1D_H
#define DATA1D_H

#include <iostream>
#include <fstream>
using namespace std;

class Data1D {
	private:
		float 	Val;
		int 	Eff;
	public:
		
		//Constructeur Default
		Data1D();
		
		//Constructeur Init
		Data1D(const float valeur, const int effectif);
		
		//Constructeur Copie
		Data1D(const Data1D &e);
		
		//Deconstructeur	
		~Data1D();
		
		//Methode Special
		const char* Txt();
		
		const char* Tuple();
		
		
		//GETTER SETTER
		float getValeur() const;
		void setValeur(const float valeur);

		int getEffectif() const;
		void setEffectif(const int effectif);
		
		
		//OPPERATOR SURCHARGE
	    Data1D& operator=(const Data1D& t2);

	    friend bool operator==(const Data1D& t1, const Data1D& t2);
 
        friend bool operator<(const Data1D& t1, const Data1D& t2);

        friend bool operator>(const Data1D& t1, const Data1D& t2);

     	friend std::ostream& operator<<(std::ostream& s, const Data1D& t1);

     	//Flux Gestion Fichier:
        void Save(ofstream& fichier) const;    //Save Objet in Fichier
        void Load(ifstream& fichier);          //Load Objet from Fichier
};
#endif
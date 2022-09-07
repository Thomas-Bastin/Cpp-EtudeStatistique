#ifndef DATASOURCE_H
#define DATASOURCE_H

#include "../debug.h"

#include <iostream>
#include <fstream>
#include <string>

#include "../Data/data1D.h"
#include "../Liste_Template/Liste.h"

using namespace std;

class DataSource {
	protected:
        string Nom;
        string Sujet;

        int EffTotal;
        string Type;
		
	public:
		
		//Constructeur Default
		DataSource();
		
		//Constructeur Init
		DataSource(string Nom, string Sujet, string Type);
		
		//Constructeur Copie
		DataSource(const DataSource &e);
		
		//Deconstructeur	
		virtual ~DataSource();
		
		
		//GETTER SETTER
		string getNom() const;
        void   setNom(const string name);

        string getSujet() const;
        void   setSujet(const string sujet);
        
        int  getEffectifTotal() const;
        void setEffectifTotal(const int efftotal);

        string  getType() const;
		void setType(const string type);

		//OPPERATOR SURCHARGE
	    DataSource& operator=(const DataSource& t2);

	    friend bool operator==(const DataSource& t1, const DataSource& t2);

     	friend std::ostream& operator<<(std::ostream& s, const DataSource& t1);
		
		//My Methods:
		virtual void AfficheData() = 0;
		virtual Liste<Data1D> getListe() const = 0;
		virtual float getMedianne() = 0;
		virtual float getMax() const = 0;
		virtual float getMin() const = 0;
		virtual float getMoyenne() const = 0;
		virtual string getMode() = 0;
		virtual float getEcartType() = 0;
};
#endif
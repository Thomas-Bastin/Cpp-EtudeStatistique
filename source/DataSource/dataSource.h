#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class DataSource {
	protected:
        string Nom;
        string Sujet;

        int EffTotal;
        int Type;
		
	public:
		
		//Constructeur Default
		DataSource();
		
		//Constructeur Init
		DataSource(string Nom, string Sujet, int Type);
		
		//Constructeur Copie
		DataSource(const DataSource &e);
		
		//Deconstructeur	
		~DataSource();
		
		
		//GETTER SETTER
		string getNom() const;
        void   setNom(const string name);

        string getSujet() const;
        void   setSujet(const string sujet);
        
        int  getEffectifTotal() const;
        void setEffectifTotal(const int efftotal);

        int  getType() const;
		void setType(const int type);

		//OPPERATOR SURCHARGE
	    DataSource& operator=(const DataSource& t2);

	    friend bool operator==(const DataSource& t1, const DataSource& t2);

     	friend std::ostream& operator<<(std::ostream& s, const DataSource& t1);
};
#endif
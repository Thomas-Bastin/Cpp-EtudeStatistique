#ifndef ECHANTILLON_H
#define ECHANTILLON_H

#include "../DataSource/dataSource.h"

#include <iostream>
#include <fstream>
using namespace std;

class Echantillon {
	private:
		DataSource* Source;
		
	public:
		
		//Constructeur Default
		Echantillon();
		
		//Constructeur Init
		Echantillon( DataSource* data);
		
		//Constructeur Copie
		Echantillon(const Echantillon &e);
		
		//Deconstructeur	
		~Echantillon();
		
		
		//GETTER SETTER
		DataSource* getSource() const;
		void setSource( DataSource* data);
		void setSource(const DataSource data);
		
		//OPPERATOR SURCHARGE
	    Echantillon& operator=(const Echantillon& t2);

	    friend bool operator==(const Echantillon& t1, const Echantillon& t2);

     	friend std::ostream& operator<<(std::ostream& s, const Echantillon& t1);
};
#endif
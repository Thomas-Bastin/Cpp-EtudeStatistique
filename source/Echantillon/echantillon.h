#ifndef ECHANTILLON_H
#define ECHANTILLON_H

#include "../debug.h"

#include "../DataSource/dataSource.h"
#include "../Data/data1D.h"
#include "../Liste_Template/Iterateur.h"
#include "../Liste_Template/Liste.h"

#include "../DataSource/DataSourceSerieDiscrete/dataSourceSerieDiscrete.h"
#include "../DataSource/DataSourceSerieContinue/dataSourceSerieContinue.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <list>
#include <exception>
#include <regex>

using namespace std;

class Echantillon {
	private:
		DataSource* Source;

	public:
		
		//Constructeur Default
		Echantillon();
		
		//Constructeur Init
		Echantillon( string filePath, int col);
		Echantillon( DataSource* data);
		
		//Constructeur Copie
		Echantillon(const Echantillon &e);
		
		//Deconstructeur	
		~Echantillon();
		
		
		//GETTER SETTER
		DataSource* getSource() const;
		void setSource( DataSource* data);
		//void setSource(const DataSource data);
		//void setSource(const DataSource data);
		
		//OPPERATOR SURCHARGE
	    Echantillon& operator=(const Echantillon& t2);

	    friend bool operator==(const Echantillon& t1, const Echantillon& t2);

     	friend std::ostream& operator<<(std::ostream& s, const Echantillon& t1);
};
#endif
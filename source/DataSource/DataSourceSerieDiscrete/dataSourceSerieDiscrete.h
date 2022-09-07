#ifndef DATASOURCESERIEDISCRETE_H
#define DATASOURCESERIEDISCRETE_H

#include "../../debug.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>

#include "../../Liste_Template/Liste.h"
#include "../../Liste_Template/Iterateur.h"
#include "../../Liste_Template/ListeTriee.h"

#include "../dataSource.h"
#include "../../Data/data1D.h"

using namespace std;

class DataSourceSerieDiscrete : public DataSource {
	private:
        Liste<Data1D> L;
		
	public:
		//Constructeur Default
		DataSourceSerieDiscrete();
		
		//Constructeur Init
        DataSourceSerieDiscrete(const Liste<Data1D> &L);
		DataSourceSerieDiscrete(string nom, string sujet, string type);
		DataSourceSerieDiscrete(string nom, string sujet, string type,const Liste<Data1D> &L);
		
		//Constructeur Copie
		DataSourceSerieDiscrete(const DataSourceSerieDiscrete &e);
		
		//Deconstructeur	
		~DataSourceSerieDiscrete();
		
		
		//GETTER SETTER
        Liste<Data1D> getListe() const;
        void setListe(const Liste<Data1D> &l);

		//OPPERATOR SURCHARGE
	    DataSourceSerieDiscrete& operator=(const DataSourceSerieDiscrete& t2);

     	friend std::ostream& operator<<(std::ostream& s, const DataSourceSerieDiscrete& t1);

        //MY Methods:
        void refreshEffectifTotal();
		void AfficheData();
		float getMedianne();
		float getMax() const;
		float getMin() const;
		float getMoyenne() const;
		float getEcartType();
		string getMode();
};
#endif
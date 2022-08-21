#ifndef DATASOURCESERIEDISCRETE_H
#define DATASOURCESERIEDISCRETE_H

#include <iostream>
#include <fstream>
#include <string>
#include "../../Liste_Template/Liste.h"
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
		DataSourceSerieDiscrete(string Nom, string Sujet, int Type,const Liste<Data1D> &L);
		
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
};
#endif
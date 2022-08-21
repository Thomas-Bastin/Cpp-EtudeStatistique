#ifndef DATASOURCESERIECONTINUE_H
#define DATASOURCESERIECONTINUE_H

#include <iostream>
#include <fstream>
#include <string>
#include "../../Liste_Template/Liste.h"
#include "../dataSource.h"
#include "../../Data/data1D.h"

using namespace std;

class DataSourceSerieContinue : public DataSource {
	private:
        Liste<Data1D> L;
		float Debut;
		float Intervalle;

	public:
		//Constructeur Default
		DataSourceSerieContinue();
		
		//Constructeur Init
        DataSourceSerieContinue(const Liste<Data1D> &L);
		DataSourceSerieContinue(string nom, string sujet, int type, float debut, float intervalle, const Liste<Data1D> &l);
		
		//Constructeur Copie
		DataSourceSerieContinue(const DataSourceSerieContinue &e);
		
		//Deconstructeur	
		~DataSourceSerieContinue();
		
		
		//GETTER SETTER
        Liste<Data1D> getListe() const;
        void setListe(const Liste<Data1D> &l);

		float getDebut() const;
		void setDebut(const float debut);

		float getIntervalle() const;
		void setIntervalle(const float intervalle);

		//OPPERATOR SURCHARGE
	    DataSourceSerieContinue& operator=(const DataSourceSerieContinue& t2);

     	friend std::ostream& operator<<(std::ostream& s, const DataSourceSerieContinue& t1);
};
#endif
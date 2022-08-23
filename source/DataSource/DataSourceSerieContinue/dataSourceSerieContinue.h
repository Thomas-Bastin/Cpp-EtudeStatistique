#ifndef DATASOURCESERIECONTINUE_H
#define DATASOURCESERIECONTINUE_H

#include "../../debug.h"

#include <iostream>
#include <fstream>
#include <string>
#include "../../Liste_Template/Liste.h"
#include "../../Liste_Template/Iterateur.h"
#include "../../Liste_Template/ListeTriee.h"

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
		DataSourceSerieContinue(string nom, string sujet, string type, const Liste<Data1D> &l);
		DataSourceSerieContinue(string nom, string sujet, string type, float debut, float intervalle, const Liste<Data1D> &l);
		
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

		//MY Methods:
        void refreshEffectifTotal();
		void AfficheData();	
		float getMedianne() const;
		float getMax() const;
		float getMin() const;
		float getMoyenne() const;
};
#endif
#ifndef ETUDESTAT1D_H
#define ETUDESTAT1D_H
#include "../debug.h"

#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <typeinfo>
#include <math.h>
#include <exception>

#include "../Data/data1D.h"
#include "../Liste_Template/Iterateur.h"
#include "../Liste_Template/Liste.h"
#include "../Liste_Template/ListeTriee.h"

#include "../DataSource/DataSourceSerieDiscrete/dataSourceSerieDiscrete.h"
#include "../DataSource/DataSourceSerieContinue/dataSourceSerieContinue.h"
#include "../Echantillon/echantillon.h"

using namespace std;

class EtudeStat1D {
	private:
        Echantillon* Echant;

        float Moyenne;
        float EcartType;
        float Mediane;
        Liste<float> Mode;
        float CoefVar;

        float Etendue;
        float ValMax;
        float ValMin;
        
	public:
		//Constructeur Default
		EtudeStat1D();
		
		//Constructeur Init
        EtudeStat1D(Echantillon* echant);
        EtudeStat1D(string filePath, int colNumber);
		
		//Constructeur Copie
		EtudeStat1D( EtudeStat1D &e);
		
		//Deconstructeur	
	    ~EtudeStat1D();
		
		
		//GETTER SETTER
        Echantillon* getEchantillon();
        void setEchantillon(Echantillon *echant);

        float getMoyenne() const;
        void setMoyenne(const float moyenne);

        float getEcartType() const;
        void setEcartType(const float ecartype);

        float getMediane() const;
        void setMediane(const float Mediane);

        float getCoefVar() const;
        void setCoefVar(const float coefvar);

        float getEtendue() const;
        void setEtendue(const float etendue);

        float getValMax() const;
        void setValMax(const float valmax);

        float getValMin() const;
        void setValMin(const float valmin);

        Liste<float> getMode() const;
        void setMode(const Liste<float> &l);

     	friend std::ostream& operator<<(std::ostream& s, const EtudeStat1D& t1);

        //MY Methods:
        int calculMoyenne();
        int calculEcartType();
        int calculMediane();
        int calculMode();
        int calculCoefVar();
        int calculEtendue();
        int calculValMax();
        int calculValMin();
        string controleQualitee();

        void AfficheRapport();
};
#endif
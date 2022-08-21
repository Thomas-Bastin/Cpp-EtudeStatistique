#include "dataSourceSerieContinue.h"

///////////////////////// Constructeurs: ///////////////////////////////
	DataSourceSerieContinue::DataSourceSerieContinue() : DataSource(){
        setListe(Liste<Data1D>());
        setDebut(-1);
        setIntervalle(-1);
        setEffectifTotal(0);
	}


    DataSourceSerieContinue::DataSourceSerieContinue(const Liste<Data1D> &l) : DataSource(){
        setListe(l);
        setDebut(-1);
        setIntervalle(-1);
        setEffectifTotal(l.getNombreElements());
    }


	DataSourceSerieContinue::DataSourceSerieContinue(string nom, string sujet, int type, float debut, float intervalle, const Liste<Data1D> &l) : DataSource( nom, sujet, type){
        setListe(l);
        setDebut(debut);
        setIntervalle(intervalle);
        setEffectifTotal(l.getNombreElements());
	}


	DataSourceSerieContinue::DataSourceSerieContinue(const DataSourceSerieContinue &e) : DataSource(e){ //Constructeur de copie
		setListe(e.getListe());
        setDebut(e.getDebut());
        setIntervalle(e.getIntervalle());
        setEffectifTotal(e.getListe().getNombreElements());
    }


	DataSourceSerieContinue::~DataSourceSerieContinue(){}


///////////////////////// Getters and Setters: ///////////////////////////////
    Liste<Data1D> DataSourceSerieContinue::getListe() const{
        return L;
    }

    void DataSourceSerieContinue::setListe(const Liste<Data1D> &l){
        L = l;
    }

    float DataSourceSerieContinue::getDebut() const{
        return Debut;
    }

	void DataSourceSerieContinue::setDebut(const float debut){
        Debut = debut;
    }

	float DataSourceSerieContinue::getIntervalle() const{
        return Intervalle;
    }

	void DataSourceSerieContinue::setIntervalle(const float intervalle){
        Intervalle = intervalle;
    }


///////////////////////// Surchage Oppérateur: ///////////////////////////////
	//=
	DataSourceSerieContinue& DataSourceSerieContinue::operator=(const DataSourceSerieContinue& e){
        DataSource::operator=(e);
  		setListe(e.getListe());
        setDebut(e.getDebut());
        setIntervalle(e.getIntervalle());
	    return *this;
	}

	//<<
    std::ostream& operator<<(std::ostream& s, const DataSourceSerieContinue& t1){
     	s << "( Nom: " << t1.getNom() << ", Sujet: " << t1.getSujet() << ", Type: " << t1.getType() << ", Effectif Total: " << t1.getEffectifTotal() << " )";
     	return (s);
    }
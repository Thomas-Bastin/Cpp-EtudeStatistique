#include "dataSourceSerieDiscrete.h"

///////////////////////// Constructeurs: ///////////////////////////////
	DataSourceSerieDiscrete::DataSourceSerieDiscrete() : DataSource(){
        setListe(Liste<Data1D>());
	}


    DataSourceSerieDiscrete::DataSourceSerieDiscrete(const Liste<Data1D> &l) : DataSource(){
        setListe(l);
    }


	DataSourceSerieDiscrete::DataSourceSerieDiscrete(string nom, string sujet, int type, const Liste<Data1D> &l) : DataSource( nom, sujet, type){
        setListe(l);
	}


	DataSourceSerieDiscrete::DataSourceSerieDiscrete(const DataSourceSerieDiscrete &e) : DataSource(e){ //Constructeur de copie
		setListe(e.getListe());
    }


	DataSourceSerieDiscrete::~DataSourceSerieDiscrete(){}


///////////////////////// Getters and Setters: ///////////////////////////////
    Liste<Data1D> DataSourceSerieDiscrete::getListe() const{
        return L;
    }

    void DataSourceSerieDiscrete::setListe(const Liste<Data1D> &l){
        L = l;
        refreshEffectifTotal();
    }

///////////////////////// Surchage Oppérateur: ///////////////////////////////
	//=
	DataSourceSerieDiscrete& DataSourceSerieDiscrete::operator=(const DataSourceSerieDiscrete& e){
        DataSource::operator=(e);
  		setListe(e.getListe());
        setEffectifTotal(e.getListe().getNombreElements());
	    
        return *this;
	}

	//<<
    std::ostream& operator<<(std::ostream& s, const DataSourceSerieDiscrete& t1){
     	s << "( Nom: " << t1.getNom() << ", Sujet: " << t1.getSujet() << ", Type: " << t1.getType() << ", Effectif Total: " << t1.getEffectifTotal() << " )";
     	return (s);
    }

///////////////////////// My Methods: ///////////////////////////////
    void DataSourceSerieDiscrete::refreshEffectifTotal(){
        setEffectifTotal(getListe().getNombreElements());
    }
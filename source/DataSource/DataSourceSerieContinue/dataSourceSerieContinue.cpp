#include "dataSourceSerieContinue.h"

///////////////////////// Constructeurs: ///////////////////////////////
	DataSourceSerieContinue::DataSourceSerieContinue() : DataSource(){
        setListe(Liste<Data1D>());
        setDebut(-1);
        setIntervalle(-1);
	}


    DataSourceSerieContinue::DataSourceSerieContinue(const Liste<Data1D> &l) : DataSource(){
        setListe(l);
        setDebut(-1);
        setIntervalle(-1);
    }

    DataSourceSerieContinue::DataSourceSerieContinue(string nom, string sujet, string type, const Liste<Data1D> &l) : DataSource( nom, sujet, type){
        setListe(l);
        setDebut(-1);
        setIntervalle(-1);
	}

	DataSourceSerieContinue::DataSourceSerieContinue(string nom, string sujet, string type, float debut, float intervalle, const Liste<Data1D> &l) : DataSource( nom, sujet, type){
        setListe(l);
        setDebut(debut);
        setIntervalle(intervalle);
	}


	DataSourceSerieContinue::DataSourceSerieContinue(const DataSourceSerieContinue &e) : DataSource(e){ //Constructeur de copie
		setListe(e.getListe());
        setDebut(e.getDebut());
        setIntervalle(e.getIntervalle());
    }


	DataSourceSerieContinue::~DataSourceSerieContinue(){}


///////////////////////// Getters and Setters: ///////////////////////////////
    Liste<Data1D> DataSourceSerieContinue::getListe() const{
        return L;
    }

    void DataSourceSerieContinue::setListe(const Liste<Data1D> &l){
        L = l;
        refreshEffectifTotal();
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
     	s << "( Nom: " << t1.getNom() << ", Sujet: " << t1.getSujet() << ", Type: " << t1.getType() << ", Effectif Total: " << t1.getEffectifTotal() << ", Debut:" << t1.getDebut() << ", Intervalle" << t1.getIntervalle() << " )";
     	return (s);
    }

///////////////////////// My Methods: ///////////////////////////////
    void DataSourceSerieContinue::refreshEffectifTotal(){
        if(!getListe().estVide()){

            Iterateur<Data1D> iter(L);
            
            int i;
            int EffectifTotal = 0;
            for(i = 0, iter.reset() ; !iter.end() ; iter++, i++){
                Data1D data = (Data1D)iter;

                if(i == 0){
                    EffectifTotal = data.getEffectif();
                }
                else{
                    EffectifTotal += data.getEffectif();
                }
            }
            setEffectifTotal(float (EffectifTotal));
        }
    }

    void DataSourceSerieContinue::AfficheData(){
        Iterateur<Data1D> iter(L);
        int i;

        for(i = 0, iter.reset() ; !iter.end() ; iter++, i++){
            Data1D tmp = (Data1D)iter;
            std::cout << "|   [" << i << "] = " << tmp << "\t\t\t        " << endl;
        }
    }

    float DataSourceSerieContinue::getMedianne() const{
        throw "TODO (float DataSourceSerieContinue::getMedianne() const;)";
    }
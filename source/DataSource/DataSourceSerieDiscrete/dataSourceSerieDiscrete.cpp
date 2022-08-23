#include "dataSourceSerieDiscrete.h"

///////////////////////// Constructeurs: ///////////////////////////////
	DataSourceSerieDiscrete::DataSourceSerieDiscrete() : DataSource(){
        setListe(Liste<Data1D>());
	}


    DataSourceSerieDiscrete::DataSourceSerieDiscrete(const Liste<Data1D> &l) : DataSource(){
        setListe(l);
    }

    DataSourceSerieDiscrete::DataSourceSerieDiscrete(string nom, string sujet, string type) : DataSource( nom, sujet, type){
        setListe(Liste<Data1D>());
	}

	DataSourceSerieDiscrete::DataSourceSerieDiscrete(string nom, string sujet, string type, const Liste<Data1D> &l) : DataSource( nom, sujet, type){
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

    void DataSourceSerieDiscrete::AfficheData(){
        Iterateur<Data1D> iter(L);
        int i;

        for(i = 0, iter.reset() ; !iter.end() ; iter++, i++){
            Data1D tmp = (Data1D)iter;
            std::cout << "|   [" << i << "] = " << tmp << "\t\t\t        " << endl;
        }
    }

    float DataSourceSerieDiscrete::getMedianne() const{
        Liste<Data1D> tmp = getListe();
        Iterateur<Data1D> iter(tmp);
        int i;

        int n = getListe().getNombreElements();
        int iMillieux1 = -1, iMillieux2 = -1;
        float valMillieux1, valMillieux2;

        if(n%2 != 0){
            iMillieux1 = (n)/2;
        }
        else{
            iMillieux1 = (n-1)/2;
            iMillieux2 =  n/2;
        }

        #ifdef DEBUG
            cout << "iMillieux1: " << iMillieux1 << ", iMillieux2: " << iMillieux2 << endl;
            cout << "ValMillieux1: " << valMillieux1 << ", ValMillieux2: " << valMillieux2 << endl;
        #endif

        for(i = 0, iter.reset() ; !iter.end() ; iter++, i++){
            Data1D tmp = (Data1D)iter;
            if(i == iMillieux1){
                valMillieux1 = tmp.getValeur();
            }

            if(i == iMillieux2){
                valMillieux2 = tmp.getValeur();
            }
        }


        if(iMillieux2 == -1){
            //Discrete Impaire
            return valMillieux1;
        }

        //Discrete Paire
        return (valMillieux1 + valMillieux2) / 2;
    }
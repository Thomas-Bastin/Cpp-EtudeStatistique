#include "dataSourceSerieDiscrete.h"

///////////////////////// Constructeurs: ///////////////////////////////
	DataSourceSerieDiscrete::DataSourceSerieDiscrete() : DataSource(){
        #ifdef DEBUG
		cout << "DataSourceDiscrete: Passage Constructeurs par Defaut" << endl;
		#endif
        setListe(Liste<Data1D>());
	}


    DataSourceSerieDiscrete::DataSourceSerieDiscrete(const Liste<Data1D> &l) : DataSource(){
        #ifdef DEBUG
		cout << "DataSourceDiscrete: Passage Constructeurs par Init Liste" << endl;
		#endif
        setListe(l);
    }

    DataSourceSerieDiscrete::DataSourceSerieDiscrete(string nom, string sujet, string type) : DataSource( nom, sujet, type){
        #ifdef DEBUG
		cout << "DataSourceDiscrete: Passage Constructeurs par Init Liste2" << endl;
		#endif
        setListe(Liste<Data1D>());
	}

	DataSourceSerieDiscrete::DataSourceSerieDiscrete(string nom, string sujet, string type, const Liste<Data1D> &l) : DataSource( nom, sujet, type){
        #ifdef DEBUG
		cout << "DataSourceDiscrete: Passage Constructeurs par Init Complet" << endl;
		#endif
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

    string DataSourceSerieDiscrete::getMode(){
        
        Liste<float> listemodes = Liste<float>();
        Liste<Data1D> listedata = getListe();

        Iterateur<Data1D> iterdata(listedata);

        int i;
        float nMax;
        for(i=0, iterdata.reset() ; !iterdata.end() ; iterdata++, i++){
            Data1D tmp = (Data1D)iterdata;
            if(i==0){
                nMax = tmp.getEffectif();
            }
            else{
                if(nMax < tmp.getEffectif()){
                    nMax = tmp.getEffectif();
                }
            }
        }

        for(i=0, iterdata.reset() ; !iterdata.end() ; iterdata++, i++){
            Data1D tmp = (Data1D)iterdata;
            if(nMax == tmp.getEffectif()){
                listemodes.insere(tmp.getValeur());
            }
        }

        //Créer une string sur base de la listemodes
        string s = "";
        std::ostringstream buffer;

        Iterateur<float> iter(listemodes);
        for(iter.reset(), i = 0 ; !iter.end() ; iter++, i++){
            float tmp = (float)iter;

            if(i == listemodes.getNombreElements()-1){
                
                buffer << tmp;
            }
            else{
                buffer << tmp << " : ";
            }
        }

        s = buffer.str();

        return s;
    }


    float DataSourceSerieDiscrete::getMedianne(){
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

    float DataSourceSerieDiscrete::getEcartType()
    {
        float ecartType;
        Liste<Data1D> tmp;
        tmp = getListe();
        Iterateur<Data1D> iter(tmp);
        int i;
        
        double Somme = 0;
        double PowSomme = 0;
        int EffectifTotal = getEffectifTotal();

        for(i = 0, iter.reset() ; !iter.end() ; iter++, i++){
            Data1D data = (Data1D)iter;

            if(i == 0){
                PowSomme = pow(data.getValeur(),2)*data.getEffectif();
                Somme = (data.getValeur()*data.getEffectif());
            }
            else{
                PowSomme += pow(data.getValeur(),2)*data.getEffectif();
                Somme += (data.getValeur()*data.getEffectif());
            }
        }

        ecartType = sqrt( (PowSomme - ( ( (pow(Somme,2)) / EffectifTotal) )) / EffectifTotal); // Voir Page 6 2ème Formule
        return ecartType;
    }

    float DataSourceSerieDiscrete::getMax() const{
        Liste<Data1D> tmp;
        tmp = getListe();
        Iterateur<Data1D> iter(tmp);
        
        int i;
        double maxvalue;
        int EffectifTotal = getEffectifTotal();

        
        for(i = 0, iter.reset() ; !iter.end() ; iter++, i++){
            Data1D data = (Data1D)iter;

            if(i==0){
                maxvalue = data.getValeur();
            }
            else{
                if(maxvalue < data.getValeur()){
                    maxvalue = data.getValeur();
                }
            }
        }

        return(maxvalue);   
    }

	float DataSourceSerieDiscrete::getMin() const{
        Liste<Data1D> tmp;
        tmp = getListe();
        Iterateur<Data1D> iter(tmp);
        
        int i;
        double minvalue;
        int EffectifTotal = getEffectifTotal();

        
        for(i = 0, iter.reset() ; !iter.end() ; iter++, i++){
            Data1D data = (Data1D)iter;

            if(i==0){
                minvalue = data.getValeur();
            }
            else{
                if(minvalue > data.getValeur()){
                    minvalue = data.getValeur();
                }
            }
        }

        return(minvalue);
    }

    float DataSourceSerieDiscrete::getMoyenne() const{
        Liste<Data1D> tmp;
        tmp = getListe();
        Iterateur<Data1D> iter(tmp);
        int i;
        
        double Somme = 0;
        int EffectifTotal = getEffectifTotal();

        for(i = 0, iter.reset() ; !iter.end() ; iter++, i++){
            Data1D data = (Data1D)iter;

            if(i == 0){
                Somme = data.getValeur()*data.getEffectif();
            }
            else{
                Somme += data.getValeur()*data.getEffectif();
            }
        }
        return((Somme/EffectifTotal));
    }
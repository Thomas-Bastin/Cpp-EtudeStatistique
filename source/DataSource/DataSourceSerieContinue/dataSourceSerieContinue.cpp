#include "dataSourceSerieContinue.h"

///////////////////////// Constructeurs: ///////////////////////////////
	DataSourceSerieContinue::DataSourceSerieContinue() : DataSource(){
        setListe(Liste<Data1D>());
        setDebut(-1);
        setIntervalle(-1);
	}


    DataSourceSerieContinue::DataSourceSerieContinue(const Liste<Data1D> &l) : DataSource(){
        #ifdef DEBUG
		cout << "DataSourceContinue: Passage Constructeurs par Init Liste" << endl;
		#endif

        setListe(l);
        setDebut(-1);
        setIntervalle(-1);
    }

    DataSourceSerieContinue::DataSourceSerieContinue(string nom, string sujet, string type, const Liste<Data1D> &l) : DataSource( nom, sujet, type){
        #ifdef DEBUG
		cout << "DataSourceContinue: Passage Constructeurs par Init Liste2" << endl;
		#endif
        setListe(l);
        setDebut(-1);
        setIntervalle(-1);
	}

	DataSourceSerieContinue::DataSourceSerieContinue(string nom, string sujet, string type, float debut, float intervalle, const Liste<Data1D> &l) : DataSource( nom, sujet, type){
        #ifdef DEBUG
		cout << "DataSourceContinue: Passage Constructeurs par Init Complet" << endl;
		#endif
        
        setListe(l);
        setDebut(debut);
        setIntervalle(intervalle);
	}


	DataSourceSerieContinue::DataSourceSerieContinue(const DataSourceSerieContinue &e) : DataSource(e){ //Constructeur de copie
        #ifdef DEBUG
		cout << "DataSourceContinue: Passage Constructeurs Copie" << endl;
		#endif

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
        float i;
        float interv = getIntervalle();

        for(i = 0, iter.reset() ; !iter.end() ; iter++){
            Data1D tmp = (Data1D)iter;
            i=(tmp.getValeur()*2);
            std::cout << "|   [" << i-interv << ", " << (i) << "[ :  " << tmp.getEffectif() << endl;
        }
    }

    float DataSourceSerieContinue::getMedianne() const{
        int n = getListe().getNombreElements();
        int i;
        int iMillieux1 = -1;
        int iMillieux2 = -1;
        Data1D valMillieux1;
        Data1D valMillieux2;
        Liste<Data1D> lis = L;
        Iterateur<Data1D> iter(lis);

        int EffCumul2;
        int EffCumul1;

        if(getListe().getNombreElements()%2 == 0){
            //Paire (moyennne des Interpol de 2 valeur)
            iMillieux1 = (n-1)/2;
            iMillieux2 =  n/2;

            EffCumul2 = 0;
            for(i = 0, iter.reset() ; !iter.end() ; iter++, i++){
                Data1D tmp = (Data1D)iter;
                EffCumul2 += tmp.getEffectif();
                if(EffCumul2 >= iMillieux2){
                    valMillieux2 = tmp;
                    break;
                }       
            }
        }
        else{
            //Impaire(Interpol 1 valeur)
            iMillieux1 = (n)/2;
        }

        EffCumul1 = 0;
        for(i = 0, iter.reset() ; !iter.end() ; iter++, i++){
            Data1D tmp = (Data1D)iter;
            EffCumul1 += tmp.getEffectif();
            if(EffCumul1 >= iMillieux1){
                valMillieux1 = tmp;
                break;
            }            
        }

        
        float solution = -1;
        float solution1;
        float solution2;
        float etend1;
        float intervPos1;
        float div1;

        float etend2;
        float intervPos2;
        float div2;



        if(getListe().getNombreElements()%2 == 0){
            cout << valMillieux1 << endl;
            cout << valMillieux2 << endl;

            etend1 = ((valMillieux1.getValeur()*2) + getIntervalle() )-((valMillieux1.getValeur()*2));
            intervPos1 = (getEffectifTotal()/2)-EffCumul1;
            div1 = ((valMillieux1.getValeur()*2) + getIntervalle());
            solution1 = (valMillieux2.getValeur()*2) + ((etend1/div1) * intervPos1);


            etend2 = ((valMillieux2.getValeur()*2) + getIntervalle() )-((valMillieux2.getValeur()*2));
            intervPos2 = (getEffectifTotal()/2)-EffCumul2;
            div2 = ((valMillieux2.getValeur()*2) + getIntervalle());
            solution2 = (valMillieux2.getValeur()*2) + ((etend2/div2) * intervPos2);

            solution = (solution1 + solution2 )/2;
        }
        else{
            cout << valMillieux1 << endl;
            float etend = ((valMillieux1.getValeur()*2) + getIntervalle() )-((valMillieux1.getValeur()*2));
            float intervPos = (getEffectifTotal()/2)-EffCumul1;
            float div = ((valMillieux1.getValeur()*2) + getIntervalle());

            cout << etend << ", " << intervPos << ", " << div << ", n: " << (valMillieux1.getValeur()*2) << ", n+1: "<< (valMillieux1.getValeur()*2+getIntervalle()) <<endl;
            
            solution = (valMillieux1.getValeur()*2) + ((etend/div) * intervPos);
            
        }
        return solution;
    }

    float DataSourceSerieContinue::getMax() const{
        float Max;
        Liste<Data1D> lis = L;
        Iterateur<Data1D> iter(lis);
        float i;
        float interv = getIntervalle();

        for(i = getDebut(), iter.reset() ; !iter.end() ; iter++){
            Data1D tmp = (Data1D)iter;
            i=tmp.getValeur()*2;
        }
        Max=i;
        return Max;
    }
	float DataSourceSerieContinue::getMin() const{
        float Min;
        Min = getDebut();
        return Min;
    }

    float DataSourceSerieContinue::getMoyenne() const{
        Liste<Data1D> t;
        t = getListe();
        Iterateur<Data1D> iter(t);
        int i;
        
        double Somme = 0;
        int EffectifTotal = getListe().getNombreElements();

        for(i = 0, iter.reset() ; !iter.end() ; iter++, i++){
            Data1D data = (Data1D)iter;

            if(i == 0){
                Somme = data.getValeur();
            }
            else{
                Somme += data.getValeur();
            }
        }
        return((Somme/EffectifTotal));
    }
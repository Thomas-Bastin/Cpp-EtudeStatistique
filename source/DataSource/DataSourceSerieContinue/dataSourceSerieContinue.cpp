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

	DataSourceSerieContinue::DataSourceSerieContinue(string nom, string sujet, string type, float debut, float intervalle, float fin, const Liste<Data1D> &l) : DataSource( nom, sujet, type){
        #ifdef DEBUG
		cout << "DataSourceContinue: Passage Constructeurs par Init Complet" << endl;
		#endif
        
        setListe(l);
        setDebut(debut);
        setFin(fin);
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

    float DataSourceSerieContinue::getFin() const{
        return Fin;
    }

	void DataSourceSerieContinue::setDebut(const float debut){
        Debut = debut;
    }

    void DataSourceSerieContinue::setFin(const float fin){
        Fin = fin;
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
        for(iter.reset() ; !iter.end() ; iter++){
            Data1D tmp = (Data1D)iter;
            std::cout << "|   [" << tmp.getValeur() << "; " << (tmp.getValeur() + getIntervalle()) << "[ :  " << tmp.getEffectif() << endl;
        }
    }

    string DataSourceSerieContinue::getMode(){
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
                
                buffer <<"["<< tmp<<"; "<< tmp+getIntervalle() <<"[";
            }
            else{
                buffer <<"["<< tmp<<"; "<< tmp+getIntervalle() <<"[" << " : ";
            }
        }

        s = buffer.str();

        return s;
    }

    float DataSourceSerieContinue::getEcartType()
    {
        float ecartType;
        Liste<Data1D> tmp;
        tmp = getListe();
        Iterateur<Data1D> iter(tmp);
        int i;
        
        double Somme = 0;
        double PowSomme = 0;
        int EffectifTotal = getEffectifTotal();
        double interdiv2 = getIntervalle()/2;

        for(i = 0, iter.reset() ; !iter.end() ; iter++, i++){
            Data1D data = (Data1D)iter;

            if(i == 0){
                PowSomme = pow((data.getValeur()+interdiv2),2)*data.getEffectif();
                Somme = ((data.getValeur()+interdiv2)*data.getEffectif());
            }
            else{
                PowSomme += pow((data.getValeur()+interdiv2),2)*data.getEffectif();
                Somme += ((data.getValeur()+interdiv2)*data.getEffectif());
            }
        }

        ecartType = sqrt( (PowSomme - ( ( (pow(Somme,2)) / EffectifTotal) )) / EffectifTotal); // Voir Page 6 2ème Formule
        return ecartType;
    }

    float DataSourceSerieContinue::getMedianne(){

        Liste<Data1D> lis = L;
        Iterateur<Data1D> iter(lis);

        int efftotdiv2 = getEffectifTotal() / 2;
        double mediane;
        Data1D elemA;
        Data1D elemB;

        cout << "EffTot " << getEffectifTotal()<<endl;

        if(getEffectifTotal()%2 == 0){
            //Pair
            //Mediane == (EffTotDiv).Val + (EffTotDiv+1).Val /2

            float med1;
            float med2;

            iter.reset();
            Data1D tmp = (Data1D) iter;
            int effcum = 0;
            for(iter.reset() ; !iter.end() ; iter++){
                elemA = tmp;
                tmp = (Data1D) iter;
                effcum+=tmp.getEffectif();
                
                if(effcum >= efftotdiv2){
                    elemB = tmp;
                    break;
                }
            }
            med1 = calculMed(elemB.getValeur(), (effcum - elemB.getEffectif()), (elemB.getValeur()+getIntervalle()),effcum, (efftotdiv2));


            effcum = 0;
            iter.reset();
            tmp = (Data1D) iter;
            for(iter.reset() ; !iter.end() ; iter++){
                elemA = tmp;
                tmp = (Data1D) iter;
                effcum+=tmp.getEffectif();
                
                if(effcum >= (efftotdiv2+1)){
                    elemB = tmp;
                    break;
                }
            }
            med2 = calculMed(elemB.getValeur(), (effcum - elemB.getEffectif()), (elemB.getValeur()+getIntervalle()),effcum, (efftotdiv2+1.0));

            mediane = (med1 + med2) / 2;
        }
        else{
            //Impair
            //Median ==(EffTotDiv).Val
            Data1D tmp;
            int effcum = 0;
            for(iter.reset() ; !iter.end() ; iter++){
                elemA = tmp;
                tmp = (Data1D) iter;
                effcum+=tmp.getEffectif();
                
                if(effcum >= efftotdiv2+1){
                    elemB = tmp;
                    break;
                }
            }
            mediane = calculMed(elemB.getValeur(), (effcum - elemB.getEffectif()), (elemB.getValeur()+getIntervalle()),effcum, (efftotdiv2));
        }

        return mediane;
    }

    float DataSourceSerieContinue::calculMed(double begInter, double begEffCum, double endInter, double endEffCum, double efftotdiv2){
        cout << begInter << ", " << begEffCum << ", " << endInter << ", " <<endEffCum << ", " << efftotdiv2 << endl;
        //Début Interval
        double mediane;

        //Formule utilisée (Interpol Linéaire)
        //https://homeomath2.imingo.net/mediane.htm
        double repartitionuniforme = (double)(endInter - begInter) / (double)(endEffCum - begEffCum);
        double posInter = efftotdiv2 - begEffCum;
        cout << "repartitionunif: " << repartitionuniforme << ", positionInter: " << posInter << endl;
        mediane = begInter + (repartitionuniforme * posInter);

        return(float) mediane;
    }

    float DataSourceSerieContinue::getMax() const{
        float Max;
        Max = getFin();
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
        double centrexi = 0;

        for(i = 0, iter.reset() ; !iter.end() ; iter++, i++){
            Data1D data = (Data1D)iter;

            if(i == 0){
                centrexi = (data.getValeur() + (data.getValeur()+getIntervalle()) ) / 2;
                Somme = centrexi* data.getEffectif();
            }
            else{
                centrexi = (data.getValeur()+(data.getValeur()+getIntervalle())) / 2;
                Somme += centrexi* data.getEffectif();
            }
        }
        return((Somme/getEffectifTotal()));
    }
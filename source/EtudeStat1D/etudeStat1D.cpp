#include "etudeStat1D.h"

///////////////////////// Constructeurs: ///////////////////////////////

    //Constructeur Default
    EtudeStat1D::EtudeStat1D(){
        #ifdef DEBUG
		cout << "EtudeStat1D: Passage Constructeurs par Defaut" << endl;
		#endif

        Echant = NULL;
        Moyenne = 0;
        EcartType = 0;
        Mediane = 0;
        Mode = "";
    }
	
    EtudeStat1D::EtudeStat1D(Echantillon* echant){
        Echant = NULL;
        setEchantillon(echant);
        #ifdef DEBUG
		cout << "EtudeStat1D: Passage Constructeurs par Init filePath" << endl;
		#endif

        //Calcul Moyenne:
        if(calculMoyenne() == -1){
            cout << "Erreur, pas d'échantillon"<<endl;
        }
        //Calcul EcartType:
        if(calculEcartType() == -1){
            cout << "Erreur, pas d'échantillon"<<endl;
        }

        //Calcul Mediane
        if(calculMediane() == -1){
            cout << "Erreur, pas d'échantillon"<<endl;
        }

        //Calcul Modes:
        if(calculMode() == -1){
            cout << "Erreur, pas d'échantillon"<<endl;
        }

        //Calcul Coef:
        if(calculCoefVar() == -1){
            cout << "Erreur, pas d'échantillon"<<endl;
        }

        //Calcul ValMax:
        if(calculValMax() == -1){
            cout << "Erreur, pas d'échantillon"<<endl;
        }

        //Calcul ValMin:
        if(calculValMin() == -1){
            cout << "Erreur, pas d'échantillon"<<endl;
        }

        //Calcul Etendue:
        if(calculEtendue() == -1){
            cout << "Erreur, pas d'échantillon"<<endl;
        }
    }

	//Constructeur Init
    EtudeStat1D::EtudeStat1D(string filePath, int colNumber){
        #ifdef DEBUG
		cout << "EtudeStat1D: Passage Constructeurs par Init filePath" << endl;
		#endif
        //Creation de l'échantillon
        try{
            setEchantillon(new Echantillon(filePath, colNumber));
        }
        catch(char const* e){
            throw e;
        }
        
        
        

        //Calcul ValMax:
        if(calculValMax() == -1){
            cout << "Erreur, pas d'échantillon"<<endl;
        }

        //Calcul ValMin:
        if(calculValMin() == -1){
            cout << "Erreur, pas d'échantillon"<<endl;
        }

        //Calcul Etendue:
        if(calculEtendue() == -1){
            cout << "Erreur, pas d'échantillon"<<endl;
        }

        //Calcul Moyenne:
        if(calculMoyenne() == -1){
            cout << "Erreur, pas d'échantillon"<<endl;
        }
        //Calcul EcartType:
        if(calculEcartType() == -1){
            cout << "Erreur, pas d'échantillon"<<endl;
        }

        //Calcul Mediane
        if(calculMediane() == -1){
            cout << "Erreur, pas d'échantillon"<<endl;
        }

        //Calcul Modes:
        if(calculMode() == -1){
            cout << "Erreur, pas d'échantillon"<<endl;
        }

        //Calcul Coef:
        if(calculCoefVar() == -1){
            cout << "Erreur, pas d'échantillon"<<endl;
        }
    }
		
	//Constructeur Copie
	EtudeStat1D::EtudeStat1D( EtudeStat1D &e){
        setEchantillon(new Echantillon(*( e.getEchantillon() )));

        //Calcul Moyenne:
        if(calculMoyenne() == -1){
            cout << "Erreur, pas d'échantillon"<<endl;
        }
        //Calcul EcartType:
        if(calculEcartType() == -1){
            cout << "Erreur, pas d'échantillon"<<endl;
        }

        //Calcul Modes:
        if(calculMode() == -1){
            cout << "Erreur, pas d'échantillon"<<endl;
        }

        //Calcul Coef:
        if(calculCoefVar() == -1){
            cout << "Erreur, pas d'échantillon"<<endl;
        }

        //Calcul ValMax:
        if(calculValMax() == -1){
            cout << "Erreur, pas d'échantillon"<<endl;
        }

        //Calcul ValMin:
        if(calculValMin() == -1){
            cout << "Erreur, pas d'échantillon"<<endl;
        }

        //Calcul Mediane
        if(calculMediane() == -1){
            cout << "Erreur, pas d'échantillon"<<endl;
        }

        //Calcul Etendue:
        if(calculEtendue() == -1){
            cout << "Erreur, pas d'échantillon"<<endl;
        }
    }


	EtudeStat1D::~EtudeStat1D(){
        if(Echant) delete Echant;
    }


///////////////////////// Getters and Setters: ///////////////////////////////
    Echantillon* EtudeStat1D::getEchantillon(){
        return Echant;
    }
    void EtudeStat1D::setEchantillon(Echantillon *echant){
        Echant = echant;
    }

    float EtudeStat1D::getMoyenne() const{
        return Moyenne;
    }
    void EtudeStat1D::setMoyenne(const float moyenne){
        Moyenne = moyenne;
    }

    float EtudeStat1D::getEcartType() const{
        return EcartType;
    }
    void EtudeStat1D::setEcartType(const float ecartype){
        EcartType = ecartype;
    }

    float EtudeStat1D::getMediane() const{
        return Mediane;
    }
    void EtudeStat1D::setMediane(const float mediane){
        Mediane = mediane;
    }

    float EtudeStat1D::getCoefVar() const{
        return CoefVar;
    }
    void EtudeStat1D::setCoefVar(const float coefvar){
        CoefVar = coefvar;
    }

    float EtudeStat1D::getEtendue() const{
        return Etendue;
    }
    void EtudeStat1D::setEtendue(const float etendue){
        Etendue = etendue;
    }

    float EtudeStat1D::getValMax() const{
        return ValMax;
    }
    void EtudeStat1D::setValMax(const float valmax){
        ValMax = valmax;
    }

    float EtudeStat1D::getValMin() const{
        return ValMin;
    }
    void EtudeStat1D::setValMin(const float valmin){
        ValMin = valmin;
    }

    string EtudeStat1D::getMode() const{
        return Mode;
    }
    void EtudeStat1D::setMode(string l){
        Mode = l;
    }

///////////////////////// Surchage Oppérateur: ///////////////////////////////

	//<<
    std::ostream& operator<<(std::ostream& s, const EtudeStat1D& t1){
     	s <<"( Echantillon: " << t1.Echant << ", Mediane: " << t1.Mediane << ", EcartType: " << t1.EcartType << ", Moyenne: " << t1.Moyenne << " )";
     	return (s);
    }

///////////////////////// My Methods: ///////////////////////////////
int EtudeStat1D::calculMoyenne(){
    if(getEchantillon()){

        setMoyenne(getEchantillon()->getSource()->getMoyenne());
        return 0;
    }
    return -1;
}

int EtudeStat1D::calculEcartType(){
    if(getEchantillon()){
        setEcartType(getEchantillon()->getSource()->getEcartType());
        return 0;

        #ifdef DEBUG
            Liste<Data1D> tmp2;
            tmp2 = getEchantillon()->getSource()->getListe();
            Iterateur<Data1D> iter2(tmp2);
            
            double Somme2 = 0;

            for(i = 0, iter2.reset() ; !iter2.end() ; iter2++, i++){
                Data1D data = (Data1D)iter2;

                if(i == 0){
                    Somme2 = pow(data.getValeur()-getMoyenne(),2)*data.getEffectif();
                }
                else{
                    Somme2 += pow(data.getValeur()-getMoyenne(),2)*data.getEffectif();
                }
            }
            double test = sqrt(Somme2/EffectifTotal);

            cout<<"EcartType TEST: "<< test << endl; // Voir Page 6 2ème Formule
        #endif        
    }
    return -1;
}

int EtudeStat1D::calculMediane(){
    if(getEchantillon()){
        setMediane(getEchantillon()->getSource()->getMedianne());
        return 0;
    }
    return -1;
}

int EtudeStat1D::calculMode(){
    setMode(getEchantillon()->getSource()->getMode());
    return 0;
}

int EtudeStat1D::calculCoefVar(){
    if(getEchantillon()){
        setCoefVar(getEcartType() / getMoyenne()*100);
        return 0;
    }
    return -1;
}

int EtudeStat1D::calculEtendue(){
    if(getEchantillon()){
        setEtendue(getValMax()-getValMin());
        return 0;
    }
    return -1;
}

int EtudeStat1D::calculValMax(){
    if(getEchantillon()){
        setValMax(getEchantillon()->getSource()->getMax());     
        return 0;
    }
    return -1;
}

int EtudeStat1D::calculValMin(){
    if(getEchantillon()){
        setValMin(getEchantillon()->getSource()->getMin());        
        return 0;
    }
    return -1;
}

string EtudeStat1D::controleQualitee(){
    if(getEchantillon() && getEcartType()){

        Liste<Data1D> tmp;
        tmp = getEchantillon()->getSource()->getListe();
        Iterateur<Data1D> iter(tmp);
        
        int i;
        bool isQuality = true;
        int EffectifTotal = getEchantillon()->getSource()->getEffectifTotal();

        for(i = 0, iter.reset() ; !iter.end() ; iter++, i++){
            Data1D data = (Data1D)iter;

            if(data.getValeur() < 2*getEcartType() && data.getValeur() > 2*getEcartType()){
                isQuality = false;
                break;
            }
        }
        if(isQuality == true) return "Processus sous contrôle";


        bool isCritical = true;
        for(i = 0, iter.reset() ; !iter.end() ; iter++, i++){
            Data1D data = (Data1D)iter;

            if(data.getValeur() < 3*getEcartType() && data.getValeur() > 3*getEcartType()){
                isCritical = false;
                break;
            }
        }
        if(isCritical == true) return "Processus hors contrôle";
        
        return "Processus Suspect"; 
    }
    return "Erreur de Programmation Critique ( ERROR EtudeStat::ControleQualite() )";
}



//Affichage Resultat
void EtudeStat1D::AfficheRapport(){
	cout << "|***********************************************************************" << endl;
	cout << "| "<< "\033[0;31m"<<"Etude Statistique à 1 Dimension:"<<"\033[0m"<<"    " << endl;
	cout << "| ---------------------                                                 " << endl;	
	cout << "|                                                                       " << endl;
	cout << "| Nom: "<< getEchantillon()->getSource()->getNom() << "\t\tSujet de l'étude: "<< getEchantillon()->getSource()->getSujet()<<"     "<< endl;
	cout << "| Type: "<< getEchantillon()->getSource()->getType() <<"                " << endl;
    cout << "|                                                                       " << endl;
	cout << "| ---------------------                                                 " << endl;
    cout << "| Données:                                                              " << endl;

    getEchantillon()->getSource()->AfficheData();
    cout << "| ---------------------                                                 " << endl;
    cout << "|                                                                       " << endl;
	cout << "| Effectif Total: "<< getEchantillon()->getSource()->getEffectifTotal() <<"" << endl;
    cout << "|                                                                       " << endl;
	cout << "| Moyenne: "<< getMoyenne() <<"                                         " << endl;
    cout << "| Médianne: "<< getMediane() <<"                                    " << endl;
    cout << "| Mode:\t" << getMode()<<endl;
    cout << "| EcartType: "<< getEcartType() <<"                                     " << endl;

	cout << endl;
	cout << "| Coefficient de Variation : " << getCoefVar() <<"%\t\t                      " << endl;
	cout << "| Controle de qualité: "<< controleQualitee() << endl;
    cout << "|                                                                       " << endl;
    cout << "| Etendue: " << getEtendue() << endl;
	cout << "| Valeur minimum: "<< getValMin() <<"\t\t\t\tValeur maximum: "<< getValMax() <<"" << endl;
    cout << "|                                                                       " << endl;
	cout << "|***********************************************************************" << endl;
}

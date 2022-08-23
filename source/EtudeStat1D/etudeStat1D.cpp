#include "etudeStat1D.h"

///////////////////////// Constructeurs: ///////////////////////////////

    //Constructeur Default
    EtudeStat1D::EtudeStat1D(){
        Echant = NULL;
        Moyenne = 0;
        EcartType = 0;
        Mediane = 0;
        Mode = Liste<float>();
    }
	
    EtudeStat1D::EtudeStat1D(Echantillon* echant){
        Echant = NULL;
        setEchantillon(echant);

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
        //Creation de l'échantillon
        try{
            setEchantillon(new Echantillon(filePath, colNumber));
        }
        catch(char const* e){
            throw e;
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


	EtudeStat1D::~EtudeStat1D(){
        if(Echant) delete Echant;
    }


///////////////////////// Getters and Setters: ///////////////////////////////
    Echantillon* EtudeStat1D::getEchantillon(){
        return Echant;
    }
    void EtudeStat1D::setEchantillon(Echantillon *echant){
        if(Echant) delete Echant;
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

    Liste<float> EtudeStat1D::getMode() const{
        return Mode;
    }
    void EtudeStat1D::setMode(const Liste<float>& l){
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

        Liste<Data1D> tmp;
        tmp = getEchantillon()->getSource()->getListe();
        Iterateur<Data1D> iter(tmp);
        int i;
        
        double Somme = 0;
        int EffectifTotal = getEchantillon()->getSource()->getEffectifTotal();

        for(i = 0, iter.reset() ; !iter.end() ; iter++, i++){
            Data1D data = (Data1D)iter;

            if(i == 0){
                Somme = data.getValeur()*data.getEffectif();
            }
            else{
                Somme += data.getValeur()*data.getEffectif();
            }
        }
        setMoyenne(float (Somme/EffectifTotal));
        return 0;
    }
    return -1;
}

int EtudeStat1D::calculEcartType(){
    if(getEchantillon()){

        Liste<Data1D> tmp;
        tmp = getEchantillon()->getSource()->getListe();
        Iterateur<Data1D> iter(tmp);
        int i;
        
        double Somme = 0;
        double PowSomme = 0;
        int EffectifTotal = getEchantillon()->getSource()->getEffectifTotal();

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

        setEcartType(   sqrt( (PowSomme - ( ( (pow(Somme,2)) / EffectifTotal) )) / EffectifTotal)   ); // Voir Page 6 2ème Formule
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
    if(getEchantillon()){
        Liste<float> listemodes = Liste<float>();
        Liste<Data1D> listedata = getEchantillon()->getSource()->getListe();

        Iterateur<Data1D> iterdata(listedata);

        int i;
        float nMax;
        for(i=0, iterdata.reset() ; !iterdata.end() ; iterdata++, i++){
            Data1D tmp = (Data1D)iterdata;
            if(i=0){
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

        setMode(listemodes);
        return 0;
    }
    return -1;
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
        Liste<Data1D> tmp;
        tmp = getEchantillon()->getSource()->getListe();
        Iterateur<Data1D> iter(tmp);
        
        int i;
        double maxvalue;
        int EffectifTotal = getEchantillon()->getSource()->getEffectifTotal();

        
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

        setValMax(maxvalue);        
        return 0;
    }
    return -1;
}

int EtudeStat1D::calculValMin(){
    if(getEchantillon()){
        Liste<Data1D> tmp;
        tmp = getEchantillon()->getSource()->getListe();
        Iterateur<Data1D> iter(tmp);
        
        int i;
        double minvalue;
        int EffectifTotal = getEchantillon()->getSource()->getEffectifTotal();

        
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

        setValMin(minvalue);        
        return 0;
    }
    return -1;
}

string EtudeStat1D::controleQualitee(){
    if(getEchantillon()){

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
    cout << "| EcartType: "<< getEcartType() <<"                                     " << endl;
    cout << "|                                                                       " << endl;
    cout << "| Médianne: "<< getMediane() <<"                                    " << endl;
    cout << "| Mode:\t";


    Liste<float> listetmp = Liste<float>(getMode());
    Iterateur<float> iter(listetmp);
    int i;
    for(iter.reset(), i = 0 ; !iter.end() ; iter++, i++){
        float tmp = (float)iter;

        if(i == listetmp.getNombreElements()-1){
            cout << tmp;
        }
        else{
            cout << tmp <<" : ";
        }
    }

	cout << endl;
	cout << "| Coefficient de Variation : " << getCoefVar() <<"%\t\t                      " << endl;
	cout << "| Controle de qualité: "<< controleQualitee() << endl;
    cout << "|                                                                       " << endl;
    cout << "| Etendue: " << getEtendue() << endl;
	cout << "| Valeur minimum: "<< getValMin() <<"\t\t\t\tValeur maximum: "<< getValMax() <<"" << endl;
    cout << "|                                                                       " << endl;
	cout << "|***********************************************************************" << endl;
}

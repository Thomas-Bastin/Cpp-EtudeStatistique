#include "data1D.h"

///////////////////////// Constructeurs: ///////////////////////////////
	Data1D::Data1D(){
		Val = -1;
		Eff = -1;

		#ifdef DEBUG
			cout << "data1D: Passage Constructeurs par défaut" << endl;
		#endif		
	}

	Data1D::Data1D(const float valeur, const int effectif){
		#ifdef DEBUG
			cout << "data1D: Passage Constructeurs Init" << endl;
		#endif	

		setValeur(valeur);
		setEffectif(effectif);
	}

	Data1D::Data1D(const Data1D &e){ //Constructeur de copie
		#ifdef DEBUG
		cout << "data1D: Passage Constructeurs par Copie" << endl;
		#endif	
		setValeur(e.getValeur());
	  	setEffectif(e.getEffectif());
    }

	Data1D::~Data1D(){}


///////////////////////// Getters and Setters: ///////////////////////////////
	float Data1D::getValeur() const{
		return Val;
	}
	void Data1D::setValeur(const float valeur){
		Val = valeur;
	}

	int Data1D::getEffectif() const{
		return Eff;
	}
	void Data1D::setEffectif(const int effectif){
		Eff = effectif;
	}


///////////////////////// Surchage Oppérateur: ///////////////////////////////
	//=
	Data1D& Data1D::operator=(const Data1D& t2){
  		setValeur(t2.getValeur());
	 	setEffectif(t2.getEffectif());
	    return *this;
	}

	//== 
    bool operator==(const Data1D& t1, const Data1D& t2){
     	if(t1.getValeur() == t2.getValeur()) 
     		return true;
     	
     	return false;
    }

    //< 
    bool operator<(const Data1D& t1, const Data1D& t2){
    	if(t1.getValeur() < t2.getValeur())	
    		return true;
    	
    	return false;
    }

    //>
    bool operator>(const Data1D& t1, const Data1D& t2){
     	if(t1.getValeur() > t2.getValeur())	
     		return true;

     	return false;
    }

	//<<
    std::ostream& operator<<(std::ostream& s, const Data1D& t1){
     	s <<"Valeur: "<<t1.getValeur()<<"\t Effectif: "<<t1.getEffectif();
     	return (s);
    }




///////////////////////// Flux Gestion Fichier: ///////////////////////////////
    //SAVE Data1D
    // void Data1D::Save(ofstream& fichier) const{
    // 	int size;
    //   	if(!fichier.is_open()){
    //     	cout << "Erreur d'ouverture"<<endl;
    //     	exit (1);
    //   	}

    //   	//ENREGISTREMENT PARTIE PLANIFIABLE
    //   	int ident = getId();
    //   	fichier.write((char*)&ident, sizeof(int)); //Identifiant Planifiable
        
    //   	//ENREGISTREMENT NUMERO Data1D
    //   	int num = numero;
    //   	fichier.write((char*)&num, sizeof(int));
    // }


    // //LOAD Data1D
    // void Data1D::Load(ifstream& fichier){
    // 	int size;
    //   	if(!fichier.is_open()){
    //     	cout << "erreur d'ouverture !"<< endl;
    //     	return;
    //   	}

    //   	//LECTURE PARTIE PLANIFIABLE
    //   	int ident;
    //   	fichier.read((char*)&ident, sizeof(int)); //Identifiant Planifiable
    //   	setId(ident);

    //   	//LECTURE NUMERO Data1D
    //   	int num;
    //   	fichier.read((char*)&num, sizeof(int));
    //   	setNumero(num);
    // }
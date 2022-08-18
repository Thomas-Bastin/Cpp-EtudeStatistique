#include "data2D.h"

///////////////////////// Constructeurs: ///////////////////////////////
	Data2D::Data2D(){
		Val = -1;
		Val2 = -1;
	}

	Data2D::Data2D(const float valeur, const float valeur2){
		setValeur(valeur);
		setValeur2(valeur2);
	}

	Data2D::Data2D(const Data2D &e){ //Constructeur de copie
		setValeur(e.getValeur());
	  	setValeur2(e.getValeur2());
    }

	Data2D::~Data2D(){}


///////////////////////// Getters and Setters: ///////////////////////////////
	float Data2D::getValeur() const{
		return Val;
	}
	void Data2D::setValeur(const float valeur){
		Val = valeur;
	}

	float Data2D::getValeur2() const{
		return Val2;
	}

	void Data2D::setValeur2(const float valeur){
		Val2 = valeur;
	}


///////////////////////// Surchage Oppérateur: ///////////////////////////////
	//=
	Data2D& Data2D::operator=(const Data2D& t2){
  		setValeur(t2.getValeur());
	 	setValeur2(t2.getValeur2());
	    return *this;
	}

	//== 
    bool operator==(const Data2D& t1, const Data2D& t2){
     	if(t1.getValeur() == t2.getValeur()) 
     		return true;

     	return false;
    }

    //< 
    bool operator<(const Data2D& t1, const Data2D& t2){
    	if(t1.getValeur() < t2.getValeur())	
    		return true;

    	return false;
    }

    //>
    bool operator>(const Data2D& t1, const Data2D& t2){
     	if(t1.getValeur() > t2.getValeur())	
     		return true;

     	return false;
    }

	//<<
    std::ostream& operator<<(std::ostream& s, const Data2D& t1){
     	s <<"Valeur: "<<t1.getValeur()<<"\t Valeur2: "<<t1.getValeur2();
     	return (s);
    }
#include "echantillon.h"

///////////////////////// Constructeurs: ///////////////////////////////
	Echantillon::Echantillon(){
		setSource(new DataSource());
	}

	Echantillon::Echantillon(DataSource* data){
		setSource(data);
	}

	Echantillon::Echantillon(const Echantillon &e){ //Constructeur de copie
		setSource(e.getSource());
    }

	Echantillon::~Echantillon(){
	}


///////////////////////// Getters and Setters: ///////////////////////////////
	DataSource* Echantillon::getSource() const{
        return Source;
    }
    
    void Echantillon::setSource( DataSource* data){
        Source = data;
    }


///////////////////////// Surchage Oppérateur: ///////////////////////////////
	//=
	Echantillon& Echantillon::operator=(const Echantillon& t2){
  		setSource(t2.getSource());
	    return *this;
	}

	//== 
    bool operator==(const Echantillon& t1, const Echantillon& t2){
        if(t1.getSource() == t2.getSource()) return true;
        return false;
    }

	//<<
    std::ostream& operator<<(std::ostream& s, const Echantillon& t1){
     	s << "Source: " << t1.getSource() << " = ( Nom: " << t1.getSource()->getNom() << ", Sujet: " << t1.getSource()->getSujet() << ", Type: " << t1.getSource()->getType() << ", Effectif Total: " << t1.getSource()->getEffectifTotal() << " )";
     	return (s);
    }
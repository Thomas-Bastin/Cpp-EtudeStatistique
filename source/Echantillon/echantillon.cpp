#include "echantillon.h"

///////////////////////// Constructeurs: ///////////////////////////////
	Echantillon::Echantillon(){
		Source = NULL;
	}

	Echantillon::Echantillon(DataSource* data){
		Source = NULL;
		setSource(data);
	}

	Echantillon::Echantillon(const Echantillon &e){ //Constructeur de copie
		Source = NULL;
		setSource(e.getSource());
    }

	Echantillon::~Echantillon(){
		if(Source) delete Source;
	}


///////////////////////// Getters and Setters: ///////////////////////////////
	DataSource* Echantillon::getSource() const{
        return Source;
    }
    
    void Echantillon::setSource( DataSource* data){
		if (Source == NULL || data == NULL) Source = data;
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
		if (t1.getSource() == NULL){
			s << "Source: NULL";
		}
		else{
			s << "Source: " << t1.getSource() << " = ( Nom: " << t1.getSource()->getNom() << ", Sujet: " << t1.getSource()->getSujet() << ", Type: " << t1.getSource()->getType() << ", Effectif Total: " << t1.getSource()->getEffectifTotal() << " )";
		}
     	return (s);
    }
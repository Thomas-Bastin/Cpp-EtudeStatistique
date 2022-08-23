#include "dataSource.h"

///////////////////////// Constructeurs: ///////////////////////////////
	DataSource::DataSource(){
		Nom = "-1";
        Sujet = "-1";
        Type = -1;
        EffTotal = -1;
	}

	DataSource::DataSource(string nom, string sujet, string type){
        setNom(nom);
        setSujet(sujet);
        setType(type);
        setEffectifTotal(-1);
	}

	DataSource::DataSource(const DataSource &e){ //Constructeur de copie
		setNom(e.getNom());
        setSujet(e.getSujet());
        setType(e.getType());
        setEffectifTotal(e.getEffectifTotal());
    }

	DataSource::~DataSource(){}


///////////////////////// Getters and Setters: ///////////////////////////////
    string DataSource::getNom() const{
        return Nom; 
    }

    void DataSource::setNom(const string name){
        Nom = name;
    }

    string DataSource::getSujet() const{
        return Sujet;
    }

    void DataSource::setSujet(const string sujet){
        Sujet = sujet;
    }
        
    int DataSource::getEffectifTotal() const{
        return EffTotal;
    }

    void DataSource::setEffectifTotal(const int efftotal){
        EffTotal = efftotal;
    }

    string DataSource::getType() const{
        return Type;
    }

	void DataSource::setType(const string type){
        Type = type;
    }

///////////////////////// Surchage Oppérateur: ///////////////////////////////
	//=
	DataSource& DataSource::operator=(const DataSource& e){
  		setNom(e.getNom());
        setSujet(e.getSujet());
        setType(e.getType());
        setEffectifTotal(e.getEffectifTotal());
	    return *this;
	}

	//== 
    bool operator==(const DataSource& t1, const DataSource& t2){
        if(
            t1.getNom() == t2.getNom() 
            && t1.getSujet() == t2.getSujet() 
            && t1.getType() == t2.getType() 
            && t1.getEffectifTotal() == t2.getEffectifTotal()
          ){
               return true;
           }
        return false;
    }

	//<<
    std::ostream& operator<<(std::ostream& s, const DataSource& t1){
     	s << "( Nom: " << t1.getNom() << ", Sujet: " << t1.getSujet() << ", Type: " << t1.getType() << ", Effectif Total: " << t1.getEffectifTotal() << " )";
     	return (s);
    }
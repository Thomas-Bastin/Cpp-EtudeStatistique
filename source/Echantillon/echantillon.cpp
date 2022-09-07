#include "echantillon.h"

///////////////////////// Constructeurs: ///////////////////////////////
	Echantillon::Echantillon(){
		Source = NULL;
	}

	Echantillon::Echantillon(string filePath, int col){
		#ifdef DEBUG
		cout << "Echantillon: Passage Constructeurs par Init filePath" << endl;
		#endif	

		int ColNumber = col;   // Indique soit que le fichier n'a qu'une seule colonne de données, soit le numéro de la colonne qui nous intéresse.
		int i;
		string name = "-1";
		string sujet = "-1";
		string type = "-1";

		char* tmpline;
		char* token;
		string line;

		ListeTriee<float> listeTrieeTmp;
		Liste<Data1D> liste;

		Iterateur<Data1D> iter(liste);
		Iterateur<float> itertmp(listeTrieeTmp);

		
		//Ouverture Fichier:
		ifstream input_file;
		input_file.open(filePath);
		if(!input_file.is_open()){
			throw "Erreur Ouverture Fichier (Chemin Inconnus)";
		}
		

		//Lecture de la ligne1 (Titre Fichier)
		getline(input_file, line);
		name = line;

		//Lecture de la ligne2 (Sujet Etude)
		getline(input_file, line);

		token = strtok((char*) line.c_str(),":");
		for(i = 1; token != NULL; i++){
			if(i > 1){
				token = strtok(NULL,":");
			}

			if(i == ColNumber){
				sujet = token;
				break;
			}
		}

		//Lecture de la ligne3 (Continue/Discrète)
		getline(input_file, line);

		token = strtok((char*) line.c_str(),":");

		for(i = 1; token != NULL; i++){
			if(i > 1){
				token = strtok(NULL,":");
			}

			if(i == ColNumber){
				type = token;
				break;
			}
		}

		if(name == "-1" || sujet == "-1" || type == "-1"){
			cout << name <<", " << sujet << ", "<<type<<endl << "Col: "<<ColNumber<<endl;
			throw "Colonne Indiquée innexistante";
		}


		//Lecture du reste des lignes jusqu'à la fin du fichier (pour créer la liste):
		string value;
		while(getline(input_file, line)){
		
			token = strtok((char*) line.c_str(), ":");
			for(int i = 1; token != NULL; i++){
				if(i>1){
					token = strtok(NULL,":");
				}
				if(i == ColNumber){
					try{
						string str = token;
						for (int i = 0; i < str.size(); i++) {
							if (str[i] == ',') {
								str[i] = '.';
							}
						}
						listeTrieeTmp.insere(stof(str));
					}
					catch(...){
						throw "Les donnée enregistrée ne sont pas composer que de nombre.";
					}
					break;
				}
			}
		}

		if(type == "c" || type == "C"){

			string col1;
			float intervalle;

			i = 0;
			cout << "|***********************************************************************|" << endl;
			cout << "  " << "\033[0;36m" << "Entré l'intervale de valeur:" << "\033[0m" << "" << endl;
			cout << "  "; cin >> col1; cin.get(); cout << endl;
			do{
				if(i>0){
					cout << "  " << "\033[0;36m" << "Entré un nombre valide (float positif)" << "\033[0m" << "" << endl;
					cout << "  "; cin >> col1; cin.get(); cout << endl;
				}
				
				i++;

				try{
					intervalle = stof(col1);
				}
				catch(...){
					continue;
				}
			}while(intervalle <= 0);

			
			//Rework: LA liste commence au début, ensuite on ajoute tout ce qui est plus petit que l'interval, 
			//Creation de la liste Vide:
			float maxval;
			itertmp.reset();
			for(int i ; !itertmp.end() ; i++, itertmp++){
				maxval = (float) itertmp;
			}
			
			itertmp.reset();
			const float DEBUT = (float)itertmp;

			for(float i = DEBUT ; i < maxval ; i+= intervalle ){
				Data1D tmp = Data1D(i,0);
				liste.insere(tmp);
			}

			//Insertion des éléments dans la liste (au bon endroit)
			itertmp.reset();
			while(!itertmp.end()){
				float valuetmp = (float)itertmp;

				iter.reset();
				while(!iter.end()){

					Data1D* tmp = iter.getRef();
					if( valuetmp >= tmp->getValeur() && valuetmp < (tmp->getValeur()+ intervalle) ){
						int count = tmp->getEffectif() + 1;
						tmp->setEffectif(count);
						break;
					}
					iter++;
				}
				itertmp++;
			}

			setSource(new DataSourceSerieContinue(name, sujet, "Continue", DEBUT, intervalle, maxval, liste));
		}
		else if (type == "d" || type == "D"){

			itertmp.reset();
			int count = 1;
			float valuecount = (float)itertmp;
			itertmp++;

			//Insertion dans la liste finale
			for(i = 1 ; !itertmp.end() ; itertmp++, i++){
				float valuetmp = (float)itertmp;

				if(valuetmp <= valuecount){
					count++;
				}
				else{
					Data1D tmp = Data1D(valuecount, count);
					liste.insere(tmp);

					valuecount = valuetmp;
					count = 1;
				}
			}
			Data1D tmp2 = Data1D(valuecount, count);
			liste.insere(tmp2);
			
			setSource(new DataSourceSerieDiscrete(name, sujet, "Discret", liste));
		}
		else{
			throw "Erreur: Le type de colonne est inconnus";
		}

		//Lecture des données
		input_file.close();
	}

	Echantillon::Echantillon(DataSource* data){
		setSource(data);
	}

	Echantillon::Echantillon(const Echantillon &e){ //Constructeur de copie
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
		Source = NULL;
		Source = data;
    }


///////////////////////// Surchage Oppérateur: ///////////////////////////////
	//=
	Echantillon& Echantillon::operator=(const Echantillon& t2){
  		setSource(NULL);
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
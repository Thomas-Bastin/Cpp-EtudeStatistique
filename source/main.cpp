#include "main.h"
using namespace std;

EtudeStat1D* Etude;

int main(){
	int returnCode;
	while(true){
		returnCode = menu();
		if(returnCode == 0)	break;
	}
	
	system("clear");
	cout << endl << endl<< endl;
	if(returnCode == 0)		
		cout << "Fin du programme, Bonne journée :-)" << endl;
	else	
		cout << "Fin du Programme: ExitCode(" << returnCode<<")" << endl;
	cout << endl << endl;
}


int menu(void){
	int returnCode;
	string choix;
	system("clear");
	cout << "|***********************************************************************|" << endl;
	cout << "| "<< "\033[0;31m"<<"Menu Principal:"<<"\033[0m"<<"                                                       |" << endl;
	cout << "| ---------------------                                                 |" << endl;	
	cout << "|                                                                       |" << endl;
	cout << "| 1. Lire un nouveau Fichier                                            |" << endl;
	cout << "| 2. Afficher l'étude Statistique                                       |" << endl;
	cout << "| 3. Autres                                                             |" << endl;
	cout << "|                                                                       |" << endl;
	cout << "|                                                                       |" << endl;
	cout << "| 0. Quitter                                                            |" << endl;
	cout << "|                                                                       |" << endl;
	cout << "|***********************************************************************|" << endl;
	cout << "| " << "\033[0;36m" << "Entrez votre choix:" << "\033[0m" << "                                                   |" << endl;
	cout << "| "; cin >> choix; cin.get(); cout << endl;

	switch(choix[0]){
		case '1':
				system("clear");
				MenuStat1D();
				returnCode = 1;
				EnterIsPressed();
			break;
		
		case '2':
				system("clear");
				if(Etude){
					Etude->AfficheRapport();
				}
				returnCode = 2;
				EnterIsPressed();
			break;
		
		case '3':
				while(true){
					returnCode = menuAutre();
					if(returnCode == 0){
						returnCode = 3;
						break;
					}
				}
			break;

		case '0':
				returnCode = 0;
			break;
	}

	return(returnCode);
}



int menuAutre(void){
	int returnCode;
	string choix;
	system("clear");
	cout << "|***********************************************************************|" << endl;
	cout << "| "<< "\033[0;31m"<<"Autres Options:"<<"\033[0m"<<"                                                       |" << endl;
	cout << "| ---------------------                                                 |" << endl;	
	cout << "|                                                                       |" << endl;
	cout << "| 1. Test Liste                                                         |" << endl;
	cout << "| 2. Test data1D                                                        |" << endl;
	cout << "| 3. Test data2D                                                        |" << endl;
	cout << "| 4. Test DataSource                                                    |" << endl;
	cout << "| 5. Test Echantillon                                                   |" << endl;
	cout << "| 6. Test DataSourceSerieDiscrete                                       |" << endl;
	cout << "| 7. Test DataSourceSerieContinue                                       |" << endl;
	cout << "| 8. Test EtudeStat1D                                                   |" << endl;
	cout << "|                                                                       |" << endl;
	cout << "|                                                                       |" << endl;
	cout << "| 0. Quitter                                                            |" << endl;
	cout << "|                                                                       |" << endl;
	cout << "|***********************************************************************|" << endl;
	cout << "| " << "\033[0;36m" << "Entrez votre choix:" << "\033[0m" << "                                                   |" << endl;
	cout << "| "; cin >> choix; cin.get(); cout << endl;

	switch(choix[0]){
		case '1':
				system("clear");
				returnCode = 1;
				TestList();
				EnterIsPressed();
			break;
		
		case '2':
				system("clear");
				returnCode = 2;
				Test1D();
				EnterIsPressed();
			break;
		
		case '3':
				system("clear");
				returnCode = 3;
				Test2D();
				EnterIsPressed();
			break;

		case '4':
				system("clear");
				returnCode = 4;
				TestDataSource();
				EnterIsPressed();
			break;

		case '5':
				system("clear");
				returnCode = 5;
				TestEchantillon();
				EnterIsPressed();
			break;

		case '6':
				system("clear");
				returnCode = 6;
				TestDataSourceSerieDiscrete();
				EnterIsPressed();
			break;

		case '7':
				system("clear");
				returnCode = 7;
				TestDataSourceSerieContinue();
				EnterIsPressed();
			break;

		case '8':
				system("clear");
				returnCode = 8;
				TestEtudeStat1D();
				EnterIsPressed();
			break;

		case '0':
				returnCode = 0;
			break;
	}
	return(returnCode);
}


void EnterIsPressed(){
	std::string myString = "";
	do {
	     std::cout<< endl << "----Appuiez sur [Enter] pour continuer----" << std::endl;
	     std::getline(std::cin, myString);
	} while (myString.length() != 0);
}


void MenuStat1D(){
	string filename;
	string col;
	int c;

	cout << "|***********************************************************************|" << endl;
	cout << "| "<< "\033[0;31m"<<"EtudeStat1D:"<<"\033[0m"<<"                                                          |" << endl;
	cout << "| ---------------------                                                 |" << endl;
	cout << "|***********************************************************************|" << endl;
	
	cout << "  " << "\033[0;36m" << "Entrez le chemin + le nom du fichier:" << "\033[0m" << "" << endl;
	cout << "  "; cin >> filename; cin.get(); cout << endl;

	cout << "|***********************************************************************|" << endl;
	cout << "  " << "\033[0;36m" << "Entrez le numéro de la colonne a étudiée" << "\033[0m" << "" << endl;
	cout << "  "; cin >> col; cin.get(); cout << endl;
	
	#ifdef DEBUG
		cout << "|***********************************************************************|" << endl;
		cout << "filename: "<< filename << ", colonne: " << c << endl;	
		cout << "|***********************************************************************|" << endl;
	#endif

	ExecEtudeStat1D(filename, col);
}

void ExecEtudeStat1D(string filename, string col){
	int c;
	int i = 0;

	do{
		if(i>0){
			cout << "  " << "\033[0;36m" << "Entré un nombre valide (entier)" << "\033[0m" << "" << endl;
			cout << "  "; cin >> col; cin.get(); cout << endl;
		}
		
		i++;

		try{
			c = stoi(col);
		}
		catch(...){
			continue;
		}
	}while(c < 1);
	
	try{
		Etude = new EtudeStat1D(filename,c);	
		Etude->AfficheRapport();
	}
	catch(char const* e){
		cout << e << endl;
	}
	
}
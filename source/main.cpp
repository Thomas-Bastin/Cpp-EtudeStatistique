#include "main.h"
using namespace std;

int main(int argc, char*argv[]){

	if (argc == 3) ExecEtudeStat1D(argv[1], argv[2]);
	
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
	cout << "| 2. Selectionnez un Fichier                                            |" << endl;
	#ifdef DEBUG
	cout << "| 3. TestTools                                                             |" << endl;
	#endif
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
			break;
		
		case '2':
				system("clear");
				ReadRepertory();
				returnCode = 2;
			break;

		#ifdef DEBUG		
		case '3':
				while(true){
					returnCode = menuTest();
					if(returnCode == 0){
						returnCode = 3;
						break;
					}
				}
			break;
		#endif

		case '0':
				returnCode = 0;
			break;
	}

	return(returnCode);
}



int menuTest(void){
	int returnCode;
	string choix;
	system("clear");
	cout << "|***********************************************************************|" << endl;
	cout << "| "<< "\033[0;31m"<<"TestsList:"<<"\033[0m"<<"                                                       |" << endl;
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

int ReadRepertory(void){
	string filename;
	string col;
	string choix;
	string list;

	int c;
	int returnCode;
	int n = 1;

	DIR *dpdf;
	std::string PathList[500];

    struct dirent *epdf;
    dpdf = opendir("./Fichier");
    if (dpdf != NULL){
		while (epdf = readdir(dpdf)){
			if(strcmp(epdf->d_name, ".") != 0 && strcmp(epdf->d_name, "") != 0 && strcmp(epdf->d_name, "..") != 0 && strcmp(epdf->d_name, ".keepfile") != 0){
				PathList[n] = epdf->d_name;
				n++;
			}
		}
    }
    closedir(dpdf);


    system("clear");
	cout << "|***********************************************************************|" << endl;
	cout << "| "<< "\033[0;31m"<<"Choissez un Fichier:"<<"\033[0m"<<"                                                  |" << endl;
	cout << "| ---------------------                                                 |" << endl;	
	cout << "|                                                                       |" << endl;

	for(int i = 1 ; i<n ; i++){
		cout << "| "<< i <<". "<< PathList[i] <<"                                                         " << endl;
	}

	cout << "|                                                                       |" << endl;
	cout << "|                                                                       |" << endl;
	cout << "| 0. Quitter                                                            |" << endl;
	cout << "|                                                                       |" << endl;
	cout << "|***********************************************************************|" << endl;
	cout << "| " << "\033[0;36m" << "Entrez votre choix:" << "\033[0m" << "                                                   |" << endl;
	cout << "| "; cin >> choix; cin.get(); cout << endl;

	int i = 0;
	do{
		if(i>0){
			cout << "  " << "\033[0;36m" << "Entré un nombre valide (entier)" << "\033[0m" << "" << endl;
			cout << "  "; cin >> col; cin.get(); cout << endl;
		}
		
		i++;

		try{
			c = stoi(choix);
		}
		catch(...){
			continue;
		}
	}while(c < 0);

	filename = "./Fichier/"+ PathList[c];
	
	system("clear");
	cout << "|***********************************************************************|" << endl;
	cout << "  " << "\033[0;36m" << "Entrez le numéro de la colonne a étudiée" << "\033[0m" << "" << endl;
	cout << "  "; cin >> col; cin.get(); cout << endl;

	ExecEtudeStat1D(filename, col);

	return(returnCode);
}

void ExecEtudeStat1D(string filename, string col){
	int c;
	int i = 0;
	EtudeStat1D* Etude;

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
		Etude =  new EtudeStat1D(filename,c);	
		Etude->AfficheRapport();
	}
	catch(char const* e){
		cout << e << endl;
	}

	EnterIsPressed();
}
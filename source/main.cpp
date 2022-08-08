#include "Liste_Template/Iterateur.h"
#include "Liste_Template/Liste.h"
#include "Liste_Template/ListeTriee.h"

#include <iostream>
#include <stdlib.h>
#include <string>



using namespace std;

int menu(void);
void EnterIsPressed();


int main(){
	int returnCode;
	while(true){
		returnCode = menu();
		if(returnCode == 0)	break;
	}

    Liste<int> test;

    test.insere(78);
    test.insere(0);
    test.insere(5);
    test.insere(58);
    test.insere(10);
    test.insere(0);
    test.insere(3);
    
    std::cout << "Liste: " << endl;
    Iterateur<int> iter(test); //Déclaration d'un itérateur pour notre liste
    int tmp;
    int i;

    for(i = 0, iter.reset() ; !iter.end() ; iter++, i++){
    	tmp = (int)iter;
    	//On récupère un objet Prof par casting
        std::cout << "[" << i << "] = " << tmp << "" << endl;
    }

    cout << "Fin du Programme: ExitCode(" << returnCode<<")" << endl;
}


int menu(void){
	string choix;
	system("clear");
	cout << "|***********************************************************************|" << endl;
	cout << "| Etude Statistique 1D:                                                 |" << endl;
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
	cout << "| Entrez votre choix:                                                   |" << endl;
	cout << "| "; cin >> choix; cin.get(); cout << endl;

	switch(choix[0]){
		case '1':
				cout << "1 has been catch" << endl;
				EnterIsPressed();
			break;
		
		case '2':
				cout << "2 has been catch" << endl;
				EnterIsPressed();
			break;
		
		case '3':
				cout << "3 has been catch" << endl;
				EnterIsPressed();
			break;

		case '0':
				return(0);
			break;
	}
}


void EnterIsPressed(){
	std::string myString = "";
	do {
	     std::cout<< endl << "*Appuiez sur [Enter] pour continuer*" << std::endl;
	     std::getline(std::cin, myString);
	} while (myString.length() != 0);
}

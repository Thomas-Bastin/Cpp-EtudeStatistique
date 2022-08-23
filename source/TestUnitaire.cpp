#include "main.h"
using namespace std;


void TestList(){
	Liste<int> test;

    test.insere(78);
    test.insere(0);
    test.insere(5);
    test.insere(58);
    test.insere(10);
    test.insere(0);
    test.insere(3);
    
    std::cout << "Liste: " << endl;
    Iterateur<int> iter(test);
    int tmp;
    int i;

    for(i = 0, iter.reset() ; !iter.end() ; iter++, i++){
    	tmp = (int)iter;
        std::cout << "[" << i << "] = " << tmp << "" << endl;
    }
}






void Test1D(){

    //// Constructors Tests: ////
    //Default Constructor 
    cout << "\033[0;31m" << "Test constructeur par Défaut:" << "\033[0m" << endl; 
    Data1D test = Data1D();
    cout << test << endl << endl;

    //InitConstructor
    cout << "\033[0;31m" << "Test constructeur initialisation:" << "\033[0m" << endl;
    Data1D test2 = Data1D(20.1, 3);
    cout << test2 << endl << endl;

    //Copy Constructor
    cout << "\033[0;31m" << "Test constructeur Copie:" << "\033[0m" << endl;
    cout << "Test1 = Data1D(Test2)"<<endl;
    test = Data1D(test2);
    cout << "Test1= " << test << " " << endl;
    cout << "Test2= " << test2 << " " << endl<<endl;

    cout << "Test1.Eff = 2" << endl;
    test.setEffectif(2);

    cout << "Test1= " << test << " " << endl;
    cout << "Test2= " << test2 << " " << endl;
    cout << endl << endl;


    //// Getters/Setters Tests: //// 
    cout << "\033[0;31m" << "Test des Getters et Setters:" << "\033[0m" << endl;
    test = Data1D();
    cout << "Test1= " << test << endl;
    cout << "Test1.setEffectif(2); \tTest1.setValeur(2.345);" << endl << endl; 
    test.setEffectif(2);
    test.setValeur(2.345);
    cout << "Test1= " << "( eff = " << test.getEffectif() << ", val = " << test.getValeur()<< " )" << endl << endl;
    

    //// Opperator Overloading Tests: //// 
    //=
    cout << "\033[0;31m" << "Test Oppérateurs Affectation:" << "\033[0m" << endl;
    test.setValeur(0.1239);
    test2.setValeur(1.235);
    cout << "Test1 = " << test << "\t Test2 = " << test2 << endl<<endl;

    cout << "Test1 = Test2" << endl;
    test = test2;
    cout << "Test1 = " << test << "\t Test2 = " << test2 << endl<<endl;

    cout << "Test1.setValeur(2)\t Test1.setEffectif(2)" << endl;
    test.setValeur(2); test.setEffectif(2);
    cout << "Test1 = " << test << "\t Test2 = " << test2 << endl;


    //==
    cout << "\033[0;31m" << "Test Oppérateurs ==:" << "\033[0m" << endl;
    test.setValeur(19.293);
    test2.setValeur(19.293);
    cout << "Test1 = " << test << "\t Test2 = " << test2 << endl;
    cout << "Test1 == Test2\t";

    if(test == test2)
        cout << "return: true" << endl<<endl;
    else
        cout << "return: false" << endl<<endl;

    test.setValeur(19.293);
    test2.setValeur(20.293);
    cout << "Test1 = " << test << "\t Test2 = " << test2 << endl;
    cout << "Test1 == Test2\t";

    if(test == test2)
        cout << "return: true" << endl<<endl;
    else
        cout << "return: false" << endl<<endl;


    //<
    cout << "\033[0;31m" << "Test Oppérateurs <:" << "\033[0m" << endl;
    test.setValeur(19.293);
    test2.setValeur(19.293);
    cout << "Test1 = " << test << "\t Test2 = " << test2 << endl;
    cout << "Test1 < Test2\t";

    if(test < test2)
        cout << "return: true" << endl<<endl;
    else
        cout << "return: false" << endl<<endl;

    test2.setValeur(19.293);
    test.setValeur(20.293);
    cout << "Test1 = " << test << "\t Test2 = " << test2 << endl;
    cout << "Test1 < Test2\t";

    if(test < test2)
        cout << "return: true" << endl<<endl;
    else
        cout << "return: false" << endl<<endl;

    test.setValeur(19.293);
    test2.setValeur(20.293);
    cout << "Test1 = " << test << "\t Test2 = " << test2 << endl;
    cout << "Test1 < Test2\t";

    if(test < test2)
        cout << "return: true" << endl<<endl;
    else
        cout << "return: false" << endl<<endl;   


    //>
    cout << "\033[0;31m" << "Test Oppérateurs >:" << "\033[0m" << endl;

    test.setValeur(19.293);
    test2.setValeur(19.293);
    cout << "Test1 = " << test << "\t Test2 = " << test2 << endl;
    cout << "Test1 > Test2\t";

    if(test > test2)
        cout << "return: true" << endl<<endl;
    else
        cout << "return: false" << endl<<endl;   

    test.setValeur(19.293);
    test2.setValeur(20.293);
    cout << "Test1 = " << test << "\t Test2 = " << test2 << endl;
    cout << "Test1 > Test2\t";

    if(test > test2)
        cout << "return: true" << endl<<endl;
    else
        cout << "return: false" << endl<<endl;   

    test2.setValeur(19.293);
    test.setValeur(20.293);
    cout << "Test1 = " << test << "\t Test2 = " << test2 << endl;
    cout << "Test1 > Test2\t";

    if(test > test2)
        cout << "return: true" << endl<<endl;
    else
        cout << "return: false" << endl<<endl;  



    //Test Liste Data1D:
    cout << "\033[0;31m" << "Test Liste Data1D:" << "\033[0m" << endl;
    Liste<Data1D> listeData1D;

    listeData1D.insere(Data1D());
    listeData1D.insere(Data1D(test));
    listeData1D.insere(Data1D(test2));
    listeData1D.insere(Data1D(20.9284,12));
    listeData1D.insere(Data1D(20.8620,1));
    listeData1D.insere(Data1D(0.9284,4));
    listeData1D.insere(Data1D(12.0012,5));
    
    std::cout << "Liste: " << endl;
    Iterateur<Data1D> iter(listeData1D);
    int i;

    for(i = 0, iter.reset() ; !iter.end() ; iter++, i++){
    	Data1D tmp = (Data1D)iter;
        std::cout << "[" << i << "] = " << tmp << "" << endl;
    }
}









void Test2D(){
    //// Constructors Tests: ////
    //Default Constructor 
    cout << "\033[0;31m" << "Test constructeur par Défaut:" << "\033[0m" << endl; 
    Data2D test = Data2D();
    cout << test << endl << endl;

    //InitConstructor
    cout << "\033[0;31m" << "Test constructeur initialisation:" << "\033[0m" << endl;
    Data2D test2 = Data2D(20.1, 3);
    cout << test2 << endl << endl;

    //Copy Constructor
    cout << "\033[0;31m" << "Test constructeur Copie:" << "\033[0m" << endl;
    cout << "Test1 = Data2D(Test2)"<<endl;
    test = Data2D(test2);
    cout << "Test1= " << test << " " << endl;
    cout << "Test2= " << test2 << " " << endl<<endl;

    cout << "Test1.Valeur2 = 2" << endl;
    test.setValeur2(2);

    cout << "Test1= " << test << " " << endl;
    cout << "Test2= " << test2 << " " << endl;
    cout << endl << endl;


    //// Getters/Setters Tests: //// 
    cout << "\033[0;31m" << "Test des Getters et Setters:" << "\033[0m" << endl;
    test = Data2D();
    cout << "Test1= " << test << endl;
    cout << "Test1.setValeur2(2); \tTest1.setValeur(2.345);" << endl << endl; 
    test.setValeur2(2);
    test.setValeur(2.345);
    cout << "Test1= " << "( Valeur2 = " << test.getValeur2() << ", val = " << test.getValeur()<< " )" << endl << endl;
    

    //// Opperator Overloading Tests: //// 
    //=
    cout << "\033[0;31m" << "Test Oppérateurs Affectation:" << "\033[0m" << endl;
    test.setValeur(0.1239);
    test2.setValeur(1.235);
    cout << "Test1 = " << test << "\t Test2 = " << test2 << endl<<endl;

    cout << "Test1 = Test2" << endl;
    test = test2;
    cout << "Test1 = " << test << "\t Test2 = " << test2 << endl<<endl;

    cout << "Test1.setValeur(2)\t Test1.setValeur2(2)" << endl;
    test.setValeur(2); test.setValeur2(2);
    cout << "Test1 = " << test << "\t Test2 = " << test2 << endl;


    //==
    cout << "\033[0;31m" << "Test Oppérateurs ==:" << "\033[0m" << endl;
    test.setValeur(19.293);
    test2.setValeur(19.293);
    cout << "Test1 = " << test << "\t Test2 = " << test2 << endl;
    cout << "Test1 == Test2\t";

    if(test == test2)
        cout << "return: true" << endl<<endl;
    else
        cout << "return: false" << endl<<endl;

    test.setValeur(19.293);
    test2.setValeur(20.293);
    cout << "Test1 = " << test << "\t Test2 = " << test2 << endl;
    cout << "Test1 == Test2\t";

    if(test == test2)
        cout << "return: true" << endl<<endl;
    else
        cout << "return: false" << endl<<endl;


    //<
    cout << "\033[0;31m" << "Test Oppérateurs <:" << "\033[0m" << endl;
    test.setValeur(19.293);
    test2.setValeur(19.293);
    cout << "Test1 = " << test << "\t Test2 = " << test2 << endl;
    cout << "Test1 < Test2\t";

    if(test < test2)
        cout << "return: true" << endl<<endl;
    else
        cout << "return: false" << endl<<endl;

    test2.setValeur(19.293);
    test.setValeur(20.293);
    cout << "Test1 = " << test << "\t Test2 = " << test2 << endl;
    cout << "Test1 < Test2\t";

    if(test < test2)
        cout << "return: true" << endl<<endl;
    else
        cout << "return: false" << endl<<endl;

    test.setValeur(19.293);
    test2.setValeur(20.293);
    cout << "Test1 = " << test << "\t Test2 = " << test2 << endl;
    cout << "Test1 < Test2\t";

    if(test < test2)
        cout << "return: true" << endl<<endl;
    else
        cout << "return: false" << endl<<endl;   


    //>
    cout << "\033[0;31m" << "Test Oppérateurs >:" << "\033[0m" << endl;
    
    test.setValeur(19.293);
    test2.setValeur(19.293);
    cout << "Test1 = " << test << "\t Test2 = " << test2 << endl;
    cout << "Test1 > Test2\t";

    if(test > test2)
        cout << "return: true" << endl<<endl;
    else
        cout << "return: false" << endl<<endl;   

    test.setValeur(19.293);
    test2.setValeur(20.293);
    cout << "Test1 = " << test << "\t Test2 = " << test2 << endl;
    cout << "Test1 > Test2\t";

    if(test > test2)
        cout << "return: true" << endl<<endl;
    else
        cout << "return: false" << endl<<endl;   

    test2.setValeur(19.293);
    test.setValeur(20.293);
    cout << "Test1 = " << test << "\t Test2 = " << test2 << endl;
    cout << "Test1 > Test2\t";

    if(test > test2)
        cout << "return: true" << endl<<endl;
    else
        cout << "return: false" << endl<<endl;


    //Test Liste Data2D:
    cout << "\033[0;31m" << "Test Liste Data1D:" << "\033[0m" << endl;
    Liste<Data2D> listeData2D;

    listeData2D.insere(Data2D());
    listeData2D.insere(Data2D(test));
    listeData2D.insere(Data2D(test2));
    listeData2D.insere(Data2D(20.9284,12));
    listeData2D.insere(Data2D(20.8620,1));
    listeData2D.insere(Data2D(0.9284,4));
    listeData2D.insere(Data2D(12.0012,5));
    
    std::cout << "Liste: " << endl;
    Iterateur<Data2D> iter(listeData2D);
    int i;

    for(i = 0, iter.reset() ; !iter.end() ; iter++, i++){
    	Data2D tmp = (Data2D)iter;
        std::cout << "[" << i << "] = " << tmp << "" << endl;
    }
}

void TestDataSource(){
    cout << "WIP, nothing to do here...";
}


void TestEchantillon(){
    //// Constructors Tests: ////
    //Default Constructor 
    cout << "\033[0;31m" << "Test constructeur par Défaut:" << "\033[0m" << endl; 
    Echantillon test = Echantillon();
    cout << test << endl << endl;

    //InitConstructor
    cout << "\033[0;31m" << "Test constructeur initialisation:" << "\033[0m" << endl;

    Echantillon test2 = Echantillon(new DataSourceSerieDiscrete("Nom","Sujet","10"));
    cout << test2 << endl << endl;

    //Copy Constructor
    cout << "\033[0;31m" << "Test constructeur Copie:" << "\033[0m" << endl;
    cout << "Test1 = Echantillon(Test2)"<<endl;
    test = Echantillon(test2);
    cout << "Test1= " << test << " " << endl;
    cout << "Test2= " << test2 << " " << endl<<endl;

    cout << "Test1.Sujet = Sujet1" << endl;

    test.setSource(new DataSourceSerieDiscrete("Nom3","Sujet1","5"));

    cout << "Test1= " << test << " " << endl;
    cout << "Test2= " << test2 << " " << endl;
    cout << endl << endl;
}





void TestDataSourceSerieDiscrete(){

    //Creation liste Data1D:
    cout << "\033[0;31m" << "Test Liste Data1D:" << "\033[0m" << endl;
    Liste<Data1D> listeData1D;

    listeData1D.insere( Data1D( 15.5254,  10));
    listeData1D.insere( Data1D( 5.5684,    3));
    listeData1D.insere( Data1D( 8.5284,    5));
    listeData1D.insere( Data1D( 20.9284,  12));
    listeData1D.insere( Data1D( 20.8620,   1));
    listeData1D.insere( Data1D( 0.9284,    4));
    listeData1D.insere( Data1D( 12.0012,   5));
    
    std::cout << "Liste: " << endl;
    Iterateur<Data1D> iter(listeData1D);
    int i;

    for(i = 0, iter.reset() ; !iter.end() ; iter++, i++){
    	Data1D tmp = (Data1D)iter;
        std::cout << "[" << i << "] = " << tmp << "" << endl;
    }


    //// Constructors Tests: ////
    //Default Constructor 
    cout << "\033[0;31m" << "Test constructeur par Défaut:" << "\033[0m" << endl; 
    DataSourceSerieDiscrete test = DataSourceSerieDiscrete();
    cout << test << endl << endl;

    //InitConstructor
    cout << "\033[0;31m" << "Test constructeur initialisation:" << "\033[0m" << endl;
    DataSourceSerieDiscrete test2 = DataSourceSerieDiscrete("Nom", "Sujet", "3", listeData1D);
    cout << test2 << endl << endl;

    //Copy Constructor
    cout << "\033[0;31m" << "Test constructeur Copie:" << "\033[0m" << endl;
    cout << "Test1 = DataSourceSerieDiscrete(Test2)"<<endl;
    test = DataSourceSerieDiscrete(test2);
    cout << "Test1= " << test << " " << endl;
    cout << "Test2= " << test2 << " " << endl<<endl;

    cout << "Test1.Sujet = Sujet1" << endl;
    test.setSujet("Sujet1");

    cout << "Test1= " << test << " " << endl;
    cout << "Test2= " << test2 << " " << endl;
    cout << endl << endl;


    //// Getters/Setters Tests: //// 
    cout << "\033[0;31m" << "Test des Getters et Setters:" << "\033[0m" << endl;
    test = DataSourceSerieDiscrete();
    cout << "Test1= " << test << endl;
    cout << "Test1.setListe(ListeData1D);" << endl << endl; 
    test.setListe(listeData1D);
    cout << "Test1= "<< test << "\nListe = " << endl;
    test.getListe().Affiche();
    cout << endl << endl;
    

    //// Opperator Overloading Tests: //// 
    //=
    cout << "\033[0;31m" << "Test Oppérateurs Affectation:" << "\033[0m" << endl;
    test.setNom("Nom1");
    test2.setNom("Nom2");
    cout << "Test1 = " << test << "\t Test2 = " << test2 << endl<<endl;

    cout << "Test1 = Test2" << endl;
    test = test2;
    cout << "Test1 = " << test << "\t Test2 = " << test2 << endl<<endl;

    cout << "Test1.setNom(2)\t Test1.setSujet(2)" << endl;
    test.setNom("Nom3"); test.setSujet("Sujet5");
    cout << "Test1 = " << test << "\t Test2 = " << test2 << endl;

    //// My Methods Tests: /////
    cout << "\033[0;31m" << "Test RefreshEffectifTotal:" << "\033[0m" << endl;
    cout << "Test1 = " << test << endl;
    Liste<Data1D> listeData2;

    listeData2.insere( Data1D( 15.5254,  5));
    listeData2.insere( Data1D( 20.9284,  12));
    listeData2.insere( Data1D( 20.8620,   1));
    listeData2.insere( Data1D( 0.9284,    4));
    listeData2.insere( Data1D( 12.0012,   5));

    test.setListe(listeData2);
    test.refreshEffectifTotal();
    cout << "Test1 = " << test << endl;
}








void TestDataSourceSerieContinue(){

    //Creation liste Data1D:
    cout << "\033[0;31m" << "Test Liste Data1D:" << "\033[0m" << endl;
    Liste<Data1D> listeData1D;

    listeData1D.insere( Data1D( 15.5254,  10));
    listeData1D.insere( Data1D( 5.5684,    3));
    listeData1D.insere( Data1D( 8.5284,    5));
    listeData1D.insere( Data1D( 20.9284,  12));
    listeData1D.insere( Data1D( 20.8620,   1));
    listeData1D.insere( Data1D( 0.9284,    4));
    listeData1D.insere( Data1D( 12.0012,   5));
    
    std::cout << "Liste: " << endl;
    Iterateur<Data1D> iter(listeData1D);
    int i;

    for(i = 0, iter.reset() ; !iter.end() ; iter++, i++){
    	Data1D tmp = (Data1D)iter;
        std::cout << "[" << i << "] = " << tmp << "" << endl;
    }


    //// Constructors Tests: ////
    //Default Constructor 
    cout << "\033[0;31m" << "Test constructeur par Défaut:" << "\033[0m" << endl; 
    DataSourceSerieContinue test = DataSourceSerieContinue();
    cout << test << endl << endl;

    //InitConstructor
    cout << "\033[0;31m" << "Test constructeur initialisation:" << "\033[0m" << endl;
    DataSourceSerieContinue test2 = DataSourceSerieContinue("Nom", "Sujet", "3", listeData1D);
    cout << test2 << endl << endl;

    //Copy Constructor
    cout << "\033[0;31m" << "Test constructeur Copie:" << "\033[0m" << endl;
    cout << "Test1 = DataSourceSerieContinue(Test2)"<<endl;
    test = DataSourceSerieContinue(test2);
    cout << "Test1= " << test << " " << endl;
    cout << "Test2= " << test2 << " " << endl<<endl;

    cout << "Test1.Sujet = Sujet1" << endl;
    test.setSujet("Sujet1");

    cout << "Test1= " << test << " " << endl;
    cout << "Test2= " << test2 << " " << endl;
    cout << endl << endl;


    //// Getters/Setters Tests: //// 
    cout << "\033[0;31m" << "Test des Getters et Setters:" << "\033[0m" << endl;
    test = DataSourceSerieContinue();
    cout << "Test1= " << test << endl;
    cout << "Test1.setListe(ListeData1D);\t Test1.setDebut(10.0); \t Test1.setIntervalle(5.1)" << endl << endl; 
    test.setListe(listeData1D);
    test.setDebut(10.0);
    test.setIntervalle(5.1);
    cout << "Test1= "<< test << "\nListe = " << endl;
    test.getListe().Affiche();
    cout << endl << endl;
    

    //// Opperator Overloading Tests: //// 
    //=
    cout << "\033[0;31m" << "Test Oppérateurs Affectation:" << "\033[0m" << endl;
    test.setNom("Nom1");
    test2.setNom("Nom2");
    cout << "Test1 = " << test << "\t Test2 = " << test2 << endl<<endl;

    cout << "Test1 = Test2" << endl;
    test = test2;
    cout << "Test1 = " << test << "\t Test2 = " << test2 << endl<<endl;

    cout << "Test1.setNom(2)\t Test1.setSujet(2)" << endl;
    test.setNom("Nom3"); test.setSujet("Sujet5");
    cout << "Test1 = " << test << "\t Test2 = " << test2 << endl;

    //// My Methods Tests: /////
    cout << "\033[0;31m" << "Test RefreshEffectifTotal:" << "\033[0m" << endl;
    cout << "Test1 = " << test << endl;
    Liste<Data1D> listeData2;

    listeData2.insere( Data1D( 15.5254,  5));
    listeData2.insere( Data1D( 20.9284,  12));
    listeData2.insere( Data1D( 20.8620,   1));
    listeData2.insere( Data1D( 0.9284,    4));
    listeData2.insere( Data1D( 12.0012,   5));

    test.setListe(listeData2);
    test.refreshEffectifTotal();
    cout << "Test1 = " << test << endl;
}







void TestEtudeStat1D(){    
    Liste<Data1D> listeData1D;
    listeData1D.insere( Data1D( 15,  10));
    listeData1D.insere( Data1D( 5,    3));
    listeData1D.insere( Data1D( 8,    5));
    listeData1D.insere( Data1D( 20,  12));
    listeData1D.insere( Data1D( 4,   1));
    listeData1D.insere( Data1D( 0,    4));
    listeData1D.insere( Data1D( 12,   5));
    
    #ifdef DEBUG
        std::cout << "Liste: " << endl;
        Iterateur<Data1D> iter(listeData1D);
        int i;

        for(i = 0, iter.reset() ; !iter.end() ; iter++, i++){
            Data1D tmp = (Data1D)iter;
            std::cout << "[" << i << "] = " << tmp << "" << endl;
        }
    #endif

    #ifdef DEBUG
        cout << "Avant Creation DataSource"<< endl;
    #endif

    DataSourceSerieDiscrete* p2 = new DataSourceSerieDiscrete("michel.txt", "Les molusques", "1", listeData1D);

    #ifdef DEBUG
        cout << "Après Creation DataSource" << endl;
    #endif

    #ifdef DEBUG
        cout << "Après Casting" << endl;
    #endif

    Echantillon* p3 = new Echantillon(p2);
    
    #ifdef DEBUG
        cout << "Après CreationEchantillon" << endl;
    #endif
    
    EtudeStat1D* test = new EtudeStat1D(p3);

    #ifdef DEBUG
        cout << "Après EtudeStat1D" << endl;
    #endif

    test->AfficheRapport();
}
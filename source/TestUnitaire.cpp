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
    //// Constructors Tests: ////
    //Default Constructor 
    cout << "\033[0;31m" << "Test constructeur par Défaut:" << "\033[0m" << endl; 
    DataSource test = DataSource();
    cout << test << endl << endl;

    //InitConstructor
    cout << "\033[0;31m" << "Test constructeur initialisation:" << "\033[0m" << endl;
    DataSource test2 = DataSource("Nom", "Sujet", 3);
    cout << test2 << endl << endl;

    //Copy Constructor
    cout << "\033[0;31m" << "Test constructeur Copie:" << "\033[0m" << endl;
    cout << "Test1 = DataSource(Test2)"<<endl;
    test = DataSource(test2);
    cout << "Test1= " << test << " " << endl;
    cout << "Test2= " << test2 << " " << endl<<endl;

    cout << "Test1.Sujet = Sujet1" << endl;
    test.setSujet("Sujet1");

    cout << "Test1= " << test << " " << endl;
    cout << "Test2= " << test2 << " " << endl;
    cout << endl << endl;


    //// Getters/Setters Tests: //// 
    cout << "\033[0;31m" << "Test des Getters et Setters:" << "\033[0m" << endl;
    test = DataSource();
    cout << "Test1= " << test << endl;
    cout << "Test1.setSujet(Sujet2); \tTest1.setNom(Nom1);" << endl << endl; 
    test.setSujet("Sujet2");
    test.setNom("Nom1");
    cout << "Test1= " << "( Sujet = " << test.getSujet() << ", val = " << test.getNom()<< " )" << endl << endl;
    

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


    //==
    cout << "\033[0;31m" << "Test Oppérateurs ==:" << "\033[0m" << endl;
    test = DataSource();
    test2 = DataSource();
    cout << "Test1 = " << test << "\t Test2 = " << test2 << endl;
    cout << "Test1 == Test2\t";

    if(test == test2)
        cout << "return: true" << endl<<endl;
    else
        cout << "return: false" << endl<<endl;

    test.setNom("1");
    test2.setNom("0");
    cout << "Test1 = " << test << "\t Test2 = " << test2 << endl;
    cout << "Test1 == Test2\t";

    if(test == test2)
        cout << "return: true" << endl<<endl;
    else
        cout << "return: false" << endl<<endl;

    //Test Liste DataSource:
    cout << "\033[0;31m" << "Test Liste Data1D:" << "\033[0m" << endl;
    Liste<DataSource> listeDataSource;

    listeDataSource.insere(DataSource());
    listeDataSource.insere(DataSource(test));
    listeDataSource.insere(DataSource(test2));
    listeDataSource.insere(DataSource("Nom 10", "Sujet 1", 1));
    listeDataSource.insere(DataSource("Nom 11", "Sujet 2", 100));
    listeDataSource.insere(DataSource("Nom 12", "Sujet 3", 5));
    listeDataSource.insere(DataSource("Nom 13", "Sujet 4", 10));
    
    std::cout << "Liste: " << endl;
    Iterateur<DataSource> iter(listeDataSource);
    int i;

    for(i = 0, iter.reset() ; !iter.end() ; iter++, i++){
    	DataSource tmp = (DataSource)iter;
        std::cout << "[" << i << "] = " << tmp << "" << endl;
    }
}


void TestEchantillon(){
    //// Constructors Tests: ////
    //Default Constructor 
    cout << "\033[0;31m" << "Test constructeur par Défaut:" << "\033[0m" << endl; 
    Echantillon test = Echantillon();
    cout << test << endl << endl;

    //InitConstructor
    cout << "\033[0;31m" << "Test constructeur initialisation:" << "\033[0m" << endl;
    Echantillon test2 = Echantillon(new DataSource("Nom","Sujet",10));
    cout << test2 << endl << endl;

    //Copy Constructor
    cout << "\033[0;31m" << "Test constructeur Copie:" << "\033[0m" << endl;
    cout << "Test1 = Echantillon(Test2)"<<endl;
    test = Echantillon(test2);
    cout << "Test1= " << test << " " << endl;
    cout << "Test2= " << test2 << " " << endl<<endl;

    cout << "Test1.Sujet = Sujet1" << endl;

    test.setSource(new DataSource("Nom","Sujet",10));

    cout << "Test1= " << test << " " << endl;
    cout << "Test2= " << test2 << " " << endl;
    cout << endl << endl;


    //// Getters/Setters Tests: //// 
    // cout << "\033[0;31m" << "Test des Getters et Setters:" << "\033[0m" << endl;
    // test = Echantillon();
    // cout << "Test1= " << test << endl;
    // cout << "Test1.setSujet(Sujet2); \tTest1.setNom(Nom1);" << endl << endl; 
    // test.setSujet("Sujet2");
    // test.setNom("Nom1");
    // cout << "Test1= " << "( Sujet = " << test.getSujet() << ", val = " << test.getNom()<< " )" << endl << endl;
    

    //// Opperator Overloading Tests: //// 
    //=
    // cout << "\033[0;31m" << "Test Oppérateurs Affectation:" << "\033[0m" << endl;
    // test.setNom("Nom1");
    // test2.setNom("Nom2");
    // cout << "Test1 = " << test << "\t Test2 = " << test2 << endl<<endl;

    // cout << "Test1 = Test2" << endl;
    // test = test2;
    // cout << "Test1 = " << test << "\t Test2 = " << test2 << endl<<endl;

    // cout << "Test1.setNom(2)\t Test1.setSujet(2)" << endl;
    // test.setNom("Nom3"); test.setSujet("Sujet5");
    // cout << "Test1 = " << test << "\t Test2 = " << test2 << endl;


    //==
    // cout << "\033[0;31m" << "Test Oppérateurs ==:" << "\033[0m" << endl;
    // test = Echantillon();
    // test2 = Echantillon();
    // cout << "Test1 = " << test << "\t Test2 = " << test2 << endl;
    // cout << "Test1 == Test2\t";

    // if(test == test2)
    //     cout << "return: true" << endl<<endl;
    // else
    //     cout << "return: false" << endl<<endl;

    // test.setNom("1");
    // test2.setNom("0");
    // cout << "Test1 = " << test << "\t Test2 = " << test2 << endl;
    // cout << "Test1 == Test2\t";

    // if(test == test2)
    //     cout << "return: true" << endl<<endl;
    // else
    //     cout << "return: false" << endl<<endl;


    //Test Liste Echantillon:
    cout << "\033[0;31m" << "Test Liste Data1D:" << "\033[0m" << endl;
    Liste<Echantillon> listeEchantillon;

    listeEchantillon.insere( Echantillon());
    listeEchantillon.insere( Echantillon( test));
    listeEchantillon.insere( Echantillon( test2));
    listeEchantillon.insere( Echantillon( new DataSource("Nom 10", "Sujet 1", 1   )));
    listeEchantillon.insere( Echantillon( new DataSource("Nom 11", "Sujet 2", 100 )));
    listeEchantillon.insere( Echantillon( new DataSource("Nom 12", "Sujet 3", 5   )));
    listeEchantillon.insere( Echantillon( new DataSource("Nom 13", "Sujet 4", 10  )));
    
    std::cout << "Liste: " << endl;
    Iterateur<Echantillon> iter(listeEchantillon);
    int i;

    for(i = 0, iter.reset() ; !iter.end() ; iter++, i++){
    	Echantillon tmp = (Echantillon)iter;
        std::cout << "[" << i << "] = " << tmp << "" << endl;
    }
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
    DataSourceSerieDiscrete test2 = DataSourceSerieDiscrete("Nom", "Sujet", 3, listeData1D);
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


    //Test Liste DataSourceSerieDiscrete:
    cout << "\n" << "\033[0;31m" << "Test Liste DataSource:" << "\033[0m" << endl;
    Liste<DataSourceSerieDiscrete> listeDataSourceSerieDiscrete;

    listeDataSourceSerieDiscrete.insere( DataSourceSerieDiscrete());
    listeDataSourceSerieDiscrete.insere( DataSourceSerieDiscrete(listeData1D));
    listeDataSourceSerieDiscrete.insere( DataSourceSerieDiscrete(test2));
    listeDataSourceSerieDiscrete.insere( DataSourceSerieDiscrete("Nom 10", "Sujet 1", 1,     listeData1D));
    listeDataSourceSerieDiscrete.insere( DataSourceSerieDiscrete("Nom 11", "Sujet 2", 100,   listeData1D));
    listeDataSourceSerieDiscrete.insere( DataSourceSerieDiscrete("Nom 12", "Sujet 3", 5,     listeData1D));
    listeDataSourceSerieDiscrete.insere( DataSourceSerieDiscrete("Nom 13", "Sujet 4", 10,    listeData1D));
    
    std::cout << "Liste: " << endl;
    Iterateur<DataSourceSerieDiscrete> iter2(listeDataSourceSerieDiscrete);
    int j;

    for(j = 0, iter2.reset() ; !iter2.end() ; iter2++, j++){
    	DataSourceSerieDiscrete tmp = (DataSourceSerieDiscrete)iter2;
        std::cout << "[" << j << "] = " << tmp << "" << endl;
        tmp.getListe().Affiche();
    }
}
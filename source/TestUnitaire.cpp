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
}

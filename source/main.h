#ifndef MAIN_H
#define MAIN_H
    #include "Liste_Template/Iterateur.h"
    #include "Liste_Template/Liste.h"
    #include "Liste_Template/ListeTriee.h"
    #include "Data/data1D.h"
    #include "Data/data2D.h"
    #include "DataSource/dataSource.h"
    #include "Echantillon/echantillon.h"

    #include <iostream>
    #include <stdlib.h>
    #include <string>

    int menu(void);
    int menuAutre(void);
    void TestList(void);
    void EnterIsPressed();
    void Test1D();
    void Test2D();
    void TestDataSource();
    void TestEchantillon();

#endif
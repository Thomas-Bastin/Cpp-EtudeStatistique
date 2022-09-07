#ifndef MAIN_H
#define MAIN_H
    #include "debug.h"

    #include "Liste_Template/Iterateur.h"
    #include "Liste_Template/Liste.h"
    #include "Liste_Template/ListeTriee.h"
    #include "Data/data1D.h"
    #include "Data/data2D.h"
    #include "DataSource/dataSource.h"
    #include "Echantillon/echantillon.h"
    #include "DataSource/DataSourceSerieDiscrete/dataSourceSerieDiscrete.h"
    #include "DataSource/DataSourceSerieContinue/dataSourceSerieContinue.h"
    #include "EtudeStat1D/etudeStat1D.h"

    #include <iostream>
    #include <fstream>
    #include <stdlib.h>
    #include <string>
    #include <exception>
    #include <stdexcept>
    #include <filesystem>
    #include <bits/stdc++.h>
    #include <dirent.h>
    #include <list>
    #include <algorithm>

    int menu(void);
    int ReadRepertory(void);
    int menuTest(void);
    void MenuStat1D();
    void ExecEtudeStat1D(string filename, string col);
    
    
    void EnterIsPressed();

    void TestList(void);
    void Test1D();
    void Test2D();
    void TestDataSource();
    void TestEchantillon();
    void TestDataSourceSerieDiscrete();
    void TestDataSourceSerieContinue();
    void TestEtudeStat1D();
    

#endif
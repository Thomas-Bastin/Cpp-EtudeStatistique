.SILENT:
DEBUG = -D DEBUG
PROGRAMS = EtudeStat
bin = obj
Lib = source
LibListeTemplate = $(Lib)/Liste_Template


objListe = $(bin)/Liste.o $(bin)/ListeTriee.o $(bin)/Iterateur.o
objData = $(bin)/data1D.o $(bin)/data2D.o $(bin)/dataSource.o $(bin)/dataSourceSerieDiscrete.o $(bin)/dataSourceSerieContinue.o


allobj = $(objListe) $(objData) $(bin)/echantillon.o $(bin)/etudeStat1D.o





ALL: $(PROGRAMS).app

$(PROGRAMS).app:	$(Lib)/main.cpp $(allobj) $(Lib)/TestUnitaire.cpp $(Lib)/main.h $(Lib)/debug.h
					echo Creation de $(PROGRAMS)
					g++ $(Lib)/main.cpp $(Lib)/TestUnitaire.cpp $(allobj) -o $(PROGRAMS).app

#Creation LibEchantillon
$(bin)/etudeStat1D.o: $(Lib)/EtudeStat1D/etudeStat1D.cpp $(Lib)/EtudeStat1D/etudeStat1D.h  $(Lib)/debug.h
			echo Création etudeStat1D.o
			g++ $(Lib)/EtudeStat1D/etudeStat1D.cpp -c -o $(bin)/etudeStat1D.o

#Creation LibDataSourceSerieDiscrete
$(bin)/dataSourceSerieDiscrete.o: $(Lib)/DataSource/DataSourceSerieDiscrete/dataSourceSerieDiscrete.cpp $(Lib)/DataSource/DataSourceSerieDiscrete/dataSourceSerieDiscrete.h $(Lib)/debug.h
			echo Création dataSourceSerieDiscrete.o
			g++ $(Lib)/DataSource/DataSourceSerieDiscrete/dataSourceSerieDiscrete.cpp -c -o $(bin)/dataSourceSerieDiscrete.o

#Creation LibDataSourceSerieContinue
$(bin)/dataSourceSerieContinue.o: $(Lib)/DataSource/DataSourceSerieContinue/dataSourceSerieContinue.cpp $(Lib)/DataSource/DataSourceSerieContinue/dataSourceSerieContinue.h $(Lib)/debug.h
			echo Création dataSourceSerieContinue.o
			g++ $(Lib)/DataSource/DataSourceSerieContinue/dataSourceSerieContinue.cpp -c -o $(bin)/dataSourceSerieContinue.o

#Creation LibDataSource
$(bin)/dataSource.o: $(Lib)/DataSource/dataSource.cpp $(Lib)/DataSource/dataSource.h $(Lib)/debug.h
			echo Création dataSource.o
			g++ $(Lib)/DataSource/dataSource.cpp -c -o $(bin)/dataSource.o

#Creation LibEchantillon
$(bin)/echantillon.o: $(Lib)/Echantillon/echantillon.cpp $(Lib)/Echantillon/echantillon.h $(Lib)/debug.h
			echo Création echantillon.o
			g++ $(Lib)/Echantillon/echantillon.cpp -c -o $(bin)/echantillon.o

#Creation LibData
$(bin)/data1D.o: $(Lib)/Data/data1D.cpp $(Lib)/Data/data1D.h $(Lib)/debug.h
			echo Création data1D.o
			g++ $(Lib)/Data/data1D.cpp -c -o $(bin)/data1D.o

$(bin)/data2D.o: $(Lib)/Data/data2D.cpp $(Lib)/Data/data2D.h $(Lib)/debug.h
			echo Création data2D.o
			g++ $(Lib)/Data/data2D.cpp -c -o $(bin)/data2D.o

#Creation Template Liste
$(bin)/Liste.o:	$(LibListeTemplate)/Liste.cpp $(LibListeTemplate)/Liste.h $(Lib)/debug.h
			echo Création Liste.o
			g++ $(LibListeTemplate)/Liste.cpp -c -o $(bin)/Liste.o

$(bin)/ListeTriee.o:	$(LibListeTemplate)/ListeTriee.cpp $(LibListeTemplate)/ListeTriee.h $(Lib)/debug.h
			echo Création ListeTriee.o
			g++ $(LibListeTemplate)/ListeTriee.cpp -c -o $(bin)/ListeTriee.o

$(bin)/Iterateur.o:	$(LibListeTemplate)/Iterateur.cpp $(LibListeTemplate)/Iterateur.h $(Lib)/debug.h
				echo Création Iterateur.o
				g++ $(LibListeTemplate)/Iterateur.cpp -c -o $(bin)/Iterateur.o






clear: clean

clean:
	echo "Supression *.o ..."
	rm obj/*
	rm EtudeStat.app


DEBUG:	$(Lib)/main.cpp $(allobj) $(Lib)/TestUnitaire.cpp $(Lib)/main.h
					echo Creation de $(PROGRAMS)
					g++ $(Lib)/main.cpp $(Lib)/TestUnitaire.cpp $(allobj) -o $(PROGRAMS).app -D DEBUG
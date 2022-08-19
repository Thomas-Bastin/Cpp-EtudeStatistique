.SILENT:

PROGRAMS = EtudeStat
bin = obj
Lib = source
LibListeTemplate = $(Lib)/Liste_Template

allobj = $(bin)/Liste.o $(bin)/ListeTriee.o $(bin)/Iterateur.o $(bin)/data1D.o $(bin)/data2D.o $(bin)/dataSource.o $(bin)/echantillon.o





ALL: $(PROGRAMS).app

$(PROGRAMS).app:	$(Lib)/main.cpp $(allobj) $(Lib)/TestUnitaire.cpp $(Lib)/main.h
					echo Creation de $(PROGRAMS)
					g++ $(Lib)/main.cpp $(Lib)/TestUnitaire.cpp $(allobj) -o $(PROGRAMS).app

#Creation LibDataSource
$(bin)/dataSource.o: $(Lib)/DataSource/dataSource.cpp $(Lib)/DataSource/dataSource.h
			echo Création dataSource.o
			g++ $(Lib)/DataSource/dataSource.cpp -c -o $(bin)/dataSource.o

#Creation LibEchantillon
$(bin)/echantillon.o: $(Lib)/Echantillon/echantillon.cpp $(Lib)/Echantillon/echantillon.h
			echo Création echantillon.o
			g++ $(Lib)/Echantillon/echantillon.cpp -c -o $(bin)/echantillon.o

#Creation LibData
$(bin)/data1D.o: $(Lib)/Data/data1D.cpp $(Lib)/Data/data1D.h
			echo Création data1D.o
			g++ $(Lib)/Data/data1D.cpp -c -o $(bin)/data1D.o

$(bin)/data2D.o: $(Lib)/Data/data2D.cpp $(Lib)/Data/data2D.h
			echo Création data2D.o
			g++ $(Lib)/Data/data2D.cpp -c -o $(bin)/data2D.o

#Creation Template Liste
$(bin)/Liste.o:	$(LibListeTemplate)/Liste.cpp $(LibListeTemplate)/Liste.h 
			echo Création Liste.o
			g++ $(LibListeTemplate)/Liste.cpp -c -o $(bin)/Liste.o

$(bin)/ListeTriee.o:	$(LibListeTemplate)/ListeTriee.cpp $(LibListeTemplate)/ListeTriee.h
			echo Création ListeTriee.o
			g++ $(LibListeTemplate)/ListeTriee.cpp -c -o $(bin)/ListeTriee.o

$(bin)/Iterateur.o:	$(LibListeTemplate)/Iterateur.cpp $(LibListeTemplate)/Iterateur.h
				echo Création Iterateur.o
				g++ $(LibListeTemplate)/Iterateur.cpp -c -o $(bin)/Iterateur.o






clear: clean

clean:
	echo "Supression *.o ..."
	rm obj/*
	rm EtudeStat.app

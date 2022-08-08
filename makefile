.SILENT:

PROGRAMS = EtudeStat
bin = obj
Lib = source
LibListeTemplate = $(Lib)/Liste_Template

allobj = $(bin)/Liste.o $(bin)/ListeTriee.o $(bin)/Iterateur.o





ALL: $(PROGRAMS).app

$(PROGRAMS).app:	$(Lib)/main.cpp $(allobj)
					echo Creation de $(PROGRAMS)
					g++ $(Lib)/main.cpp $(allobj) -o $(PROGRAMS).app



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
#	rm obj/threadVaisseauAmiral.o
	rm SpaceInvaders.app

all_test : test_bib test_app clean

test_bib: test_bib_classes test_bib_algo clean

test_app: test_app_fichier test_app_GUI clean

clean:
	rm -f *.o

# TEST BIB =====================================================================
test_bib_algo:

## TEST CLASSES ================================================================
test_bib_classes: test_bib_classes_Arc test_bib_classes_Graphe test_bib_classes_Matrice test_bib_classes_Sommet clean

test_bib_classes_Arc: clean
	#Partie code
	g++ ../src/bib/classes/Arc.cc -c
	#Partie test
	g++ Arc.o test_bib/classes/Arc.cc -o OUTarc.o
	./OUTarc.o
test_bib_classes_Graphe: clean
	#Partie code
	g++ ../src/bib/classes/Graphe.cc -c
	#Partie test
	g++ Graphe.o test_bib/classes/Graphe.cc -o OUTgraphe.o
	./OUTgraphe.o
test_bib_classes_Matrice: clean
	#Partie code
	g++ ../src/bib/classes/Matrice.cc -c
	#Partie test
	g++ Matrice.o test_bib/classes/Matrice.cc -o OUTmatrice.o
	./OUTmatrice.o
test_bib_classes_Sommet: clean
	#Partie code
	g++ ../src/bib/classes/Sommet.cc -c
	#Partie test
	g++ Sommet.o test_bib/classes/Sommet.cc -o OUTSommet.o
	./OUTSommet.o

##==============================================================================
#===============================================================================

# TEST APP =====================================================================
test_app_fichier: clean

test_app_GUI: clean
#===============================================================================

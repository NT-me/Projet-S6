#include <string.h>
#include "../bib/Graphe.hh"
#include "../bib/Sommet.hh"
#include "../bib/Matrice.hh"
#include "../bib/Arc.hh"

int sauvegarde(String path = NULL, Graphe G);

Graphe chargement(String path);

bool verif_file(Document D);

int suppression(String path);

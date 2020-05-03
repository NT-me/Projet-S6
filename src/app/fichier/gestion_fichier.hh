#include <string.h>

#include "../../bib/classes/GrapheMatrice.hh"
#include "../../bib/classes/Arc.hh"
#include "../../bib/classes/Sommet.hh"

int sauvegarde(String path = NULL, Graphe G);

Graphe chargement(String path);

bool verif_file(Document D);

int suppression(String path);

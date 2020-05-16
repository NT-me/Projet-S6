#include <string.h>
#include "../../bib/classes/classes.hh"

#include "../../../libExt/rapidjson/document.h"


int sauvegarde(Graphe G, std::string path="NULL");

Graphe chargement(string path);

bool verif_file(string path);

int suppression(string path);

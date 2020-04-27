#include <stdlib.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

#ifndef STRUCTS
#define STRUCTS

typedef struct Valeur_Vecteur{
  bool type; // Si 0 entier, si 1 réel.
  int valeur_entiere;
  float valeur_reel;
}VectVal;

typedef struct ROW{
  int tache;
  string nom_tache;
  int duree;
  vector <int> taches_anterieures;
  vector <int> taches_posterieures;
} pert_row;

#endif

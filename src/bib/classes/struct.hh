#ifndef STRUCTS_HH
#define STRUCTS_HH

#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;



struct VectVal {
  bool type; // Si 0 entier, si 1 réel.
  int valeur_entiere;
  float valeur_reel;

  VectVal operator=(VectVal v2){
   type = v2.type;
   valeur_entiere = v2.valeur_entiere;
   valeur_reel = v2.valeur_reel;
   return *this;
 }
};

inline bool operator== (VectVal v1, VectVal v2){
  if (v1.type == v2.type){
    if (v1.valeur_entiere == v2.valeur_entiere || v1.valeur_reel == v2.valeur_reel){
        return true;
    }
  }
  return false;
}




typedef struct ROW{
  int tache;
  string nom_tache;
  int duree;
  vector <int> taches_anterieures;
  vector <int> taches_posterieures;
} pert_row;

inline bool operator== (pert_row v1, pert_row v2){
  if (v1.tache == v2.tache && v1.nom_tache == v2.nom_tache && v1.taches_anterieures == v2.taches_anterieures
      && v1.taches_posterieures == v2.taches_posterieures){
        return true;
  }
  return false;
}

#endif

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




#endif

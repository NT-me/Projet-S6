#include "Graphe.hh"

Graphe(string nom, vector<Sommet> listeS, vector<Arc> listeA, string path){
  this->etiquette = nom;
  this->liste_Sommets = listeS;
  this->liste_Arcs = listeA;
  this->path = path;
}

Graphe(string nom){ // Création Graphe vide
  this->etiquette = nom;
  this->path = NULL;
}

Graphe(Matrice& M){ // Création d'un Graphe via une matrice d'adjacence
  if(M.getType()!=0){
    std::cout << "/*Mauvais type de Matrice */" << '\n';
    this->etiquette ="ERROR_TYPEMATRICE"
  }
  else{
    this->etiquette = "Graphe Adjacence";
    int id = 0; //nombre d'arcs
    for(int i=0; i<M.gettV(); i++){
        this->liste_Sommets.push_back(Sommet(i)); // Création du Sommet avec son numéro
    }

    for(int i=0; i<M.gettV(); i++){   // ID Sommet entrant
      for(int j=0; j<M.gettV(); j++){ // ID Sommet sortant
        if(M.getTab()[i][j]){         // Si il existe un arc
          this->liste_Arcs.push_back(Arc(id, i, j)); // Création d'un Arc entre i et j avec son id
          id++; // On incrémente le nombre d'arc
        }
      }
    }
  }
  this->path = NULL;
}

Graphe(Graphe& G){  // Constructeur de copie
  this->etiquette = G.etiquette;
  this->liste_Sommets = G.liste_Sommets;
  this->liste_Arcs = G.liste_Arcs;
  this->path = G.path;
}

Graphe(vector<vector<int>> liste_voisin){

  this->path = NULL;
}

~Graphe(){

}

#include "Arc.hh"
#include "Sommet.hh"
#include "Matrice.hh"
#include <vector>
#include <cstring>

class Graphe{
private:
  String etiquette;
  vector<Arc> liste_Arcs;
  vector<Sommet> liste_Sommets;
  String path;

public:
  Graphe(String nom, vector<Sommet> listeS, vector<Arc> listeA, String path);
  Graphe(String nom);
  Graphe(Matrice& M);
  Graphe(Graphe& G);
  Graphe(vector<vector<int>> liste_voisin);
  ~Graphe();

  Matrice conversion_vers_Matrice_adj();
  Matrice conversion_vers_Matrice_inc();
  vector<vector<int>>  conversion_vers_listeDeVoisins();
  int ajout_Sommet(int id, int posx, int posy);
  
}

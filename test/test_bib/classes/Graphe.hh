#include "Arc.hh"
#include "Sommet.hh"
#include "Matrice.hh"
#include <vector.h>
#include <string.h>

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

  String getEtiq();
  vector<Arc> getListe_Arcs();
  vector<Sommet> getListe_Sommets();
  String getPath();

  void setEtiq(String etiq);
  void setListe_Arc(vector<Arc> LA);
  void setListe_Sommet(vector<Sommet> LS);
  void setPath(String p);

  Matrice conversion_vers_Matrice_adj();
  Matrice conversion_vers_Matrice_inc();
  vector<vector<int>>  conversion_vers_listeDeVoisins();
  int ajout_Sommet(int id, int posx, int posy);
  int supprimer_Sommet(int id);
  int ajout_Arc(int id_Sdepart, int id_Sarrive);
  int supprimer_Arc(int id);
  vector<Sommet> getVecteurSommet(vector<int> id);

  bool operator==(Graphe const& G1, Graphe const& G2);
  bool operator!=(Graphe const& G1, Graphe const& G2);
  Graphe operator=(Graphe const& G1, Graphe const& G2);
}

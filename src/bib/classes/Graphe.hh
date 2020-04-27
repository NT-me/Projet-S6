#include "Arc.hh"
#include "Sommet.hh"
#include "Matrice.hh"
#include <vector>
#include <string>

class Graphe{
private:
  string etiquette;
  vector<Arc> liste_Arcs;
  vector<Sommet> liste_Sommets;
  string path;

public:
  Graphe(string nom, vector<Sommet> listeS, vector<Arc> listeA, string path);
  Graphe(string nom);
  Graphe(Matrice& M);
  Graphe(Graphe& G);
  Graphe(vector<vector<int>> liste_voisin);
  ~Graphe();

  string getEtiq();
  vector<Arc> getListe_Arcs();
  vector<Sommet> getListe_Sommets();
  string getPath();

  void setEtiq(string etiq);
  void setListe_Arc(vector<Arc> LA);
  void setListe_Sommet(vector<Sommet> LS);
  void setPath(string p);

  Matrice conversion_vers_Matrice_adj();
  Matrice conversion_vers_Matrice_inc();
  vector<vector<int>>  conversion_vers_listeDeVoisins();
  int ajout_Sommet(int id, int posx, int posy);
  int supprimer_Sommet(int id);
  int ajout_Arc(int id_Sdepart, int id_Sarrive);
  int supprimer_Arc(int id);
  vector<Sommet> getVecteurSommet(vector<int> id);

<<<<<<< HEAD
  bool operator==(Graphe const& G1);
  bool operator!=(Graphe const& G1);
  Graphe operator=(Graphe const& G1);

};
=======

};

bool operator==(Graphe const& G1, Graphe const& G2);
bool operator!=(Graphe const& G1, Graphe const& G2);
Graphe operator=(Graphe const& G1, Graphe const& G2);
>>>>>>> 1bcd35e829c72ae8fd857c43a69ccec878c94a27

#ifndef MATRICE_HH
#define MATRICE_HH

#include <vector>
#include "struct.hh"
#include "iostream"

class Graphe;

class Matrice {

private:
  int taille_V;		// nombre de sommets
  int taille_E;		// nombre d'arcs (dans le cas d'une matrice d'incidence)
  int type;			// type de la matrice (0->adjacence,1->incidence)
  vector<vector <int>> tab;			// matrice

public:
  Matrice(Graphe G, int type);
  Matrice(int tailleV);
  Matrice(int tailleV, int tailleE, int t);
  Matrice(const Matrice &M);
  ~Matrice();
  int gettV();
  int gettE();
  int getType();
  vector<vector <int>> getTab();

  void setV(int v);
  void setE(int e);
  void setType(int type);
  void setTab(vector<vector <int>> tab);

  Matrice conversion_incidence();
  Matrice inversion_Matrice();
  Graphe conversionGraphe();
  int Sommet_non_isole();
  int modifTab(int x, int y, int n);
  void supprLigne(int x);
  void supprCol(int y);

  bool operator==(Matrice & M1);
  bool operator!=(Matrice & M1);
  Matrice operator=(Matrice & M1);

};


#endif
#ifndef GRAPHE_HH
#define GRAPHE_HH

#include "Arc.hh"
#include "Sommet.hh"

#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>

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
  Graphe(const Graphe& G);
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

  bool const operator==(Graphe const& G1);
  bool operator!=(Graphe const& G1);
  //Graphe operator=(Graphe const& G1);
  void operator=(Graphe const& G1);

};

#endif

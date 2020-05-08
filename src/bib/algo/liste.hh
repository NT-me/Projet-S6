#include "../classes/classes.hh"
#include <utility>
#include <iostream>
#include <string.h>
#include <vector>

#define INFINI 999999999

#ifndef HH_LISTE
#define HH_LISTE

using namespace std;

pair<vector<vector<int>>, vector<int>> calcul_Bellman(Matrice M, Sommet S);

pair<Matrice, Matrice> calcul_Floyd_Warshall(Matrice M);

vector<int> liste_floyd(Matrice Parent, int deb, int fin);

int calcul_degres_entrant(Matrice M, int id);

int calcul_degres_sortant(Sommet S);

pair<int, int> calcul_degres_entrant_sortant(Matrice M, Sommet S);

vector<int> coloration_Graphe(Graphe G);

int couleur_adjacente(Sommet S);

vector<vector<int>> stables_Graphe(Matrice M);

vector<vector<int>> cliques_Graphe(Matrice M);

vector<int> voisin_sommet(Matrice M, int ID);

int gestion_flots(Graphe G, int ID_source, int ID_puit);

vector<pert_row> calcul_posterite(vector<pert_row>);

Graphe pert(vector<pert_row>);

Graphe arborescence(Graphe G);

Graphe anti_arborescence(Graphe G);

int connexite(Matrice M);

vector<vector<int>> chaine_eulerienne(Matrice M);

vector<vector<int>> chaine_hamiltonienne(Matrice M);

vector<int> postier_chinois(Matrice M);

vector<int> voyageur_de_commerce(vector<int>, Matrice M);

#endif

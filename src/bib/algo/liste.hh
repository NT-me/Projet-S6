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

vector<vector<int>> chaine_eulerienne(Matrice M){
	 vector<int> path;
  vector<vector<int>> result;

  if(M.getType() != 0){
    std::cout << "ERROR WRONG MATRICE TYPE" << '\n';
    return result;
  }
  else{
    int pred=0,succ=0,Dmax=0,Fmax=0;
    int deb=0;fin=0;
    vector<int> out;

    // Vérifie si il existe un chemin Eulérien
    for(int i=0;i<M.gettV();i++){
      for(int j=0;j<M.gettV();j++){
        if(M.getTab()[i][j]) succ++;
        if(M.getTab()[j][i]) pred++;
      }
      out.push_back(succ);    // Stocke le nombre de successeurs

      if(succ-pred>1 || pred-succ>1){
        std::cout << "NO EULERIAN PATH" << '\n';
        return res;
      }
      else{
        if(pred-succ==1){
          fin = i;          // Sommet d'arrivée
          Fmax++;
        }
        else if(succ-pred==1){
          deb = i;         // Sommet de départ
          Dmax++;
        }
      }

      if(!connexite(M) && !succ && !pred){
        std::cout << "NO EULERIAN PATH" << '\n';
        return res;
      }
      if(Dmax>1 || Fmax>1){
        std::cout << "NO EULERIAN PATH" << '\n';
        return res;
      }
      succ = 0;
      pred = 0;
    }

    // Nombre d'arcs
    int nbA;
    for(int i=0;i<M.gettV();i++){
      for(int j=0;j<M.gettV();j++){
        if(M.getTab()[i][j]) nbA++;
      }
    }

    // Sommet de départ
    for(int i=0;i<M.gettV();i++){
      if(deb==0 && out[i]>0) deb = i;
    }

    // #########################
    int i = deb;
    while(out[i] != 0){
      for(int j=0;j<M.gettV();j++){
        if(M.getTab[i][j]){
          --out[i];
          path.push_back(i);
          i = j;
          j = 0;
        }
      }
      i++;
    }

    path.push_back(i);
    }

    if(path.size() ==  nbA+1) res.first = path
  }
  return res;
}

vector<vector<int>> chaine_hamiltonienne(Matrice M);

vector<int> postier_chinois(Matrice M);

vector<int> voyageur_de_commerce(vector<int>, Matrice M);

#endif

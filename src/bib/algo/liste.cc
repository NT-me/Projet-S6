#include "liste.hh"

pair<vector<vector<int>>, vector<int>> calcul_Bellman(Matrice M, Sommet S){
  // int INFINI = 999999999;

  // vector<int> dist;
  // vector<vector<int>> prev;
  // dist.resize(M.gettV());
  // for(int i=0;i<M.gettV();i++){
  //     //M.getTab()[S.getID][i];//case i j du Tableau tab dans la Matrice M
  //     // <<0>,<0,1>>,<0,1>
  //     dist.push_back(INFINI);
  // }
  //
  // dist[S.getID()] = 0;
  //
  // for(int i=0;i<M.gettV();i++){
  //   for(int j=0;j<M.gettE();j++){
  //     if(dist(i) > (dist(j) + M.getTab()[i][j]))
  //   }
  // }
}

pair<Matrice, Matrice> calcul_Floyd_Warshall(Matrice M){
  //parcourt de la matrice d'adjacence
  if(M.getType()!=0){
    Matrice MP(M.gettV(),M.gettV(),2),MT(M.gettV(),M.gettV(),3);
    pair<Matrice,Matrice> res{MP,MT};
    std::cout << "ERROR WRONG MATRICE TYPE" << '\n';
    return res; //retour de pair<Matrice,Matrice> vide
  }
  else{
    //initialisation de MatriceParent
    Matrice MP(M.gettV(),M.gettV(),3);
    for(int i=0;i<M.gettV();i++){
      for(int j=0;j<M.gettV();j++){
        if(M.getTab()[i][j]!=0){
          MP.modifTab(i,j,i);
        }
        else
        MP.modifTab(i,j,-1);// il n'y a pas de parent direct

      }
    }

    //init de Matrice de poids
    Matrice MT(M.gettV(),M.gettV(),2);
    for(int i=0;i<M.gettV();i++){
      for(int j=0;j<M.gettV();j++){
        if(i==j){
          MT.modifTab(i,j,0);
        }
        else if(M.getTab()[i][j]!=0){
          MT.modifTab(i,j,M.getTab()[i][j]);
        }
        else{
          MT.modifTab(i,j,INFINI);// il n'y a pas de chemin

        }

      }
    }
    


    for (int k = 0; k < M.gettV();k++) {
      for (int i = 0; i < M.gettV(); i++) {
        for (int j = 0; j < M.gettV(); j++) {
        //  if(k!=j&&i!=j&&k!=i){
            if(MT.getTab()[i][j]> (MT.getTab()[i][k]+MT.getTab()[k][j])){
              MT.modifTab(i,j,MT.getTab()[i][k]+MT.getTab()[k][j]);
              MP.modifTab(i,j,k);
            }

        //  }
        }
      }
    }
    //création de la pair<Matrice,Matrice> res
    pair<Matrice,Matrice> res{MT,MP};
    return res;

  }

}

vector<int> liste_floyd(Matrice Parent, int deb, int fin){
  if(Parent.getType()!=3){
    std::cout << "ERROR WRONG TYPE" << '\n';
    vector<int> res{-1};
    return res;
  }
  else{
    vector<int> res{deb};
    while(Parent.getTab()[deb][fin]!=fin){
      if(Parent.getTab()[deb][fin]!=-1){
        deb = Parent.getTab()[deb][fin];
        res.push_back(deb);

      }
      else{
        std::cout << "PAS DE CHEMIN" << '\n';
        vector<int> res{-2};
        return res;
      }
    }
    res.push_back(fin);
    return res;
  }
}

int calcul_degres_entrant(Matrice M, int id){}

int calcul_degres_sortant(Sommet S){}

pair<int, int> calcul_degres_entrant_sortant(Matrice M, Sommet S){}

vector<int> coloration_Graphe(Graphe G){}

int couleur_adjacente(Sommet S){}

vector<vector<int>> stables_Graphe(Matrice M){}

vector<vector<int>> cliques_Graphe(Matrice M){}

vector<int> voisin_sommet(Matrice M, int ID){}

int gestion_flots(Graphe G, int ID_source, int ID_puit){}

vector<pert_row> calcul_posterite(vector<pert_row>){}

Graphe pert(vector<pert_row>){}

Graphe arborescence(Graphe G){}

Graphe anti_arborescence(Graphe G){}

int connexite(Matrice M){}

vector<vector<int>> chaine_eulerienne(Matrice M){}

vector<vector<int>> chaine_hamiltonienne(Matrice M){}

vector<int> postier_chinois(Matrice M){}

vector<int> voyageur_de_commerce(vector<int>, Matrice M){}

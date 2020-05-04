#include "liste.hh"
#include <map>
#include <utility>
#include <vector>

pair<vector<vector<int>>, vector<int>> calcul_Bellman(Matrice M, Sommet S){}

pair<Matrice, Matrice> calcul_Floyd_Warshall(Matrice M){}

vector<int> liste_floyd(Matrice Parent, int deb, int fin){}

int calcul_degres_entrant(Matrice M, int id){}

int calcul_degres_sortant(Sommet S){}

pair<int, int> calcul_degres_entrant_sortant(Matrice M, Sommet S){}

vector<int> coloration_Graphe(Graphe G){
    vector<int> res(G.getListe_Sommets().size());//vecteur qui contiendra l'ensemble des couleurs
    vector<Sommet> listeS= G.getListe_Sommets();
    vector<pair<int, Sommet>> L;//vecteur qui contient les Sommets non colorés ainsi que le nb de voisins
    Matrice M(G, 0);
    map<string, VectVal> map;
    int s;
    VectVal v;
    v.type = 0;
    
    //On ajoute le premier sommet
    pair<int, int> tmp = calcul_degres_entrant_sortant(M, G.getListe_Sommets()[0]);
    pair<int, Sommet> t(tmp.first+tmp.second, G.getListe_Sommets()[0]);
    L.push_back(t);
    
    //on classe les sommets par ordre décroissant de degré
    //peut être optimisée il me semble
    for(int i=1; i<G.getListe_Sommets().size(); i++){
        tmp = calcul_degres_entrant_sortant(M, G.getListe_Sommets()[i]);
        t.first = tmp.first+tmp.second;
        t.second = G.getListe_Sommets()[i];
        for(int j=0; j<L.size(); j++){
            if(t.first >= L[j].first){
                L.insert(L.begin()+j, t);
            }
        }
    }
    // AJOUTER DANS LE GRAPHE LA COULEUR

  /*  res[L[0].second.getID()] = 1;
    L.erase(L.begin());
    map = G.getListe_Sommets()[0].getCU();
    map.insert(pair<string, VectVal>("couleur", v));
    G.getListe_Sommets()[0].setCU(map);

    while (L.size()>0) {
        //choix du sommet a colorer
        s=0;
        for(int i=1; i<L.size(); i++){
            if(couleur_adjacente(L[s]) < couleur_adjacente(L[i])){
                s=i;
            }
            if(DSAT(L[s]) == DSAT(L[i])){
                if(L[s].first < L[i].first){
                    s=i;
                }
            }
        }
        //coloration du sommet
        while (res[L[s].second.getID()] == 0) {
            //trouver la plus petite couleur
            //parcours de la matrice pour trouver les voisins mise dans un vecteur?
            //puis comparaison avec L?

        }
        //suppression du sommet de la liste des sommets non colorés
        L.erase(L.begin()+s);
    }*/
}

pair<int, vector<int>> couleur_adjacente(int id, vector<int> v, Matrice M){
    vector<int> res;
    int r = 0;
    for (int i=0; i<M.gettE(); i++) {
        if(i!=id){
            if(M.getTab()[id][i]==1){
                for(int j=0; j<res.size(); j++){
                    if(res[j]>=v[i]){
                        res.insert(res.begin()+j, v[i]);
                        if(res[j]!=v[i]){
                            r++;
                        }
                        break;
                    }
                    if(j==res.size()){
                        res.push_back(v[i]);
                        r++;
                        break;
                    }
                }
            }
            else{
                if(M.getTab()[i][id]==1){
                    for(int j=0; j<res.size(); j++){
                     if(res[j]>=v[i]){
                        res.insert(res.begin()+j, v[i]);
                        if(res[j]!=v[i]){
                            r++;
                        }
                        break;
                    }
                    if(j==res.size()){
                        res.push_back(v[i]);
                        r++;
                        break;
                    }
                     }
                }
            }
        }
        
    }
    return pair<int, vector<int>>(r, res);
}

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

#include "liste.hh"
#include <map>
#include <string>
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
    pair<int, vector<int>> voisin;
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
                break;
            }
            if(L.size()-1){
                L.push_back(t);
                break;
            }
        }
    }

    // AJOUTER DANS LE GRAPHE LA COULEUR

    res[L[0].second.getID()] = 1;
    L.erase(L.begin());
    map = G.getListe_Sommets()[0].getCU();
    map.insert(pair<string, VectVal>("couleur", v));
    G.getListe_Sommets()[0].setCU(map);

    while (L.size()>0) {
        //choix du sommet a colorer
        s=0;
        voisin = couleur_adjacente(L[s].second.getID(), res, M);
        for(int i=1; i<L.size(); i++){
            if(voisin.first < couleur_adjacente(L[i].second.getID(), res, M).first){
                s=i;
                voisin = couleur_adjacente(L[i].second.getID(), res, M);
            }
            else{
                if(voisin.first == couleur_adjacente(L[i].second.getID(), res, M).first){
                if(L[s].first < L[i].first){
                    s=i;
                    voisin = couleur_adjacente(L[i].second.getID(), res, M);
                }
            }
            }
            
        }
        //coloration du sommet
        while (res[L[s].second.getID()] == 0) {
            v.valeur_entiere = 1;
            for(int i=0; i<voisin.second.size(); i++){
                if(v.valeur_entiere<voisin.second[i]){
                    res[L[s].second.getID()] = v.valeur_entiere;
                    map = G.getListe_Sommets()[s].getCU();
                    map.insert(pair<string, VectVal>("couleur", v));
                    G.getListe_Sommets()[s].setCU(map);
                }
            }

        }
        //suppression du sommet de la liste des sommets non colorés
        L.erase(L.begin()+s);
    }

    return res;
}

pair<int, vector<int>> couleur_adjacente(int id, vector<int> v, Matrice M){
    vector<int> res;
    int r = 0;
    for (int i=0; i<M.gettV(); i++) {
        if(i!=id){
            if(M.getTab()[id][i]==1 && v[i]!=0){
                if(res.empty()){
                    res.push_back(v[i]);
                    r++;
                    break;
                }
                for(int j=0; j<res.size(); j++){
                    if(res[j]<v[i]){
                        res.insert(res.begin()+j, v[i]);
                        r++;
                        break;
                    }
                    if(res[(j)==v[i]]){
                        r++;
                        break;
                    }
                    if(j==res.size()-1){
                        res.push_back(v[i]);
                        r++;
                        break;
                    }
                }
            }
            else{
                if(v[i]!=0 && M.getTab()[i][id]==1 ){
                    if(res.empty()){
                        res.push_back(v[i]);
                        r++;
                        break;
                    }
                    for(int j=0; j<res.size(); j++){
                        if(res[j]<v[i]){
                            res.insert(res.begin()+j, v[i]);
                            r++;
                            break;
                        }
                        if(res[j]==v[i]){
                            r++;
                            break;
                        }
                        if(j==res.size()-1){
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

vector<pert_row> calcul_posterite(vector<pert_row> v){}

Graphe pert(vector<pert_row> v){
    Graphe G ("PERT");
    vector<Sommet> ListeS;
    vector<Arc> ListeA;
    VectVal val; 
    map<string, VectVal> mapS;
    map<string, VectVal> mapA;

    val.type = 0;
    val.valeur_entiere = 0;

    mapA.insert(pair<string, VectVal>("duree", val));
    mapS.insert(pair<string, VectVal> ("date au plus tot", val));
    ListeS.push_back(Sommet(100, 100, "Départ", 0, mapS));
    for(int i=0; i<v.size(); i++){
        if(v[i].taches_anterieures.empty()){
            val.valeur_entiere = v[i].duree;
            mapS["date au plus tot"] = val;
            ListeS.push_back(Sommet(100, 100, "fin " + to_string(v[i].tache), ListeS.size(), mapS));
            mapA["duree"]=val;
            ListeA.push_back(Arc(v[i].nom_tache, v[i].tache, 0, ListeS.back().getID(), mapA));
            v.erase(v.begin()+i);
            i=i-1;
        }
    }
    while (!v.empty()) {
        
    }

}

Graphe arborescence(Graphe G){}

Graphe anti_arborescence(Graphe G){}

int connexite(Matrice M){}

vector<vector<int>> chaine_eulerienne(Matrice M){}

vector<vector<int>> chaine_hamiltonienne(Matrice M){}

vector<int> postier_chinois(Matrice M){}

vector<int> voyageur_de_commerce(vector<int>, Matrice M){}

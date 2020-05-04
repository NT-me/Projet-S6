#include "liste.hh"

pair<vector<vector<int>>, vector<int>> calcul_Bellman(Matrice M, Sommet S){}

pair<Matrice, Matrice> calcul_Floyd_Warshall(Matrice M){}

vector<int> liste_floyd(Matrice Parent, int deb, int fin){}

int calcul_degres_entrant(Matrice M, int ID){
    
    /* déclare variable int vide  */
        int nb_entrant = 0;
    
    /* ittération sur le nombre de sommet de la matrice en paramètre */
        for (int i=0; i < M.gettV() ; i++){
            if (M.getTab()[i][ID]) nb_entrant++;
         }
    return nb_entrant;
    }

int calcul_degres_sortant(Sommet S){
    
    /* déclare variable int vide  */
        int nb_sortant = 0;
    
    /* ittération sur la taille du vecteur de sommet S, contenant les arcs sortants */
        for (int i=0;  i < S.getVecArc().size();  i++){
             nb_sortant ++;
         }
    return nb_sortant;
    }

pair<int, int > calcul_degres_entrant_sortant(Matrice M, Sommet S){

     pair<int,int> result( calcul_degres_entrant(M, S.getID()) , calcul_degres_sortant(S) );

     return result;
    }

vector<int> coloration_Graphe(Graphe G){}

int couleur_adjacente(Sommet S){}

vector<vector<int>> stables_Graphe(Matrice M){}

vector<vector<int>> cliques_Graphe(Matrice M){}

vector<int> voisin_sommet(Matrice M, int ID){
    
    /* déclare variable vector vide  */
    vector<int> voisins;
     
     /* ittération sur le nombre de sommet de la matrice M  */
        for (int i=0; i < M.gettV() ; i++){
            if ( M.getTab()[i][ID] ) {
                voisins.insert(voisins.end(),i);
            }
        }
    return voisins;
    }

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

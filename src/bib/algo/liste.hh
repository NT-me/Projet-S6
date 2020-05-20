#include "../classes/classes.hh"
#include <utility>
#include <iostream>
#include <string.h>
#include <vector>

#define INFINI 999999999	/// Valeur INFINI utilis&eacute; dans le calcul de plus court chemin

#ifndef HH_LISTE
#define HH_LISTE

using namespace std;

/**
 * \brief Plus court chemin par l'algorithme de Ford-Bellman
 * Calcul du plus court chemin entre un Sommet et tout les autres Sommets du Graphe
 * Retourne une paire de vecteurs
 * Le premier vecteur sont les chemins pour aller du Sommet S &agrave; tout les autres Sommets du Graphe
 * Le deuxieme vecteur indique la distance entre le Sommet S et les autres Sommets du Graphe
 * @param M Matrice d'adjacence du Graphe (contenant le poids des Arcs)
 * @param S Sommet de d&eacute;part de l'algorithme
 * @return Paire de vecteurs. Chemin le plus court d'un sommet &agrave; tout les autres et distance
 * */
pair<vector<vector<int>>, vector<int>> calcul_Bellman(Matrice M, Sommet S);

/**
 * \brief Plus court chemin par l'algorithme de Floyd-Warshall
 * Calcul du plus court chemin entre chaque Sommet du Graphe
 * Retourne une paire de Matrices
 * La premiere Matrice est la Matrice de poids minimum pour aller d'un sommet &agrave; tout les autres
 * La deuxieme Matrice indique le prochain Sommet &agrave; atteindre pour effectuer le plus court chemin d'un sommet
 * @param M Matrice d'adjacence du Graphe (contenant le poids des Arcs)
 * @return Paire de Matrices
 * */
pair<Matrice, Matrice> calcul_Floyd_Warshall(Matrice M);

/**
 * \brief Plus court chemin entre deux Sommets
 * Cette fonction interprete la Matrice parent de la fonction Floyd_Warshall
 * Retourne une liste d'ID correspondant au plus court chemin entre deux sommets
 * @param Parent Matrice parent obtenue par Floyd_Warshall
 * @param deb Sommet de d&eacute;part du plus court chemin
 * @param fin Sommet d'arriv&eacute;e du plus court chemin
 * @return Liste de Sommets repr&eacute;sentant le plus court chemin
 * */
vector<int> liste_floyd(Matrice Parent, int deb, int fin);

/**
 * \brief Degr&eacute; entrant d'un Sommet
 * Cette fonction calcule le degr&eacute; entrant (nombre d'Arcs entrant) d'un Sommet
 * @param M Matrice d'adjacence sur lequel on applique la fonction
 * @param id ID du sommet pour lequel on calcule le degr&eacute;
 * @return Entier &eacute; au degr&eacute; entrant du Sommet
 * */
int calcul_degres_entrant(Matrice M, int id);


/**
 * \brief Degr&eacute; sortant d'un Sommet
 * Cette fonction calcule le degr&eacute; sortant (nombre d'Arcs sortant) d'un Sommet
 * @param id ID du sommet pour lequel on calcule le degr&eacute;
 * @return Entier &eacute; au degr&eacute; sortant du Sommet
 * */
int calcul_degres_sortant(Sommet S);

/**
 * \brief Calcul de degr&eacute;s d'un Sommet
 * Cette fonction calcule les degr&eacute;s entrant et sortant d'un Sommet 
 * Appel des fonctions calcul_degres_entrant et calcul_degres_sortant
 * @param M Matrice sur laquelle on applique la fonction
 * @param S Sommet pour lequel on veux connaitre le degr&eacute;
 * @return Paire d'entiers. Degr&eacute; sortant et entrant
 * */
pair<int, int> calcul_degres_entrant_sortant(Matrice M, Sommet S);

/**
 * \brief Coloration de Graphe par DSATUR
 * La fonction colore le graphe grace &agrave; l'algorithme DSATUR
 * Pour chaque position de ce vecteur un num&eacute;ro est attribu&eacute; permettant ainsi une coloration
 * @param G Graphe &agrave; colorer
 * @return vecteur
 * */
vector<int> coloration_Graphe(Graphe G);


/**
 * \brief Couleurs disponible pour la coloration de Graphe
 * Cette fonction est une sous fonction de coloration_Graphe.
 * Elle calcule les couleurs disponibles pour un Sommet en fonction de ses Sommets adjacents
 * @param id Sommet sur lequel on applique la fonction
 * @param v vecteur qui contient pour chaque sommet le numéro de couleur, si le sommet n'a pas &eacute;t&eacute; trait&eacute; c'est &agrave; 0
 * @param M matrice d'adjacence du Graphe
 * @return Couleur &agrave; affecter au Sommet
 * */

pair<int, vector<int>> couleur_adjacente(int id, vector<int> v, Matrice M);


/**
 * \brief Stables du Graphe
 * Cette fonction calcule les stables pr&eacute;sente dans le Graphe
 * @param M Matrice repr&eacute;sentant le Graphe
 * @return Liste des identifiants des Sommets formant un stable
 * */
vector<vector<int>> stables_Graphe(Matrice M);

/**
 * \brief Cliques du Graphe
 * Cette fonction calcule les cliques pr&eacute;sente dans le Graphe
 * @param M Matrice repr&eacute;sentant le Graphe
 * @return Liste des identifiants des Sommets formant une clique
 * */
vector<vector<int>> cliques_Graphe(Matrice M);

/**
 * \brief Voisins d'un Sommet
 * Cette fonction calcule les voisins d'un Sommet
 * @param Matrice associ&eacute;e au Graphe
 * @param ID Identifiant du Sommet sur lequel on applique la fonction
 * @return Vecteur d'identifiants des Sommets adjacents au Sommet ID
 * */
vector<int> voisin_sommet(Matrice M, int ID);

/**
 * \brief Algorithme d'Edmond Karp
 * Cette fonction calcule le flot maximum d'un Graphe
 * @param G Graphe sur lequel la fonction est appliqu&eacute;e
 * @param ID_source Sommet source
 * @param ID_puit Sommet d'arriv&eacute;e
 * @return Flot maximum sous forme d'entier
 * */
int gestion_flots(Graphe G, int ID_source, int ID_puit);

/**
 * \brief Contraintes de post&eacute;rit&eacute;
 * Cette fonction calcule les contraines de post&eacute;rit&eacute; pour chaque pert_row an argument
 * Retourne le meme vecteur avec les taches_posterieures mis &agrave; jour
 * @param vector Tache sur lesquelles on applique la fonction
 * @return Vecteur mis &agrave; jour
 * */
vector<pert_row> calcul_posterite(vector<pert_row>);

/**
 * \brief PERT
 * La fonction cr&eacute;e pour chaque tache un ou plusieurs Sommets et Arcs mod&eacute;lisant : 
 * Les contraintes d'anteriorit&eacute;
 * Le d&eacute;roulement de la tache
 * La fin de la tache
 * L'ensemble des tache est donn&eacute; en argument &agrave; travers le vecteur
 * @param vector Vecteur de taches
 * @return Graphe mod&eacute;lisant l'application de la fonction PERT
 * 
 * */
Graphe pert(vector<pert_row>);

/**
 * \brief Arborescence
 * @param G Graphe sur lequel est appliqu&eacute; la fonction
 * @return Graphe correspondant &agrave; l'arborescence du graphe courant
 * @return Graphe de valeur -1 si il n'y a pas d'arborescence
 * */
Graphe arborescence(Graphe G);

/**
 * \brief Anti-Arborescence
 * @param G Graphe sur lequel est appliqu&eacute; la fonction
 * @return Graphe correspondant &agrave; l'anti-arborescence du graphe courant
 * @return Graphe de valeur -1 si il n'y a pas d'anti-arborescence
 * */
Graphe anti_arborescence(Graphe G);

/**
 * \brief Connexit&eacute; du Graphe
 * Cette fonction recherche la connexit&eacute; du graphe grace &agrave; l'arborescence et anti-arborescence
 * @param M Matrice d'adjacence sur laquelle la recherche est faite
 * @return 1 si le graphe est connexe
 * @return 0 si le graphe n'est pas connexe
 * */
int connexite(Matrice M);

/**
 * \brief Chaine Eul&eacute;rienne
 * Cette fonction recherche un chemin Eul&eacute;rien dans la Graphe
 * @param Matrice d'adjacence sur laquelle on recherche le chemin
 * @return Liste d'ID de Sommet formant un chemin Eul&eacute;rien
 * @return Liste vide si il n'existe pas de chemin Eul&eacute;rien
 * */
vector<vector<int>> chaine_eulerienne(Matrice M);

/**
 * \brief Chaine Hamiltonienne
 * Cette fonction recherche un chemin Hamiltonien dans la Graphe
 * @param Matrice d'adjacence sur laquelle on recherche le chemin
 * @return Liste d'ID de Sommet formant un chemin Hamiltonien
 * @return Liste vide si il n'existe pas de chemin Hamiltonien
 * */
vector<vector<int>> chaine_hamiltonienne(Matrice M);

/**
 * \brief Probleme du Postier Chinois
 * Cette fonction r&eacute;sout le problème du postier chinois
 * @param M Matrice d'adjacence sur laquelle le probleme du postier chinois est appliqu&eacute;
 * @return Vecteur d'identifiants des Sommets contenus dans le cycle Eul&eacute;rien dans l'ordre du parcours
 * */
vector<int> postier_chinois(Matrice M);

/**
 * \brief Probleme du Voyageur de commerce
 * Cette fonction r&eacute;sout le probleme du voyageur de commerce avec l'algorithme de Little
 * @param M Matrice d'adjacence sur laquelle on applique le probleme du voyageur de commerce
 * @param vector ID des Sommets sur lesquels l'algorithme de Little va it&eacute;rer
 * @return Liste d'identifiants des Sommets correspondant au plus court chemin passant par chacun des Sommets
 * */
vector<int> voyageur_de_commerce(vector<int>, Matrice M);

#endif

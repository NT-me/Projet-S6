#include "Sommet.hh"
#include "Arc.hh"
#include "Matrice.hh"

class Graphe {
    
    private :
        int nbSommets			 // nombre de sommets du graphe
        String etiquette		 // nom du graphe
        Sommet liste_de_sommet	 	 // tous les sommets du graphe	
        Arc liste_arc			 // tous les arcs du graphe
        
    public :
        get; // getter de tout les attributs privés
        set; // setter de tout les attributs privés
        
        Graphe(String Nom, int nb_sommets, Sommet listeS, Arc listeA) // constructeur manuel
        Graphe(Graphe & G) // constructeur de copie
        Graphe(String Nom) // constructeur par défaut qui créé un graphe aleatoire
        
    Matrice convert_to_matrice_adj(){
    // Retourne la matrice d'adjacence correspondant aux listes
    }
    
    Matrice convert_to_matrice_inc(){
    // Retourne la matrice d'incidence correspondant aux listes
    }

    int ajout_Sommet(int numero, int posX, int posY){
    // Ajout un nouveau sommet et retourne son numéro
    }

    int supprimer_Sommet(int numero){
    // Appelle destructeur + Supprime le sommet des listes et renvoie son numéro
    }
    
    liste_de_voisins Convert_to_ldV(){
    // Retourne la liste de voisin correspondant au graphe
    }
    
    int ajout_Arc(Sommet, Sommet){
    // Ajoute un nouvel arc et renvoie son numero
    }
    
    int supprimer_Arc(numero){
    // Appelle destructeur + Supprime l'arc des liste et renvoie son numero
    }

};


struct  list_sommet {
    Sommet s;		// le sommet courant
    list_arc *a;	// les arcs ayant pour départ le sommet s
    list_sommet *ss	// le sommet suivant
}

struct list_arc {
    Arc a;			// l'arc courant
    list_arc *as;   // l'arc suivant
}

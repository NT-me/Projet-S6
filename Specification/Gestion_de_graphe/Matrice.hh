class Matrice {

int taille V;		// nombre de sommets 
int taille E;		// nombre d'arcs (dans le cas d'une matrice d'incidence)
bool type;			// type de la matrice (0->adjacence,1->incidence)
int **tab;			// matrice 

Matrice (int taille_V, Graphe G);					// constructeur cas adjacence  
Matrice (int taille_V, int taille E, Graphe G);	    // constructeur cas incidence

Matrice convert_incidence (Matrice A);				// conversion d'une matrice d'adjacence en matrice d'incidence 


};

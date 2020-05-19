#include "liste.hh"
/*
pair<vector<vector<int>>, vector<int>> calcul_Bellman(Matrice M, Sommet S){}

pair<Matrice, Matrice> calcul_Floyd_Warshall(Matrice M){}

vector<int> liste_floyd(Matrice Parent, int deb, int fin){}

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

int connexite(Matrice M)
{
	if(M.getType()!=0)
	{
		return -1;
	}
	vector<vector <int>> T = M.getTab(), ListeVoisin;
	
	vector<int> Marque, ListeSommet;	// 1 si marqué, 0 sinon ?
	
	
	
	
	for(int y = 0; y<M.gettV(); y++)
	{
		Marque.push_back(0);
		ListeVoisin.push_back({});
		ListeSommet.push_back(y);	//initialisation à vide
	}
	

	
	int i,j;
	
	for(i=0; i<M.gettV(); i++)	//boucle sommet départ
	{
		for(j=0; j<M.gettV(); j++)	//On teste tous les sommets de la matrice
		{
			
			if(T[i][j]==1)	//Si il existe un arc entre i et j
			{
				if(Marque[i]!=1)	//Si j n'est pas encore marqué par le programme
				{
					Marque[i] = 1;
					ListeVoisin[i].push_back(j);	//On l'ajoute à la liste des successeurs
				}
				
			}
		}
	}
	
	for(i=0; i<ListeVoisin.size(); i++)
	{
		for(j=0; j<ListeVoisin[i].size(); j++)
		{
			ListeSommet[ListeVoisin[i][j]] = -1;
			ListeSommet[i] = -1;
		}
	}
	
	int flag = 0;
	
	
	for(i=0; i<ListeSommet.size(); i++)
	{
		if(ListeSommet[i]!=-1)
		{
			
			flag = 1;
		}
	}
	
	if(flag == 0)
	{
		return 1; //graphe connexe
	}
	
	return 0; 	//graphe non connexe
	
}

vector<vector<int>> chaine_eulerienne(Matrice M){}

vector<vector<int>> chaine_hamiltonienne(Matrice M){}

vector<int> postier_chinois(Matrice M){}
* 
*/

Matrice reduction(Matrice M, int* SommeReduc)
{
	int Reduc;
	int i,j; 
	vector<vector <int>> T, L;
	Matrice N = Matrice(M);
	
	T = M.getTab();
	L = M.getTab();
	
	printf("Réductionn ligne\n");
	for(i=0; i<M.gettV(); i++)	//Calcul réduction sur les lignes
	{
		Reduc = 100000000;
		for(j=0; j<M.gettV(); j++)
		{
			if(T[i][j]<Reduc && T[i][j]>-1)
			{
				Reduc = T[i][j];	//Calcul min de la ligne
				printf("Reduc = %d\n",Reduc);
			}
		}
		
		SommeReduc = SommeReduc+Reduc;	//Calcul noeud racine

		
		for(j=0; j<M.gettV(); j++)
		{
			L[i][j] = T[i][j] - Reduc;		//Création de la matrice partiellement réduite
			printf("L[%d][%d] = %d\n",i,j,L[i][j]);
		}
	}
	
	printf("Réduction colonne\n");
	
	for(j=0; j<M.gettV(); j++)	//Calcul réduction sur les colonnes
	{
		Reduc = L[0][j];
		for(i=0; i<M.gettV(); i++)
		{
			if(L[i][j]<Reduc && T[i][j]>-1)
			{
				Reduc = L[i][j];	//min de la colonne
				printf("Reduc = %d\n", Reduc);
			}
		}
		
		SommeReduc = SommeReduc + Reduc;	//Calcul du noeud racine
		
		for(i=0; i<M.gettV(); i++)
		{
			L[i][j] = L[i][j] - Reduc;		//Création de la matrice réduite
			printf("L[%d][%d] = %d\n",i,j,L[i][j]);
		}
	}
	N.setTab(L);
	printf("done");
	
	//~ if(arbre.getListe_Sommets().size() == 0)
	//~ {
		//~ string etiquette = "racine";
		//~ Sommet racine = Sommet(1, 1, etiquette,   
		//~ // en gros il faut ajouter le sommet racine au graphe arbre avec abre.push_back(Sommet S); en gros
	//~ }
	return N;
}
void prolonge_arbre(int* somme_reduc, Matrice reduite, Graphe &arbre, int ID_sommet_a_visiter, vector<int> sommet_visiter_plus_tard)
{
	
	
	//on ne fait pas le premier cas, où la racine dois etre crée.
	//Ici, on va créer l'arbre à partir de la matrice des regrets.
    vector< vector<int> > tableau = reduite.getTab();	
    vector< vector<int>> regrets; // on ajoutera des vecteur avec trois elements, dans ce vecteur regrets
    
    //pour un vecteur donner, il y aura:
    //1er element -> regret
    //2eme element = coordonnées x
    //3eme element = coordonnées y
    
    
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////
    int regret = 0; // on initie un entier regret, qui contiendra la valeur du regret pour une case donnée.
    //ces deux entiers serviront à la recherche de l'entier minimal en x et en y.
    // car regret = minimum en x + minimum en y.
    int regretX = 0;
    int regretY = 0;
    
    
    
    //////////////////////////////////////////////////////////////////////////////////
    // PARTIE 1: ON INSTANCIE REGRET A UNE VALEUR ELEVE
    ////////////////////////////
    // il est important de leur associer une valeur élevé afin d'obtenu la plus petite valeur du tableau.
    for(int i = 0; i < reduite.gettV(); i++)  
    {
		 for(int j = 0; j < reduite.gettV(); j++) 
		 {
			if(tableau[i][j]>regret)
			{
				regret = tableau[i][j];
			}
		 }
    
    }
    regretX= regret;
    regretY= regret;
    /////////////////////////////////////////////////////////////////////////////////
    
    // PARTIE 2: ON RECHERCHE LES CASES DE LA MATRICE REDUITE DONT LA VALEUR EST ZERO
    // ET ON CALCULE LES REGRETS ASSOCIE, ON STOCKERA DANS UN VECTEUR TOUTS LES REGRETS
    
	for(int x = 0; x<reduite.gettV(); x++)
	{
		for(int y = 0; y<reduite.gettV(); y++)
		{
			if(tableau[x][y] == 0) 
			{
			// Si une case vaut zéro, il faut calculer le regret asscocié,
			// si on ne prendrait pas ce chemin
			
				for(int i = 0; i<reduite.gettV(); i++)
				{
					// on fera attention en cherchant la valeur minimale comme regret de pas prendre 0
					// ca c'est va valeur de la case étudiée justement.
					if(regretX > tableau[i][y] && (i != x) ) 
					{
						regretX = tableau[i][y];
					}
				}
				for(int j = 0; y<reduite.gettV();y++)
				{
					if(regretY > tableau[y][j] && (j != y) )
					{
						regretY = tableau[y][j];
					}	
				}
				regret = regretX + regretY;
				vector<int> regret_actuel {regret, x, y};
				regrets.push_back(regret_actuel);
			}
			
			///////////////////////////////////////
			// on remet à zero les valeur de regretX et regretY puis on leur donne la valeur max possible.
			regretX = 0;
			regretY = 0;
			regret = 0;
			
			 for(int i = 0; i < reduite.gettE(); i++)  
			 {
				for(int j = 0; j < reduite.gettE(); j++) 
				{
					if(tableau[i][j]>regret)
					{
						regret = tableau[i][j];
					}
				}
    
			 }
			regretX = regret;
			regretY = regret;
			///////////////////////////////////////////////
			
		}
	}
	
	
	
	
	//////////////////////////////////////////////////////////////////////////////////////
	//PARTIE 3, ON VA SELECTIONNER LE PLUS GRAND REGRET DANS LE VECTEUR AYANT STOCKE LES REGRETS
	// OU UNE CASE VALAIT 0 D APRES LA MATRICE REDUITE.
	//////////////////////////////////////////////////////////////////////////////////////
	int unsigned i;
	
	for(i= 0; i<regrets.size(); i++)
	 // usigned car le nombre d'element renvoyé par le la taile 
	// du vecteur est un entier non signé.
	
	// on va stocker les coordonnées X et Y du plus grand regret, afin de le recuperer après.
	{
		if(regrets[i][0]> regret)
		{
			regret = regrets[i][0];
		}
	}
	for(int unsigned i= 0; i<regrets.size(); i++)
	{
		int a = i; // on initilise l'entier a car i est un int unsigned et cela ne fonctionne pas 
		// pour s'en servir pour acceder aux indices des tableaux.
		if(regrets[a][0] == regret)
		{
			regretX = regrets[a][1];
			regretY = regrets[a][2];
		}
	}
	vector<int> REGRET_FINAL {regret, regretX, regretY}; // ici regret final contient la case avec le plus haut regret ainsi que ses coordonnées X et Y.
	regrets.clear(); // on supprimme tous les élèments du vecteur ca on n'en a plus besoin ici.kjhk
	
	
	
	
	
	
	
	////////////////////////////////////////////////////////////////////////////////////////
	// PARTIE 4: ON AJOUTE A L ABRE LE CAS DE L AJOUT DU CHEMIN VERS CE SOMMET AVEC LE PLUS GRAND REGRET
	// ET ENSUITE LE CAS OU ON NE PREND PAS CE MEME CHEMIN
	////////////////////////////////////////////////////////////////////////////////////////
	
	// on cherche à récupérer la valeur du plus grand indice de sommet
	int unsigned taille = arbre.getListe_Sommets().size();
	
	
	
	
	string name1_1 = to_string(regrets[i][1]);
	string name1_2 = to_string(regrets[i][2]);
	string name = name1_1 + name1_2;

	map <string, VectVal> Avec_chemin;
	map <string, VectVal> Sans_chemin;
	string a = "value";
	Avec_chemin[a]={somme_reduc + regret};
	
	//////////////////////////////////////////
	// Ici il faudrait la valeur du nouveau somme réduc de la prochaine reudction de la matrice
	reduite = reduction(reduite, somme_reduc);
	Sans_chemin[a]={somme_reduc + regret};
	///////////////////////////////////////////
	
    Sommet avec_chemin = Sommet(regretX, regretY, name, taille+1, Avec_chemin); 
    Sommet sans_chemin = Sommet(regretX, regretY, name, taille+2, Sans_chemin); 
	
	vector<Sommet> liste = arbre.getListe_Sommets();
	liste.push_back(avec_chemin);
	liste.push_back(sans_chemin);
	
	arbre.setListe_Sommet(liste);
	
	
	arbre.ajout_Arc(taille, taille+2);
	arbre.ajout_Arc(taille, taille+1);
	
	if(reduite.gettV() > 2)
	{
		
		prolonge_arbre(somme_reduc, reduite, arbre, taille+1, sommet_visiter_plus_tard);
	}
	/////////////////////////////////////////////////////
	// PARTIE 5: IL FAUT VISITER LES AUTRES CHEMIN EXCLU
	/////////////////////////////////////////////////////
	
	

	
}
vector<int> voyageur_de_commerce(vector<int> sommet, Matrice M)
{
	
	int* somme_reduc;
	vector <int> sommet_visiter_plus_tard;
	
	int test;
	if(M.getType()!=0)	//Test si c'est adj
	{
		return {-1};
	}
	
	
	
	vector<vector <int>> T, Reg;
	
	T = M.getTab();
	//Test si matrice d'entrée possède valeur négative
	for(int i=0; i<M.gettV(); i++)
	{
		for(int j=0; j<M.gettV(); j++)
		{
			if(T[i][j]<0)
			{
				test = 1;	//Valeur négative dans le tableau
			}
		}
	}
	if(test == 0)	//Si pas de valeur négative dans le tableau
	{
		for(int i=0; i<M.gettV(); i++)
		{
			T[i][i] = -1;	//Diagonal de la matrice prend la valeur -1 au lieu de zéro.
		}
	}
	
	
	reduction(M, somme_reduc);
	
	vector<int> juste_pour_le_retour_de_fonction_mais_a_supprimer;
	return juste_pour_le_retour_de_fonction_mais_a_supprimer;
}	
int maint(){
	  Matrice M(3);
      vector <int> v1;
      v1.push_back(1);
  
  
	v1 = voyageur_de_commerce(v1,M );
	
	// test l'affichage du vecteur
	for(int i = 0; i<10; i++)
	{
		printf("%d",v1[i]);
	}
	return 1;
}

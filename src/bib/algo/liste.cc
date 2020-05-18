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
Graphe Creer_arbre(int somme_reduc, Matrice reduite, Graphe arbre)
{
	
	
	//on ne fait pas le premier cas, où la racine dois etre crée.
	//Ici, on va créer l'arbre à partir de la matrice des regrets.
    vector< vector<int> > tableau = reduite.getTab();	
    vector< vector<int>> regrets; // on ajoutera des vecteur avec trois element, dans ce vecteur regrets
    
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
	// PARTIE 4: ON AJOUTE A L ABRE LE CAS DE LAJOUT DU CHEMIN VERS CE SOMMET AVAEC LE PLUS GRAND REGRET
	// ET ENSUITE LE CAS OU ON NE PREND PAS CE MEME CHEMIN
	////////////////////////////////////////////////////////////////////////////////////////
	 // on cherche à recuperer la valeur du plus grand indice de sommet
	int unsigned taille = arbre.getListe_Sommets().size();
	
	Arc A1 = Arc(regret,taille, taille+1);
	Arc A2 = Arc(regret, taille,taille+2);
	
	int ACALCULER = 0;
	string name1_1 = to_string(regrets[i][1]);
	string name1_2 = to_string(regrets[i][2]);
	string name = name1_1 + name1_2;
	
 //   Sommet avec_sommet = Sommet(regretX, regretY, taille +1, name, ACALCULER);
	//Sommet sans_sommet = Sommet(regretX, regretY, taille +2, name, ACALCULER);
	
	
	
	
	
	//arbre.ajout_Sommet();
	
	
	
	return arbre;
}
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
	return N;
}

vector<int> voyageur_de_commerce(vector<int>, Matrice M)
{
	int SommeReduc;
	int test;
	if(M.getType()!=0)	//Test si c'est adj
	{
		return {-1};
	}
	
	vector<vector <int>> T, Reg;
	int Num = 0;	//compteur pour l'id des sommets et des arcs
	
	Graphe G = Graphe("Arbre binaire");
	Sommet S = Sommet("etiq",Num);
	//Arc A = Arc();

	
	
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
	
	
	//Réduction de la matrice
	Matrice N = reduction(M, &SommeReduc);
	
	/*
	S.setID(Num);
	S.setCU(<"etiq",SommeReduc>);	//Sommet ayant la valeur de la réduction de matrice
	N.setTab(L);		//Initialisation de la copie de matrice M avec réduction 
	
	//Calcul du regret
	for(i=0; i<M.gettV(); i++)
	{
		for(j=0; j<M.gettV(); j++)
		{
			Reg[i][j]=0;		//Initialisation du tableau des regrets à zéro
		}
	}
	
	
	
	for(i=0; i<M.gettV(); i++)
	{
		for(j=0; j<M.gettV; j++)
		{
			if(L[i][j]==0)				//Si l'arc est de valeur nul
			{
				Regretlig = L[i][0];
				Regretcol = L[0][j];
				for(x=0; x<M.gettV(); x++)
				{
					if(L[i][x]<Regretlig && x!=i)
					{
						if(L[i][x]>-1)				//On ne prend pas en compte les valeurs négatives et L[i][j]
						{
							Regretlig = L[i][x];
						}
					}
				}
				
				for(y=0; y<M.gettV(); y++)
				{
					if(L[y][j]<Regretcol && y!=j)
					{
						if(L{y][j]>-1)
						{
							Regretcol = L[y][j];
						}
					}
				}
				
				Reg[i][j] = Regretlig  + Regretcol;		//Calcul du regret de l'arc nul
			}
		}
	}
	
	max = 0;
	for(i=0; i<M.gettV(); i++)	//Recherche regret maximum du tableau
	{
		for(j=0; j<M.gettV; j++)
		{
			if(Reg[i][j]>max)
			{
				x = i;
				y = j;
				max = Reg[i][j];	//On garde la valeur max, ainsi que les sommets entant et sortant de l'arc
			}
		}
	}
	
	//Itératif
	
	
	
	//Si on ne prend pas l'arc de regret max
	Sommet I = new Sommet(Num+1);			//Sommet quand l'arc n'est pas choisi
	I.setCU(<"etiq",S.getCU()+Reg[i][j]);	//Sommet I prend la valeur du regret plus la valeur du parent
											//poour la map, on sélectionne la valeur regret du père
	
	G.ajout_Sommet(I.id(),100,100);	
	G.ajout_Arc(Num,Num+1);
	
	//Si on prend l'arc de regret max
	Sommet J = new Sommet(Num+2);
	J.setCU(<"etiq",S.getCU());
	N.supprLigne(x);						//Suppression de la ligne i et de la colonne j de la matrice
	N.supprCol(y);							//Afin d'éviter une boucle dans la recherche de regret.
	
	N.modifTab(y,x,-1);						//On ne considère l'arc en sens inverse de celui choisi
	
	while(Test si l'arbre binaire de recherche est égale au nombre de sommet en entrée);
	
	//parcours de l'arbre + plus court chemin
	//Créer un arbre binaire complet, puis on recherche la feuille de poids minimum
	//Son chemin sera le plus court chemin pour l'algo de Little
	*/
	vector<int> juste_pour_le_retour_de_fonction_mais_a_supprimer;
	return juste_pour_le_retour_de_fonction_mais_a_supprimer;
}	

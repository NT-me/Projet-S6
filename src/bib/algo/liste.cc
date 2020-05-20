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

vector<int> voyageur_de_commerce(vector<int> sommet, Matrice M)
{
	int somme_reduc = 0;
	Graphe arbre = Graphe("arbre");

	//////////////////////////////////////////
	
	// PREMIERE REDUCTION DE LA MATRICE
	//////////////////////////////////////////
	
	int reduc_colonne = 10000000;
	int reduc_total = 10000000;
	
	
	vector < vector <int>> tab = M.getTab();
 	for(int i = 0; i<M.gettV(); i++)
	{
		for(int j = 0; j<M.gettV(); j++)
		{
			if(i == j)
			{
				tab[i][j] = -2;
			}
		}
	}
	
	
	
	
	//~ //Ici, réduction ligne
	for(int i = 0; i<M.gettV(); i++)
	{
		int reduc_ligne = 10000000;
		for(int j = 0; j<M.gettV(); j++)
		{
			// on cherche la valeur minimale pour la colonne donnée
			if(tab[i][j]<reduc_ligne && (tab[i][j] != (-2)))
			{
				reduc_ligne = tab[i][j];
			}
			
		}
		// pour la ligne en question, on soustrait tout les valeurs de cette valeur minimale trouvée.
		
		somme_reduc = somme_reduc + reduc_ligne;
		
		
		for(int j = 0; j<M.gettV(); j++)
		{
				if(tab[i][j] != -2)
				{
				tab[i][j] = tab[i][j] - reduc_ligne;
				}
			
		}
	}
	
	//~ //Ici, réduction colonne
	for(int j = 0; j<M.gettV(); j++)
	{
		int reduc_colonne = 10000000;
		for(int i = 0; i<M.gettV(); i++)
		{
			// on cherche la valeur minimale pour la colonne donnée
			if(tab[i][j]<reduc_colonne && (tab[i][j] != (-2)))
			{
				reduc_colonne= tab[i][j];
			}
			
		}
		// pour la ligne en question, on soustrait tout les valeurs de cette valeur minimale trouvée.
		
		somme_reduc = somme_reduc + reduc_colonne;
		for(int i = 0; i<M.gettV(); i++)
		{
				if(tab[i][j] != -2)
				{
				tab[i][j] = tab[i][j] - reduc_colonne;
				}
			
		}
	}
	
	
	M.setTab(tab);
	
	
	
	
	
	////////////////////////////////
	//fin de la première réduction
	//////////////////////////////
	
	
	
	
	
	// si l'arbre est vide, on initialise le sommet racine à la valeur de la réduction de la matrice pour
	// pour la première réduction
	
	if(arbre.getListe_Sommets().size() == 0)
	{
		string etiquette = "racine";
		map <string, VectVal> A;
		string a = "value";
		
		VectVal regret;
		regret.type = 0;
		regret.valeur_entiere = somme_reduc;
		regret.valeur_reel = 0;
		
		A[a]=regret;
		Sommet racine = Sommet(1, 1, etiquette , 0, A);
		
		vector<Sommet> liste = arbre.getListe_Sommets();
		liste.push_back(racine);
		arbre.setListe_Sommet(liste);
	}
	
	
	
	while(M.gettV() > 2) // tant que on a pas une matrice de taille 2x2
	{
		printf("\n\n nouvelle reduction de la matrice: \n\n\n");
		M.affiche_matrice();
		
	
	
    vector< vector<int> > tableau = M.getTab();	
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
    // il est important de leur associer une valeur élevé afin d'obtenir la plus petite valeur du tableau après.
    for(int i = 0; i < M.gettV(); i++)  
    {
		 for(int j = 0; j < M.gettV(); j++) 
		 {
			if(tableau[i][j]>regret)
			{
				regret = tableau[i][j];
			}
		 }
    
    }
    regretX = regret;
    regretY = regret;
    

    /////////////////////////////////////////////////////////////////////////////////
    
    // PARTIE 2: ON RECHERCHE LES CASES DE LA MATRICE REDUITE DONT LA VALEUR EST ZERO
    // ET ON CALCULE LES REGRETS ASSOCIES, ON STOCKERA DANS UN VECTEUR TOUTS LES REGRETS
    
	for(int x = 0; x<M.gettV(); x++)
	{
		for(int y = 0; y<M.gettV(); y++)
		{
			if(tableau[x][y] == 0) 
			{
			// Si une case vaut zéro, il faut calculer le regret asscocié, si on ne prendrait pas ce chemin
			
				for(int i = 0; i<M.gettV(); i++)
				{
					// on fera attention en cherchant la valeur minimale comme regret de pas prendre 0
					// ca c'est va valeur de la case étudiée justement.
					if(regretY > tableau[i][y] && (i != x) && tableau[i][y] != -2 ) 
					{
						regretY = tableau[i][y];
					}
				}
				for(int j = 0; j<M.gettV();j++)
				{
					if(regretX> tableau[x][j] && (j != y) && tableau[x][j] != -2)
					{
						regretX= tableau[x][j];
					}	
				}
				regret = regretX + regretY;
				vector<int> regret_actuel {regret, y, x};
				regrets.push_back(regret_actuel);
			}
			
			///////////////////////////////////////
			// on remet à zero les valeur de regretX et regretY puis on leur donne la valeur max possible.
			regretX = 0;
			regretY = 0;
			regret = 0;
			
			 for(int i = 0; i < M.gettV(); i++)  
			 {
				for(int j = 0; j < M.gettV(); j++) 
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
		//~ for(int unsigned i= 0; i<regrets.size(); i++)
	 //~ // usigned car le nombre d'elements renvoyé par le size() est un entier non signé.
	
	//~ // on va stocker les coordonnées X et Y du plus grand regret, afin de le recuperer après.
	//~ {
		
			//~ printf("valeur du vecteur regret: %d\n", regrets[i][0]);
			//~ printf("X du regret: %d\n", regrets[i][1]);
			//~ printf("Y du regret: %d\n", regrets[i][2]);
		
	//~ }
	
	
	
	
	
	//////////////////////////////////////////////////////////////////////////////////////
	//PARTIE 3, ON VA SELECTIONNER LE PLUS GRAND REGRET DANS LE VECTEUR AYANT STOCKE LES REGRETS
	// OU UNE CASE VALAIT 0 D APRES LA MATRICE REDUITE.
	//////////////////////////////////////////////////////////////////////////////////////
	int unsigned i;
	regret = 0;
	for(i= 0; i<regrets.size(); i++)
	{
	// usigned car le nombre d'element renvoyé par le la taile 
	// du vecteur est un entier non signé.
	
	// on va stocker les coordonnées X et Y du plus grand regret, afin de le recuperer après.
	
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
	vector<int> REGRET_FINAL{regret, regretX, regretY}; // ici, le regret final contient la case avec le plus haut regret ainsi que ses coordonnées X et Y.
	
			//~ printf("\nvaleur du vecteur regret max: %d\n", REGRET_FINAL[0]);
			//~ printf("X du regret max: %d\n", REGRET_FINAL[1]);
			//~ printf("Y du regret max: %d\n", REGRET_FINAL[2]);
		

	
	
	
	
	
	
	
	////////////////////////////////////////////////////////////////////////////////////////
	// PARTIE 4: ON AJOUTE A L ABRE LE CAS DE L AJOUT DU CHEMIN VERS CE SOMMET AVEC LE PLUS GRAND REGRET
	// ET ENSUITE LE CAS OU ON NE PREND PAS CE MEME CHEMIN
	////////////////////////////////////////////////////////////////////////////////////////
	
	// on cherche à récupérer la valeur du plus grand indice de sommet
	
		
	
	
	
	
	// Ici il faudrait la valeur du nouveau sommet réduc de la prochaine réduction de la matrice
	
	
	///////////////////////////////////////////
	
   
	
	
		
	int unsigned taille = arbre.getListe_Sommets().size();
	
	string name1_1 = to_string(REGRET_FINAL[1]);
	string name1_2 = to_string(REGRET_FINAL[2]);
	string name = name1_1 + name1_2;

	map <string, VectVal> Avec_chemin;
	map <string, VectVal> Sans_chemin;
	string a = "value";
	
		VectVal regret_Avec_chemin;
		VectVal regret_Sans_chemin;
		
		regret_Sans_chemin.type = 0;
		regret_Sans_chemin.valeur_entiere = somme_reduc + REGRET_FINAL[0];
		regret_Sans_chemin.valeur_reel = 0;
		
		Sans_chemin[a]=regret_Sans_chemin;
		
	
		
		///////////////////////
		// REDUCTION DE LA MATRICE
		
		
		
		
		reduc_colonne = 10000000;
	    reduc_total = 10000000;
	
	tab.clear();
	tab = M.getTab();
 	for(int i = 0; i<M.gettV(); i++)
	{
		for(int j = 0; j<M.gettV(); j++)
		{
			if(i == j)
			{
				tab[i][j] = -2;
			}
		}
	}
	
	
	
	
	//~ //Ici, réduction ligne
	for(int i = 0; i<M.gettV(); i++)
	{
		int reduc_ligne = 10000000;
		for(int j = 0; j<M.gettV(); j++)
		{
			// on cherche la valeur minimale pour la colonne donnée
			if(tab[i][j]<reduc_ligne && (tab[i][j] != (-2)))
			{
				reduc_ligne = tab[i][j];
			}
			
		}
		// pour la ligne en question, on soustrait tout les valeurs de cette valeur minimale trouvée.
		
		somme_reduc = somme_reduc + reduc_ligne;
		for(int j = 0; j<M.gettV(); j++)
		{
				if(tab[i][j] != -2)
				{
				tab[i][j] = tab[i][j] - reduc_ligne;
				}
			
		}
	}
	
	//~ //Ici, réduction colonne
	for(int j = 0; j<M.gettV(); j++)
	{
		int reduc_colonne = 10000000;
		for(int i = 0; i<M.gettV(); i++)
		{
			// on cherche la valeur minimale pour la colonne donnée
			if(tab[i][j]<reduc_colonne && (tab[i][j] != (-2)))
			{
				reduc_colonne= tab[i][j];
			}
			
		}
		// pour la ligne en question, on soustrait tout les valeurs de cette valeur minimale trouvée.
		
		somme_reduc = somme_reduc + reduc_colonne;
		for(int i = 0; i<M.gettV(); i++)
		{
				if(tab[i][j] != -2)
				{
				tab[i][j] = tab[i][j] - reduc_colonne;
				}
			
		}
	}
	
	
	M.setTab(tab);
	
		
		
		
		///////////////////////
		
		
		
		regret_Avec_chemin.type = 0;
		regret_Avec_chemin.valeur_entiere = somme_reduc; 
		regret_Avec_chemin.valeur_reel = 0;
		
		Avec_chemin[a]=regret_Avec_chemin;
			
	Sommet avec_chemin = Sommet(1, 1, name, taille+1, Avec_chemin); 
    Sommet sans_chemin = Sommet(1, 1, name, taille, Sans_chemin); 
	
	vector<Sommet> liste = arbre.getListe_Sommets();
	liste.push_back(sans_chemin);
	liste.push_back(avec_chemin);
	
	arbre.setListe_Sommet(liste);
	
	
	arbre.ajout_Arc(taille-1, taille);
	arbre.ajout_Arc(taille-1, taille+1);
	/////////////////////////////////////
	//     ON SUPPRIMME LA LIGNE ET LA COLONNE DE LA CASE CHOISIE
	/////////////////////////////////////
	
	M.supprLigne(REGRET_FINAL[1]);
	M.supprCol(REGRET_FINAL[2]);
	
	
	///////////////////////////////////////:::::
	// ON doit supprimer l'arc inverse pour éviter un alle retour
	//////////////////////////////
	M.modifTab(REGRET_FINAL[1], REGRET_FINAL[2], -2);
	// modfier pour que -2 soit un truc qui soit pris comme un case pas possible.
	//////////////////////////////////////////
	
	
	}
    printf("\n\n nouvelle reduction de la matrice: \n\n\n");
	M.affiche_matrice();
	// ICI ON DOIT AVOIR UNE MATRICE DE TAILLE 2x2.
	
	if(M.gettV() == 2) // Si on a une matrice de taille 2x2
	{
		tab = M.getTab();
		tab[1][0] = -2;
		tab[0][1] = -2;
	}
	// on va ajouter à l'étiquette du dernier sommet du graphe, les derniers chemin de cette matrice 2*2.
	//~ vector<Sommet> liste = arbre.getListe_Sommets();
	//~ Sommet A =  liste[arbre.getListe_Sommets().size()];
	//~ string a = A.getEtiq() + to_string(tab);
	
	//~ Sommet A.setEtiq(a);
	//on va ajouter à la charge utile du dernier sommet les deux derniers chemins possibles.
	//~ /////////////////////////////////////////////////////
	//~ // PARTIE 5: IL FAUT VISITER LES AUTRES CHEMIN EXCLU
	//~ /////////////////////////////////////////////////////
	
	
	////////////////////
	// A PARTIR DE L ARBRE IL FAUT RENVOYER LE CYCLE 
	/////////////////::
	arbre.affiche_graphe();
	
	
	vector<int> juste_pour_le_retour_de_fonction_mais_a_supprimer;
	return juste_pour_le_retour_de_fonction_mais_a_supprimer;
}	

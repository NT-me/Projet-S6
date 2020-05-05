#include "liste.hh"

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

vector<int> voyageur_de_commerce(vector<int>, Matrice M){}

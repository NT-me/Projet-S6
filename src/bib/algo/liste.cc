#include "liste.hh"
#include <cstdio>
#include <map>
#include <ostream>
#include <string>
#include <utility>
#include <vector>


pair<vector<vector<int>>, vector<int>> calcul_Bellman(Matrice M, Sommet S){
  vector<int> dist;
  vector<int> file;
  vector<int> pred;
  vector<vector<int>> liste_res;
  pair <vector<vector<int>>,vector<int>> res;

  if(M.getType()!=0){
    std::cout << "ERROR WRONG MATRICE TYPE" << '\n';
    return res;
  }
  else{
    for(int i=0;i<M.gettV();i++){
        dist.push_back(INFINI);
        pred.push_back({-1});
     }
     dist[S.getID()] = 0;

    int cmpA = 0,cmpW = 0;
    for(int i=0;i<M.gettV();i++){     // Nb Arcs
      for(int j=0;j<M.gettV();j++){
        if(M.getTab()[i][j])
        cmpA++;//renvoie le nombre d'arcs
      }
    }
    file.push_back(S.getID());
    while(file[0]!=-1 && cmpW<cmpA-1){ // Bellman (poids des chemins)
      for(int j=0;j<M.gettV();j++){
        if(M.getTab()[file[0]][j]!=0){
          if(dist[j] > (dist[file[0]] + M.getTab()[file[0]][j])){
            dist[j] = dist[file[0]] + M.getTab()[file[0]][j];
            file.push_back(j);
            pred[j] = file[0];
          }
        }
      }
      if(file.size()==1){
        file[0]=-1;
      }
      else {
        file.erase(file.begin());
      }
      cmpW++;
    }
    // Cycles négatifs
    for(int i=0;i<M.gettV();i++){
      for(int j=0;j<M.gettV();j++){
        if(M.getTab()[i][j]!=0){
          if(dist[j] > (dist[i] + M.getTab()[i][j])){
            std::cout << "NEGATIVE CYCLE" << '\n';
            return res;
          }
        }
      }
    }
    // Liste prédécesseurs
    for(int i=0;i<pred.size();i++){
      if(pred[i] == -1){
        liste_res.push_back({S.getID()});
      }
      else if(pred[i]==S.getID()){
        liste_res.push_back({S.getID(),i});


      }
      else{
        int j = i;
        vector<int> tmp;
        vector<int> tmp2;
        while(j!=S.getID()){
          tmp.push_back(j);
          j = pred[j];
        }
        tmp.push_back(S.getID());
        tmp2.resize(tmp.size());
        for(int a=0;a<tmp.size();a++){  // Remet à l'endroit
          tmp2[a] = tmp[tmp.size()-a-1];
        }
        liste_res.push_back(tmp2);
      }
    }

    res.first = liste_res;
    res.second = dist;
    return res;
  }
}

//################# FLOYD Warshall  ######################
pair<Matrice, Matrice> calcul_Floyd_Warshall(Matrice M){
  //parcourt de la matrice d'adjacence
  if(M.getType()!=0){
    Matrice MP(M.gettV(),M.gettV(),2),MT(M.gettV(),M.gettV(),3);
    pair<Matrice,Matrice> res{MP,MT};
    std::cout << "ERROR WRONG MATRICE TYPE" << '\n';
    return res; //retour de pair<Matrice,Matrice> vide
  }
  else{
    //initialisation de MatriceParent
    Matrice MP(M.gettV(),M.gettV(),3);
    for(int i=0;i<M.gettV();i++){
      for(int j=0;j<M.gettV();j++){
        if(M.getTab()[i][j]!=0){
          MP.modifTab(i,j,j);
        }
        else
        MP.modifTab(i,j,-1);// il n'y a pas de parent direct

      }
    }

    //init de Matrice de poids
    Matrice MT(M.gettV(),M.gettV(),2);
    for(int i=0;i<M.gettV();i++){
      for(int j=0;j<M.gettV();j++){
        if(i==j){
          MT.modifTab(i,j,0);
        }
        else if(M.getTab()[i][j]!=0){
          MT.modifTab(i,j,M.getTab()[i][j]);
        }
        else{
          MT.modifTab(i,j,INFINI);// il n'y a pas de chemin

        }

      }
    }
    for (int k = 0; k < M.gettV();k++) {
      for (int i = 0; i < M.gettV(); i++) {
        for (int j = 0; j < M.gettV(); j++) {
        //  if(k!=j&&i!=j&&k!=i){
            if(MT.getTab()[i][j]> (MT.getTab()[i][k]+MT.getTab()[k][j])){
              MT.modifTab(i,j,MT.getTab()[i][k]+MT.getTab()[k][j]);
              MP.modifTab(i,j,MP.getTab()[i][k]);
            }

        //  }
        }
      }
    }
    //création de la pair<Matrice,Matrice> res
    pair<Matrice,Matrice> res{MT,MP};
    return res;

  }
}

vector<int> liste_floyd(Matrice Parent, int deb, int fin){
  if(Parent.getType()!=3){
    std::cout << "ERROR WRONG TYPE" << '\n';
    vector<int> res{-1};
    return res;
  }
  else{
    vector<int> res{deb};
    while(Parent.getTab()[deb][fin]!=fin){
      if(Parent.getTab()[deb][fin]!=-1){
        deb = Parent.getTab()[deb][fin];
        res.push_back(deb);

      }
      else{
        std::cout << "PAS DE CHEMIN" << '\n';
        vector<int> res{-2};
        return res;
      }
    }
    res.push_back(fin);
    return res;
  }
}

int calcul_degres_entrant(Matrice M, int id){

     /* déclare variable int vide  */
        int nb_entrant = 0;

    /* ittération sur le nombre de sommet de la matrice en paramètre */
        for (int i=0; i < M.gettV() ; i++){
            if (M.getTab()[i][id]) nb_entrant++;
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

pair<int, int> calcul_degres_entrant_sortant(Matrice M, Sommet S){
    pair<int,int> result( calcul_degres_entrant(M, S.getID()) , calcul_degres_sortant(S) );

     return result;
}


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
            if(t.first > L[j].first){
                L.insert(L.begin()+j, t);
                break;
            }
            if(j == L.size()-1){
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

    while (!L.empty()) {

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
        v.valeur_entiere = 1;
        while (res[L[s].second.getID()] == 0) {
            if(voisin.first == 0){
                res[L[s].second.getID()] = v.valeur_entiere;
                map = G.getListe_Sommets()[s].getCU();
                map.insert(pair<string, VectVal>("couleur", v));
                G.getListe_Sommets()[s].setCU(map);
            }
            else{
                for(int i=0; i<voisin.second.size(); i++){
                    if(v.valeur_entiere<voisin.second[i]){
                        res[L[s].second.getID()] = v.valeur_entiere;
                        map = G.getListe_Sommets()[s].getCU();
                        map.insert(pair<string, VectVal>("couleur", v));
                        G.getListe_Sommets()[s].setCU(map);
                        break;
                    }else{
                        if(i == voisin.second.size()-1){
                            v.valeur_entiere += 1;
                            res[L[s].second.getID()] = v.valeur_entiere;
                            map = G.getListe_Sommets()[s].getCU();
                            map.insert(pair<string, VectVal>("couleur", v));
                            G.getListe_Sommets()[s].setCU(map);
                        }
                    }
                    v.valeur_entiere++;

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
                }
                else{
                    for(int j=0; j<res.size(); j++){
                        if(res[j]>v[i]){
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
            else{
                if(v[i]!=0 && M.getTab()[i][id]==1 ){
                    if(res.empty()){
                        res.push_back(v[i]);
                        r++;
                    }
                    else{
                        for(int j=0; j<res.size(); j++){
                            if(res[j]>v[i]){
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

    }
    return pair<int, vector<int>>(r, res);
}

vector<vector<int>> stables_Graphe(Matrice M){
    Graphe G(M);
    vector<int> colo = coloration_Graphe(G);

    vector<vector<int>> res;
    for(int i=0; i<colo.size(); i++){
        if(colo[i]<=res.size()){
            res[colo[i]-1].push_back(i);
        }
        else{
            vector<int>tmp;
            tmp.push_back(i);
            res.push_back(tmp);
        }
    }
    return res;
}

vector<vector<int>> cliques_Graphe(Matrice M){
    //invesion de la matrice (au sens d'un graphe non orienté)
    for(int i=0; i<M.gettV(); i++){
        for(int j=i+1; j<M.gettV(); j++){
            if(M.getTab()[i][j] == 0 && M.getTab()[j][i] == 0){
                M.modifTab(i, j, 1);
            }
            else{
                M.modifTab(i, j, 0);
                M.modifTab(j, i, 0);
            }
        }
    }
    return stables_Graphe(M);
}

vector<int> voisin_sommet(Matrice M, int ID){
     /* déclare variable vector vide  */
    vector<int> voisins;

     /* ittération sur le nombre de sommet de la matrice M  */
        for (int i=0; i < M.gettV() ; i++){
            if ( M.getTab()[ID][i] )  {
                voisins.insert(voisins.end(),i);
            }
        }
    return voisins;
}


void parcours_largeur(Graphe G, Sommet S)
{
	   vector<Sommet> marquage;
	   marquage.push_back(S);

       vector<Sommet> liste_sommet = G.getListe_Sommets();
       while(!liste_sommet.empty())
       {
		   for(int i =0; i<marquage.size(); i++)
		   {
			   if(marquage[i] == S)
			   {
				   liste_sommet.pop_back();
			   }
		   }
		   S = liste_sommet.back();

		   S.afficher_Sommet();
		   liste_sommet.pop_back();


	   }


                //~ pour tout voisin t de s dans G
                         //~ si t non marqué
                                 //~ f.enfiler(t);
                                 //~ marquer(t);


}

int gestion_flots(Graphe G, int ID_source, int ID_puit){}



vector<pert_row> calcul_posterite(vector<pert_row> p){
  vector<pert_row> tmp = p;
  int ex;
  for(int i = 0; i<tmp.size(); i++){
    ex = tmp[i].taches_anterieures.size();
    for(int j = 0; j<tmp[i].taches_anterieures.size(); j++){
      for(int k = 0; k<tmp.size(); k++){
        if(tmp[i].taches_anterieures[j] == tmp[k].tache){
          tmp[k].taches_posterieures.push_back(tmp[i].tache);
          ex --;
        }
      }
    }
    if(ex != 0){
      cout<<"/* ERROR NON-EXISTENT TASK */"<<endl;
      return p;
    }
  }

  for(int i = 0; i<tmp.size(); i++){
    if(tmp[i].taches_anterieures.size() == 0){
      vector<int> v={tmp[i].tache};
      vector<int> suiv = tmp[i].taches_posterieures;
      while(!suiv.empty()){
        for(int j = 0; j<v.size(); j++){
            if(suiv[0] == v[j]){
                cout<<"/* ERROR SELF-PERPETUATING TASK *//*"<<endl;
                return p;
            }
        }
        for(int j = 0; j<tmp.size(); j++){

          if (tmp[j].tache == suiv[0]){
            for(int k = 0; k<tmp[j].taches_posterieures.size(); k++){
              int cmp = 0;
              for(int l=0; l<suiv.size(); l++){
                if(suiv[l] == tmp[j].taches_posterieures[k]){
                  cmp++;
                }
              }
              if(cmp==0){
                suiv.push_back(tmp[j].taches_posterieures[k]);
              }

            }
          }
        }

        v.push_back(suiv[0]);
        suiv.erase(suiv.begin());
      }

    }
  }

  return tmp;
}



Graphe pert(vector<pert_row> p){
    std::vector<pert_row> pe = p;
    vector<Sommet> ListeS;
    vector<Arc> ListeA;
    VectVal val;
    map<string, VectVal> mapS;
    map<string, VectVal> mapA;
    map<string, VectVal> mapT;
    VectVal fin;

    fin.type = 0;
    fin.valeur_entiere = 0;

    val.type = 0;
    val.valeur_entiere = 0;

    //création d'un sommet départ
    mapA.insert(pair<string, VectVal>("duree", val));
    mapS.insert(pair<string, VectVal> ("date au plus tot", val));
    ListeS.push_back(Sommet(100, 100, "Départ", 0, mapS));

    //création du sommet fin
    ListeS.push_back(Sommet(100, 100, "Fin", 1));

    //création des sommets n'ayant aucunes contraîntes d'antériorités et les arcs correspondants
    for(int i=0; i<p.size(); i++){
        if(p[i].taches_anterieures.empty()){
            val.valeur_entiere = p[i].duree;
            mapS["date au plus tot"] = val;
            ListeS.push_back(Sommet(100, 100, "fin " + to_string(p[i].tache), ListeS.size(), mapS));
            mapA["duree"]=val;
            ListeA.push_back(Arc(to_string(p[i].tache) + p[i].nom_tache, ListeA.size(), 0, ListeS.back().getID(), mapA));
            if(p[i].taches_posterieures.empty()){
                if(val.valeur_entiere>fin.valeur_entiere){
                    fin.valeur_entiere = val.valeur_entiere;
                }
                //ajouter arc
                val.valeur_entiere = 0;
                mapA["duree"]=val;
                ListeA.push_back(Arc("fictif", ListeA.size(), ListeS.back().getID(), 1, mapA));
            }
            p.erase(p.begin()+i);
            i=i-1;
        }
    }

    while (!p.empty()) {
        //on vérifie pour une unique contraînte
        for(int i=0; i<p.size(); i++){
            if(p[i].taches_anterieures.size() == 1){
                int tmp = 0;
                int id;
                for(Sommet s : ListeS){
                    if("fin " + to_string(p[i].taches_anterieures[0]) == s.getEtiq()){
                        tmp++;
                        id = s.getID();
                    }
                }
                if(tmp == 1){
                    val.valeur_entiere = p[i].duree + ListeS[id].getCU()["date au plus tot"].valeur_entiere;
                    mapS["date au plus tot"] = val;
                    ListeS.push_back(Sommet(100, 100, "fin " + to_string(p[i].tache), ListeS.size(), mapS));
                    val.valeur_entiere = p[i].duree;
                    mapA["duree"]=val;
                    ListeA.push_back(Arc(to_string(p[i].tache) + p[i].nom_tache, ListeA.size(), id, ListeS.back().getID(), mapA));
                    if(p[i].taches_posterieures.empty()){
                      val.valeur_entiere = p[i].duree + ListeS[id].getCU()["date au plus tot"].valeur_entiere;
                        if(val.valeur_entiere>fin.valeur_entiere){
                            fin.valeur_entiere = val.valeur_entiere;
                        }
                        //ajouter arc
                        val.valeur_entiere = 0;
                        mapA["duree"]=val;
                        ListeA.push_back(Arc("fictif", ListeA.size(), ListeS.back().getID(), 1, mapA));
                    }
                    p.erase(p.begin()+i);
                    i=i-1;
                }

            }
        }


        //test pour plusieurs contraîntes d'antériorités
        for(int i=0; i<p.size(); i++){
            //on vérifie que les taches antérieures sont déjà traitées
            int tmp = 0;
            for(Sommet s : ListeS){
                for(int j=0; j<p[i].taches_anterieures.size(); j++)
                if("fin " + to_string(p[i].taches_anterieures[j]) == s.getEtiq()){
                    tmp++;
                }
            }
            if(tmp == p[i].taches_anterieures.size()){
                //recherche de l'antécédent avec la date au plus tôt la plus élevée
                int x = 0; // id de la tâche
                int id = 0; // id du sommet dans la liste
                for(int k=0; k<ListeS.size(); k++){
                    for(int j=0; j<p[i].taches_anterieures.size(); j++)
                        if("fin " + to_string(p[i].taches_anterieures[j]) == ListeS[k].getEtiq()){
                            if (ListeS[id].getCU()["date au plus tot"].valeur_entiere
                                <= ListeS[k].getCU()["date au plus tot"].valeur_entiere){
                                    id = k;
                                    x = j;
                                }
                        }
                }
                //si l'antécédent avec la date au plus tôt la plus élevée a au plus un sommet postérieur
                if(pe[x].taches_posterieures.size() <= 1){
                    val.valeur_entiere = p[i].duree + ListeS[id].getCU().at("date au plus tot").valeur_entiere;
                    mapS["date au plus tot"] = val;
                    ListeS.push_back(Sommet(100, 100, "fin " + to_string(p[i].tache), ListeS.size(), mapS));
                    val.valeur_entiere = p[i].duree;
                    mapA["duree"]=val;
                    ListeA.push_back(Arc(to_string(p[i].tache) + p[i].nom_tache, ListeA.size(), ListeS[id].getID(), ListeS.back().getID(), mapA));
                    if(p[i].taches_posterieures.empty()){
                      val.valeur_entiere = val.valeur_entiere = p[i].duree + ListeS[id].getCU().at("date au plus tot").valeur_entiere;
                        if(val.valeur_entiere>fin.valeur_entiere){
                            fin.valeur_entiere = val.valeur_entiere;
                        }
                        //ajouter arc
                        val.valeur_entiere = 0;
                        mapA["duree"]=val;
                        ListeA.push_back(Arc("fictif", ListeA.size(), ListeS.back().getID(), 1, mapA));
                    }
                    //ajouter les arcs fictifs entre tous les sommets antérieurs et le sommet xi
                    val.valeur_entiere = 0;
                    mapA["duree"]=val;
                    for(int j=0; j<p[i].taches_anterieures.size(); j++){
                        for(int k = 0; k<ListeS.size(); k++){
                            if("fin " + to_string(p[i].taches_anterieures[j]) == ListeS[k].getEtiq() && ListeS[k].getID()!= id){
                                ListeA.push_back(Arc("fictif", ListeA.size(), ListeS[k].getID(), id, mapA));
                             }
                        }
                    }
                    p.erase(p.begin()+i);
                    i=i-1;
                }
                 //si il a plusieurs sommets postérieurs
                else{
                    //créer un sommet fin de toutes les tâches antérieurs
                    val.valeur_entiere = ListeS[id].getCU().at("date au plus tot").valeur_entiere;
                    mapS["date au plus tot"] = val;
                    string etiq = " fin ";
                    for(int j=0; j<p[i].taches_anterieures.size(); j++){
                        etiq += ", " + to_string(p[i].taches_anterieures[j]);
                    }
                    ListeS.push_back(Sommet(100, 100, etiq, ListeS.size(), mapS));
                    val.valeur_entiere = 0;
                    mapA["duree"]=val;
                    for(int j=0; j<p[i].taches_anterieures.size(); j++){
                        for(Sommet s : ListeS){
                            if("fin " + to_string(p[i].taches_anterieures[j]) == s.getEtiq()){
                                ListeA.push_back(Arc("fictif", ListeA.size(), s.getID(), ListeS.back().getID(), mapA));
                             }
                        }
                    }
                    val.valeur_entiere = p[i].duree + ListeS.back().getCU().at("date au plus tot").valeur_entiere;
                    mapS["date au plus tot"] = val;
                    ListeS.push_back(Sommet(100, 100, "fin " + to_string(p[i].tache), ListeS.size(), mapS));
                    val.valeur_entiere = p[i].duree;
                    mapA["duree"] = val;
                    ListeA.push_back(Arc(to_string(p[i].tache) + p[i].nom_tache, ListeA.size(), ListeS[ListeS.size()-2].getID(),ListeS.back().getID(), mapA));
                    if(p[i].taches_posterieures.empty()){
                      val.valeur_entiere =  p[i].duree + ListeS.back().getCU().at("date au plus tot").valeur_entiere;
                        if(val.valeur_entiere>fin.valeur_entiere){
                            fin.valeur_entiere = val.valeur_entiere;
                        }
                        //ajouter arc
                        val.valeur_entiere = 0;
                        mapA["duree"]=val;
                        ListeA.push_back(Arc("fictif", ListeA.size(), ListeS.back().getID(), 1, mapA));
                    }
                    p.erase(p.begin()+i);
                    i=i-1;
                }
            }
        }

    }



    mapS["date au plus tot"] = fin;
    mapS.insert(pair<string, VectVal> ("date au plus tard", fin));
    ListeS[1].setCU(mapS);





    //calcul de toutes les dates au plus tard

    vector<Arc> li = ListeA; //liste de tous les Arcs non traités
    vector<int> f(ListeS.size()); //liste des sommets traités
    f[1] = 1;


    while(!li.empty()){
      for (int i = ListeS.size()-1; i>= 0; i--){
        int r = 0;
        map<string, VectVal> m = ListeS[i].getCU();

        for(int j = li.size()-1; j>=0; j--){
          vector<int> sortant = ListeS[i].getVecArc();
          if(li[j].getIDDepart() == ListeS[i].getID()){
            if(f[li[j].getIDArrive()] == 1){
              int tmp = ListeS[li[j].getIDArrive()].getCU()["date au plus tard"].valeur_entiere - li[j].getCU()["duree"].valeur_entiere;
              if(ListeS[i].getCU().count("date au plus tard") == 1){
                fin.valeur_entiere = ListeS[i].getCU()["date au plus tard"].valeur_entiere;
                if(tmp < fin.valeur_entiere){
                  fin.valeur_entiere = tmp;
                  m["date au plus tard"] = fin;
                }
              }
              else{
                fin.valeur_entiere = INFINI;
                if(tmp < fin.valeur_entiere){
                  fin.valeur_entiere = tmp;
                  m.insert(pair<string, VectVal> ("date au plus tard", fin));
                }

              }

              if(sortant.empty()){
                sortant.push_back(li[j].getID());
              }
              else{
                for (int t = 0; t < sortant.size(); t++) {
                  if(li[j].getID() < sortant[t]){
                    sortant.insert(sortant.begin() + t, li[j].getID());
                    break;
                  }
                  else{
                    if(t == sortant.size()-1){
                      sortant.push_back(li[j].getID());
                      break;
                    }
                  }
                }
              }

              ListeS[i].setVecArc(sortant);
              ListeS[i].setCU(m);
              li.erase(li.begin() + j);

            }
            else{r++;}

          }
        }
        if(r == 0){
          f[i] = 1;
        }
      }
    }

    for (int i = ListeS.size()-1; i>= 0; i--){
      if(ListeS[i].getCU()["date au plus tot"].valeur_entiere == ListeS[i].getCU()["date au plus tard"].valeur_entiere){
        fin.valeur_entiere = 1;
      }
      else{fin.valeur_entiere = 0;}
      mapT = ListeS[i].getCU();
      mapT.insert(pair<string, VectVal> ("critique", fin));
      ListeS[i].setCU(mapT);
    }

    //création du Graphe
    return Graphe("PERT", ListeS, ListeA, "\0");

}

Graphe arborescence(Graphe G){
    int succ=0,pred=0,Smax=0,Pmax=0;
    int deb=-1;
    Matrice M = G.conversion_vers_Matrice_adj();
    Graphe A("Arborescence");
    Graphe tmp("Arborescence");
    vector<int>in;
    
    // Vérifie si il existe une arborescence
    for(int i=0;i<M.gettV();i++){
        for(int j=0;j<M.gettV();j++){
            if(M.getTab()[i][j]) succ++;   // Successeurs
            if(M.getTab()[j][i]) pred++;   // Prédecesseurs
        }
        if(!pred){      // Si pas de prédecesseurs
            deb = i;
            Pmax++;
        } 
        if(Pmax >1 || !Pmax || !connexite(M)){    // Si plusieurs/aucun sommet sans prédecesseurs ou non connexe
            std::cout << "NO ARBORESCENCE" << '\n';
            tmp.ajout_Sommet(-1, -1,-1);
            return tmp;
        }
        succ = 0;
        pred = 0;
        in.push_back(0);
    }

    // ##############
    int min=INFINI;
    for(int i=0;i<M.gettV();i++)  A.ajout_Sommet(i,0,0);   // Ajoute les sommets dans graphe de retour
    
    int out = 0;
    for(int i=0; i<M.gettV() && !in[i];i++){
        if(i==deb)i++;
        for(int j=0;j<M.gettV();j++){   // Calcul Arc de poids min
            if(M.getTab()[j][i] && M.getTab()[j][i]<min){
                min = M.getTab()[j][i];     // Arc entrant de poids min
                if(j == deb) out++;
            }
        }
        
        for(int j=0;j<M.gettV() && min!=INFINI;j++){    // Ajout arc de poids min arrivant au sommet i
            int val = M.getTab()[j][i]-min;
            if(!val && !in[i]){
                in[i] = 1;
                A.ajout_Arc(j,i);
                break;
            }
        }

        min = INFINI;

        if(i == deb) i = -1;
    }
   
    if(!out){   // Si pas d'arcs de poids min partant du sommet 
        std::cout << "NO ARBORESCENCE" << '\n';
        tmp.ajout_Sommet(-1, -1,-1);
        return tmp;
    }
    
  /*  Matrice aff = A.conversion_vers_Matrice_adj();
    for(int i=0;i<aff.gettV();i++){
        for(int j=0;j<aff.gettV();j++){
            std::cout << "["<<i<<"]["<<j<<"] = "<<aff.getTab()[i][j]<<endl;
        }
    }*/
    return A;
}

Graphe anti_arborescence(Graphe G){
  int succ=0,Smax=0;
    int fin=-1;
    Matrice M = G.conversion_vers_Matrice_adj();
    Graphe A("Anti-Arborescence");
    Graphe tmp("Anti-Arborescence");
    vector<int>in;
    
    // Vérifie si il existe une anti-arborescence
    for(int i=0;i<M.gettV();i++){
        for(int j=0;j<M.gettV();j++){
            if(M.getTab()[i][j]) succ++;   // Successeurs
        }
        if(!succ){      // Si pas de successeurs
            fin = i;
            Smax++;
        } 
        if(Smax >1 || !Smax || !connexite(M)){    // Si plusieurs/aucun sommet sans prédecesseurs ou non connexe
            std::cout << "NO ANTI-ARBORESCENCE" << '\n';
            tmp.ajout_Sommet(-1,-1,-1);
            return tmp;
        }
        succ = 0;
        in.push_back(0);
    }

    // ##############
    int min=INFINI;
    for(int i=0;i<M.gettV();i++)  A.ajout_Sommet(i,0,0);   // Ajoute les sommets dans graphe de retour
    
    int out = 0;
    for(int i=0; i<M.gettV() && !in[i];i++){
        if(i==fin)i++;
        for(int j=0;j<M.gettV();j++){   // Calcul Arc de poids min
            if(M.getTab()[i][j] && M.getTab()[i][j]<min){
                min = M.getTab()[i][j];     // Arc entrant de poids min
                if(j == fin) out++;
            }
        }
        
        for(int j=0;j<M.gettV() && min!=INFINI;j++){    // Ajout arc de poids min arrivant au sommet i
            int val = M.getTab()[i][j]-min;
            if(!val && !in[i]){
                in[i] = 1;
                A.ajout_Arc(i,j);
                break;
            }
        }

        min = INFINI;
        if(i == fin) i = -1;
    }
   
    if(!out){   // Si pas d'arcs de poids min partant du sommet 
        std::cout << "NO ANTI-ARBORESCENCE" << '\n';
        tmp.ajout_Sommet(-1, -1,-1);
        return tmp;
    }
    return A;
}

int connexite(Matrice M){}

vector<vector<int>> chaine_eulerienne(Matrice M){
  vector<int> path;
  vector<vector<int>> res;

  if(M.getType() != 0){
    std::cout << "ERROR WRONG MATRICE TYPE" << '\n';
    return res;
  }
  else{
    int pred=0,succ=0,Dmax=0,Fmax=0;
    int deb=0,fin=-1;
    vector<int> out;

    int mark[M.gettV()][M.gettV()];

    // Vérifie si il existe un chemin Eulérien
    for(int i=0;i<M.gettV();i++){
      for(int j=0;j<M.gettV();j++){
        if(M.getTab()[i][j]) succ++;
        if(M.getTab()[j][i]) pred++;
        mark[i][j] = 0;
      }
      out.push_back(succ);    // Stocke le nombre de successeurs

      if(succ-pred>1 || pred-succ>1){
        std::cout << "NO EULERIAN PATH" << '\n';
        return res;
      }
      else{
        if(pred-succ==1){
          fin = i;          // Sommet d'arrivée
          Fmax++;
        }
        else if(succ-pred==1){
          deb = i;         // Sommet de départ
          Dmax++;
        }
      }

      if(!connexite(M) && !succ && !pred){
        std::cout << "NO EULERIAN PATH" << '\n';
        return res;
      }
      if(Dmax>1 || Fmax>1){
        std::cout << "NO EULERIAN PATH" << '\n';
        return res;
      }
      succ = 0;
      pred = 0;
    }

    // Nombre d'arcs
    int nbA = 0;
    for(int i=0;i<M.gettV();i++){
      for(int j=0;j<M.gettV();j++){
        if(M.getTab()[i][j]) nbA++;
      }
    }

    // Sommet de départ
    if(deb==0 && !out[deb]){
        for(int i=0;i<M.gettV();i++){
            if(out[i]>0) deb = i;
        }
    }
    
    // #########################
    int i = deb;
    while (out[i]){
        for(int j=0;j<M.gettV();j++){         
            if(M.getTab()[i][j] && !mark[i][j]){   // Si arc
                --out[i];
                mark[i][j] = 1;
                path.push_back(i);
                i = j;
                j = 0;
            }

            if(!out[i] && path.size() == nbA){
                path.push_back(i);
                res.push_back(path);
                return res;
            }       
        } // Fin for
    } // Fin while
  } // Fin else
  return res;
}

vector<vector<int>> chaine_hamiltonienne(Matrice M){
  vector<int> mark;
  vector<int> path;
  vector<vector<int>> res;

  if(M.getType() != 0){
    std::cout << "ERROR WRONG MATRICE TYPE" << '\n';
    return res;
  }
  else{
      int pred, succ, Pmax, Smax;
      int deb=-1,fin=-1;
      
      // Vérifie si il existe un chemin Hamiltonien
      for(int i=0;i<M.gettV();i++){   
          for(int j=0;j<M.gettV();j++){
            if(M.getTab()[i][j]) succ++;      // Nb successeur pour i
            if(M.getTab()[j][i]) pred++;      // Nb predecesseur pour j

            mark.push_back(0);
          }
          if(!succ){
            Smax++;
            fin = i;
          } 
          if(!pred){
            Pmax++;
            deb = i;
          } 
          succ = 0;
          pred = 0;
      }
      if(Smax > 1 || Pmax > 1){                 // Plusieurs sommets sans successeurs ou prédecesseurs
           std::cout << "NO HAMILTTONIAN PATH" << '\n';
            return res;
      }
      
      // Sommet de départ
      if(deb == -1) deb = 0;

      int i = deb;
      while(!mark[i]){
        if(path.size() == M.gettV()-1){
            path.push_back(i);
            res.push_back(path);
            return res;
        }
        for(int j=0;j<M.gettV();j++){
          if(M.getTab()[i][j] && !mark[j]){
            mark[i] = 1;
            path.push_back(i);
            i = j;
            j = 0;
            }
        } // Fin for
      } // Fin while
    } // Fin else
  return res;
}

vector<int> postier_chinois(Matrice M){}

vector<int> voyageur_de_commerce(vector<int>, Matrice M){}

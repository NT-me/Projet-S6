#include "liste.hh"
#include <iostream>
#include <algorithm>

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
            if (M.getTab()[id][i]) nb_entrant++;
         }
    return nb_entrant;
}

int calcul_degres_sortant(Sommet S){

    return S.getVecArc().size();
}

pair<int, int> calcul_degres_entrant_sortant(Matrice M, Sommet S){

    pair<int,int> result( calcul_degres_entrant(M, S.getID()) , calcul_degres_sortant(S) );

     return result;
}

vector<int> coloration_Graphe(Graphe G){}

int couleur_adjacente(Sommet S){}

vector<vector<int>> stables_Graphe(Matrice M){}

vector<vector<int>> cliques_Graphe(Matrice M){}

vector<int> voisin_sommet(Matrice M, int ID){}

int gestion_flots(Graphe G, int ID_source, int ID_puit){}

vector<pert_row> calcul_posterite(vector<pert_row>){}

Graphe pert(vector<pert_row>){}

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

vector<int> postier_chinois(Matrice M){

        vector<int> sommetsImpair;
        vector<int> vecteurResult;
        int nb_sortant, nb_entrant;
        pair<Matrice, Matrice> FloydMa = calcul_Floyd_Warshall(M);
        int deb, fin;
        int EstPair = 1;

        
        /*On vérifie la connexité*/
        if (connexite(M)){

            /*On boucle sur les sommets, pour vérifier s'ils sont tous pairs */
             for(int i=0; i<M.getTab().size(); i++){
                nb_sortant =0;

                /*nb degré entrant */
                nb_entrant = calcul_degres_entrant(M, i);
                
                /*nb degré sortant */
                for (int j=0; j < M.gettV() ; j++){
                    if (M.getTab()[i][j]) nb_sortant++;
                }
                
                /* si l'un des sommets a un degré impair on sort de la boucle */
                if (nb_sortant!= nb_entrant){
                     sommetsImpair.push_back(i);
                     EstPair = 0;
                }
            }
            /* on produit le cycle eulérien pour résoudre le postier chinois*/
            if (EstPair) {
                    /* permet de récupérer le premier vecteur des chaines eulériennes.*/
                    vector<vector<int>> tmp = chaine_eulerienne(M);
                    vecteurResult = tmp[0];

                return vecteurResult;
            }
            else{
                int tmp;
                int total_poid_couplage=0;
                int total;
                int noChemin;
                int nb_combinaisons;
                vector<int> vect_tmp;
                vector<int> couplageParfait;
                vector<vector<int>> combinaisons;
                

                /*factoriel pour récupérer le nombre de combinaisons possibles*/
                for(int fact=1; fact<(sommetsImpair.size()+1); fact++){
                    nb_combinaisons*=fact;
                }

                /* récupérer toutes les combinaisons de couplages possibles */
                 do{
                   for( int i = 0; i < sommetsImpair.size(); i += 1 ){
                       vect_tmp.push_back(sommetsImpair[i]);
                    }
                    combinaisons.push_back(vect_tmp);
                    vect_tmp.clear();
                }while( std::next_permutation( sommetsImpair.begin(), sommetsImpair.end() ) );
                 
           
                /*UNIQUEMENT POUR STOCKER LA PREMIERE COMBINAISON POSSIBLE */
                int min=0;
                for(auto deb=combinaisons.begin(); deb!=combinaisons.end(); deb++){
                   
                    /* effacer le vecteur pour pouvoir le réutiliser*/
                    couplageParfait.clear();
                    total_poid_couplage = 0;
                    noChemin = 0;
                    for(auto fin=deb->begin(); fin!=deb->end(); fin=fin+2){
                        tmp = 0;
                        tmp = FloydMa.first.getTab()[*fin ][*(fin+1)];
                        /* s'il n'y a pas de chemin du sommet *fin au sommet *(fin +1),on sort de la boucle interne pour tester la deb+1 combinaisons */
                        if (tmp == 0) {
                            min = 0;
                            break;
                        }
                        if (!noChemin){
                            total_poid_couplage += tmp;
                            /*sauvegarder les sommets dans le vecteur temporaire au cas où ils seraient des couplages parfaits */
                            couplageParfait.push_back(*fin);
                            couplageParfait.push_back(*(fin+1));
                            /*on a récupérer la premiere valeur*/
                            min = 1;
                        }
                    }
                    if (min) break;
                }
                
                /* ON RECUPERE LE MINIMUM parmis toutes les combinaisons possibles du vecteur couplageParfait*/
                for(auto deb=combinaisons.begin(); deb!=combinaisons.end(); deb++){
                   
                    /* effacer le vecteur pour pouvoir le réutiliser*/
                    vect_tmp.clear();
                    total = 0;
                    noChemin = 0;
                    for(auto fin=deb->begin(); fin!=deb->end(); fin=fin+2){
                        tmp = 0;
                        tmp = FloydMa.first.getTab()[*fin ][*(fin+1)];
                        /* s'il n'y a pas de chemin entre 2 sommets : break*/
                        if (tmp == 0) {
                            noChemin=1;
                            break;
                        }
                        if (!noChemin){
                             total += tmp;
                            /*sauvegarder les sommets dans le vecteur temporaire au cas où ils seraient des couplages parfaits */
                            vect_tmp.push_back(*fin);
                            vect_tmp.push_back(*(fin+1));
                        }
                    }
                    

                        if ( (!noChemin) & (total < total_poid_couplage) ){
                             total_poid_couplage = total;
                            couplageParfait = vect_tmp;
                        }
                    
                }
                
                /*Création d'un Matrice bis pour stocker les nouveaux arcs */
                Matrice Mbis(M);
                for(auto deb = couplageParfait.begin(); deb != couplageParfait.end(); deb=deb+2 ){
                    Mbis.modifTab(*deb, *(deb+1), 1);
                 }

                /* permet de récupérer le premier vecteur des chaines eulériennes.*/
                vector<vector<int>> stock = chaine_eulerienne(Mbis);
                vecteurResult = stock[0];
                return vecteurResult;
            
            }

        }

        else {
            std::cout << "ERREUR CONNEXITE MATRICE (Postier Chinois)" << '\n';
            /* retourne un vecteur vide */
            return vecteurResult;
            }
}

vector<int> voyageur_de_commerce(vector<int>, Matrice M){}


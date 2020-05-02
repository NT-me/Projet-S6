#define CATCH_CONFIG_MAIN
#include "../../../libExt/catch.hpp"
#include "../../../src/bib/algo/liste.hh"
#include <utility>

#ifndef listeTest
#define listeTest

TEST_CASE("Calcul Bellman","[Algorithmes]"){
vector<vector<int>> tab, R_A;

pair<vector<vector<int>>, vector<int>> res_F, res_A;
Sommet S0(0);

// Création de la matrice M0
vector<int> a{0,0,0};
vector<int> b{1,0,0};
vector<int> c{1,0,0};
tab.push_back(a);
tab.push_back(b);
tab.push_back(c);

Matrice M0(3);
M0.setTab(tab);
// ---------------------
res_F = calcul_Bellman(M0, S0);

vector<int> v_a{0,1,1}, v1{0}, v2{0,1}, v3{0,2};
vector<vector<int>> g{v1,v2,v3};
res_A.first = g;
res_A.second = v_a;
REQUIRE(res_F == res_A);
}

TEST_CASE("Calcul Floyd-Warshall","[Algorithmes]"){
  Matrice po(6, 6, 2), pa(6, 6, 3);
  vector<vector<int>> po_m{{0,1,1,2,3,2}, {0,0,1,1,2,2}, {0,0,0,1,2,1}, {0,0,0,0,1,0}, {0,0,0,0,0,0}, {0,0,0,0,0,0}},
                      pa_m{{0,1,2,1,1,2}, {0,0,2,3,3,2}, {0,0,0,3,3,5}, {0,0,0,0,4,0}, {0,0,0,0,0,0}, {0,0,0,0,0,0}};

  po.setTab(po_m);
  pa.setTab(pa_m);
  pair<Matrice, Matrice> p_a(po, pa);


  // Création de la matrice M0
  vector<vector<int>> tab;
  vector<int> a{0,0,0};
  vector<int> b{1,0,0};
  vector<int> c{1,0,0};
  tab.push_back(a);
  tab.push_back(b);
  tab.push_back(c);


  Matrice M0(3);
  M0.setTab(tab);
  // ---------------------

  pair<Matrice, Matrice> p_f (calcul_Floyd_Warshall(M0));

  REQUIRE(p_f == p_a);
}

TEST_CASE("liste floyd","[Algorithmes]"){
  // Création de la matrice parent
  Matrice pa(6, 6, 3);
  vector<vector<int>> pa_m{{0,1,2,1,1,2},
                           {0,0,2,3,3,2},
                           {0,0,0,3,3,5},
                           {0,0,0,0,4,0},
                           {0,0,0,0,0,0},
                           {0,0,0,0,0,0}};
  pa.setTab(pa_m);
  //------------
  // Création du vecteur attendu
  vector<int> v_a{0,1,3,4}, v_f;
  //------------
  v_f = liste_floyd(pa, 0, 4);
  REQUIRE(v_f == v_a);

  // Création d'une matrice PAS parent (pour tester le cas d'erreur)
  Matrice pas_pa(6,5,4);
  //------------
  // Création du vecteur d'erreur attendu
  vector<int> ERRv_a{-1};
  //------------
  v_f = liste_floyd(pas_pa, 0, 4);
  REQUIRE(v_f == ERRv_a);
}

TEST_CASE("calcul degres entrant","[Algorithmes]"){
 // Création de la matrice
 Matrice MA1(3);
 MA1.setTab({{0,1,0},
             {0,0,1},
             {1,0,0}});
//---------
  int i_f, i_a = 1;
  i_f = calcul_degres_entrant(MA1, 1);
  REQUIRE(i_f == i_a);

  // Test de l'erreur sur une matrice non adj
  Matrice ME(6,5,4);
  REQUIRE(calcul_degres_entrant(ME, 1) == -1);

}

TEST_CASE("calcul degres sortant","[Algorithmes]"){
  Sommet S(0);
  S.setVecArc({1,2});
  REQUIRE(calcul_degres_sortant(S) == S.getVecArc().size());
}

TEST_CASE("calcul degres entrant sortant","[Algorithmes]"){
  // Création de la matrice
  Matrice MA1(3);
  MA1.setTab({{0,1,0},
              {0,0,1},
              {1,0,0}});
 //---------
 // Création du sommet
 Sommet S(0);
 S.setVecArc({0});
 pair<int, int> p_a(1,1);
 REQUIRE(calcul_degres_entrant_sortant(MA1, S) == p_a);
}

TEST_CASE("coloration","[Algorithmes]"){
  // Création du graphe
Graphe G("G");
G.ajout_Sommet(0,0,0);
G.ajout_Sommet(1,0,0);
G.ajout_Sommet(2,0,0);

G.ajout_Arc(0,1);
G.ajout_Arc(0,2);
// -------------------
vector<int> v_a{0,1,1};

REQUIRE(coloration_Graphe(G) == v_a);
}

TEST_CASE("couleur adjacence","[Algorithmes]"){

}

TEST_CASE("stables","[Algorithmes]"){
  // Création de la matrice
  Matrice MA1(3);
  MA1.setTab({{0,1,0},
              {0,0,1},
              {1,0,0}});
 //---------
 vector<vector<int>> v_a{{0},{1,2}};
 REQUIRE(stables_Graphe(MA1) == v_a);
}

TEST_CASE("cliques","[Algorithmes]"){
  // Création de la matrice
  Matrice MA1_(4);
  MA1_.setTab({{0,1,0,0},
               {0,0,1,0},
               {1,0,0,1},
               {0,0,0,0}});
 //---------
 vector<vector<int>> v_a{{0,1,2}};
 REQUIRE(cliques_Graphe(MA1_) == v_a);


}

TEST_CASE("voisin sommet","[Algorithmes]"){
  // Création de la matrice
  Matrice MA1(3);
  MA1.setTab({{0,1,0},
              {0,0,1},
              {1,0,0}});
    //---------
    vector<int> res_a{1};
  REQUIRE(voisin_sommet(MA1, 0) == res_a);
}

TEST_CASE("gestion de flots","[Algorithmes]"){
  // Création du graphe
Graphe G3("G3");
int idS0, idS1, idS2, idS3, idS4, idS5, idS6, idS7, idS8, idS9, idS10, idS11, idS12, idS13, idS14;
G3.ajout_Sommet(0,0,0);
G3.ajout_Sommet(1,0,0);
G3.ajout_Sommet(2,0,0);
G3.ajout_Sommet(3,0,0);
G3.ajout_Sommet(4,0,0);
G3.ajout_Sommet(5,0,0);
G3.ajout_Sommet(6,0,0);
G3.ajout_Sommet(7,0,0);

idS0 = G3.ajout_Arc(0,1);
idS1 = G3.ajout_Arc(0,2);
idS2 = G3.ajout_Arc(0,6);
idS3 = G3.ajout_Arc(1,2);
idS4 = G3.ajout_Arc(1,3);
idS5 = G3.ajout_Arc(1,4);
idS6 = G3.ajout_Arc(2,3);
idS7 = G3.ajout_Arc(3,4);
idS8 = G3.ajout_Arc(3,5);
idS9 = G3.ajout_Arc(3,6);
idS10 = G3.ajout_Arc(4,2);
idS11 = G3.ajout_Arc(4,5);
idS12 = G3.ajout_Arc(4,7);
idS13 = G3.ajout_Arc(5,7);
idS14 = G3.ajout_Arc(6,7);

VectVal VV0 {true, 30}, VV1 {true, 1},VV2 {true, 2},VV3 {true, 8},
        VV4 {true, 11}, VV5 {true, 13},VV6 {true, 26},VV7 {true, 9},
        VV8 {true, 8}, VV9 {true, 22}, VV10 {true, 2}, VV11 {true, 1},
        VV12 {true, 7}, VV13 {true, 7}, VV14 {true, 27};

map <string, VectVal> cu0, cu1, cu2, cu3, cu4, cu5, cu6, cu7, cu8, cu9, cu10, cu11,
                      cu12, cu13, cu14;

string flotName = "flot";
cu0.insert(make_pair(flotName, VV0));
cu1.insert(make_pair(flotName, VV1));
cu2.insert(make_pair(flotName, VV2));
cu3.insert(make_pair(flotName, VV3));
cu4.insert(make_pair(flotName, VV4));
cu5.insert(make_pair(flotName, VV5));
cu6.insert(make_pair(flotName, VV6));
cu7.insert(make_pair(flotName, VV7));
cu8.insert(make_pair(flotName, VV8));
cu9.insert(make_pair(flotName, VV9));
cu10.insert(make_pair(flotName, VV10));
cu11.insert(make_pair(flotName, VV11));
cu12.insert(make_pair(flotName, VV12));
cu13.insert(make_pair(flotName, VV13));
cu14.insert(make_pair(flotName, VV14));

vector<Arc> vArc;
vArc = G3.getListe_Arcs();

for (int banana = 0; banana < vArc.size();++banana){
    if (vArc[banana].getID() == idS0){
      vArc[banana].setCU(cu0);
    }
    if (vArc[banana].getID() == idS1){
      vArc[banana].setCU(cu1);
    }
    if (vArc[banana].getID() == idS2){
      vArc[banana].setCU(cu2);
    }
    if (vArc[banana].getID() == idS3){
      vArc[banana].setCU(cu3);
    }
    if (vArc[banana].getID() == idS4){
      vArc[banana].setCU(cu4);
    }
    if (vArc[banana].getID() == idS5){
      vArc[banana].setCU(cu5);
    }
    if (vArc[banana].getID() == idS6){
      vArc[banana].setCU(cu6);
    }
    if (vArc[banana].getID() == idS7){
      vArc[banana].setCU(cu7);
    }
    if (vArc[banana].getID() == idS8){
      vArc[banana].setCU(cu8);
    }
    if (vArc[banana].getID() == idS9){
      vArc[banana].setCU(cu9);
    }
    if (vArc[banana].getID() == idS10){
      vArc[banana].setCU(cu10);
    }
    if (vArc[banana].getID() == idS11){
      vArc[banana].setCU(cu11);
    }
    if (vArc[banana].getID() == idS12){
      vArc[banana].setCU(cu12);
    }
    if (vArc[banana].getID() == idS13){
      vArc[banana].setCU(cu13);
    }
    if (vArc[banana].getID() == idS14){
      vArc[banana].setCU(cu14);
    }
  }
  G3.setListe_Arc(vArc);

  REQUIRE(gestion_flots(G3, 0, 7) == 32);

}
TEST_CASE("calcul posterite","[Algorithmes]"){

}

TEST_CASE("pert","[Algorithmes]"){

}

TEST_CASE("arbo","[Algorithmes]"){
Matrice M0;
M0.setTab({{0,1,1},
          {0,0,0},
          {0,0,0}})

Graphe G("Retour attendu"), G_ret(M0);
G.ajout_Sommet(0,0,0);
G.ajout_Sommet(1,0,0);
G.ajout_Sommet(2,0,0);

G.ajout_Arc(0,1);
G.ajout_Arc(0,2);

REQUIRE(arborescence(G_ret) == G);
}

TEST_CASE("anti-arbo","[Algorithmes]"){
  Matrice M0;
  M0.setTab({{0,0,0},
             {1,0,0},
             {1,0,0}})

  Graphe G("Retour attendu"), G_ret(M0);
  G.ajout_Sommet(0,0,0);
  G.ajout_Sommet(1,0,0);
  G.ajout_Sommet(2,0,0);

  G.ajout_Arc(0,1);
  G.ajout_Arc(0,2);

  REQUIRE(anti_arborescence(G_ret) == G);
}

TEST_CASE("connexite","[Algorithmes]"){

}

TEST_CASE("chaine eulerienne","[Algorithmes]"){

}

TEST_CASE("chaine hamiltonienne","[Algorithmes]"){

}

TEST_CASE("postier chinois","[Algorithmes]"){

}

TEST_CASE("voyageur de commerce","[Algorithmes]"){

}



#endif

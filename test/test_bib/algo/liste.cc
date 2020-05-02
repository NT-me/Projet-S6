#define CATCH_CONFIG_MAIN
#include "../../../libExt/catch.hpp"
#include "../../../src/bib/algo/liste.hh"
#include <utility>

#ifndef listeTest
#define listeTest

TEST_CASE("Calcul Bellman","[Algorithmes]"){
vector<vector<int>> tab, R_A;

pair<vector<vector<int>>, vector<int>> res_F, res_A;
S0(0);

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
res_A.fisrt = g;
res_A.second = v_a;
REQUIRE(res_F == res_A);
}

TEST_CASE("Calcul Floyd-Warshall","[Algorithmes]"){
  pair<Matrice, Matrice> p_f, p_a;
  Matrice po(6, 6, 2), pa(6, 6, 3);
  vector<vector<int>> po_m{{0,1,1,2,3,2}, {0,0,1,1,2,2}, {0,0,0,1,2,1}, {0,0,0,0,1,0}, {0,0,0,0,0,0}, {0,0,0,0,0,0}},
                      pa_m{{0,1,2,1,1,2}, {0,0,2,3,3,2}, {0,0,0,3,3,5}, {0,0,0,0,4,0}, {0,0,0,0,0,0}, {0,0,0,0,0,0}};

  po.setTab(po_m);
  pa.setTab(pa_m);
  p_a.first = po;
  p_a.second = pa;

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

  p_f = calcul_Floyd_Warshall(M0);

  REQUIRE(p_f == p_a);

}

TEST_CASE("liste floyd","[Algorithmes]"){

}

TEST_CASE("calcul degres entrant","[Algorithmes]"){

}

TEST_CASE("calcul degres sortant","[Algorithmes]"){

}

TEST_CASE("calcul degres entrant sortant","[Algorithmes]"){

}

TEST_CASE("coloration","[Algorithmes]"){

}

TEST_CASE("couleur adjacence","[Algorithmes]"){

}

TEST_CASE("stables","[Algorithmes]"){

}

TEST_CASE("cliques","[Algorithmes]"){

}

TEST_CASE("voisin sommet","[Algorithmes]"){

}

TEST_CASE("gestion de flots","[Algorithmes]"){

}

TEST_CASE("calcul posterite","[Algorithmes]"){

}

TEST_CASE("pert","[Algorithmes]"){

}

TEST_CASE("arbo","[Algorithmes]"){

}

TEST_CASE("anti-arbo","[Algorithmes]"){

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

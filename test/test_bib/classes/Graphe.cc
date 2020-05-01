
#define CATCH_CONFIG_MAIN
#include "../../../libExt/catch.hpp"
#include "../../../src/bib/classes/GrapheMatrice.hh"

// A FINIR
TEST_CASE ("Test des setters", "[Graphe]"){
  /* GRAPHE G1*/
  vector<Sommet> listeS;
  vector<Arc> listeA;
  listeS.push_back(Sommet(0));
  listeS.push_back(Sommet(1));
  listeS.push_back(Sommet(2));

  listeA.push_back(Arc(1,listeS[0].getID(),listeS[1].getID()));
  listeA.push_back(Arc(2,listeS[1].getID(),listeS[2].getID()));
  listeA.push_back(Arc(3,listeS[2].getID(),listeS[0].getID()));
  Graphe G1("Graphe1", listeS, listeA, "NULL");

  SECTION ("Set etiquette"){
    G1.setEtiq("modif");
    REQUIRE(G1.getEtiq() == "modif");
  }

  SECTION("Set path"){
    G1.setPath("/home/Desktop/");
    REQUIRE(G1.getPath() == "/home/Desktop/");
  }

  SECTION("Set liste_Arcs"){
    std::vector<Arc> v;
    v.push_back(Arc(0,0,1));
    v.push_back(Arc(1,1,2));
    v.push_back(Arc(2,0,2));
    G1.setListe_Arc(v);
    REQUIRE(G1.getListe_Arcs() == v);
  }

  SECTION("Set liste_Sommets"){
    //a faire
    std::vector<Sommet> v;
    v.push_back(Sommet(0));
    v.push_back(Sommet(1));
    v.push_back(Sommet(2));
    G1.setListe_Sommet(v);
    REQUIRE(G1.getListe_Sommets()==v);
  }

}

TEST_CASE ("Test des getters", "[Graphe]"){

/* GRAPHE G1*/
vector<Sommet> listeS;
vector<Arc> listeA;
listeS.push_back(Sommet(0));
listeS.push_back(Sommet(1));
listeS.push_back(Sommet(2));

listeA.push_back(Arc(1,listeS[0].getID(),listeS[1].getID()));
listeA.push_back(Arc(2,listeS[1].getID(),listeS[2].getID()));
listeA.push_back(Arc(3,listeS[2].getID(),listeS[0].getID()));

Graphe G1("Graphe1", listeS, listeA, "NULL");

  SECTION("Get etiquette"){
    REQUIRE(G1.getEtiq() == "Graphe1");
  }

  SECTION("Get liste_Arcs"){
    REQUIRE(G1.getListe_Arcs() == listeA);
  }

  SECTION("Get liste_Sommets"){
    REQUIRE(G1.getListe_Sommets() == listeS);
  }

  SECTION("Get path"){
    REQUIRE(G1.getPath() == "NULL");
  }
}

// A FINIR
TEST_CASE("Test des constructeur de la classe", "[Graphe]" ){

  /*GRAPHE G0*/
  vector<Sommet> listeS;
  vector<Arc> listeA;
  listeS.push_back(Sommet(0));
  listeS.push_back(Sommet(1));
  listeS.push_back(Sommet(2));
  listeS.push_back(Sommet(3));
  listeS.push_back(Sommet(4));
  listeS.push_back(Sommet(5));
  listeA.push_back(Arc(0,listeS[1].getID(),listeS[2].getID()));
  listeA.push_back(Arc(1,listeS[0].getID(),listeS[1].getID()));
  listeA.push_back(Arc(2,listeS[0].getID(),listeS[2].getID()));
  listeA.push_back(Arc(3,listeS[1].getID(),listeS[3].getID()));
  listeA.push_back(Arc(4,listeS[2].getID(),listeS[3].getID()));
  listeA.push_back(Arc(5,listeS[2].getID(),listeS[5].getID()));
  listeA.push_back(Arc(6,listeS[3].getID(),listeS[4].getID()));

  SECTION("Test du constructeur avec tout les arguments"){
      Graphe G0("Graphe0", listeS, listeA, "NULL");
      REQUIRE(G0.getEtiq() == "Graphe0");
      REQUIRE(G0.getListe_Arcs() == listeA);
      REQUIRE(G0.getListe_Sommets() == listeS);
      REQUIRE(G0.getPath() == "NULL");

  }

  SECTION("Test du constructeur vide"){
    Graphe G0 ("Graphe G0");
    REQUIRE(G0.getEtiq() == "Graphe0");
    // REQUIRE(G1.getListe_Arcs() == listeA);
    // REQUIRE(G1.getListe_Sommets() == listeS);
    REQUIRE(G0.getPath() == "\0");
  }

  SECTION("Test du constructeur par Matrice d'Adjacence"){
      std::vector<Sommet> LS; // Liste Sommet (3 sommets)
      LS.push_back(Sommet(0));
      LS.push_back(Sommet(1));
      LS.push_back(Sommet(2));

      std::vector<Arc> LA; //Liste Arcs vide

      Matrice MA1(3); //Matrice Adjacence avec 3 Sommets 0 Arcs
      Graphe G0(MA1);
      REQUIRE(G0.getEtiq() == "Graphe Adjacence");
      REQUIRE(G0.getListe_Arcs() == LA);
      REQUIRE(G0.getListe_Sommets() == LS);
      REQUIRE(G0.getPath() == "\0");
  }

  SECTION("Test du constructeur par copie"){
    Graphe G1("Bonjour");
    Graphe G2(G1);
    REQUIRE(G1.getEtiq()==G2.getEtiq());
    REQUIRE(G1.getListe_Arcs()==G2.getListe_Arcs());
    REQUIRE(G1.getListe_Sommets()==G2.getListe_Sommets());
    REQUIRE(G1.getPath()==G2.getPath());
  }
//suite a revoir
  SECTION("Test du constructeur par Liste de Voisin"){
    std::vector<std::vector<int>> LV;
    LV.push_back({1});
    LV.push_back({2});
    LV.push_back({0});
    Graphe GV(LV);

  }

}


TEST_CASE ("Test du destructeur de la classe", "[Graphe]"){ // A FAIRE
  // à faire
}

TEST_CASE ("Test de l'opérateur =", "[Graphe]"){

}

TEST_CASE ("Test de l'opérateur ==", "[Graphe]"){

}

TEST_CASE ("Test de conversion en matrice d'adjacence et d'incidence", "[Graphe]"){
  /* GRAPHE G1*/
  std::vector<Sommet> listeS;
  std::vector<Arc> listeA;
  listeS.push_back(Sommet(0));
  listeS.push_back(Sommet(1));
  listeS.push_back(Sommet(2));
  listeA.push_back(1,listeS[0],listeS[1]);
  listeA.push_back(2,listeS[1],listeS[2]);
  listeA.push_back(3,listeS[2],listeS[0]);
  Graphe G1("Graphe0", listeS, listeA, "NULL");

  SECTION("Test de conversion en Matrice d'adjacence"){
    /*Matrice MA1*/
    Matrice MA1 (3);

    REQUIRE(G1.conversion_vers_Matrice_adj() == MA1);
  }

  SECTION("Test de conversion en Matrice d'incidence"){
    /*Matrice MI*/
    Matrice MI1 (1,3,1);

    REQUIRE(G1.conversion_vers_Matrice_inc() == MI1);
  }
}

TEST_CASE ("Test ajout de sommet", "[Graphe]"){

}

TEST_CASE ("Test suprression de sommet", "[Graphe]"){

}

// A FAIRE
TEST_CASE ("Test ajout d'arc", "[Graphe]"){
  /* GRAPHE G1*/
  vector<Sommet> listeS;
  vector<Arc> listeA;
  listeS.push_back(Sommet(0));
  listeS.push_back(Sommet(1));
  listeS.push_back(Sommet(2));
  listeA.push_back(1,listeS[0],listeS[1]);
  listeA.push_back(2,listeS[1],listeS[2]);
  listeA.push_back(3,listeS[2],listeS[0]);
  Graphe G1("Graphe1", listeS, listeA, "NULL");

}

// A FAIRE
TEST_CASE ("Test de suppression d'arc", "[Graphe]"){
  /* GRAPHE G1*/
  vector<Sommet> listeS;
  vector<Arc> listeA;
  listeS.push_back(Sommet(0));
  listeS.push_back(Sommet(1));
  listeS.push_back(Sommet(2));
  listeA.push_back(1,listeS[0],listeS[1]);
  listeA.push_back(2,listeS[1],listeS[2]);
  listeA.push_back(3,listeS[2],listeS[0]);
  Graphe G1("Graphe1", listeS, listeA, "NULL");
}

// A FAIRE KILL ME PLIZ
TEST_CASE ("Test de conversion en liste de voisin", "[Graphe]"){
  /*GRAPHE G0*/
  vector<Sommet> listeS;
  vector<Arc> listeA;
  listeS.push_back(Sommet(0));
  listeS.push_back(Sommet(1));
  listeS.push_back(Sommet(2));
  listeS.push_back(Sommet(5));
  listeS.push_back(Sommet(3));
  listeS.push_back(Sommet(4));
  listeA.push_back(1,listeS[1],listeS[2]);
  listeA.push_back(2,listeS[0],listeS[1]);
  listeA.push_back(3,listeS[0],listeS[2]);
  listeA.push_back(4,listeS[1],listeS[3]);
  listeA.push_back(5,listeS[2],listeS[3]);
  listeA.push_back(6,listeS[2],listeS[5]);
  listeA.push_back(7,listeS[3],listeS[4]);
  Graphe G0("Graphe0", listeS, listeA, "NULL");
  vector<vector<int>> result;

  REQUIRE(G0.conversion_vers_listeDeVoisins())
}

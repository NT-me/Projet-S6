#define CATCH_CONFIG_MAIN
#include "../../../libExt/catch2/include/catch.hpp"
#include "../../../src/bib/classes/Matrice.hh"


TEST_CASE ("Test des setters", "[Matrice]"){
  Matrice MA1 (3,3,0);

  SECTION ("Set tailleV"){
    MA1.setV (5);
    REQUIRE (MA1.gettV() == 5);
  }
  SECTION ("Set tailleE"){
    MA1.setE (5);
    REQUIRE (MA1.gettE() == 5);
  }
  SECTION ("Set type"){
    MA1.setType (1);
    REQUIRE (MA1.getType() == 1);
  }
  SECTION ("Set tab"){
    // A faire
  }
}

TEST_CASE ("Test des getters", "[Matrice]"){
  Matrice MA1 (3,3,0);

  SECTION ("Get tailleV"){
    REQUIRE (MA1.gettV () == 3)
  }
  SECTION ("Get tailleE"){
    REQUIRE (MA1.gettE () == 3)
  }
  SECTION ("Get type"){
    REQUIRE (MA1.getType () == 0)
  }
  SECTION ("Get tab"){
    // A faire
  }
}



TEST_CASE("Test des constructeur de la classe", "[Matrice]" ){

  SECTION ("Constructeur avec un grahe et un type"){

  }

  SECTION ("Constructeur avec une tailleV"){
    Matrice M1 (1);
    REQUIRE (M1.gettV() == 1);

    SECTION ("Constructeur par copie"){
      Matrice M2 (M1);
      REQUIRE (M2.gettV() == 1);
    }

  }

  SECTION ("Constructeur avec une tailleV, une tailleE et un type"){
    Matrice MI1 (1,3,1);

    REQUIRE (MI1.gettV() == 1);
    REQUIRE (MI1.gettE() == 3);
    REQUIRE (MI1.getType() == 1);
  }



}

TEST_CASE ("Test du destructeur de la classe", "[Matrice]"){
  // A faire
}

TEST_CASE("test modification d’une case","[matrice]"){
  Matrice MQ(3,3,4);
  MQ.modifTab(0,1,1);
  MQ.modifTab(1,2,1);
  MQ.modifTab(2,0,1);

  MQ.modifTab(1,2,10);

  REQUIRE((MQ.getTab()[1][2] == 10));

}

TEST_CASE ("Test de l'opérateur =", [matrice]){
  Matrice MI1 (1,3,1);
  Matrice MI2 (2,5,1);
  MI2 = MI1;

  REQUIRE (MI2.gettV() == 1);
  REQUIRE (MI2.gettE() == 3);
  REQUIRE (MI2.getType() == 1);

}

TEST_CASE ("Test de l'opérateur ==", "[Matrice]"){
  Matrice MI1 (1,3,1);
  Matrice MI2 (2,5,1);

  REQUIRE ((MI1 == MI2));
}

TEST_CASE ("Test de conversion en matrice d'incidence", "[Matrice]"){
  Matrice MA1(3);
  MA1.modifTab(0,1,1);
  MA1.modifTab(1,2,1);
  MA1.modifTab(2,0,1);

  Matrice MI1(3,3,1);
  MI1.modifTab(0,0,1);
  MI1.modifTab(1,1,1);
  MI1.modifTab(2,2,1);
  MI1.modifTab(0,2,-1);
  MI1.modifTab(1,0,-1);
  MI1.modifTab(2,1,-1);

  MA1.conversion_incidence();

  Matrice MQ(3,3,4);

  REQUIRE ((MQ.conversion_incidence() == -1));
  REQUIRE ((MA1 == MI1));

}

TEST_CASE ("Test d'inversion de la matrice", "[Matrice]"){
  Matrice MA1(3);
  MA1.modifTab(0,1,1);
  MA1.modifTab(1,2,1);
  MA1.modifTab(2,0,1);

  Matrice MAI1(3);
  MAI1.modifTab(0,2,1);
  MAI1.modifTab(1,0,1);
  MAI1.modifTab(2,1,1);

  MA1.inversion_Matrice();

  REQUIRE((MA1 == MAI1));

}

TEST_CASE ("test de sommet isolé d'un graphe", "[matrice]"){
  Matrice MA1(3);
  MA1.modifTab(0,1,1);
  MA1.modifTab(1,2,1);
  MA1.modifTab(2,0,1);

  Matrice M2(3);
  M2.modifTab(1,0,1);

  REQUIRE((MA1.Sommet_non_isole() == 1 && M2.Sommet_non_isole() == 0))


}


TEST_CASE ("Test de la conversion en graphe", "[Matrice]"){
  Matrice MA1(3);
  MA1.modifTab(0,1,1);
  MA1.modifTab(1,2,1);
  MA1.modifTab(2,0,1);

  Matrice MI1(3,3,1);
  MI1.modifTab(0,0,1);
  MI1.modifTab(1,1,1);
  MI1.modifTab(2,2,1);
  MI1.modifTab(0,2,-1);
  MI1.modifTab(1,0,-1);
  MI1.modifTab(2,1,-1);

  Graphe G1("testG1")
  G1.ajout_Sommet(0,0,0);
  G1.ajout_Sommet(1,20,20);
  G1.ajout_Sommet(2,0,30);
  G1.ajout_Arc(0,1);
  G1.ajout_Arc(1,2);
  G1.ajout_Arc(2,0);

  Graphe G2("g2");
  Graphe G3("g3")

  G2 = MA1.conversionGraphe();
  G3 = MI1.conversionGraphe();

  REQUIRE((G1 == G2 && G1 == G3));
}

TEST_CASE ("Test  de supression de ligne", "[Matrice]"){
  Matrice MQ(3,3,4);
  MQ.modifTab(0,1,1);
  MQ.modifTab(1,2,1);
  MQ.modifTab(2,0,1);

  MQ.supprLigne(1);

  Matrice MQ2(2,3,4)
  MQ2.modifTab(0,1,1);
  MQ2.modifTab(1,0,1);

  REQUIRE((MQ == MQ2));

}

TEST_CASE ("Test de supression de colonne", "[Matrice]"){
  Matrice MQ(3,3,4);
  MQ.modifTab(0,1,1);
  MQ.modifTab(1,2,1);
  MQ.modifTab(2,0,1);

  MQ.supprCol(1);

  Matrice MQ3(3,2,4)

  MQ3.modifTab(1,1,1);
  MQ3.modifTab(2,0,1);

  REQUIRE((MQ == MQ3));
}

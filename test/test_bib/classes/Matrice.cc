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

}

TEST_CASE ("Test d'inversion de la matrice", "[Matrice]"){

}

TEST_CASE ("Test de la conversion en graphe", "[Matrice]"){

}

TEST_CASE ("Test  de supression de ligne", "[Matrice]"){

}

TEST_CASE ("Test de supression de colonne", "[Matrice]"){

}

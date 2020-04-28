#include "../../../src/bib/classes/Matrice.hh"

#define CATCH_CONFIG_MAIN
#include "../../../libExt/catch2/include/catch.hpp"


TEST_CASE ("Test des setters", [matrice]){
  Matrice MA1 (3,3,0);

  SECTION ("Set tailleV"){
    MA1.setV (5);
    REQUIRE (MA1.tailleV == 5);
  }
  SECTION ("Set tailleE"){
    MA1.setE (5);
    REQUIRE (MA1.tailleE == 5);
  }
  SECTION ("Set type"){
    MA1.setType (1);
    REQUIRE (MA1.type == 1);
  }
  SECTION ("Set tab"){
    // A faire
  }

}

TEST_CASE ("Test des getters", []){
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



TEST_CASE("Test des constructeur de la classe", [matrice] ){

  SECTION ("Constructeur avec un grahe et un type"){

  }

  SECTION ("Constructeur avec une tailleV"){
    Matrice M1 (1);
    REQUIRE (M1.tailleV == 1);

    SECTION ("Constructeur par copie"){
      Matrice M2 (M1);
      REQUIRE (M2.tailleV == 1);
    }

  }

  SECTION ("Constructeur avec une tailleV, une tailleE et un type"){
    Matrice MI1 (1,3,1);

    REQUIRE (MI1.tailleV == 1);
    REQUIRE (MI1.tailleE == 3);
    REQUIRE (MI1.type == 1);
  }



}

TEST_CASE ("Test du destructeur de la classe", [matrice]){
  // A faire
}

TEST_CASE ("Test de l'opérateur =", [matrice]){
  Matrice MI1 (1,3,1);
  Matrice MI2 (2,5,1);
  MI2 = MI1;

  REQUIRE (MI2.tailleV == 1);
  REQUIRE (MI2.tailleE == 3);
  REQUIRE (MI2.type == 1);

}

TEST_CASE ("Test de l'opérateur ==", [matrice]){
  Matrice MI1 (1,3,1);
  Matrice MI2 (2,5,1);

  REQUIRE ((MI1 == MI2));
}

TEST_CASE ("Test de conversion en matrice d'incidence", [matrice]){

}

TEST_CASE ("Test d'inversion de la matrice", [matrice]){

}

TEST_CASE ("Test de la conversion en graphe", [matrice]){

}

TEST_CASE ("Test  de supression de ligne", [matrice]){

}

TEST_CASE ("Test de supression de colonne", [matrice]){

}

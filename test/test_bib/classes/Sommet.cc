#include "../../../src/bib/classes/Sommet.hh"

#define CATCH_CONFIG_MAIN
#include "../../../libExt/catch2/include/catch.hpp"

TEST_CASE ("Test des setters", [sommet]){

  Sommet S0 (1,2,"sommet0",0,m);

    SECTION ("Set x"){
      S0.setPosX (54);
      REQUIRE (S0.x == 54)
    }
    SECTION ("Set y"){
      S0.setPosY (45);
      REQUIRE (S0.y == 45);
    }
    SECTION ("Set ID"){
      S0.setID (12);
      REQUIRE (S0.ID == 12);
    }
    SECTION ("Set etiquette"){
      S0.setEtiq("sommet0'");
      REQUIRE (S0.etiquette == "sommet0'");
    }
    SECTION ("Set SCharge_utile"){
      S0.setCU ();      // A faire
    }

}

TEST_CASE ("Test des getters", []){

  Sommet S0 (23,32,"sommet0",0,m);

    SECTION ("Get x"){
      REQUIRE (S0.getPosX() == 23);
    }
    SECTION ("Get y"){
      REQUIRE (S0.getPosY() == 32);
    }
    SECTION ("Get ID"){
      REQUIRE (S0.getID() == 0);
    }
    SECTION ("Get etiquette"){
      REQUIRE (S0.getEtiq () == "sommet0");
    }

    SECTION ("Get map"){
      REQUIRE (S0.getCU () == NULL); // A faire
    }

}


TEST_CASE("Test des constructeur de la classe", [sommet] ){

    SECTION ("Test du constructeur avec tout les arguments"){
      Sommet S1 (2,3,"sommet1",1,vec);

      REQUIRE (S1.x == 2);
      REQUIRE (S1.y == 3);
      REQUIRE (S1.ID == 1);
      REQUIRE (S1.etiquette == "sommet1");

      REQUIRE (S1.SCharge_utile == NULL); // A faire
    }

    SECTION ("Test du constructeur sans map"){
      Sommet S2 (2,3,"sommet2",2);

      REQUIRE (S2.x == 2);
      REQUIRE (S2.y == 3);
      REQUIRE (S2.ID == 2);
      REQUIRE (S2.etiquette == "sommet2");
    }

    SECTION ("Test du constructeur avec une etiquette et un ID"){
      Sommet S3 ("sommet3", 3);

      REQUIRE (S3.ID == 3);
      REQUIRE (S3.etiquette == "sommet3");
    }

    SECTION ("Test du constructeur avec un id "){
      Sommet S4 (4);

      REQUIRE (S4.ID == 4);

        SECTION ("Test du constructeur par copie"){
          Sommet S5 (S4);

          REQUIRE (S5.ID == 4);
        }
    }

}

TEST_CASE ("Test du destructeur de la classe", [sommet]){

  // A faire

}

TEST_CASE ("Test de l'opérateur =", [sommet]){
  Sommet S2 (2,3,"sommet2", 2);
  Sommet S5 (4);
  S5 = S2;

  REQUIRE (S5.x == 2);
  REQUIRE (S5.y == 3);
  REQUIRE (S5.etiquette == "sommet2");
  REQUIRE (S5.ID == 2);

}

/*
Raison pour laquelle il y a deux parenthèse dans le REQUIRE
https://stackoverflow.com/questions/59770581/cant-use-overloaded-comparison-operator-with-catch-test
*/
TEST_CASE ("Test de l'opérateur ==", [sommet]){
  Sommet S0 (23,32,"sommet0",0,m);
  Sommet S1 (2,3,"sommet1",1,vec);
  // Faire les map

  REQUIRE ((S0 == S1));

}

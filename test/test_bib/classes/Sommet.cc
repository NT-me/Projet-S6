#define CATCH_CONFIG_MAIN
#include "../../../libExt/catch2/include/catch.hpp"
#include "../../../src/bib/classes/Sommet.hh"

TEST_CASE ("Test des setters", "[Sommet]"){
  map<string, VectVal> m;

  Sommet S0 (1,2,"sommet0",0,m);

    SECTION ("Set x"){
      S0.setPosX (54);
      REQUIRE (S0.getPosX() == 54)
    }
    SECTION ("Set y"){
      S0.setPosY (45);
      REQUIRE (S0.getPosY() == 45);
    }
    SECTION ("Set ID"){
      S0.setID (12);
      REQUIRE (S0.getID () == 12);
    }
    SECTION ("Set etiquette"){
      S0.setEtiq("sommet0'");
      REQUIRE (S0.getEtiq() == "sommet0'");
    }
    SECTION ("Set SCharge_utile"){
      S0.setCU ();      // A faire
      REQUIRE (getCU () == m);
    }

}

TEST_CASE ("Test des getters", "[Sommet]"){

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


TEST_CASE("Test des constructeur de la classe", "[Sommet]" ){

    SECTION ("Test du constructeur avec tout les arguments"){
      Sommet S1 (2,3,"sommet1",1,vec);

      REQUIRE (S1.getPosX() == 2);
      REQUIRE (S1.getPosY() == 3);
      REQUIRE (S1.getID() == 1);
      REQUIRE (S1.getEtiq () == "sommet1");

      REQUIRE (S1.getCU () == NULL); // A faire
    }

    SECTION ("Test du constructeur sans map"){
      Sommet S2 (2,3,"sommet2",2);

      REQUIRE (S2.getPosX() == 2);
      REQUIRE (S2.getPosY() == 3);
      REQUIRE (S2.getID() == 2);
      REQUIRE (S2.getEtiq () == "sommet2");
    }

    SECTION ("Test du constructeur avec une etiquette et un ID"){
      Sommet S3 ("sommet3", 3);

      REQUIRE (S3.getID () == 3);
      REQUIRE (S3.getEtiq () == "sommet3");
    }

    SECTION ("Test du constructeur avec un id "){
      Sommet S4 (4);

      REQUIRE (S4.getID() == 4);

        SECTION ("Test du constructeur par copie"){
          Sommet S5 (S4);

          REQUIRE (S5.getID() == 4);
        }
    }

}

TEST_CASE ("Test du destructeur de la classe", "[Sommet]"){

  // A faire

}


TEST_CASE ("Test de l'opérateur =", "[Sommet]"){
  Sommet S2 (2,3,"sommet2", 2);
  Sommet S5 (4);
  S5 = S2;

  REQUIRE (S5.getPosX() == 2);
  REQUIRE (S5.getPosY () == 3);
  REQUIRE (S5.getEtiq() == "sommet2");
  REQUIRE (S5.getID() == 2);

}

/*
Raison pour laquelle il y a deux parenthèse dans le REQUIRE
https://stackoverflow.com/questions/59770581/cant-use-overloaded-comparison-operator-with-catch-test
*/
TEST_CASE ("Test de l'opérateur ==", "[Sommet]"){
  Sommet S0 (23,32,"sommet0",0,m);
  Sommet S1 (2,3,"sommet1",1,vec);
  // Faire les map

  REQUIRE ((S0 == S1));

}

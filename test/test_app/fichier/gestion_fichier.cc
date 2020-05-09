#define CATCH_CONFIG_MAIN
#include "../../../libExt/catch.hpp"
#include "../../../src/app/fichier/gestion_fichier.hh"

#ifndef test_fichier
#define test_fichier


// Le test de la suppression est effectué avant les autres afin de supprimer les présedents essais.
TEST_CASE ("Test de la suppression", "[]"){
  // Il doit y avoir le fichier G0.json dans le repertoire fichierJSON pour que le test passe
  REQUIRE (suppression("../fichierJSON/G0.json") == 0);
}


TEST_CASE ("Test de la sauvegarde", "[]"){

  vector<Sommet> listeS;
  vector<Arc> listeA;
  listeS.push_back(Sommet(0));
  listeS.push_back(Sommet(1));
  listeS.push_back(Sommet(2));

  listeA.push_back(Arc(1,listeS[0].getID(),listeS[1].getID()));
  listeA.push_back(Arc(2,listeS[1].getID(),listeS[2].getID()));
  listeA.push_back(Arc(3,listeS[2].getID(),listeS[0].getID()));

  SECTION ("Test de la sauvegarde normale"){
    Graphe G0 ("graphe0", listeS, listeA, "../fichierJSON/G0.json");
    REQUIRE (sauvegarde(G0,"") == 0);
    REQUIRE (G0.getPath() == "../fichierJSON/G0.json");
  }


  SECTION ("Test de la sauvegarde avancé"){
    Graphe G0 ("graphe0", listeS, listeA, "../fichierJSON/G0.json");
    REQUIRE (sauvegarde(G0,"../fichierJSON/G0modif.json") == 0);
    cout << "test"<<G0.getPath ()<< endl ;
    //REQUIRE (G0.getPath() == "../fichierJSON/G0modif.json");
  }
}
//
//
// TEST_CASE ("Test du chargement", "[]"){
//
//   vector<Sommet> listeS;
//   vector<Arc> listeA;
//
//   listeS.push_back(Sommet(0));
//   listeS.push_back(Sommet(1));
//   listeS.push_back(Sommet(2));
//   listeA.push_back(Arc(1,listeS[0].getID(),listeS[1].getID()));
//   listeA.push_back(Arc(2,listeS[1].getID(),listeS[2].getID()));
//   listeA.push_back(Arc(3,listeS[2].getID(),listeS[0].getID()));
//
//   Graphe G0 ("graphe0", listeS, listeA, "/fichierJSON/G0.json");
//   sauvegarde (G0,"");
//   REQUIRE (G0 == chargement("/fichierJSON/G0.json"));
//
// }
//
//
//
// TEST_CASE ("Test de la verification de fichier", "[]"){
//
//   // string fic "/fichierJSON/G0.json";
//   // D = fic parser ????
//
//   // rapidjson::Document D;
//   // REQUIRE (verif_file (D) == 0);
//
// }



#endif

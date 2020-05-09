#include "gestion_fichier.hh"
// #include "../../../libExt/rapidjson/stringbuffer.h"
#include "../../../libExt/rapidjson/writer.h"
#include "../../../libExt/rapidjson/filewritestream.h"
#include "../../../libExt/rapidjson/prettywriter.h"

#include <fstream>

using namespace rapidjson;

int sauvegarde(Graphe G, string path){

  // sauvegarde classique
if (path == ""){

     StringBuffer s;
     PrettyWriter <StringBuffer> writer(s);
     writer.StartObject();

     writer.Key("etiquette");
     writer.String(G.getEtiq().c_str());

     writer.Key ("path");
     writer.String(G.getPath().c_str());

     writer.Key ("listeS");
     writer.StartArray ();
     //Boucle pour les Sommets
     for (int i = 0; i < G.getListe_Sommets().size() ; i++ ){

      writer.StartObject ();

       writer.Key ("x");
       writer.Uint (G.getListe_Sommets()[i].getPosX());

       writer.Key ("y");
       writer.Uint (G.getListe_Sommets()[i].getPosY());

       writer.Key ("id");
       writer.Uint (G.getListe_Sommets()[i].getID());

       writer.Key("etiquette");
       writer.String(G.getListe_Sommets()[i].getEtiq().c_str());

       writer.Key ("vecArc");
       writer.StartArray();
       //writer.StartObject();
       //Boucle pour savoir a quels arcs le sommet et relié
        for (int j = 0; j < G.getListe_Sommets()[i].getVecArc().size() ;j++)
          writer.Uint (G.getListe_Sommets()[i].getVecArc()[j]);
       //writer.EndObject();
       writer.EndArray();


       // Revoir avec les maps

       // writer.Key("AChargeUtile");
       // writer.StartArray ();
       //   for (int k = 0; k < /*G.getListe_Sommets()[i].getCU().size()*/ 5 ;k++){
       //    writer.StartObject();
       //    writer.Key("vecteur");
       //    writer.Uint (5);
       //    writer.EndObject();
       //   }
       // writer.EndArray ();
       //


       writer.EndObject();
     }

     writer.EndArray (); // Fin des Sommets

     writer.Key ("listeA");
     writer.StartArray ();
     //Boucle pour les Sommets
     for (int i = 0; i < G.getListe_Arcs().size() ; i++ ){

      writer.StartObject ();

       writer.Key ("id");
       writer.Uint (G.getListe_Arcs()[i].getID());

       writer.Key ("etiquette");
       writer.String (G.getListe_Arcs()[i].getEtiq().c_str());

       writer.Key ("IDdepart");
       writer.Uint (G.getListe_Arcs()[i].getIDDepart());

       writer.Key("IDarrive");
       writer.Uint(G.getListe_Arcs()[i].getIDArrive());

       // Revoir avec les maps

       // writer.Key("AChargeUtile");
       // writer.StartArray ();
       //   for (int k = 0; k < /*G.getListe_Sommets()[i].getCU().size()*/ 5 ;k++){
       //    writer.StartObject();
       //    writer.Key("vecteur");
       //    writer.Uint (5);
       //    writer.EndObject();
       //   }
       // writer.EndArray ();

       writer.EndObject();
     }

     writer.EndArray (); // Fin des Arcs


   writer.EndObject(); // Fin du fichier

     // Utilisation du fichier ayant pour chemin celui du graphe pour modifier les valeurs dans le fichier.
     std::ofstream o(G.getPath().c_str());
     o<<s.GetString ();

      if (!o.good())
        return 1;

    return 0;
  }



  // sauvegarde sous
  if (path != ""){

    StringBuffer s;
    PrettyWriter <StringBuffer> writer(s);
    writer.StartObject();

    writer.Key("etiquette");
    writer.String(G.getEtiq().c_str());

    writer.Key ("path");
    writer.String(path.c_str());

    writer.Key ("listeS");
    writer.StartArray ();
    //Boucle pour les Sommets
    for (int i = 0; i < G.getListe_Sommets().size() ; i++ ){

     writer.StartObject ();

      writer.Key ("x");
      writer.Uint (G.getListe_Sommets()[i].getPosX());

      writer.Key ("y");
      writer.Uint (G.getListe_Sommets()[i].getPosY());

      writer.Key ("id");
      writer.Uint (G.getListe_Sommets()[i].getID());

      writer.Key("etiquette");
      writer.String(G.getListe_Sommets()[i].getEtiq().c_str());

      writer.Key ("vecArc");
      writer.StartArray();
      //writer.StartObject();
      //Boucle pour savoir a quels arcs le sommet et relié
       for (int j = 0; j < G.getListe_Sommets()[i].getVecArc().size() ;j++)
         writer.Uint (G.getListe_Sommets()[i].getVecArc()[j]);
      //writer.EndObject();
      writer.EndArray();


      // Revoir avec les maps

      // writer.Key("AChargeUtile");
      // writer.StartArray ();
      //   for (int k = 0; k < /*G.getListe_Sommets()[i].getCU().size()*/ 5 ;k++){
      //    writer.StartObject();
      //    writer.Key("vecteur");
      //    writer.Uint (5);
      //    writer.EndObject();
      //   }
      // writer.EndArray ();
      //


      writer.EndObject();
    }

    writer.EndArray (); // Fin des Sommets

    writer.Key ("listeA");
    writer.StartArray ();
    //Boucle pour les Sommets
    for (int i = 0; i < G.getListe_Arcs().size() ; i++ ){

     writer.StartObject ();

      writer.Key ("id");
      writer.Uint (G.getListe_Arcs()[i].getID());

      writer.Key ("etiquette");
      writer.String (G.getListe_Arcs()[i].getEtiq().c_str());

      writer.Key ("IDdepart");
      writer.Uint (G.getListe_Arcs()[i].getIDDepart());

      writer.Key("IDarrive");
      writer.Uint(G.getListe_Arcs()[i].getIDArrive());

      // Revoir avec les maps

      // writer.Key("AChargeUtile");
      // writer.StartArray ();
      //   for (int k = 0; k < /*G.getListe_Sommets()[i].getCU().size()*/ 5 ;k++){
      //    writer.StartObject();
      //    writer.Key("vecteur");
      //    writer.Uint (5);
      //    writer.EndObject();
      //   }
      // writer.EndArray ();

      writer.EndObject();
    }

    writer.EndArray (); // Fin des Arcs



    writer.EndObject();

    cout << s.GetString() <<endl;


    // Utilisation du fichier ayant pour chemin celui du graphe pour modifier les valeurs dans le fichier.
    std::ofstream o(path.c_str());
    o<<s.GetString ();

    //cout << "fin" << G.getPath () <<endl;

     if (!o.good())
       return 1;

    return 0;
  }

  return 2;

}






Graphe chargement (string path){

  Graphe G0 (0);
  return G0;

}


bool verif_file (rapidjson::Document D){

  return true;
}





int suppression (string path){
  return std::remove (path.c_str());
}

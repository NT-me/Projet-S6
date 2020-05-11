#include "gestion_fichier.hh"
// #include "../../../libExt/rapidjson/stringbuffer.h"
#include "../../../libExt/rapidjson/writer.h"
#include "../../../libExt/rapidjson/filewritestream.h"
#include "../../../libExt/rapidjson/prettywriter.h"

#include <fstream>
#include <iterator>
#include <map>
#include <iostream>

using namespace rapidjson;

int sauvegarde(Graphe G, string path){

  // sauvegarde classique
if (path == ""){

     StringBuffer s;
     PrettyWriter <StringBuffer> writer(s);
     writer.StartObject();
     writer.SetMaxDecimalPlaces (3);

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



       // Poids sur les sommets avec des valeurs entieres ou reelles
       writer.Key("SChargeUtile");
       writer.StartArray ();
       /*Iterateur sur la liste de sommets pour les poids*/
       map<string, VectVal>::iterator itr = G.getListe_Sommets()[i].getCU().begin();
       map<string, VectVal> m  = G.getListe_Sommets()[i].getCU();


        while (itr != m.end()){

         string mot = itr->first; // Accede au premier champs de la map (string)
         VectVal V = itr->second; // Accede au deuxieme champs de la map (VectVal)
         writer.StartObject();
         writer.Key(mot.c_str());
         writer.Uint(V.type);

         if (V.type == 1){
           writer.Key("Valeur reel");
           writer.Double(V.valeur_reel);
         }
         if (V.type == 0){
           writer.Key("Valeur entiere");
           writer.Uint(V.valeur_entiere);
         }

         writer.EndObject();
         itr ++;

       }
       writer.EndArray (); // Fin de SChargeUtile

     writer.EndObject(); //Fin de listeS
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



       writer.Key("AChargeUtile");
       writer.StartArray();

       map<string, VectVal> map2 = G.getListe_Arcs()[i].getCU();
       map<string, VectVal>::iterator itr = map2.begin();

       while (itr != map2.end()){

         string mot2 = itr->first;
         VectVal V2 = itr->second;

         writer.StartObject();
         writer.Key (mot2.c_str());
         writer.Uint (V2.type);

           if (V2.type == 1){
             writer.Key("Valeur reel");
             writer.Double(V2.valeur_reel);
           }
           if (V2.type == 0){
             writer.Key("Valeur entiere");
             writer.Uint(V2.valeur_entiere);
           }

         writer.EndObject();
         itr ++;
       }

       writer.EndArray(); // Fin de AChargeUtile


       writer.EndObject(); // Fin de listeA
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



      // Poids sur les sommets avec des valeurs entieres ou reelles
      writer.Key("SChargeUtile");
      writer.StartArray ();
      /*Iterateur sur la liste de sommets pour les poids*/
      map<string, VectVal>::iterator itr = G.getListe_Sommets()[i].getCU().begin();
      map<string, VectVal> m  = G.getListe_Sommets()[i].getCU();


       while (itr != m.end()){

        string mot = itr->first; // Accede au premier champs de la map (string)
        VectVal V = itr->second; // Accede au deuxieme champs de la map (VectVal)
        writer.StartObject();
        writer.Key(mot.c_str());
        writer.Uint(V.type);

        if (V.type == 1){
          writer.Key("Valeur reel");
          writer.Double(V.valeur_reel);
        }
        if (V.type == 0){
          writer.Key("Valeur entiere");
          writer.Uint(V.valeur_entiere);
        }

        writer.EndObject();
        itr ++;

      }
      writer.EndArray (); // Fin de SChargeUtile

    writer.EndObject(); //Fin de listeS
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



      writer.Key("AChargeUtile");
      writer.StartArray();

      map<string, VectVal> map2 = G.getListe_Arcs()[i].getCU();
      map<string, VectVal>::iterator itr = map2.begin();

      while (itr != map2.end()){

        string mot2 = itr->first;
        VectVal V2 = itr->second;

        writer.StartObject();
        writer.Key (mot2.c_str());
        writer.Uint (V2.type);

          if (V2.type == 1){
            writer.Key("Valeur reel");
            writer.Double(V2.valeur_reel);
          }
          if (V2.type == 0){
            writer.Key("Valeur entiere");
            writer.Uint(V2.valeur_entiere);
          }

        writer.EndObject();
        itr ++;
      }

      writer.EndArray(); // Fin de AChargeUtile


      writer.EndObject(); // Fin de listeA
    }

      writer.EndArray (); // Fin des Arcs


  writer.EndObject(); // Fin du fichier


    // Utilisation du fichier ayant pour chemin celui du graphe pour modifier les valeurs dans le fichier.
    std::ofstream o(path.c_str());
    o<<s.GetString ();

     if (!o.good())
       return 1;

   return 0;
 }

  return 2; // Revoir les returns

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

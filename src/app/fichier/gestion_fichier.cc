#include "gestion_fichier.hh"
// #include "../../../libExt/rapidjson/stringbuffer.h"
#include "../../../libExt/rapidjson/writer.h"
#include "../../../libExt/rapidjson/filewritestream.h"
#include <fstream>

using namespace rapidjson;

int sauvegarde(Graphe G, string path){

  // sauvegarde classique
if (path == "")
{

     StringBuffer s;
     Writer <StringBuffer> writer(s);
     writer.StartObject();

     writer.Key("etiquette");
     writer.String(G.getEtiq().c_str());

     writer.Key ("path");
     writer.String(G.getPath().c_str());

     // A faire : listeA et listeS













     writer.EndObject();

     cout << s.GetString() <<endl;


     // Utilisation du fichier ayant pour chemin celui du graphe pour modifier les valeurs dans le fichier.
     std::ofstream o(G.getPath().c_str());
     o<<s.GetString ();

      if (!o.good())
        return 1;

    return 0;
  }



  // sauvegarde sous
  if (path != ""){
    //cout << "avant" << G.getPath() << endl;
    G.setPath(path);
    //cout << "apres" <<G.getPath()<< endl;

    StringBuffer s;
    Writer <StringBuffer> writer(s);
    writer.StartObject();

    writer.Key("etiquette");
    writer.String(G.getEtiq().c_str());

    writer.Key ("path");
    writer.String(G.getPath().c_str());

    // A faire : listeA et listeS










    writer.EndObject();

    cout << s.GetString() <<endl;


    // Utilisation du fichier ayant pour chemin celui du graphe pour modifier les valeurs dans le fichier.
    std::ofstream o(G.getPath().c_str());
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

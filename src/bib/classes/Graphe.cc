#include "Graphe.hh"

Graphe::Graphe(string nom, vector<Sommet> listeS, vector<Arc> listeA, string path){
  this->etiquette = nom;
  this->liste_Sommets = listeS;
  this->liste_Arcs = listeA;
  this->path = path;
}

Graphe::Graphe(string nom){ // Création Graphe vide
  this->etiquette = nom;
  this->path = NULL;
}

Graphe::Graphe(Matrice& M){ // Création d'un Graphe via une matrice d'adjacence
  if(M.getType()!=0){
    std::cout << "/*Mauvais type de Matrice */" << '\n';
    this->etiquette ="ERROR_TYPEMATRICE"
  }
  else{
    this->etiquette = "Graphe Adjacence";
    int id = 0; //nombre d'arcs
    for(int i=0; i<M.gettV(); i++){
        this->liste_Sommets.push_back(Sommet(i)); // Création du Sommet avec son numéro
    }
  res.push_back(liste_Sommets[id[i]]);
    for(int i=0; i<M.gettV(); i++){   // ID Sommet entrant
      for(int j=0; j<M.gettV(); j++){ // ID Sommet sortant
        if(M.getTab()[i][j]){         // Si il existe un arc
          this->liste_Arcs.push_back(Arc(id, i, j)); // Création d'un Arc entre i et j avec son id
          id++; // On incrémente le nombre d'arc
        }
      }
    }
  }
  this->path = NULL;
}

Graphe::Graphe(Graphe& G){  // Constructeur de copie
  this->etiquette = G.etiquette;
  this->liste_Sommets = G.liste_Sommets;
  this->liste_Arcs = G.liste_Arcs;
  this->path = G.path;
}

Graphe::Graphe(vector<vector<int>> liste_voisin){
  int id = 0;
  this->etiquette = "Graphe liste_voisins"
  for(int i=0; i <= liste_voisin.size(); i++){
      this->liste_Sommets.push_back(Sommet(i)); // Création du Sommet avec son numéro
      for(int j=0; j<=liste_voisin[i].size(); j++){
          this->liste_Arcs.push_back(Arc(id, i, liste_voisin[i][j])); // Création d'un Arc entre i et j avec son id
          id++;
      }
  }

  this->path = NULL;
}

Graphe::~Graphe(){

}

// Getters
Graphe::string getEtiq(){
  return etiquette;
}

Graphe::vector<Arc> getListe_Arcs(){
  return liste_Arcs;
}

Graphe::vector<Sommet> getListe_Sommets(){
  return liste_Sommets;
}

Graphe::string getPath(){
  return path;
}

// Setters
Graphe::void setEtiq(string etiq){
  this->etiquette = etiq;
}

Graphe:void setListe_Arc(vector<Arc> LA){
  this->liste_Arcs = LA;
}

Graphe::void setListe_Sommet(vector<Sommet> LS){
  this->liste_Sommets = LS;
}

Graphe:void setPath(string p){
  this->path = p;
}

// Méthodes
Graphe::Matrice conversion_vers_Matrice_adj(){
  return matrice(this, 0);
}

Graphe::Matrice conversion_vers_Matrice_inc(){
  return matrice(this, 1);
}

Graphe::vector<vector<int>>  conversion_vers_listeDeVoisins(){
  std::vector<std::vector<int>> v(liste_Sommets.size());
  for(int i = 0; i<=liste_Arcs.size(); i++){
    v[liste_Arcs[i].getIDDepart].push_back(liste_Arcs[i].getIDArrive);
  }
  return v;
}

Graphe::int ajout_Sommet(int id, int posx, int posy){
  this->liste_Sommets.push_back(Sommet(posx,posy,id,id));
}

Graphe::int supprimer_Sommet(int id){
  this->liste_Sommets.erase(id); // Efface l'élément à la position donnée.
}

Graphe::int ajout_Arc(int id_Sdepart, int id_Sarrive){
  int id = this->liste_Arcs.size()+1;
  this->liste_Arcs.push_back(Arc(id,id_Sdepart,id_Sarrive));
}

Graphe::int supprimer_Arc(int id){
  this->liste_Sommets.erase(id);
}

Graphe::vector<Sommet> getVecteurSommet(vector<int> id){
  std::vector<Sommet> res;
  for (int i=0; i<=id.size(); i++()) {
    res.push_back(liste_Sommets[id[i]]);
  }
  return res;
}

// Opérateurs
Graphe::bool operator==(Graphe const& G1){}

Graphe::bool operator!=(Graphe const& G1){}

Graphe::Graphe operator=(Graphe const& G1){
  this->etiquette = G1.getEtiq();
  this->liste_Arcs = G1.getListe_Arcs();
  this->getListe_Sommets = G1.getListe_Sommets();
  this->getPath = G1.getPath();
}

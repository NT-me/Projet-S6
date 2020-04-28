#include "../../../src/bib/classes/Matrice.hh"

Matrice(Graphe G, int type){// Constructeur d'une matrice issue d'un Graphe
  if(type == 0){  // Matrice Adjacence
    this->type = type;
    int cmptV=G.getListe_Sommets().size();

    this->taille_V = cmptV;
    this->taille_E = NULL;

    this->tab.resize(cmptV);  // On redimensionne la Matrice
    for(int i=0;i<cmptV;i++){
      this->tab[i].resize(tailleV);

    for(Arc x : G.getListe_Arcs()){//on met le poids dans la Matrice
      this->tab[x.getIDDepart()][x.getIDArrive()]= x.getCU().at("poids");
    }

  }
  else if(type == 1){ // Matrice incidence
    this->type = type;
    int cmptV=G.getListe_Sommets().size(),
        cmptE=G.getListe_Arcs().size();


    this->taille_V = cmptV;
    this->taille_E = cmptE;

    this->tab.resize(cmptV);  //on redimensionne la Matrice
    for(int i=0;i<cmptV;i++){
      this->tab[i].resize(cmptE);

    for(Arc x : G.getListe_Arcs()){
      this->tab[x.getIDDepart()][x.getIDArrive()]= x.getCU().at("poids");
    }
  }
  else{ //erreur création d'une Matrice vide
    std::cout << "/* Mauvais type de Matrice */" << '\n';
    this->taille_V = 0;
    this->taille_E = 0;
    this->type = type;
  }
}

Matrice(int tailleV){ //Construceur d'une matrice d'adjacence vide
  this->taille_V = tailleV;
  this->taille_E = NULL;
  this->type = 0;
  this->tab.resize(tailleV);  //on redimensionne la Matrice
  for(int i=0;i<tailleV;i++){
    this->tab[i].resize(tailleV);
  }
}

Matrice(int tailleV, int tailleE, int t){ // Constructeur d'une matrice autre vide
  this->V = tailleV;
  this->E = tailleE;
  this->type = t;
  this->tab.resize(tailleV);  //on redimensionne la Matrice
  for(int i=0;i<tailleV;i++){
    this->tab[i].resize(tailleE);
  }
}

Matrice(Matrice &M){ // Construceur de copie d'une Matrice
  this->taille_V = M.taille_V;
  this->taille_E = M.taille_E;
  this->type = M.type;
  this->tab = M.tab;
}

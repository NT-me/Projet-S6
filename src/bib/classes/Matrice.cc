#include "Matrice.hh"

Matrice::Matrice(Graphe G, int type){// Constructeur d'une matrice issue d'un Graphe
  if(type == ADJACENCE){  // Matrice Adjacence
    this->type = type;
    int cmptV=G.getListe_Sommets().size();

    this->taille_V = cmptV;
    this->taille_E = -1;

    this->tab.resize(cmptV);  // On redimensionne la Matrice
    for(int i=0;i<cmptV;i++){
      this->tab[i].resize(tailleV);
    }
    for(Arc x : G.getListe_Arcs()){//on met le poids dans la Matrice
      this->tab[x.getIDDepart()][x.getIDArrive()]= x.getCU().at("poids").valeur_entiere;
    }

  }
  else if(type == INCIDENCE){ // Matrice incidence
    this->type = type;
    int cmptV=G.getListe_Sommets().size(),
        cmptE=G.getListe_Arcs().size();


    this->taille_V = cmptV;
    this->taille_E = cmptE;

    this->tab.resize(cmptV);  //on redimensionne la Matrice
    for(int i=0;i<cmptV;i++){
      this->tab[i].resize(cmptE);
    }
    for(Arc x : G.getListe_Arcs();){
      this->[x.getIDDepart()][x.getID()]=1;
      this->[x.getIDArrive()][x.getID()]=-1;
    }
  }
  else{ //erreur création d'une Matrice vide
    std::cout << "/* Mauvais type de Matrice */" << '\n';
    this->taille_V = 0;
    this->taille_E = 0;
    this->type = type;
  }
}

Matrice::Matrice::Matrice(int tailleV){ //Construceur d'une matrice d'adjacence vide
  this->taille_V = tailleV;
  this->taille_E = 0;
  this->type = ADJACENCE;
  this->tab.resize(tailleV);  //on redimensionne la Matrice
  for(int i=0;i<tailleV;i++){
    this->tab[i].resize(tailleV);
  }
}

Matrice::Matrice(int tailleV, int tailleE, int t){ // Constructeur d'une matrice autre vide
  this->V = tailleV;
  this->E = tailleE;
  this->type = t;
  this->tab.resize(tailleV);  //on redimensionne la Matrice
  for(int i=0;i<tailleV;i++){
    this->tab[i].resize(tailleE);
  }
}

Matrice::Matrice(Matrice &M){ // Construceur de copie d'une Matrice
  this->taille_V = M.taille_V;
  this->taille_E = M.taille_E;
  this->type = M.type;
  this->tab = M.tab;
}

//Getters
int gettV(){return this->taille_V;}
int gettE(){return this->taille_E;}
int getType(){return this->type;}
vector<vector <int>> getTab(){return this->tab;}

//Setters
void setV(int v){this->taille_V = v;}
void setE(int e){this->taille_E = e;}
void setType(int type){this->type = type;}
void setTab(vector<vector <int>> tab){this->tab=tab;}

//Méthodes
Matrice conversion_incidence(){
//conversion d'une matrice d'adjacence en matrice d'incidence
  if(this->type == ADJACENCE){
    this->type = INCIDENCE;
    int cmp=0;
    for(int i=0;i<this->taille_E;i++){
      for(int j=0;j<this->taille_V;j++){
        if(this->tab[i][j])cmp++;
      }
    }

    Matrice res(this->taille_V,cmp,INCIDENCE);
    //a finir
    cmp=0;
    for(int i=0;i<this->taille_V;i++){
      for(int j=0;j<this->taille_V;j++){
        if(this->tab[i][j]){
          res.tab[i][cmp] = 1; //arc sortant
          res.tab[j][cmp] = -1; //arc entrant
          cmp++

        }
      }
    }
    return res;

  }
  else{
    std::cout << "/* Mauvaise conversion  */" << '\n';
    return this;
  }
}

Matrice inversion_Matrice();

  bool Matrice::operator==(Matrice const& M1){
  if(
  this->taille_E == M1.gettE()
  && this->taille_V == M1.gettV()
  && this->type == M1.getType()
  && this->tab == M1.getTab()
  )
  return 1;
  else return 0;
	  
	  
  }
  
  bool Matrice::operator!=(Matrice const& M1){return 1;}
  Matrice Matrice::operator=(Matrice const& M1){
  if(
     this->taille_E != M1.gettE()
  || this->taille_V != M1.gettV()
  || this->type != M1.getType()
  || this->tab != M1.getTab()
  )
  return 1;
  else return 0;
  }
  
  
  
  Matrice Matrice::operator=(Matrice const& M1){
  this->taille_E = M1.gettE
  this->taille_V = M1.gettV
  this->type = M1.getType
  this->tab = M1.getTab
  return this;
  }

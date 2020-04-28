#include "Arc.hh"


// GETTERS DE LA CLASSE ARC
int Arc::getID(){return ID;}
string Arc::getEtiq(){return etiquette;}
int Arc::getIDDepart(){return IDdepart;}
int Arc::getIDArrive(){return IDarrive;}
map <string,VectVal> Arc::getCU(){return ACharge_Utile;}


// SETTER DE LA CLASSE ARC
void Arc::setID(int id){ID = id;}
void Arc::setEtiq(string etiq){etiquette = etiq;}
void Arc::setIDDepart(int id){IDdepart = id;}
void Arc::setIDArrive(int id){IDarrive = id;}
void Arc::setCU(map <string, VectVal> CU){ACharge_Utile = CU;}

// Constructeurs de la classe Arc
Arc::Arc(string etiq, int id, int SDepart, int SArrive, map <string, VectVal> M){
  etiquette = etiq;
  ID = id;
  IDdepart = SDepart;
  IDarrive = SArrive;
  ACharge_Utile = M;
}

Arc::Arc(string etiq, int id, int SDepart, int SArrive){
  etiquette = etiq;
  ID=id;
  IDdepart = SDepart;
  IDarrive = SArrive;
}

Arc::Arc(int id, int SDepart, int SArrive){
  etiquette = to_string (id);
  ID=id;
  IDdepart = SDepart;
  IDarrive = SArrive;
}

Arc::Arc(Arc &A){
  etiquette = A.getEtiq();
  ID = A.getID ();
  IDdepart = A.getIDDepart();
  IDarrive = A.getIDArrive();
  ACharge_Utile = A.getCU();
}

Arc::~Arc(){
  //delete this;
}


// OPERATEUR DE LA CLASSE ARC
bool Arc::operator==(Arc const &A) {
  if (etiquette == A.etiquette && ID==A.ID && IDdepart == A.IDdepart && IDarrive == A.IDarrive && ACharge_Utile == A.ACharge_Utile){
    return true;
  }
return false;
}

bool Arc::operator!=(Arc const &A){
  if (etiquette != A.etiquette || ID !=A.ID || IDdepart != A.IDdepart || IDarrive != A.IDarrive || ACharge_Utile != A.ACharge_Utile){
    return true;
  }
return false;
}

Arc Arc::operator=(Arc &A1){

  this->ID = A1.getID();
  this->etiquette = A1.getEtiq();
  this->IDdepart = A1.getIDDepart ();
  this->IDarrive = A1.getIDArrive ();
  this->ACharge_Utile = A1.getCU();


return *this;


}

#include "Arc.hh"
// GETTERS DE LA CLASSE ARC
int Arc::getID(){return this->ID;}
string Arc::getEtiq(){ return this->etiquette;}
int Arc::getIDDepart(){ return this->IDdepart;}
int Arc::getIDArrive(){return this->IDarrive;}
map <string,VectVal> Arc::getCU(){ return this->ACharge_Utile;}

// SETTER DE LA CLASSE ARC
void Arc::setID(int id){ this->ID = id;}
void Arc::setEtiq(string etiq){this->etiquette = etiq;}
void Arc::setIDDepart(int id){this->IDdepart = id;}
void Arc::setIDArrive(int id){this->IDarrive = id;}
void Arc::setCU(map <string, VectVal> CU){}



// OPERATEUR DE LA CLASSE ARC
bool Arc::operator==(Arc const& A1){return 1;}
bool Arc::operator!=(Arc const& A1){return 1;}
//Arc Arc::operator=(Arc const& A1){ Arc res; return res; }

// METHODE LA CLASSE ARC

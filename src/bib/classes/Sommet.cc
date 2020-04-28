#include "Sommet.hh"
#include <iostream>

using namespace std;

Sommet::Sommet(int posx, int posy, string etiq, int id, map <string, VectVal> v){
  this->x = posx;
  this->y = posy;
  this->ID = id;
  this->etiquette = etiq;
  this->SCharge_utile = v;
}

Sommet::Sommet(int posx, int posy, string etiq, int id){
  this->x = posx;
  this->y = posy;
  this->ID = id;
  this->etiquette = etiq;

  map<string, VectVal> v;
  this->SCharge_utile = v;
}

Sommet::Sommet(string etiq, int id){
  this->ID = id;
  this->etiquette = etiq;

  this->x = 0;
  this->y = 0;
  map<string, VectVal> v;
  this->SCharge_utile = v;
}

Sommet::Sommet(int id){
  this->ID = id;

  this->etiquette = to_string(id);
  this->x = 0;
  this->y = 0;
  map<string, VectVal> v;
  this->SCharge_utile = v;
}

Sommet::Sommet(Sommet &S){
  this->x = S.getPosX();
  this->y = S.getPosY();
  this->ID = S.getID();
  this->etiquette = S.getEtiq();
  this->SCharge_utile = S.getCU();
}

Sommet::~Sommet(){
  //delete(this);
}

int Sommet::getPosX(){
  return this->x;
}

int Sommet::getPosY(){
  return this->y;
}

int Sommet::getID(){
  return this->ID;
}

string Sommet::getEtiq(){
  return this->etiquette;
}

map <string, VectVal> Sommet::getCU(){
  return this->SCharge_utile;
}

void Sommet::setPosX(int x){
  this->x = x;
}

void Sommet::setPosY(int y){
  this->y = y;
}

void Sommet::setID(int id){
  this->ID = id;
}

void Sommet::setEtiq(string etiq){
  this->etiquette = etiq;
}

void Sommet::setCU(map <string, VectVal> S_CU){
  this->SCharge_utile = S_CU;
}

bool Sommet::operator==(Sommet & S1){
  return (this->x == S1.getPosX())&&(this->y == S1.getPosY())&&(this->ID == S1.getID())&&(this->etiquette == S1.getEtiq())&&(this->SCharge_utile == S1.getCU());
}
bool Sommet::operator!=(Sommet & S1){
  return (this->x != S1.getPosX())||(this->y != S1.getPosY())||(this->ID != S1.getID())||(this->etiquette != S1.getEtiq())||(this->SCharge_utile != S1.getCU());

}
void Sommet::operator=(Sommet const& S1){
  Sommet S(S1.x, S1.y, S1.etiquette, S1.ID, S1.SCharge_utile);
  // S.setVecArc(v);
  this->x = S1.x;
  this->y = S1.y;
  this->ID = S1.ID;
  this->etiquette = S1.etiquette;
  this->vecArc = S1.vecArc;
  this->SCharge_utile = S1.SCharge_utile;
  //return S;
}

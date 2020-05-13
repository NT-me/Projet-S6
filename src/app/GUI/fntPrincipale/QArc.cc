#include <typeinfo>
#include "QArc.hh"

Qarc::Qarc (Arc A){
  this->id = A.getID();
  setData(0,"Arc");

// Pour trouver les positions des sommets il faudrait qu'on puisse accéder à la scene
// chose impossible car le QArc est créée AVANT d'être ajouté à la scene
// Ce qui signifie que le constructeur est lancé AVANT d'être lié à une scene.
// Trois façons de régler le soucis :
// - On laisse ainsi on peut utiliser les setters et je pense que c'est jouable
// - On change la signature du constructeur et on lui ajoute la scene en paramètre
// - On change le constructeur et on lui donne direct les positions.
// Je préfère la première comme ça on change pas nos signature.

  if(scene() != nullptr){
    QList<QGraphicsItem*> listS = scene()->items();
    for(int i=0; i< listS.size(); ++i){
      QSommet* QS = qgraphicsitem_cast<QSommet*>(listS[i]);
      if(QS->data(0) == "Sommet"){
        if(A.getIDDepart() == QS->getID()){
          this->posxA = QS->getPosX();
          this->posyA = QS->getPosY();
        }
        else if(A.getIDArrive() == QS->getID()){
          this->posxB = QS->getPosX();
          this->posyB = QS->getPosY();
        }
      }
    }
  }
  else{
    this->posxA = 0;
    this->posyA = 0;
    this->posxB = 0;
    this->posyB = 0;
  }
}

Qarc::Qarc(Qarc const &A){
  this->id = A.id;
  this->posxA = A.posxA;
  this->posyA = A.posyA;
  this->posxB = A.posxB;
  this->posyB = A.posyB;
}

Qarc::~Qarc(){

}

int Qarc::getID() const{return this->id;}
int Qarc::getPosXA() const{return this->posxA;}
int Qarc::getPosYA() const{return this->posyA;}
int Qarc::getPosXB() const{return this->posxB;}
int Qarc::getPosYB() const{return this->posyB;}

void Qarc::setID(int id){this->id = id;}
void Qarc::setPosXA(int x){this->posxA = x;}
void Qarc::setPosYA(int y){this->posyA = y;}
void Qarc::setPosXB(int x){this->posxB = x;}
void Qarc::setPosYB(int y){this->posyB = y;}

void Qarc::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event){}
QRectF Qarc::boundingRect() const{}
void Qarc::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){}

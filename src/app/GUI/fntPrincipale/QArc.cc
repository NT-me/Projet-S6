#include <typeinfo>
#include "QArc.hh"

QArc::QArc (Arc A){
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

QArc::QArc(QArc const &A){
  this->id = A.id;
  this->posxA = A.posxA;
  this->posyA = A.posyA;
  this->posxB = A.posxB;
  this->posyB = A.posyB;
}

QArc::~QArc(){

}

int QArc::getID() const{return this->id;}
int QArc::getPosXA() const{return this->posxA;}
int QArc::getPosYA() const{return this->posyA;}
int QArc::getPosXB() const{return this->posxB;}
int QArc::getPosYB() const{return this->posyB;}

void QArc::setID(int id){this->id = id;}
void QArc::setPosXA(int x){ prepareGeometryChange() ;this->posxA = x;}
void QArc::setPosYA(int y){ prepareGeometryChange() ;this->posyA = y;}
void QArc::setPosXB(int x){ prepareGeometryChange() ;this->posxB = x;}
void QArc::setPosYB(int y){ prepareGeometryChange() ;this->posyB = y;}

void QArc::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event){}
QRectF QArc::boundingRect() const{
  // QLineF l(posxA, posyA, posxB, posyB);
  // QGraphicsLineItem line(l);
  // return line.boundingRect();
  qreal sin =(posyB-posyA)/qSqrt( qPow(posxB-posxA,2) + qPow(posxB-posxA,2));
  qreal cos =(posxB-posxA)/qSqrt( qPow(posxB-posxA,2) + qPow(posxB-posxA,2));
  qreal radius = TAILLE_RAYON;
  qreal rx = 0;
  qreal ry = 0;

  if (qFabs(posyB-posyA) < 10 ) ry = 10;
  if (qFabs(posxB-posxA) < 10 ) rx = 10;

  return mapRectFromScene(QRectF(posxA+cos*radius-(rx/2), posyA+sin*radius-(ry/2), posxB-posxA-2*cos*radius+rx, posyB-posyA-2*sin*radius+ry));
}
void QArc::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){}

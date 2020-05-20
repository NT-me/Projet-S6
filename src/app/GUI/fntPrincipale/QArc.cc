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
/*
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
  */
  this->posxA = 0;
  this->posyA = 0;
  this->posxB = 0;
  this->posyB = 0;
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

  return shape().boundingRect();
  //return mapRectFromScene(QRectF(posxA+cos*radius-(rx/2), posyA+sin*radius-(ry/2), posxB-posxA-2*cos*radius+rx, posyB-posyA-2*sin*radius+ry).normalized());
}

QPainterPath QArc::shape() const{

  qreal sin =(posyB-posyA)/qSqrt( qPow(posxB-posxA,2) + qPow(posxB-posxA,2));
  qreal cos =(posxB-posxA)/qSqrt( qPow(posxB-posxA,2) + qPow(posxB-posxA,2));
  qreal radius = TAILLE_RAYON+10;

  if (qFabs(posxB-posxA) < 10 ){
    sin = (posyB-posyA)/qFabs(posyB-posyA);
    cos = 0;
  }
  QPointF pA = mapFromScene(posxA+cos*radius,posyA+sin*radius);
  QPointF pB = mapFromScene(posxB-cos*radius,posyB-sin*radius);
  // QPainterPath path;
  // // QLineF line(pA.x(), pA.y(),pB.x(),pB.y());
  // qreal ep = 20;
  // qreal theta = qFabs(qRadiansToDegrees(qAsin(sin)));
  // qreal rx = 0, ry = 0;
  // qDebug()<<"angle "<<theta;
  // if()
  // QPointF pA1(pA.x() -rx, pA.y()-ry);
  // QPointF pA2(pA.x() +rx, pA.y()+ry);
  // QPointF pB1(pB.x() -rx, pB.y()-ry);
  // QPointF pB2(pB.x() +rx, pB.y()+ry);
  // QPolygonF polygon;
  // polygon <<pA1<<pB1<<pB2<<pA2;
  // path.addPolygon(polygon);
  QGraphicsLineItem line (pA.x(),pA.y(),pB.x(),pB.y());
  return line.shape();
  // QPainterPath path(QPointF(posxA+cos*radius-(rx/2), posyA+sin*radius-(ry/2)));
  // path.lineTo(QPointF(posyA+sin*radius-(ry/2)));
  // path.lineTo(QPointF(posxB+cos*radius-(rx/2), posyB+sin*radius-(ry/2)));
  //return mapRectFromScene(QRectF(posxA+cos*radius-(rx/2), posyA+sin*radius-(ry/2), posxB-posxA-2*cos*radius+rx, posyB-posyA-2*sin*radius+ry).normalized());

  // return line.shape();
  // return path;
}

void QArc::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
  // QRectF rect = boundingRect();
  QPen greenPen(Qt::green, 3 );
  // painter->setPen(greenPen);
  // QPainterPath sha = shape();
  // painter->drawPath(sha);

  QPen blackPen(Qt::black, 3 );
  painter->setPen(blackPen);

  prepareGeometryChange();
  QPoint firstp,secondp;
  QPointF pA = mapFromScene(posxA,posyA);
  QPointF pB = mapFromScene(posxB,posyB);
  QBrush redBrush(Qt::red,Qt::SolidPattern);

  firstp.setX(pA.x()); firstp.setY(pA.y());
  secondp.setX(pB.x()); secondp.setY(pB.y());

  // QRectF tete(QPointF(secondp.x()-20,secondp.y()-20),QPointF(secondp.x()-10,secondp.y()-10));
  // painter->setBrush(redBrush);
  // painter->drawRect(tete);
  //
  double a,b,d,e,f,x1,x2,y1,y2;
  QPointF arrow,pI1,pI2,pC;
  if(posxB-posxA != 0){
    a = double(posyB - posyA)/double(posxB - posxA);
    b = posyA - a*posxA;
    d = 1+a*a;
    e = -2*posxB+2*a*b-2*a*posyB;
    f = posxB*posxB+b*b+-2*b*posyB+posyB*posyB-(TAILLE_RAYON+5)*(TAILLE_RAYON+5);
    x1 = (-e + qSqrt(e*e-4*d*f))/(2*d);
    x2 = (-e - qSqrt(e*e-4*d*f))/(2*d);
    y1 = a*x1+b;
    y2 = a*x2+b;
    pI1 = mapFromScene(x1,y1);
    pI2 = mapFromScene(x2,y2);
    if(QLineF(pI1,pA).length()<QLineF(pI2,pA).length()) arrow = pI1;
    else arrow = pI2;


    // qDebug()<<a<<b<<d<<e<<f<<x1<<x2;
    // qDebug()<<posxB<<posxA<<posyB<<posyA;

  }
  else{
    if (posyB-posyA > 0)arrow = mapFromScene(posxB,posyB + 5);
    else arrow = mapFromScene(posxB,posyB - 5);
  }

  // qDebug()<<"point intersection 1 "<<pI1;
  // qDebug()<<"point intersection 2 "<<pI2;


  QBrush whiteBrush(Qt::white,Qt::SolidPattern);
  QPen darkbluePen(Qt::darkBlue,3);
  //
  painter->drawLine(firstp,secondp);
  painter->setBrush(whiteBrush);
  // painter->drawEllipse(pA,TAILLE_RAYON,TAILLE_RAYON);
  // painter->drawEllipse(pB,TAILLE_RAYON,TAILLE_RAYON);
  painter->setBrush(redBrush);
  painter->drawEllipse(arrow,5,5);

}

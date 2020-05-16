#include "QZoneDeDessin.hh"

QZoneDeDessin::QZoneDeDessin(QWidget *parent) : QGraphicsView(parent), graphe_dessine("EMPTY_GRAPH"){
this->selected_list = {};
// this->setSceneRect(50, 50, 350, 350);
this->sc = new QGraphicsScene;
// this->sc->addItem(&itemParent);
QGraphicsView::setScene(sc);
}

vector<int> QZoneDeDessin::getSelected_list() const{return this->selected_list;}
Graphe QZoneDeDessin::getGraphe_dessine() const{return this->graphe_dessine;}
QGraphicsScene* QZoneDeDessin::getScene() const{return this->sc;}

void QZoneDeDessin::setSelected_list(vector<int> sl){this->selected_list = sl;}
void QZoneDeDessin::setGraphe_dessine(Graphe g){this->graphe_dessine = g;}

void QZoneDeDessin::setScene(QGraphicsScene * scene){
  this->sc = scene;
  QGraphicsView::setScene(scene);
}

void QZoneDeDessin::force_Atlas2(){}
pair<int,int> QZoneDeDessin::distance(QSommet a, QSommet b){
  pair<int,int> res;
  res.first = fabs(a.getPosX() - b.getPosX());
  res.second = fabs(a.getPosY() - b.getPosY());
  return res;

}

void QZoneDeDessin::addSelect_Sommet(int ID){
  vector<int> tmp;
  tmp = this->selected_list;
  tmp.push_back(ID);
  this->selected_list = tmp;
}

void QZoneDeDessin::deleteSelect_Sommet(int ID){
  vector<int> tmp, res;
  tmp = this->selected_list;
  for(int i = 0; i<tmp.size();++i){
    if(tmp[i] != ID){
      res.push_back(tmp[i]);
    }
  }
  this->selected_list = res;
}

void QZoneDeDessin::razSelected_list(){
  this->selected_list = {};
}

void QZoneDeDessin::afficher_Sommet(Sommet s){
  QSommet *QS = new QSommet(s);
  QPointF qpf = mapToScene(QPoint(QS->getPosX(),QS->getPosY()));
  QS->setPos(qpf.x(),qpf.y());
  QS->setVisible(1); // -
  this->sc->addItem(QS);

}

void QZoneDeDessin::afficher_arc(Arc a){
  int IDa, IDb, dblFlag = 0;
  IDa = a.getIDDepart();
  IDb = a.getIDArrive();

  QArc *QA = new QArc(a);

  QList<QGraphicsItem*> listS = items();
  for(int i=0; i< listS.size(); ++i){
    QSommet* QS = qgraphicsitem_cast<QSommet*>(listS[i]);
    if(QS->data(0) == "Sommet"){
      if(QS->getID() == IDa){ //On cherche le sommet de départ
        ++dblFlag;
        QA->setPosXA(QS->getPosX());
        QA->setPosYA(QS->getPosY());
      }
      else if (QS->getID() == IDb){ // On cherche le sommet d'arrivée
        ++dblFlag;
        QA->setPosXB(QS->getPosX());
        QA->setPosYB(QS->getPosY());
      }
    }
  }
  if (dblFlag != 2){
    qDebug() <<"--> SOMMETS NON TROUVES ID QARC :" <<QA->getID();
  }
  else{
    QPointF qpfA = mapToScene(QPoint(QA->getPosXA(),QA->getPosYA()));
    // QPointF qpfB = mapToScene(QPoint(QA->getPosXB(),QA->getPosYB()));
    QA->setPos(qpfA.x(), qpfA.y());
    QA->setVisible(1);
    this->sc->addItem(QA);
  }

}

void QZoneDeDessin::afficher_Graphe(Graphe G){

}

void QZoneDeDessin::mousePressEvent(QMouseEvent * e){}
void QZoneDeDessin::dessiner_sommet(int x, int y){}
void QZoneDeDessin::dessiner_arc(int xA, int yA, int xB, int yB){}

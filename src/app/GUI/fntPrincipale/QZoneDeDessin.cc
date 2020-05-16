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
  QS->setVisible(1); // -
  this->sc->addItem(QS);
  QS->setPos(QS->getPosX(),QS->getPosY());
}

void QZoneDeDessin::afficher_arc(Arc a){
  int IDa, IDb, dblFlag = 0;
  IDa = a.getIDDepart();
  IDb = a.getIDArrive();
  QPoint posA, posB;
  QPointF posRef;
  QArc *QA = new QArc(a);

  QList<QGraphicsItem*> listS = items();
  for(int i=0; i< listS.size(); ++i){
    QSommet* QS = qgraphicsitem_cast<QSommet*>(listS[i]);
    if(QS->data(0) == "Sommet"){
      if(QS->getID() == IDa){ //On cherche le sommet de départ
        ++dblFlag;
        posA.setX(QS->getPosX());
        posA.setY(QS->getPosY());
        posRef.setX(QS->x());
        posRef.setY(QS->y());
      }
      else if (QS->getID() == IDb){ // On cherche le sommet d'arrivée
        ++dblFlag;
        posB.setX(QS->getPosX());
        posB.setY(QS->getPosY());
      }
    }
  }
  if (dblFlag != 2){
    qDebug() <<"--> SOMMETS NON TROUVES ID QARC :" <<QA->getID();
  }
  else{
    this->sc->addItem(QA);
    QA->setPos(posRef);
    QA->setPosXA(posA.x());
    QA->setPosYA(posA.y());
    QA->setPosXB(posB.x());
    QA->setPosYB(posB.y());
    QA->setVisible(1);
  }

}

void QZoneDeDessin::afficher_Graphe(Graphe G){
  vector<Arc> La = G.getListe_Arcs();
  vector<Sommet> Ls = G.getListe_Sommets();

  for(int i =0; i<Ls.size(); ++i) afficher_Sommet(Ls[i]);

  for(int i =0; i<La.size(); ++i) afficher_arc(La[i]);
}

void QZoneDeDessin::mousePressEvent(QMouseEvent * e){}
void QZoneDeDessin::dessiner_sommet(int x, int y){}
void QZoneDeDessin::dessiner_arc(int xA, int yA, int xB, int yB){}

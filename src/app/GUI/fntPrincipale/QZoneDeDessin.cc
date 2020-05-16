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

void QZoneDeDessin::force_Atlas2(){
  int stable = 0;
  vector<QSommet> QS
  QList<QGraphicsItem*> listS = qzdd.items();
  for(int i=0; i< listS.size(); ++i){
    QS.push_back(listS[i]) = qgraphicsitem_cast<QSommet*>(listS[i]);
  }
  for(int i=0; i< listS.size(); ++i){
    if(QS[i]->data(0) != "Sommet"){
      QS.erase(QS.begin()+i);
      i--;
    }
  }
  while(stable == 0){
    stable = 1;
    for(int i = 0; i < QS.size(); i++){
      int ft = 0;
      vector<int> SommetCo;
      for(int k = 0; k < this.getGraphe_dessine().getListe_Sommets()[i].getVecArc().size(), k++){
        if(this.getGraphe_dessine().getListe_Sommets()[i].getVecArc()[k].getIDArrive() != i){
          SommetCo.push_back(this.getGraphe_dessine().getListe_Sommets()[i].getVecArc()[k].getIDArrive()); }

        if(this.getGraphe_dessine().getListe_Sommets()[i].getVecArc()[k].getIDDepart() != i){
          SommetCo.push_back(this.getGraphe_dessine().getListe_Sommets()[i].getVecArc()[k].getIDDepart()); }
      }
      for(int j = 0; j < QS.size(); j++){
        if(i != j){
          if((SommetCo.find(SommetCo.begin(),SommetCo.end(), j ) != SommetCo.end()) || j == SommetCo.at(SommetCo.end()) ){
            if(distanceForce(QS[i], QS[j]) > 0){// a changer des que possible
               ft = distanceForce(QS[i], QS[j]) - 10*(((this.getGraphe_dessine().getListe_Sommets()[i].Degrs_entrant_et_sortant()+1)*(this.getGraphe_dessine().getListe_Sommets()[j].Degrs_entrant_et_sortant()+1))/distanceForce(QS[i], QS[j])) ;
            }
            else if(distanceForce(QS[i], QS[j]) < 0){// a changer des que possible
               ft = 0-100*((this.getGraphe_dessine().getListe_Sommets()[i].Degrs_entrant_et_sortant()+1)*(this.getGraphe_dessine().getListe_Sommets()[j].Degrs_entrant_et_sortant()+1));

            }
            else ft = 1;
          }
          else {
            if(distanceForce(QS[i], QS[j]) > 0){// a changer des que possible
               ft = 0-10*(((this.getGraphe_dessine().getListe_Sommets()[i].Degrs_entrant_et_sortant()+1)*(this.getGraphe_dessine().getListe_Sommets()[j].Degrs_entrant_et_sortant()+1))/distanceForce(QS[i], QS[j])) ;
            }
            else if(distanceForce(QS[i], QS[j]) < 0){// a changer des que possible
               ft = 0-100*((this.getGraphe_dessine().getListe_Sommets()[i].Degrs_entrant_et_sortant()+1)*(this.getGraphe_dessine().getListe_Sommets()[j].Degrs_entrant_et_sortant()+1));

            }
            else ft = 1;
          }
        }
      }

    }
  }
}

int QZoneDeDessin::distanceForce(Sommet a, Sommet b){
  int res;
  res = sqrt(pow(b.getPosX() - a.getPosX() ,2)+pow(b.getPosY() - a.getPosY() ,2)) - a.getRayon() -b.getRayon();
  return res;

}

int QZoneDeDessin::distanceForce(QSommet a, QSommet b){
  int res;
  res = sqrt(pow(b.getPosX() - a.getPosX() ,2)+pow(b.getPosY() - a.getPosY() ,2)) - a.getRayon() -b.getRayon();
  return res;

}


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

}

void QZoneDeDessin::afficher_Graphe(Graphe G){

}

void QZoneDeDessin::mousePressEvent(QMouseEvent * e){}
void QZoneDeDessin::dessiner_sommet(int x, int y){}
void QZoneDeDessin::dessiner_arc(int xA, int yA, int xB, int yB){}

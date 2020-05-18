#include "QZoneDeDessin.hh"

QZoneDeDessin::QZoneDeDessin(QWidget *parent_) : QGraphicsView(parent_), graphe_dessine("EMPTY_GRAPH"){
this->selected_list = {};
// this->setSceneRect(50, 50, 350, 350);
this->sc = new QGraphicsScene;
// this->sc->addItem(&itemParent);
QGraphicsView::setScene(sc);


// test
setProperty("DBE", 4);

qDebug()<<parent()->parent();
}

vector<int> QZoneDeDessin::getSelected_list() const{return this->selected_list;}
Graphe QZoneDeDessin::getGraphe_dessine() const{return this->graphe_dessine;}
QGraphicsScene* QZoneDeDessin::getScene() const{return this->sc;}

void QZoneDeDessin::setSelected_list(vector<int> sl){this->selected_list = sl;}
void QZoneDeDessin::setGraphe_dessine(Graphe g){
  this->graphe_dessine = g;
  afficher_Graphe(g);
}

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
  int flag = 0;
  tmp = this->selected_list;
  for(int i = 0;i<tmp.size();++i){
    if(tmp[i] == ID){
      flag = 1;
    }
  }
  if (!flag){
    tmp.push_back(ID);
    this->selected_list = tmp;
  }
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
    qDebug()<<QA->sceneBoundingRect();
  }

}

void QZoneDeDessin::afficher_Graphe(Graphe G){
  vector<Arc> La = G.getListe_Arcs();
  vector<Sommet> Ls = G.getListe_Sommets();

  for(int i =0; i<Ls.size(); ++i) afficher_Sommet(Ls[i]);

  for(int i =0; i<La.size(); ++i) afficher_arc(La[i]);
}

void QZoneDeDessin::mousePressEvent(QMouseEvent * e){
  int dbe = property("DBE").toInt();

  if (itemAt(e->pos())->data(0) == "Sommet"){

  }

  if(dbe == 1){
    //select
    if (itemAt(e->pos())->data(0) == "Sommet"){
      QSommet* QS = qgraphicsitem_cast<QSommet*>(itemAt(e->pos()));
      if(QS->getSelect()){
        QS->setSelect(0);
        deleteSelect_Sommet(QS->getID());
      }
      else{
        addSelect_Sommet(QS->getID());
        QS->setSelect(1);
      }
      QS->update();
      qDebug()<<selected_list;
    }
    else{
      QList<QGraphicsItem*> listS = items();
      for(int i = 0;i<selected_list.size();++i){
        for(int i=0; i< listS.size(); ++i){
          QSommet* QS_ = qgraphicsitem_cast<QSommet*>(listS[i]);
          if(QS_->data(0) == "Sommet"){
            if(QS_->getSelect() != 0){
              QS_->setSelect(0);
              QS_->update();
            }
          }
        }
      }
      razSelected_list();
    }
  }
  else if(dbe == 2){
    //add sommet
    if (!(itemAt(e->pos())->data(0) == "Sommet" || itemAt(e->pos())->data(0) == "Arc")){
      dessiner_sommet(e->x(), e->y());
    }

  }
  else if(dbe == 3){
    // add arc

    if (!(itemAt(e->pos())->data(0) == "Sommet" || itemAt(e->pos())->data(0) == "Arc")){
      QList<QGraphicsItem*> listS = items();
      for(int i = 0;i<selected_list.size();++i){
        for(int i=0; i< listS.size(); ++i){
          QSommet* QS_ = qgraphicsitem_cast<QSommet*>(listS[i]);
          if(QS_->data(0) == "Sommet"){
            if(QS_->getSelect() != 0){
              QS_->setSelect(0);
              QS_->update();
            }
          }
        }
      }
      razSelected_list();
    }
    else if (itemAt(e->pos())->data(0) == "Sommet"){
      QSommet* QS = qgraphicsitem_cast<QSommet*>(itemAt(e->pos()));
      QS->setSelect(1);
      QS->update();
      addSelect_Sommet(QS->getID());
      if (selected_list.size()==2){
        QList<QGraphicsItem*> listS = items();
        for(int i = 0;i<selected_list.size();++i){
          for(int i=0; i< listS.size(); ++i){
            QSommet* QSb = qgraphicsitem_cast<QSommet*>(listS[i]);
            if(QSb->data(0) == "Sommet"){
              if(QSb->getID() == selected_list[0]){
                dessiner_arc(QSb->getPosX(), QSb->getPosY(), QS->getPosX(), QS->getPosY());
                razSelected_list();
                QS->setSelect(0);
                QSb->setSelect(0);
                QS->update();
                QSb->update();
              }
            }
          }
        }
      }
    }
  }
  else if(dbe == 4){
    //del sommet
    QSommet* QS = qgraphicsitem_cast<QSommet*>(itemAt(e->pos()));
    vector<int> arc_sor, arc_ent;
    vector<Arc> ListeA = graphe_dessine.getListe_Arcs();
    vector<Sommet> vS = graphe_dessine.getListe_Sommets();

    if (QS->data(0) == "Sommet"){
      this->sc->removeItem(QS); // On retire l'item sommet graphique

      for(int i = 0; i<vS.size();++i){ // On cherche les arcs sortants du sommet
        if(QS->getID() == vS[i].getID()){
          arc_sor = vS[i].getVecArc();
        }
      }
      qDebug()<<"sortant :"<<arc_sor;

      for(int i =0;i<ListeA.size();++i){ //On trouve les IDs des arcs entrants
        if(QS->getID() == ListeA[i].getIDArrive()){
          arc_ent.push_back(ListeA[i].getID());
        }
      }
      qDebug()<<"Entrant :"<<arc_ent;

      QList<QGraphicsItem*> listS = items();
      for(int i=0; i< listS.size(); ++i){
        if (listS[i]->data(0) == "Arc"){
          QArc* QA = qgraphicsitem_cast<QArc*>(listS[i]);
          for(int j= 0; j<arc_sor.size();++j){
            if(QA->getID() == arc_sor[j]){ // On supprime les arcs sortants graphiquement
              this->sc->removeItem(QA);
            }
          }
          for(int k=0;k<arc_ent.size();++k){ // On supprime les arcs entrants graphiquement
            if(QA->getID() == arc_ent[k]){
              this->sc->removeItem(QA);
            }
          }
        }
      }

      for(int j = 0; j<arc_sor.size();++j){ // On supprime les arcs sortants du graphe
        graphe_dessine.supprimer_Arc(arc_sor[j]);
      }

      for(int j = 0; j<arc_ent.size();++j){ // On supprime les arcs sortants du graphe
        graphe_dessine.supprimer_Arc(arc_ent[j]);
      }

      graphe_dessine.supprimer_Sommet(QS->getID()); // On supprime le sommet du graphe
    }
  }
  else if(dbe == 5){
    //del arc
    QArc* QA = qgraphicsitem_cast<QArc*>(itemAt(e->pos()));
    if(QA->data(0) == "Arc"){
      this->sc->removeItem(QA);
      graphe_dessine.supprimer_Arc(QA->getID());
    }
  }


}
void QZoneDeDessin::dessiner_sommet(int x, int y){
  Graphe Gtmp = graphe_dessine;
  int Sid;
  Sid = Gtmp.ajout_Sommet(Gtmp.getListe_Sommets().size(), x, y);
  afficher_Sommet(Gtmp.getListe_Sommets()[Sid]);
  graphe_dessine = Gtmp;

}
void QZoneDeDessin::dessiner_arc(int xA, int yA, int xB, int yB){
  Graphe Gtmp = graphe_dessine;
  int Aid;
  QSommet* qsA = qgraphicsitem_cast<QSommet*>(itemAt(mapFromScene(QPointF (xA,yA))));
  QSommet* qsB = qgraphicsitem_cast<QSommet*>(itemAt(mapFromScene(QPointF (xB,yB))));
  qDebug()<<qsA->getID();
  qDebug()<<qsB->getID();
  Aid = Gtmp.ajout_Arc(qsA->getID(), qsB->getID());
  afficher_arc(Gtmp.getListe_Arcs()[Aid]);
  graphe_dessine = Gtmp;
}

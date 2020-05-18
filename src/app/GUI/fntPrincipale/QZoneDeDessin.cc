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
  vector<QSommet> QS;
  vector<int> SommetCo; // id des sommet connecté au sommet i
  Matrice MG = Matrice(this.graphe_dessine);

  // recuperation des QSommet
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
  // debut de la fonction
  while(stable == 0){
    stable = 1; // on met stable a 0 si un sommet bouge (pas fait)
    for(int i = 0; i < QS.size(); i++){ // on parcours tout les sommet
      int ft = 0; // ensemble des force a appliquer au vecteur de direction
      // on ajoute les sommet connecter au sommet i dans SommetCo
      for(int k = 0; k < this.getGraphe_dessine().getListe_Sommets()[QS[i].getID()].getVecArc().size(), k++){
        if(this.getGraphe_dessine().getListe_Sommets()[QS[i].getID()].getVecArc()[k].getIDArrive() != i){
          SommetCo.push_back(this.getGraphe_dessine().getListe_Sommets()[QS[i].getID()].getVecArc()[k].getIDArrive()); }

        if(this.getGraphe_dessine().getListe_Sommets()[QS[i].getID()].getVecArc()[k].getIDDepart() != i){
          SommetCo.push_back(this.getGraphe_dessine().getListe_Sommets()[QS[i].getID()].getVecArc()[k].getIDDepart()); }
      }
      // on parcour les sommet autre que i
      for(int j = 0; j < QS.size(); j++){
        if(i != j){
          // on verifie si le sommet j est connecter ou non au sommet i
          if((SommetCo.find(SommetCo.begin(),SommetCo.end(), j ) != SommetCo.end()) || j == SommetCo.at(SommetCo.end()) ){
            // si j est connecter alors la force d'attraction est calculé
            if(distanceForce(QS[i], QS[j]) > 0){ // si ils ne sont pas superposés ils s'attire et ce repousse
               ft = distanceForce(QS[i], QS[j]) - 1*((Degrs_entrant_et_sortant(M,this.getGraphe_dessine().getListe_Sommets()[QS[i].getID()])+1)*(Degrs_entrant_et_sortant(M,this.getGraphe_dessine().getListe_Sommets()[QS[i].getID()])+1)/distanceForce(QS[i], QS[j])) ;
            }
            else if(distanceForce(QS[i], QS[j]) < 0){ // si ils sont superposés ils se repoussent
               ft = 0-100*((Degrs_entrant_et_sortant(M,this.getGraphe_dessine().getListe_Sommets()[QS[i].getID()]+1)*(Degrs_entrant_et_sortant(M,this.getGraphe_dessine().getListe_Sommets()[QS[i].getID()])+1);

            }
            else ft = 1; // si ils sont placé cote a cote on ne les deplace pas
          }
          else { // si i et j ne son pas connecter il n'y a pas d'attraction
            if(distanceForce(QS[i], QS[j]) > 0){ //force de repulsion faible si ils ne sont pas superposés
               ft = 0-1*(((Degrs_entrant_et_sortant(M,this.getGraphe_dessine().getListe_Sommets()[QS[i].getID()])+1)*(Degrs_entrant_et_sortant(M,this.getGraphe_dessine().getListe_Sommets()[QS[i].getID()])+1))/distanceForce(QS[i], QS[j])) ;
            }
            else if(distanceForce(QS[i], QS[j]) < 0){ //force de repulsion forte si ils sont superposés
               ft = 0-100*((Degrs_entrant_et_sortant(M,this.getGraphe_dessine().getListe_Sommets()[QS[i].getID()])+1)*(Degrs_entrant_et_sortant(M,this.getGraphe_dessine().getListe_Sommets()[QS[i].getID()])+1));

            }
            else ft = 1; // cote a cote et ne bouge pas
          }
        }
        // si ils sont l'un sur l'autre le vecteur de direction est aléatoire
        if ((QS[i].getPosX() == QS[j].getPosX()) && (QS[i].getPosY() == QS[j].getPosY())){
          this.getGraphe_dessine().getListe_Sommets()[QS[i].getID()].setPosX(QS[i].getPosX() + ft*pow(-1,rand()%2));
          this.getGraphe_dessine().getListe_Sommets()[QS[i].getID()].setPosY(QS[i].getPosY() + ft*pow(-1,rand()%2));
        }
        else { // sinon on calcule le vecteur de direction
          this.getGraphe_dessine().getListe_Sommets()[QS[i].getID()].setPosX(QS[i].getPosX() + ft*(QS[j].getPosX() - QS[i].getPosX()));
          this.getGraphe_dessine().getListe_Sommets()[QS[i].getID()].setPosY(QS[i].getPosY() + ft*(QS[j].getPosY() - QS[i].getPosY()));
        }
      }
    SommetCo.clear(); // on vide le vecteur de sommet.
    }
  }

}

int QZoneDeDessin::distanceForce(QSommet a, QSommet b){ // calcul la distance en prenant en compte le rayon d'un sommet
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

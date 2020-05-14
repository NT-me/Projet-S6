#include "QZoneDeDessin.hh"

QZoneDeDessin::QZoneDeDessin(QWidget *parent) : QGraphicsView(parent), graphe_dessine("EMPTY_GRAPH"), selected_list({})
{

}

vector<int> QZoneDeDessin::getSelected_list() const{}
Graphe QZoneDeDessin::getGraphe_dessine() const{}
QGraphicsScene* QZoneDeDessin::getScene() const{}

void QZoneDeDessin::setSelected_list(vector<int> sl){}
void QZoneDeDessin::setGraphe_dessine(Graphe g){}
void QZoneDeDessin::setScene(QGraphicsScene * scene){}

void QZoneDeDessin::force_Atlas2(){}
pair<int,int> QZoneDeDessin::distance(QSommet a, QSommet b){}
void QZoneDeDessin::addSelect_Sommet(int ID){}
void QZoneDeDessin::deleteSelect_Sommet(int ID){}
void QZoneDeDessin::razSelected_list(){}
void QZoneDeDessin::afficher_Graphe(Graphe G){}
void QZoneDeDessin::afficher_Sommet(Sommet id){}
void QZoneDeDessin::afficher_arc(Arc id){}

void QZoneDeDessin::mousePressEvent(QMouseEvent * e){}
void QZoneDeDessin::dessiner_sommet(int x, int y){}
void QZoneDeDessin::dessiner_arc(int xA, int yA, int xB, int yB){}

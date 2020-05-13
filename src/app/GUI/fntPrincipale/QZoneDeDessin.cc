#include "QZoneDeDessin.hh"

explicit QZoneDeDessin::QZoneDeDessin(QWidget *parent = 0){}

vector<int> QZoneDeDessin::getSelected_list(){}
Graphe QZoneDeDessin::getGraphe_dessine(){}

void QZoneDeDessin::setSelected_list(vector<int> sl){}
void QZoneDeDessin::setGraphe_dessine(Graphe g){}

void QZoneDeDessin::force_Atlas2(){}
pair<int,int> QZoneDeDessin::distance(QSommet a, QSommet b){}
void QZoneDeDessin::addSelect_Sommet(int ID){}
void QZoneDeDessin::deleteSelect_Sommet(int ID){}
void QZoneDeDessin::razSelected_list(){}
void QZoneDeDessin::afficher_Graphe(Graphe G){}
void QZoneDeDessin::afficher_Sommet(int id){}
void QZoneDeDessin::afficher_arc(int id){}

void QZoneDeDessin::mousePressEvent(QMouseEvent * e){}
void QZoneDeDessin::dessiner_sommet(int x, int y){}
void QZoneDeDessin::dessiner_arc(int xA, int yA, int xB, int yB){}

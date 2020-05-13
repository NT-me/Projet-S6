#ifndef H_QZDD
#define H_QZDD

#include <QGraphicsView>
#include <QGraphicsScene>
#include "QSommet.hh"
#include "QArc.hh"

class QZoneDeDessin : public QGraphicsView{
    Q_OBJECT

private:
     QGraphicsScene *scene;
     vector<int> selected_list;
     Graphe graphe_dessine;

public :
    explicit QZoneDeDessin(QWidget *parent = 0);

    vector<int> getSelected_list();
    Graphe getGraphe_dessine();

    void setSelected_list(vector<int> sl);
    void setGraphe_dessine(Graphe g);

    void force_Atlas2();
    pair<int,int> distance(QSommet a, QSommet b);
    void addSelect_Sommet(int ID);
    void deleteSelect_Sommet(int ID);
    void razSelected_list();
    void afficher_Graphe(Graphe G);
    void afficher_Sommet(int id);
    void afficher_arc(int id);

public slots :
    void mousePressEvent(QMouseEvent * e);
    void dessiner_sommet(int x, int y);
    void dessiner_arc(int xA, int yA, int xB, int yB);

};

#endif

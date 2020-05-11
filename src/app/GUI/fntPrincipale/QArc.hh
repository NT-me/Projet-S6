#ifndef H_QARC
#define H_QARC

#include <QGraphicsItem>
#include "../../../bib/bib.hh"
class Qarc : public QGraphicsItem{

private:
    int id;
    int posxA;
    int posyA;
    int posxB;
    int posyB;

public:
    Qarc (Arc A);
    ~Qarc();
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    QRectF boundingRect();

};

#endif

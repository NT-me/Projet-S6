#ifndef H_QSOMMET
#define H_QSOMMET

#include <QGraphicsItem>
#include "../../../bib/bib.hh"

class QSommet : public QGraphicsItem{

private:
    int id;
    int posx;
    int posy;
    int rayon;
    QColor coul;
    bool select;

public:
    QSommet(Sommet S);
    ~QSommet();
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    QRectF boundingRect();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setSelect(bool B);

};

#endif

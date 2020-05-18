#ifndef H_QARC
#define H_QARC

#include <QGraphicsItem>
#include <QDebug>
#include <QList>
#include <QGraphicsLineItem>
#include <QtMath>
#include "QSommet.hh"
#include "../../../bib/bib.hh"

class QArc : public QGraphicsItem{

private:
    int id;
    int posxA;
    int posyA;
    int posxB;
    int posyB;

public:
    QArc (Arc A);
    QArc (QArc const &A);
    ~QArc();

    int getID() const;
    int getPosXA() const;
    int getPosYA() const;
    int getPosXB() const;
    int getPosYB() const;

    void setID(int id);
    void setPosXA(int x);
    void setPosYA(int y);
    void setPosXB(int x);
    void setPosYB(int y);

    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif

#ifndef H_QSOMMET
#define H_QSOMMET

#include <QGraphicsItem>
#include <map>
#include <vector>
#include <QPen>
#include <QPainter>
#include "../../../bib/bib.hh"

//Taille du rayon des QSommets en pixel
#define TAILLE_RAYON 10

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
    QSommet(QSommet const &S);
    ~QSommet();

    int getID() const;
    int getPosX() const;
    int getPosY() const;
    int getRayon() const;
    QColor getCoul() const;
    bool getSelect() const;

    void setID(int id);
    void setPosX(int x);
    void setPosY(int y);
    void setRayon(int r);
    void setCoul(QColor color);
    void setSelect(bool select);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif

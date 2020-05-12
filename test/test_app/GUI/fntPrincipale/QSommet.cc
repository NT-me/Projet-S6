#include <QtTest/QtTest>
#include "../../../../src/app/GUI/fntPrincipale/QSommet.hh"
#include "../../../../src/app/GUI/fntPrincipale/QSommet.cc"

class TestQSommet: public QObject
{
    Q_OBJECT
private slots:
  void testConstructQSomment(){
    // On fait la map INUTILE du sommet
    VectVal vv;
    vv.type = 0;
    vv.valeur_entiere = 12;

    map <string, VectVal> cu;
    cu.insert (pair <string, VectVal> ("plus_tot", vv));
    cu.insert (pair <string, VectVal> ("plus_tard", vv));

    // On construit le Sommet
    Sommet S0(23, 32, "sommet0", 0, cu);

    // On construit le QSommet
    QSommet QS0(S0);

    QVERIFY(QS0.getID() == S0.getID());
    QVERIFY(QS0.getPosX() == S0.getPosX());
    QVERIFY(QS0.getPosY() == S0.getPosY());
    QVERIFY(QS0.getRayon() == TAILLE_RAYON);
    QVERIFY(QS0.getSelect() == 0);
  }


  // void TestGetters();
  // void TestSetters();
  //
  // void TestmouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
  // void TestboundingRect();
  // void Testpaint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#ifndef QTT_MAIN
#define QTT_MAIN
QTEST_MAIN(TestQSommet);
#endif
#include "QSommet.moc"

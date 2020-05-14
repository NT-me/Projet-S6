#include <QtTest/QtTest>
#include "../../../../src/app/GUI/fntPrincipale/QZoneDeDessin.hh"

#include "../../../../src/app/GUI/fntPrincipale/QZoneDeDessin.cc"
#include "../../../../src/app/GUI/fntPrincipale/QArc.hh"
#include "../../../../src/app/GUI/fntPrincipale/QArc.cc"
#include "../../../../src/app/GUI/fntPrincipale/QSommet.hh"
#include "../../../../src/app/GUI/fntPrincipale/QSommet.cc"
#include "../../../../src/bib/classes/GrapheMatrice.cc"
#include "../../../../src/bib/classes/Sommet.cc"
#include "../../../../src/bib/classes/Arc.cc"

class TestQZoneDeDessin: public QObject
{
    Q_OBJECT
private slots:
  void TestConstructQZoneDeDessin(){
    // Pas grand chose à tester jpense
  }

  void TestSettersGetters(){
    QZoneDeDessin qzdd;
    Graphe G("Graphe");
    qzdd.setSelected_list({0,1});
    qzdd.setGraphe_dessine(G);

    vector<int> v {0,1};

    QCOMPARE(qzdd.getSelected_list(), v);
    QCOMPARE(qzdd.getGraphe_dessine(), G);

  }

  void Testforce_Atlas2(){
    //
  }
  void Testdistance(){
    QZoneDeDessin qzdd;
    Sommet S0(0,0,"S0",0), S1(1,1,"S1",1);
    QSommet QS0(S0), QS1(S0);
    pair<int,int> a (1,1);
    pair<int,int> b;
    b = qzdd.distance(QS0, QS1);
    QCOMPARE(b, a);
  }

  void TestaddSelect_Sommet(){
    QZoneDeDessin qzdd;
    vector<int> v {0,1}, v1{0,1,2};
    qzdd.setSelected_list({0,1});

    qzdd.addSelect_Sommet(2);

    QCOMPARE(qzdd.getSelected_list(), v1);
  }
  void TestdeleteSelect_Sommet(){
    QZoneDeDessin qzdd;
    vector<int> v {0,1}, v1{0};
    qzdd.setSelected_list({0,1});

    qzdd.deleteSelect_Sommet(1);
    QCOMPARE(qzdd.getSelected_list(), v1);
  }
  void TestrazSelected_list(){
    QZoneDeDessin qzdd;
    vector<int> v {0,1}, v1{};
    qzdd.setSelected_list({0,1});

    qzdd.razSelected_list();
    QCOMPARE(qzdd.getSelected_list(), v1);
  }
  void Testafficher_Sommet(){
    QZoneDeDessin qzdd;
    QGraphicsScene * sc;
    qzdd.setScene(sc);

    Sommet S(1,1,"Sommet",0);
    QSommet QS_r (S);
    qzdd.afficher_Sommet(S);
    QSommet* QS = qgraphicsitem_cast<QSommet*>(qzdd.itemAt(1,1));

    QVERIFY(QS->data(0) == "Sommet");
    QCOMPARE(QS->getID(), QS_r.getID());
    QCOMPARE(QS->getPosX(), QS_r.getPosX());
    QCOMPARE(QS->getPosY(), QS_r.getPosY());
    QCOMPARE(QS->getRayon(), QS_r.getRayon());
    QCOMPARE(QS->getCoul(), QS_r.getCoul());
    QCOMPARE(QS->getSelect(), QS_r.getSelect());
  }
  void Testafficher_arc(){
    QZoneDeDessin qzdd;
    Sommet S0(0,0,"Sommet",0);
    Sommet S1(2,2,"Sommet",1);
    QSommet QS0 (S0), QS1 (S1);
    QGraphicsScene * sc;
    sc->addItem(&QS0);
    sc->addItem(&QS1);
    qzdd.setScene(sc);

    Arc A("5", 5, 0, 1);
    Qarc QA_r(A);
    qzdd.afficher_arc(A);
    Qarc* QA = qgraphicsitem_cast<Qarc*>(qzdd.itemAt(1,1));

    QVERIFY(QA->data(0) == "Arc");
    QCOMPARE(QA->getPosXA(), QA_r.getPosXA());
    QCOMPARE(QA->getPosYA(), QA_r.getPosYA());
    QCOMPARE(QA->getPosXB(), QA_r.getPosXB());
    QCOMPARE(QA->getPosYA(), QA_r.getPosYB());

  }
  void Testafficher_Graphe(){
    QZoneDeDessin qzdd;
    Sommet S0(0,0,"Sommet",0);
    Sommet S1(2,2,"Sommet",1);

    QGraphicsScene * sc;
    qzdd.setScene(sc);

    QSommet QS_r(S0);
    QSommet QS0_r(S1);

    qzdd.afficher_Sommet(S0);
    qzdd.afficher_Sommet(S1);

    Arc A("5", 5, 0, 1);
    Qarc QA_r(A);
    qzdd.afficher_arc(A);
    Qarc* QA = qgraphicsitem_cast<Qarc*>(qzdd.itemAt(1,1));

    QVERIFY(QA->data(0) == "Arc");
    QCOMPARE(QA->getPosXA(), QA_r.getPosXA());
    QCOMPARE(QA->getPosYA(), QA_r.getPosYA());
    QCOMPARE(QA->getPosXB(), QA_r.getPosXB());
    QCOMPARE(QA->getPosYA(), QA_r.getPosYB());

    QSommet* QS = qgraphicsitem_cast<QSommet*>(qzdd.itemAt(0,0));
    QVERIFY(QS->data(0) == "Sommet");
    QCOMPARE(QS->getID(), QS_r.getID());
    QCOMPARE(QS->getPosX(), QS_r.getPosX());
    QCOMPARE(QS->getPosY(), QS_r.getPosY());
    QCOMPARE(QS->getRayon(), QS_r.getRayon());
    QCOMPARE(QS->getCoul(), QS_r.getCoul());
    QCOMPARE(QS->getSelect(), QS_r.getSelect());

    QSommet* QS0 = qgraphicsitem_cast<QSommet*>(qzdd.itemAt(2,2));
    QVERIFY(QS0->data(0) == "Sommet");
    QCOMPARE(QS0->getID(), QS0_r.getID());
    QCOMPARE(QS0->getPosX(), QS0_r.getPosX());
    QCOMPARE(QS0->getPosY(), QS0_r.getPosY());
    QCOMPARE(QS0->getRayon(), QS0_r.getRayon());
    QCOMPARE(QS0->getCoul(), QS0_r.getCoul());
    QCOMPARE(QS0->getSelect(), QS0_r.getSelect());
  }

  void testMousePressEvent(){

  }

  void testDessiner_sommet(){

  }

  void testDessiner_arc(){

  }
};

#ifndef QTT_MAIN
#define QTT_MAIN

QTEST_MAIN(TestQZoneDeDessin);
#endif

#include "QZoneDeDessin.moc"

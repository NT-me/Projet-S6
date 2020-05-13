#include <QtTest/QtTest>
#include "../../../../src/app/GUI/fntPrincipale/QZoneDeDessin.hh"

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
  void Testafficher_Graphe(){}
  void Testafficher_Sommet(){}
  void Testafficher_arc(){}
};

#ifndef QTT_MAIN
#define QTT_MAIN

QTEST_MAIN(TestQZoneDeDessin);
#endif

#include "QZoneDeDessin.moc"

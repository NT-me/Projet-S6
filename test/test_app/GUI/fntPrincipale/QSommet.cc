#include <QtTest/QtTest>
#include "../../../../src/app/GUI/fntPrincipale/QSommet.hh"

class TestQSommet: public QObject
{
    Q_OBJECT
private slots:
};

#ifndef QTT_MAIN
#define QTT_MAIN
QTEST_MAIN(TestQSommet);
#endif
#include "QSommet.moc"

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QString>
#include <QDebug>
#include <QPushButton>
#include <QDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QRandomGenerator>
#include <QTimer>
#include <utility>
#include "mainwindow_copy.hh"
#include "../../../bib/bib.hh"
#include "../../fichier/gestion_fichier.hh"

//QT BEGIN NAMESPACE //chelou à voir si c'est vraiment utile
namespace Ui {
class MainWindow;
}
//QT END NAMESPACE //chelou à voir si c'est vraiment utile

class MainWindow : public QMainWindow
{
Q_OBJECT
private :
  Ui::MainWindow *ui;
  Graphe grapheCourant;
  int dernierBoutonEnclenche;
public :
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  int printConsole(string nomMethode, string valRetFunc);
  int ajouterOnglet(QString nomOnglet, Graphe G);
  int supprimerOnglet(QString nomOnglet);

public slots :
  int printCaraSelection();
  void nv_graphe_vide();
  void nv_graphe_aleatoire();
  void Enregistrer();
  void Charger();
  void Enregistrer_sous();
  void Dupliquer_graphe();
  void Supprimer_graphe();
  void Ford_Bellman();
  void Floyd_Warshall();
  void Degr_sortant();
  void Degr_entrant();
  void Degrs_entrant_et_sortant();
  void Coloration_de_graphe();
  void Determinaison_de_stables();
  void Determinaison_de_cliques();
  void Voisins_de_sommets();
  void Gestion_de_flots();
  void Creer_un_graphe_dordonnancement();
  void Arborescence();
  void AntiArborescence();
  void Recherche_de_la_connexite();
  void Trouver_chaine_eulerienne();
  void Trouver_chaine_hamiltonienne();
  void Postier_chinois();
  void Voyageur_de_commerce();
  void Documentation();
  void Github();
  void extraireSousGraphe();
  void arrangerSommets();
  void fermer_graphe();
  void DBEselection(bool checked);
  void DBEaddSommet(bool checked);
  void DBEaddArc(bool checked);
  void DBEdeleteSommet(bool checked);
  void DBEdeleteArc(bool checked);
};

#endif

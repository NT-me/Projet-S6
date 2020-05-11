#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "UI_MainWindow.hh"

QT BEGIN NAMESPACE //chelou à voir si c'est vraiment utile
namespace Ui {
class MainWindow;
}
QT END NAMESPACE //chelou à voir si c'est vraiment utile

class MainWindow : public QMainWindow
{
Q OBJECT
private :
  Ui::MainWindow ∗ui;
  Graphe grapheCourant;
  int dernierBoutonEnclenche;
public :
  MainWindow(QWidget ∗parent = nullptr );
  ~MainWindow();
  int printConsole(string nomMethode, string valRetFunc);
  int printCaraSelection();
  int ajouterOnglet(Qstring nomOnglet, Graphe G);
  int supprimerOnglet(Qstring nomOnglet);

public slots :
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
  void DBEselection();
  void DBEaddSommet();
  void DBEaddArc();
  void DBEdeleteSommet();
  void DBEdeleteArc();
};

#endif

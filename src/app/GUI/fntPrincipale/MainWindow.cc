#include "MainWindow.hh"


MainWindow::MainWindow(QWidget ∗parent = nullptr );
MainWindow::~MainWindow();
int MainWindow::printConsole(string nomMethode, string valRetFunc);
int MainWindow::printCaraSelection();
int MainWindow::ajouterOnglet(Qstring nomOnglet, Graphe G);
int MainWindow::supprimerOnglet(Qstring nomOnglet);

void MainWindow::nv_graphe_vide();
void MainWindow::nv_graphe_aleatoire();
void MainWindow::Enregistrer();
void MainWindow::Charger();
void MainWindow::Enregistrer_sous();
void MainWindow::Dupliquer_graphe();
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

#include "MainWindow.hh"


MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow), grapheCourant("courant"){
ui->setupUi(this);
// ui->zoneDessin->afficher_Sommet(Sommet(50,50,"hey",0));
// ui->zoneDessin->show();
Graphe g("G");
g.ajout_Sommet(0,100, 100);
g.ajout_Sommet(1,300, 300);
g.ajout_Sommet(2,350, 300);
g.ajout_Sommet(3,200, 200);
g.ajout_Arc(0,1);
g.ajout_Arc(0,2);

ui->zoneDessin->setGraphe_dessine(g);
}
MainWindow::~MainWindow(){}
int MainWindow::printConsole(string nomMethode, string valRetFunc){}
int MainWindow::printCaraSelection(){}
int MainWindow::ajouterOnglet(QString nomOnglet, Graphe G){}
int MainWindow::supprimerOnglet(QString nomOnglet){}

void MainWindow::nv_graphe_vide(){}
void MainWindow::nv_graphe_aleatoire(){}
void MainWindow::Enregistrer(){}
void MainWindow::Charger(){}
void MainWindow::Enregistrer_sous(){}
void MainWindow::Dupliquer_graphe(){}
void MainWindow::Supprimer_graphe(){}
void MainWindow::Ford_Bellman(){}
void MainWindow::Floyd_Warshall(){}
void MainWindow::Degr_sortant(){}
void MainWindow::Degr_entrant(){}
void MainWindow::Degrs_entrant_et_sortant(){}
void MainWindow::Coloration_de_graphe(){}
void MainWindow::Determinaison_de_stables(){}
void MainWindow::Determinaison_de_cliques(){}
void MainWindow::Voisins_de_sommets(){}
void MainWindow::Gestion_de_flots(){}
void MainWindow::Creer_un_graphe_dordonnancement(){}
void MainWindow::Arborescence(){}
void MainWindow::AntiArborescence(){}
void MainWindow::Recherche_de_la_connexite(){}
void MainWindow::Trouver_chaine_eulerienne(){}
void MainWindow::Trouver_chaine_hamiltonienne(){}
void MainWindow::Postier_chinois(){}
void MainWindow::Voyageur_de_commerce(){}
void MainWindow::Documentation(){}
void MainWindow::Github(){}
void MainWindow::extraireSousGraphe(){}
void MainWindow::arrangerSommets(){}
void MainWindow::fermer_graphe(){}
void MainWindow::DBEselection(){}
void MainWindow::DBEaddSommet(){}
void MainWindow::DBEaddArc(){}
void MainWindow::DBEdeleteSommet(){}
void MainWindow::DBEdeleteArc(){}

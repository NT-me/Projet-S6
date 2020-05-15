#include "MainWindow.hh"


MainWindow::MainWindow(QWidget ∗parent = nullptr ) : QMainWindow(parent){
  ui->setupUi(this);
  QObject::connect(ui->actionNouveau_graphe,SIGNAL(clicked()),this, SLOT (nv_graphe_vide()));
  QObject::connect(ui->actionNouveau_graphe_al_atoire,SIGNAL(clicked()),this, SLOT (nv_graphe_aleatoire()));
  QObject::connect(ui->actionEnrengistrer,SIGNAL(clicked()),this, SLOT (Enregistrer()));
  QObject::connect(ui->actionEnrengistrer_sous,SIGNAL(clicked()),this, SLOT (Enregistrer_sous()));
  QObject::connect(ui->actionDupliquer_graphe,SIGNAL(clicked()),this, SLOT (Dupliquer_graphe()));
  QObject::connect(ui->actionSupprimer_graphe,SIGNAL(clicked()),this, SLOT (Supprimer_graphe()));
  QObject::connect(ui->actionFord_Bellman,SIGNAL(clicked()),this, SLOT (Ford_Bellman()));
  QObject::connect(ui->actionFloyd_Warshall,SIGNAL(clicked()),this, SLOT (Floyd_Warshall()));
  QObject::connect(ui->actionDegr_sortant,SIGNAL(clicked()),this, SLOT (Degr_sortant()));
  QObject::connect(ui->actionDegr_entrant,SIGNAL(clicked()),this, SLOT (Degr_entrant()));
  QObject::connect(ui->actionDegr_s_entrant_et_sortant,SIGNAL(clicked()),this, SLOT (Degrs_entrant_et_sortant()));
  QObject::connect(ui->actionColoration_de_graphe,SIGNAL(clicked()),this, SLOT (Coloration_de_graphe()));
  QObject::connect(ui->actionD_termination_de_stables,SIGNAL(clicked()),this, SLOT (Determinaison_de_stables()));
  QObject::connect(ui->actionD_termination_de_cliques,SIGNAL(clicked()),this, SLOT (Determinaison_de_cliques()));
  QObject::connect(ui->actionVoisins_de_sommets,SIGNAL(clicked()),this, SLOT (Voisins_de_sommets()));
  QObject::connect(ui->actionGEstion_de_flots,SIGNAL(clicked()),this, SLOT (Gestion_de_flots()));
  QObject::connect(ui->actionCr_er_un_graphe_d_ordonnancement,SIGNAL(clicked()),this, SLOT (Creer_un_graphe_dordonnancement()));
  QObject::connect(ui->actionArborescence,SIGNAL(clicked()),this, SLOT (Arborescence()));
  QObject::connect(ui->actionAnti_Arborescence,SIGNAL(clicked()),this, SLOT (AntiArborescence()));
  QObject::connect(ui->actionRecherche_de_la_connexit,SIGNAL(clicked()),this, SLOT (Recherche_de_la_connexite()));
  QObject::connect(ui->actionTrouver_chaine_eul_rienne,SIGNAL(clicked()),this, SLOT (Trouver_chaine_eulerienne()));
  QObject::connect(ui->actionTrouver_chaine_hamiltonienne,SIGNAL(clicked()),this, SLOT (Trouver_chaine_hamiltonienne()));
  QObject::connect(ui->actionR_solution_du_probl_me_du_postier_chinois,SIGNAL(clicked()),this, SLOT (Postier_chinois()));
  QObject::connect(ui->actionR_solution_du_probl_me_de_voyageur_de_commerce,SIGNAL(clicked()),this, SLOT (Voyageur_de_commerce()));
  QObject::connect(ui->actionDocumentation,SIGNAL(clicked()),this, SLOT (documentation()));
  QObject::connect(ui->actionGithub,SIGNAL(clicked()),this, SLOT (Github()));
  QObject::connect(ui->actionExtraire_sous_graphe,SIGNAL(clicked()),this, SLOT (extraireSousGraphe()));
  QObject::connect(ui->actionArranger_sommets,SIGNAL(clicked()),this, SLOT (arrangerSommets()));
  QObject::connect(ui->actionFermer_graphe,SIGNAL(clicked()),this, SLOT (fermer_graphe()));
  QObject::connect(ui->radioButton,SIGNAL(clicked()),this, SLOT (DBEaddSommet()));
  QObject::connect(ui->radioButton_2,SIGNAL(clicked()),this, SLOT (DBEdeleteSommet()));
  QObject::connect(ui->radioButton_3,SIGNAL(clicked()),this, SLOT (DBEselection()));
  QObject::connect(ui->radioButton_4,SIGNAL(clicked()),this, SLOT (DBEaddArc()));
  QObject::connect(ui->radioButton_5,SIGNAL(clicked()),this, SLOT (DBEdeleteArc()));



}
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

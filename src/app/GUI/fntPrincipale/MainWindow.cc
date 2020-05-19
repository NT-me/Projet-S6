#include "MainWindow.hh"

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow), grapheCourant("courant"){
  ui->setupUi(this);
  // ui->zoneDessin->afficher_Sommet(Sommet(50,50,"hey",0));
  // ui->zoneDessin->show();
  // Graphe g("G");

  // g.ajout_Sommet(0,100, 100);
  // g.ajout_Sommet(1,300, 300);
  // g.ajout_Sommet(2,100, 300);
  // g.ajout_Sommet(3,300, 100);
  // g.ajout_Sommet(4,322, 455);
  // g.ajout_Arc(0,1);
  // g.ajout_Arc(0,2);
  // ui->zoneDessin->setGraphe_dessine(g);
  //

  QObject::connect(ui->actionNouveau_graphe,&QAction::activate,this, &MainWindow::nv_graphe_vide);
  // QObject::connect(ui->actionNouveau_graphe_al_atoire,SIGNAL(clicked()),this, SLOT (nv_graphe_aleatoire()));
/*  QObject::connect(ui->actionEnrengistrer,SIGNAL(clicked()),this, SLOT (Enregistrer()));
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
  */
  QObject::connect(ui->radioButton, &QRadioButton::toggled,this, &MainWindow::DBEaddSommet);
  QObject::connect(ui->radioButton_2, &QRadioButton::toggled,this, &MainWindow::DBEdeleteSommet);
  QObject::connect(ui->radioButton_3, &QRadioButton::toggled,this, &MainWindow::DBEselection);
  QObject::connect(ui->radioButton_4, &QRadioButton::toggled,this, &MainWindow::DBEaddArc);
  QObject::connect(ui->radioButton_5, &QRadioButton::toggled,this, &MainWindow::DBEdeleteArc);

}
MainWindow::~MainWindow(){}
int MainWindow::printConsole(string nomMethode, string valRetFunc){}
int MainWindow::printCaraSelection(){}
int MainWindow::ajouterOnglet(QString nomOnglet, Graphe G){}
int MainWindow::supprimerOnglet(QString nomOnglet){}

void MainWindow::nv_graphe_vide(){
   qDebug()<<"HEY";
}
void MainWindow::nv_graphe_aleatoire(){
  qDebug()<<"HEY";

}
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
void MainWindow::DBEselection(bool checked){
  if (checked){
    ui->zoneDessin->setProperty("DBE", 1);
    qDebug()<<"selection";
  }
}
void MainWindow::DBEaddSommet(bool checked){
  if (checked){
    ui->zoneDessin->setProperty("DBE", 2);
    qDebug()<<"addS";
  }
}
void MainWindow::DBEaddArc(bool checked){
  if (checked){
    ui->zoneDessin->setProperty("DBE", 3);
    qDebug()<<"addA";
  }
}
void MainWindow::DBEdeleteSommet(bool checked){
  if (checked){
    ui->zoneDessin->setProperty("DBE", 4);
    qDebug()<<"delS";
  }
}
void MainWindow::DBEdeleteArc(bool checked){
  if (checked){
    ui->zoneDessin->setProperty("DBE", 5);
    qDebug()<<"delA";

  }
}

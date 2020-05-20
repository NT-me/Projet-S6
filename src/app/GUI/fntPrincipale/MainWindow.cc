#include "MainWindow.hh"

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow), grapheCourant("courant"){
  ui->setupUi(this);
  ui->console->clear();

  QTimer::singleShot(1000,this,SLOT(printCaraSelection()));

  QObject::connect(ui->actionNouveau_graphe,&QAction::triggered,this, &MainWindow::nv_graphe_vide);
  QObject::connect(ui->actionNouveau_graphe_al_atoire,&QAction::triggered,this, &MainWindow::nv_graphe_aleatoire);
  QObject::connect(ui->actionEnrengistrer,&QAction::triggered,this, &MainWindow::Enregistrer);
  QObject::connect(ui->actionEnrengistrer_sous,&QAction::triggered,this, &MainWindow::Enregistrer_sous);
  QObject::connect(ui->actionDupliquer_graphe,&QAction::triggered,this, &MainWindow::Dupliquer_graphe) ;
  QObject::connect(ui->actionSupprimer_graphe,&QAction::triggered,this, &MainWindow::Supprimer_graphe) ;
  QObject::connect(ui->actionCharger,&QAction::triggered,this, &MainWindow::Charger) ;
  QObject::connect(ui->actionFord_Bellman,&QAction::triggered,this, &MainWindow::Ford_Bellman) ;
  // QObject::connect(ui->actionFloyd_Warshall,&QAction::triggered,this, &MainWindow:: ;
  // QObject::connect(ui->actionDegr_sortant,&QAction::triggered,this, &MainWindow:: ;
  // QObject::connect(ui->actionDegr_entrant,&QAction::triggered,this, &MainWindow:: ;
  // QObject::connect(ui->actionDegr_s_entrant_et_sortant,&QAction::triggered,this, &MainWindow:: ;
  // QObject::connect(ui->actionColoration_de_graphe,&QAction::triggered,this, &MainWindow:: ;
  // QObject::connect(ui->actionD_termination_de_stables,&QAction::triggered,this, &MainWindow:: ;
  // QObject::connect(ui->actionD_termination_de_cliques,&QAction::triggered,this, &MainWindow:: ;
  // QObject::connect(ui->actionVoisins_de_sommets,&QAction::triggered,this, &MainWindow:: ;
  // QObject::connect(ui->actionGEstion_de_flots,&QAction::triggered,this, &MainWindow:: ;
  // QObject::connect(ui->actionCr_er_un_graphe_d_ordonnancement,&QAction::triggered,this, &MainWindow:: ;
  // QObject::connect(ui->actionArborescence,&QAction::triggered,this, &MainWindow:: ;
  // QObject::connect(ui->actionAnti_Arborescence,&QAction::triggered,this, &MainWindow:: ;
  // QObject::connect(ui->actionRecherche_de_la_connexit,&QAction::triggered,this, &MainWindow:: ;
  // QObject::connect(ui->actionTrouver_chaine_eul_rienne,&QAction::triggered,this, &MainWindow::;
  // QObject::connect(ui->actionTrouver_chaine_hamiltonienne,&QAction::triggered,this, &MainWindow::;
  // QObject::connect(ui->actionR_solution_du_probl_me_du_postier_chinois,&QAction::triggered,this, &MainWindow::;
  // QObject::connect(ui->actionR_solution_du_probl_me_de_voyageur_de_commerce,&QAction::triggered,this, &MainWindow::;
  QObject::connect(ui->actionDocumentation,&QAction::triggered,this, &MainWindow::Documentation);
  QObject::connect(ui->actionGithub,&QAction::triggered,this, &MainWindow::Github);
  QObject::connect(ui->actionExtraire_sous_graphe,&QAction::triggered,this, &MainWindow::extraireSousGraphe) ;
  // QObject::connect(ui->actionArranger_sommets,&QAction::triggered,this, &MainWindow::;
  QObject::connect(ui->actionFermer_graphe,&QAction::triggered,this, &MainWindow::fermer_graphe);

  QObject::connect(ui->radioButton, &QRadioButton::toggled,this, &MainWindow::DBEaddSommet);
  QObject::connect(ui->radioButton_2, &QRadioButton::toggled,this, &MainWindow::DBEdeleteSommet);
  QObject::connect(ui->radioButton_3, &QRadioButton::toggled,this, &MainWindow::DBEselection);
  QObject::connect(ui->radioButton_4, &QRadioButton::toggled,this, &MainWindow::DBEaddArc);
  QObject::connect(ui->radioButton_5, &QRadioButton::toggled,this, &MainWindow::DBEdeleteArc);

}
MainWindow::~MainWindow(){}
int MainWindow::printConsole(string nomMethode, string valRetFunc){
  QString res = "["+QString(ui->tabWidget->tabText(ui->tabWidget->currentIndex()))+"] ["+QString::fromStdString(nomMethode)+"] : "+QString::fromStdString(valRetFunc);
  ui->console->append(res);
return 1;
}

int MainWindow::printCaraSelection(){
  Graphe g = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine();
  vector<int> listeSommet = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getSelected_list();
  ui->caraSelection->clear();

  if(!listeSommet.empty()){
    vector<Sommet> vs = g.getVecteurSommet(listeSommet);
    for(int i=0; i<vs.size();++i){
      ui->caraSelection->append("<b>Sommet "+QString::number(vs[i].getID())+" :</b>");
      ui->caraSelection->append("x :"+QString::number(vs[i].getPosX()));
      ui->caraSelection->append("y :"+QString::number(vs[i].getPosY()));
      ui->caraSelection->append("Liste ID arcs sortant:");
      vector<int> listeIDarc = vs[i].getVecArc();
      for(int j=0;j<listeIDarc.size();++j){
        ui->caraSelection->append(QString::number(listeIDarc[j]));
      }
      ui->caraSelection->append("<br>");

    }
  }

  QTimer::singleShot(1000,this,SLOT(printCaraSelection()));
}

int MainWindow::ajouterOnglet(QString nomOnglet, Graphe G){}
int MainWindow::supprimerOnglet(QString nomOnglet){}

void MainWindow::nv_graphe_vide(){
  QString text = QInputDialog::getText(this, tr("Nouveau graphe"),
                                       tr("Nom du graphe :"), QLineEdit::Normal);
  QWidget *tab = new QWidget();
  tab->setObjectName(QStringLiteral("tab"));
  QHBoxLayout *horizontalLayout = new QHBoxLayout(tab);
  horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
  QHBoxLayout *horizontalLayout_2 = new QHBoxLayout();
  horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
  horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
  QZoneDeDessin* zoneDessin = new QZoneDeDessin(tab);
  zoneDessin->setObjectName(QStringLiteral("zoneDessin"));
  zoneDessin->setMinimumSize(QSize(575, 0));

  horizontalLayout_2->addWidget(zoneDessin);
  horizontalLayout->addLayout(horizontalLayout_2);
  QString nom = "Graphe ";
  QString str;
  if(text != ""){
    Graphe g = zoneDessin->getGraphe_dessine();
    g.setEtiq(text.toStdString());
    zoneDessin->setGraphe_dessine(g);
    nom = text;
    str = nom;

  }
  else{
    str = nom+" "+QString::number(ui->tabWidget->count()+1);
  }


  ui->tabWidget->addTab(tab,str);
}

void MainWindow::nv_graphe_aleatoire(){
  QWidget *tab = new QWidget();
  tab->setObjectName(QStringLiteral("tab"));
  QHBoxLayout *horizontalLayout = new QHBoxLayout(tab);
  horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
  QHBoxLayout *horizontalLayout_2 = new QHBoxLayout();
  horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
  horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
  QZoneDeDessin* zoneDessin = new QZoneDeDessin(tab);
  zoneDessin->setObjectName(QStringLiteral("zoneDessin"));
  zoneDessin->setMinimumSize(QSize(575, 0));
  horizontalLayout_2->addWidget(zoneDessin);
  horizontalLayout->addLayout(horizontalLayout_2);
  QString str = "Graphe "+QString::number(ui->tabWidget->count()+1);

  bool ok;
  int nb_som = QInputDialog::getInt(this, tr("Graphe aléatoire"),
                               tr("Combien de sommets souhaitez-vous ?:"), 0, 0, 100, 1, &ok);

  if (ok){
    int max_arc = nb_som*(nb_som-1);
    Graphe G("randomG");
    for(int i = 0;i<nb_som;++i){
      QRandomGenerator qrg(i*1200);
      int xs = qrg.bounded(1000);
      int ys = qrg.bounded(1000);
      G.ajout_Sommet(i, xs, ys);
    }
    for(int i = 0; i<max_arc;++i){
      QRandomGenerator qrg(i*2600);
      if (qrg.bounded(3)==1){
        int ida = qrg.bounded(nb_som);
        int idb = qrg.bounded(nb_som);
        if(ida != idb){
          G.ajout_Arc(ida,idb);
        }
      }
    }
    zoneDessin->setGraphe_dessine(G);
    ui->tabWidget->addTab(tab,str);
  }

}

void MainWindow::Enregistrer(){
  QString chem = QString::fromStdString(ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine().getPath());
  if(chem == "\0"){
    Enregistrer_sous();
  }
  else{
    sauvegarde(ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine(), chem.toStdString());
    printConsole("Enregistrer", "Graphe sauvegardé "+chem.toStdString());
  }
}
void MainWindow::Charger(){
  QString chem;

  chem = QFileDialog::getOpenFileName(this, tr("Enregsitrer"), tr(".json"));
  Graphe g = chargement(chem.toStdString());
  ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->setGraphe_dessine(g);
  ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), QString::fromStdString(g.getEtiq()));
  printConsole("Charger", "Graphe chargé depuis "+chem.toStdString());


}
void MainWindow::Enregistrer_sous(){
  QString chem;

  chem = QFileDialog::getSaveFileName(this, tr("Enregsitrer"), tr(".json"));
  qDebug()<<chem;
  Graphe g = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine();
  g.setPath(chem.toStdString());

  ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->setGraphe_dessine(g);
  sauvegarde(ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine(), chem.toStdString());
  printConsole("Enregistrer sous", "Graphe sauvegardé "+chem.toStdString());

}
void MainWindow::Dupliquer_graphe(){
  QWidget *tab = new QWidget();
  tab->setObjectName(QStringLiteral("tab"));
  QHBoxLayout *horizontalLayout = new QHBoxLayout(tab);
  horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
  QHBoxLayout *horizontalLayout_2 = new QHBoxLayout();
  horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
  horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
  QZoneDeDessin* zoneDessin = new QZoneDeDessin(tab);
  zoneDessin->setObjectName(QStringLiteral("zoneDessin"));
  zoneDessin->setMinimumSize(QSize(575, 0));
  horizontalLayout_2->addWidget(zoneDessin);
  horizontalLayout->addLayout(horizontalLayout_2);
  QString str = "Duplicata "+ui->tabWidget->tabText(ui->tabWidget->currentIndex());
  Graphe g = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine();
  g.setPath("\0");


  zoneDessin->setGraphe_dessine(g);
  ui->tabWidget->addTab(tab,str);
  printConsole("Duplication", "Graphe dupliqué");

}
void MainWindow::Supprimer_graphe(){
  string chem = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine().getPath();
  if (ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine().getPath() == "\0"){
    printConsole("Supprimer graphe","Le fichier n'existe pas");
  }
  else{
    if (suppression(chem)){
      printConsole("Supprimer graphe", "Fichier supprimé");
    }
    else{
      printConsole("Supprimer graphe", "Problème lors de la suppression du fichier");
    }
  }
  ui->tabWidget->removeTab(ui->tabWidget->currentIndex());
}

void MainWindow::Ford_Bellman(){
  vector<int> listeSommet = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getSelected_list();
  Graphe g = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine();
  vector<Sommet> vs = g.getVecteurSommet(listeSommet);

  for(int i=0; i<vs.size();++i){
    pair<vector<vector<int>>, vector<int>> res = calcul_Bellman(g.conversion_vers_Matrice_adj(), vs[i]);

    string str = "Appliqué sur sommet :"+to_string(vs[i].getID())+"<br>";
    vector<int> dP = res.second;
    str = str+"Distance de "+to_string(vs[i].getID())+" à i : <br>";
    for(int j=0;j<dP.size();++j){
      if(dP[j] != 999999999){
        str = str+to_string(dP[j])+", ";
      }
      else{
        str =str + "infini, ";
      }
    }
    vector<vector<int>> pP = res.first;
    for(int k=0; k<pP.size();++k){
      str = str + "<br> Le chemin pour aller de "+to_string(vs[i].getID())+" à "+ to_string(k)+"<br>";
      for(int l=0;l<pP[k].size();++l){
        str = str+to_string(dP[l])+", ";
      }
    }
    printConsole("Ford_Bellman", str);
  }

}
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

void MainWindow::Documentation(){
  QMessageBox msgBox;
  msgBox.setText("<a href=''>Documentation</a>");
  msgBox.exec();
}
void MainWindow::Github(){
  QMessageBox msgBox;
  msgBox.setText("<a href='https://github.com/gnouf1/Projet-S6'>Depôt github</a>");
  msgBox.exec();
}

void MainWindow::extraireSousGraphe(){
  Graphe g = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getGraphe_dessine();
  vector<int> listeSelect = ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->getSelected_list(),
  listeIDArc_nec;
  if(!listeSelect.empty()){
    QString text = QInputDialog::getText(this, tr("Nouveau graphe"),
    tr("Nom du graphe :"), QLineEdit::Normal);
    string etiq = "Graphe extrait";
    if (text != "") etiq = text.toStdString();
    Graphe g_extract(etiq);
    vector<Arc> listeArc = g.getListe_Arcs();
    vector<Sommet> vgs = g.getVecteurSommet(listeSelect);


    for(int i=0;i<listeArc.size();++i){
      int flag_dep = 0, flag_arr = 0;
      for(int j = 0; j<listeSelect.size();++j){ // id départ
        if(listeSelect[j] == listeArc[i].getIDDepart()){
          flag_dep = 1;
        }
      }
      for(int j = 0; j<listeSelect.size();++j){ // id arrive
        if(listeSelect[j] == listeArc[i].getIDArrive()){
          flag_arr = 1;
        }
      }
      if(flag_arr && flag_dep){
        listeIDArc_nec.push_back(listeArc[i].getID());
      }
    }
    qDebug()<<"listeIDArc_nec"<<listeIDArc_nec;
    for(int i = 0; i<vgs.size();++i){ // Ajoute les sommets
      g_extract.ajout_Sommet(vgs[i].getID(), vgs[i].getPosX(), vgs[i].getPosY());
    }

    for(int i=0;i<listeArc.size();++i){
      for(int j=0;j<listeIDArc_nec.size();++j){
        if(listeArc[i].getID() == listeArc[j].getID()){
          g_extract.ajout_Arc(listeArc[j].getIDDepart(), listeArc[j].getIDArrive());
        }
      }
    }

    QWidget *tab = new QWidget();
    tab->setObjectName(QStringLiteral("tab"));
    QHBoxLayout *horizontalLayout = new QHBoxLayout(tab);
    horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
    QHBoxLayout *horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
    horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
    QZoneDeDessin* zoneDessin = new QZoneDeDessin(tab);
    zoneDessin->setObjectName(QStringLiteral("zoneDessin"));
    zoneDessin->setMinimumSize(QSize(575, 0));
    horizontalLayout_2->addWidget(zoneDessin);
    horizontalLayout->addLayout(horizontalLayout_2);

    zoneDessin->setGraphe_dessine(g_extract);
    ui->tabWidget->addTab(tab,QString::fromStdString(etiq));
    printConsole("Extraction", "Graphe extrait");
  }
}
void MainWindow::arrangerSommets(){}

void MainWindow::fermer_graphe(){
  ui->tabWidget->removeTab(ui->tabWidget->currentIndex());
  printConsole("Fermer graphe", "Onglet fermé");

}

void MainWindow::DBEselection(bool checked){
  if (checked){
    ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->setProperty("DBE", 1);
    qDebug()<<"selection";
  }
}
void MainWindow::DBEaddSommet(bool checked){
  if (checked){
    ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->setProperty("DBE", 2);
    qDebug()<<"addS";
  }
}
void MainWindow::DBEaddArc(bool checked){
  if (checked){
    ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->setProperty("DBE", 3);
    qDebug()<<"addA";
  }
}
void MainWindow::DBEdeleteSommet(bool checked){
  if (checked){
    ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->setProperty("DBE", 4);
    qDebug()<<"delS";
  }
}
void MainWindow::DBEdeleteArc(bool checked){
  if (checked){
    ui->tabWidget->currentWidget()->findChild<QZoneDeDessin*>("zoneDessin")->setProperty("DBE", 5);
    qDebug()<<"delA";

  }
}

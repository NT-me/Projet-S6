#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Ui_MainWindow
{
    public:
    /* ##############################################################
     *  Attributs des menus déroulants
     * ##############################################################
     * */
        QMenuBar *menubar; // Objet qui englobe tous les menus déroulants

        QMenu *menuFichier; // Menu déroulant qui concerne les fichiers et permet de créer un nouveau graphe, d'en ouvrir un, de l'enregistrer et l'enregistrer sous
        QMenu *menuEdition; // Menu déroulant permettant l'édition d'un graphe. Tel que la suppression et duplication
        QMenu *menuAlgorithmes; // Menu déroulant proposant tout les algorithmes applicables sur le graphe
        QMenu *menuCalcul_du_plus_court_chemin; // Double menu déroulant proposant les différents algorithmes de calcul de plus court chemin
        QMenu *menuCalcul_des_degr_s_entrant_ou_sortant_d_un_sommet; // Double menu déroulant qui propose de sélectionner le calcul des sommets entrant ou bien des sommets sortant
        QMenu *menuTrouver_arborescence_anti_arborescence; // Double menu déroulant permettant de sélectionner la fonction calculant l'arborescence, ou l'anti-arborescence
        QMenu *menuAide; // Menu déroulant d'aide proposant la documentation du projet ainsi que le GitHub

        // Les Qaction sont des actions pouvant être insérées dans des menus déroulants.
        // ### Menu FICHIER ###
        QAction *actionNouveau_graphe; // Objet permettant la création d'un nouveau graphe vide et l'ouverture d'un nouvel onglet
        QAction *actionNouveau_graphe_al_atoire; // Objet permettant la création d'un nouveau graphe avec un nombre de sommet aléatoire défini dans une fenêtre et l'ouverture d'un nouvel onglet
        QAction *actionEnregistrer;  // Permet de sauvegarder un graphe
        QAction *actionCharger;    // Permet d'ouvrir un graphe déjà créé
        QAction *actionEnrengistrer_sous; // Permet d'enregistrer sous un graphe

        // ### Menu EDITION ###
        QAction *actionDupliquer_graphe; // Duplication du graphe
        QAction *actionSupprimer_graphe; // Suppression du graphe
        QAction *arrangerSommet; // Applique Force Atlas 2 sur le graphe courant
        QAction *extraireSousGraphe; // Permet d'extraire grâce aux sommets selectionnés un sous graphe du graphe courant.
        QAction *fermerGraphe; // Permet de fermer l'onglet sans sauvegarder

        // ### Menu ALGORITHMES ###
        QAction *actionFord_Bellman; // Appel de l'algorithme de Ford-Bellman
        QAction *actionFloyd_Warshall; // Appel de l'agorithme de Floyd-Warshall
        QAction *actionDegr_sortant; // Algorithme des degrés sortants
        QAction *actionDegr_entrant; // Algorithme des degrés entrant
        QAction *actionDegrs_entrant_et_sortant; // Selection des fonctions de calcul de degré entrant ou sortant
        QAction *actionColoration_de_graphe; // Sélection de la coloration de graphe
        QAction *actionD_Termination_de_stables; // Sélection de l'algorithme de détermination de stables
        QAction *actionD_Termination_de_cliques; // Sélection de l'algorithme de détermination de cliques
        QAction *actionVoisins_de_sommets; // Sélection de l'algorithme de calcul des voisins d'un sommet
        QAction *actionGestion_de_flots; // Sélection de l'algorithme de gestion de flots
        QAction *actionCr_Creer_un_graphe_d_ordonnancement; // Sélection de l'algorithme d'ordonnancement
        QAction *actionArborescence; // Sélection de l'algorithme déterminant l'arborescence
        QAction *actionAnti_Arborescence; // Sélection de l'algorithme déterminant l'anti-arborescence
        QAction *actionRecherche_de_la_connexite; // Sélection de l'algorithme calculant la connexité du graphe
        QAction *actionTrouver_chaine_eulerienne; // Sélection de l'algorithme permettant de trouver une chaine eulérienne
        QAction *actionTrouver_chaine_hamiltonienne; // Sélection de l'algorithme permettant de trouver une chaine hamiltonienne
        QAction *actionR_Postier_chinois; // Sélection de l'algorithme résolvant le problème du postier chinois
        QAction *actionR_Voyageur_de_commerce; // Sélection de l'algorithme résolvant le problème du voyageur de commerce

        // ### Menu AIDE ###
        QAction *actionDocumentation; // Objet renvoyant vers la documentation du projet
        QAction *actionGithub; // Objet qui renvoie le lien Github du projet




    /* ##############################################################
     *  Liste des boutons permettant de choisir l'action a effectuer sur le dessin
     * ##############################################################
     * */

        QRadioButton *addSommetButton; // bouton qui permet d'ajouter un sommet au graphe en cliquant
        QRadioButton *addArcButton; // bouton qui permet de creer un arc entre 2 sommets
        QRadioButton *selectButton; // bouton qui permet de selectioner des sommet ou des arcs dans le graphe

        QRadioButton *deleteSommetButton; // Permet de supprimer les sommets sur lesquels on clic

        QRadioButton *deleteArcButton; // Permet de supprimer les arcs sur lesquels on clic
        // Bouton permettant d'ouvrir un nouvel onglet avec le sous graphe séléctionné issu du graphe courant.
    /* ##############################################################
     *  Attributs des onglets
     * ##############################################################
     * */
        QTabWidget *tabWidget; // Widget contenant les onglets

        /* ##############
         * Onglet
         * ##############*/

        QWidget *tab; // Onglet


        QZoneDeDessin *zoneDessin; // Zone sur chaque onglet de dessin de graphe
        QTextBrowser *caraSelection; // Caractéristiques de la sélection
        QTextBrowser *console; // Console affichant les résulats des différentes fonctionnalitées.

        // Barre de statut (barre en bas)
        QStatusBar *statusbar; // Barre de statut

        void setupUi(QMainWindow *MainWindow){
        /*
         * Utilise les setters des attributs de MainWindow pour leur affecter les valeurs par défaut (déterminer par le biais de Qt Designer)
         * */
        }

        void retranslateUi(QMainWindow *MainWindow){
        /*
         * Affecte les textes des éléments, la séparation est rendu nécessaire par les fonctionnalités de traduction de Qt.
         * */
        }
    };

#endif

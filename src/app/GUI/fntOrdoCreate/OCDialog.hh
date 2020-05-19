class Ui_Dialog {
public:
    QTableWidget *tableWidget;	/// Tableau ou sont affich&eacute;es les informations sur les taches
    QLineEdit *DureelineEdit;	/// Zone de texte permettant de donner la dur&eacute;e d'une tache
    QLineEdit *TacheAnterieurlineEdit;	/// Zone de texte permettant de donner les ID des taches anterieures
    QLineEdit *IDlineEdit;		/// Zone de texte permettant de donner l'ID de la tache que l'on souhaite ajouter au PERT
    QLineEdit *nomDeLaTachelineEdit;	/// Zone de textepermettant de donner le nom de la tache que l'on souhaite ajouter au PERT
    
    /**
     * Ajout tache
     * Lorsque l'utilisateur clique sur ce bouton l'ensemble des informations presentes dans les QLineEddit rejoignent le tableau
     * Informations dans QLineEdit converties en pert_row puis envoy&eacute;es dans calc_post
     * */
    QPushButton *ajoutTacheButton;
    QPushButton *supprimeTacheButton;	/// La tache selectionn&eacute;e par l'utilisateur est supprim&eacute;
    
    /**
     * \brief Boutons
     * Clic sur l'un des deux boutons : OK et Annuler
     * Annuler : La fenetre se ferme sans rien faire
     * OK : Les informations presentes dans le tableau sont converties en pert_row, mises dans un vecteur et pass&eacute; en parametre de la fonction pert
     * */
    QDialogButtonBox *buttonBox;
    void setupUi(QDialog *Dialog)
    void retranslateUi(QDialog *Dialog)

};

namespace Ui {
class ordoCreate;
}

/**
 * \brief Classe ordoCreate
 * Cette classe est utilis&eacute;e dans PERT
 * */
class ordoCreate : public QDialog {
Q_OBJECT

public:
	/**
	 * \brief Constructeur d'ordoCreate
	 * Constructeur de la fenetre permettant l'entr&eacute; d'informations servant de base &agrave; la creation de PERT
	 * Aucun champ n'est pr&eacute;-rempli
	 * */
    ordoCreate(QWidget *parent = nullptr);
    ~ordoCreate();	/// Destructeut de la fenetre

private:
    Ui::ordoCreate *ui;
    vector<row_pert> res;

public slots:

    void ajoutTache();	/// Permet d'ajouter les informations presentes dans les QLineEdit dans le tableau
    void supprimerTache();	/// Permet de supprimer les informations selectionn&eacute;es du tableau
};	

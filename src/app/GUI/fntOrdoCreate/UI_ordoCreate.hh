/********************************************************************************
** Form generated from reading UI file 'ordoCreate.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDOCREATE_H
#define UI_ORDOCREATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE
/**
 * \brief Classe Ui_Dialog
 * Cette classe est cr&eacute;&eacute; automatiquement par Qt
 * Cette classe est utilis&eacute;e dans PERT
 * */
class Ui_Dialog
{
public:
    QTableWidget *tableWidget;	/// Tableau ou sont affich&eacute;es les informations sur les taches
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *DureelineEdit;	/// Zone de texte permettant de donner la dur&eacute;e d'une tache
    QLineEdit *TacheAnterieurlineEdit;	/// Zone de texte permettant de donner les ID des taches anterieures
    QLineEdit *IDlineEdit;	/// Zone de texte permettant de donner l'ID de la tache que l'on souhaite ajouter au PERT
    QLineEdit *nomDeLaTachelineEdit;	/// Zone de textepermettant de donner le nom de la tache que l'on souhaite ajouter au PERT
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    
    /**
     * Ajout tache
     * Lorsque l'utilisateur clique sur ce bouton l'ensemble des informations presentes dans les QLineEddit rejoignent le tableau
     * Informations dans QLineEdit converties en pert_row puis envoy&eacute;es dans calc_post
     * */
    QPushButton *ajoutTacheButton;
    QPushButton *supprimeTacheButton;	/// La tache selectionn&eacute;e par l'utilisateur est supprim&eacute;
    QFrame *line;
    
    /**
     * \brief Boutons
     * Clic sur l'un des deux boutons : OK et Annuler
     * Annuler : La fenetre se ferme sans rien faire
     * OK : Les informations presentes dans le tableau sont converties en pert_row, mises dans un vecteur et pass&eacute; en parametre de la fonction pert
     * */
    QDialogButtonBox *buttonBox;
	
	/**
	 * \brief SetupUi
	 * Utilise les setters des attributs de MainWindow pour leur affecter les valeurs par defaut
	 * */
    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(650, 525);
        tableWidget = new QTableWidget(Dialog);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(8, 17, 621, 351));
        gridLayoutWidget = new QWidget(Dialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 370, 621, 42));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        DureelineEdit = new QLineEdit(gridLayoutWidget);
        DureelineEdit->setObjectName(QStringLiteral("DureelineEdit"));

        gridLayout->addWidget(DureelineEdit, 1, 3, 1, 1);

        TacheAnterieurlineEdit = new QLineEdit(gridLayoutWidget);
        TacheAnterieurlineEdit->setObjectName(QStringLiteral("TacheAnterieurlineEdit"));

        gridLayout->addWidget(TacheAnterieurlineEdit, 1, 4, 1, 1);

        IDlineEdit = new QLineEdit(gridLayoutWidget);
        IDlineEdit->setObjectName(QStringLiteral("IDlineEdit"));

        gridLayout->addWidget(IDlineEdit, 1, 1, 1, 1);

        nomDeLaTachelineEdit = new QLineEdit(gridLayoutWidget);
        nomDeLaTachelineEdit->setObjectName(QStringLiteral("nomDeLaTachelineEdit"));

        gridLayout->addWidget(nomDeLaTachelineEdit, 1, 2, 1, 1);

        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 420, 621, 92));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ajoutTacheButton = new QPushButton(layoutWidget);
        ajoutTacheButton->setObjectName(QStringLiteral("ajoutTacheButton"));

        verticalLayout->addWidget(ajoutTacheButton);

        supprimeTacheButton = new QPushButton(layoutWidget);
        supprimeTacheButton->setObjectName(QStringLiteral("supprimeTacheButton"));

        verticalLayout->addWidget(supprimeTacheButton);

        line = new QFrame(layoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Abort|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi
	
	/**
	 * \brief retranslateUi
	 * Affecte les textes des &eacute;l&eacute;ments
	 * */
    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Dialog", "ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Dialog", "Nom de la t\303\242che", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Dialog", "Dur\303\251e", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Dialog", "T\303\242ches ant\303\251rieurs (ID s\303\251par\303\251s par des virugles)", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Dialog", "T\303\242ches post\303\251rieurs (ID s\303\251par\303\251s par des virugles)", Q_NULLPTR));
        DureelineEdit->setPlaceholderText(QApplication::translate("Dialog", "Dur\303\251e", Q_NULLPTR));
        TacheAnterieurlineEdit->setPlaceholderText(QApplication::translate("Dialog", "T\303\242ches ant\303\251rieures", Q_NULLPTR));
        IDlineEdit->setPlaceholderText(QApplication::translate("Dialog", "ID", Q_NULLPTR));
        nomDeLaTachelineEdit->setPlaceholderText(QApplication::translate("Dialog", "Nom de la t\303\242che", Q_NULLPTR));
        ajoutTacheButton->setText(QApplication::translate("Dialog", "Ajouter t\303\242che", Q_NULLPTR));
        supprimeTacheButton->setText(QApplication::translate("Dialog", "Supprimer t\303\242che", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDOCREATE_H

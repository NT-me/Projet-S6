// class Ui_Dialog {
// public:
//     QTableWidget *tableWidget;
//     QLineEdit *DureelineEdit;
//     QLineEdit *TacheAnterieurlineEdit;
//     QLineEdit *IDlineEdit;
//     QLineEdit *nomDeLaTachelineEdit;
//     QPushButton *ajoutTacheButton;
//     QPushButton *supprimeTacheButton;
//     QDialogButtonBox *buttonBox;
//     void setupUi(QDialog *Dialog)
//     void retranslateUi(QDialog *Dialog)
//
// };
//
// namespace Ui {
// class ordoCreate;
// }
//
//
// class ordoCreate : public QDialog {
// Q_OBJECT
//
// public:
//     ordoCreate(QWidget *parent = nullptr);
//     ~ordoCreate();
//
// private:
//     Ui::ordoCreate *ui;
//     vector<row_pert> res;
//
// public slots:
//
//     void ajoutTache();
//     void supprimerTache();
// };
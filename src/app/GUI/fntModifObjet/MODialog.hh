class Ui_Dialog {
public:

    QLineEdit *lineEditEtiquette;
    QTableWidget *tableWidget;
    QPushButton *supprimeButton;
    QLineEdit *NomlineEdit;
    QLineEdit *ValeurlineEdit;
    QPushButton *addTacheButton;
    QDialogButtonBox *buttonBox;

};

namespace Ui {
class modifObjet;
}

class modifObjet : public QDialog {
Q_OBJECT

public:
    modifObjet(QWidget *parent = nullptr);
    ~modifObjet();

private:
ui::modifObjet *ui;
pair<string, map<string,vectVal>> res;


public slots:
    void supprimeCU();
    void addCU();

};

#ifndef SOMMET_HH
#define SOMMET_HH

#include <string>
#include "struct.hh"
#include <vector>
#include <utility>
using namespace std;

class Sommet {

    private:
    int x; // Coordonnées x
    int y; // Coordonnées y
    int ID;  // pour le retrouver
    string etiquette; // nom du sommet
    vector <int> vecArc;
    map <string, VectVal> SCharge_utile;

    public:
    Sommet(int posx, int posy, string etiq, int id, map <string, VectVal> v);
    Sommet(int posx, int posy, string etiq, int id);
    Sommet(string etiq, int id);
    Sommet(int id);
    Sommet(Sommet const &S);
    ~Sommet();

    int getPosX();
    int getPosY();
    int getID();
    string getEtiq();
    vector<int> getVecArc();
    map <string, VectVal> getCU();

    void setPosX(int x);
    void setPosY(int y);
    void setID(int id);
    void setEtiq(string etiq);
    void setVecArc(vector<int> v);
    void setCU(map <string, VectVal> S_CU);

    bool operator==(Sommet const& S1)const;
    bool operator!=(Sommet const& S1);
    Sommet operator=(Sommet const& S1);
	void afficher_Sommet();
};

#endif

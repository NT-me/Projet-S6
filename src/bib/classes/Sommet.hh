#include <iostream.h>
#include <string>
#include "struct.hh"
#include <vector>
using namespace std;

class Sommet {

    private:
    int x; // Coordonnées x
    int y; // Coordonnées y
    int ID;  // pour le retrrouver
    String etiquette; // nom du sommet
    map <string, VectVal> SCharge_utile;

    public:
    Sommet(int posx, int posy, string etiq, int id, VectVal v);
    Sommet(int posx, int posy, string etiq, int id);
    Sommet(string etiq, int id);
    Sommet(int id);
    Sommet(Sommet &S);
    ~Sommet();

    int getPosX();
    int getPosY();
    int getID();
    string getEtiq();
    map <string, VectVal> getCU();

    void setPosX(int x);
    void setPosY(int y);
    void setID(int id);
    void setEtiq(string etiq);
    void setCU(vector <string, VectVal> S_CU);

    bool operator==(Sommet const& S1);
    bool operator!=(Sommet const& S1);
    Sommet operator=(Sommet const& S1);

};

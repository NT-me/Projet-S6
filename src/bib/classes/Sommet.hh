#include "iostream"
#include "cstring"
#include "struct.hh"

class Sommet {

    private:
    int x; // Coordonnées x
    int y; // Coordonnées y
    int ID;  // pour le retrrouver
    String etiquette; // nom du sommet
    vector <String, VectVal> SCharge_utile;

    public:
    Sommet(int posx, int posy, String etiq, int id, VectVal v);
    Sommet(int posx, int posy, String etiq, int id);
    Sommet(string etiq, int id);
    Sommet(int id);
    Sommet(&Sommet S);
    ~Sommet();

    int getPosX();
    int getPosY();
    int getID();
    String getEtiq();
    vector <String, VectVal> getCU();

    void setPosX(int x);
    void setPosY(int y);
    void setID(int id);
    void setEtiq(String etiq);
    void setCU(vector <String, VectVal> S_CU);

    bool operator==(Sommet const& S1, Sommet const& S2);
    bool operator!=(Sommet const& S1, Sommet const& S2);
    Sommet operator=(Sommet const& S1, Sommet const& S2);
};

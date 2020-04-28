#include "struct.hh"

#ifndef arc
#define arc



class Arc {

    private:
			int ID;
			string etiquette;
			int IDdepart;
			int IDarrive;
			map <string, VectVal> ACharge_Utile;

		public:
			Arc(string etiq, int id, int SDepart, int SArrive, map <string, VectVal>);
			Arc(string etiq, int id, int SDepart, int SArrive);
			Arc(int id, int SDepart, int SArrive);
			Arc(Arc &a);
			~Arc();

			int getID();
			string getEtiq();
			int getIDDepart();
			int getIDArrive();
			map <string, VectVal> getCU();

			void setID(int id);
			void setEtiq(string etiq);
			void setIDDepart(int id);
			void setIDArrive(int id);
			void setCU(map <string, VectVal> CU);

      bool operator==(Arc const& A1);
      bool operator!=(Arc const& A1);
      Arc operator=(Arc &A1);

};

#endif

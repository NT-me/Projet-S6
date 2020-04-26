#include "struct.hh"
#include <cstring>

class Arc {

    private:
			int ID;
			String etiquette;
			int IDdepart;
			int IDarrive;
			map <String, VectVal> ACharge_Utile;

		public:
			Arc(String etiq, int id, int SDepart, int SArrive, map <String, VectVal>);
			Arc(String etiq, int id, int SDepart, int SArrive);
			Arc(int id, int SDepart, int SArrive);
			Arc(&Arc a);
			~Arc();

			int getID();
			String getEtiq();
			int getIDDepart();
			int getIDArrive();
			map <String, VectVal> getCU();

			void setID(int id);
			void setEtiq(String etiq);
			void setIDDepart(int id);
			void setIDArrive(int id);
			void setCU(map <String, VectVal> CU);

			bool operator==(Arc const& A1, Arc const& A2);
			bool operator!=(Arc const& A1, Arc const& A2);
			Arc operator=(Arc const& A1, Arc const& A2);
};

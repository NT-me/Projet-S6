#ifndef ARC_HH
#define ARC_HH

#include "struct.hh"



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
			Arc(Arc const&a);
			~Arc();

			int getID() const;
			string getEtiq() const;
			int getIDDepart() const;
			int getIDArrive() const;
			map <string, VectVal> getCU() const;

			void setID(int id);
			void setEtiq(string etiq);
			void setIDDepart(int id);
			void setIDArrive(int id);
			void setCU(map <string, VectVal> CU);

      bool operator==(Arc const&A) const;
      bool operator!=(Arc const&A);
      Arc operator=(Arc const&A1);

};

#endif

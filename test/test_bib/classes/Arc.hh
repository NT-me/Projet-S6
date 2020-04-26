
typedef struct Valeur_Vecteur{
	int valeur_entiere;
	float valeur_reel;
}VectVal;

class Arc {

    private:
        int numero; 		// id de l'arc
        char * etiquette;	// nom de l'arc
        vecteur;			// vecteur de valeur d'un arc
        sommet &Sdepart; 	// Sommet de départ 
        sommet &Sarrive; 	// Sommet d'arrive
        
     public:
         
         
         int get_num() ;
         void set_num() ;
         
         char * get_etiquette();
         void set_etiquette();
         
         get_vect_val(); // permet de get la valeur a la position i du vecteur
         void set_vect_val(); // permet de set la valeur à la position i du vecteur
     
     
		 Arc (int num, char* etiq, vecteur Vect, Sommet Sdepart, Sommet Sarrivee); 	// constructeur complet
		 Arc (int num, vecteur Vect, Sommet Sdepart, Sommet Sarrivee);				// constructeur complet sans étiquette
		 Arc (int num, char* etiq, Sommet Sdepart, Sommet Sarrivee); 				// constructeur sans valeur sur l'arc
		 Arc (int num, Sommet Sdepart, Sommet Sarrivee); 							// constructeur par défaut
		 Arc (&Arc a); 																// constructeur de copie
		 
		 ~Arc(); 	// destructeur

};

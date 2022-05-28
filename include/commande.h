#ifndef COMMANDE_H
#define COMMANDE_H
#include<vector>
#include "medicament.h"
#include "fournisseur.h"
using namespace std;
enum Erreur_c{siro,compr,peli,poma};
class  commande
{
    friend class pharmacie;
    public:
        commande();
        virtual ~commande();
        void passer_commande();
        friend ostream& operator<< (ostream&,commande&);
        friend istream& operator>> (istream&,commande&);
        int rechercher_m(int);
        int chercherFR(int);
        void lire_fourn();
        void afficherFR();
        void enregistrer();
        int getnum_com();
        int getcode_f();
        void afficher_com();


    protected:

    private:
        vector <medicament*> tab_med;
        vector <fournisseur*> tab ;
        int code_f;
        int num_commande;

};

#endif // COMMANDE_H

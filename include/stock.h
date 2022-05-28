#ifndef STOCK_H
#define STOCK_H
#include<vector>
#include "medicament.h"
#include"sirop.h"
using namespace std;
enum Erreur{med,sir,comp,pel,pom};
class stock
{
    vector<medicament*> tab_med;
    vector<medicament*> tab_sr;
    vector<medicament*> tab_cm;
    vector<medicament*> tab_pl;
    vector<medicament*> tab_pm;
    public:
        stock();
        virtual ~stock();
        stock(const stock&);
        void ajouter_stock(medicament&);
        void afficher_stock();
        void rechercher();
        int rechercher_m(int);
        int rechercher_sr(int);
        int rechercher_cm(int);
        int rechercher_pl(int);
        int rechercher_pm(int);
        void supprimer();
        medicament afficher(int);
        sirop afficher_s(int);
        void modifier_sr(int,int);
        void modifier_cm(int,int);
        void modifier_pl(int,int);
        void modifier_pm(int,int);

        void afficher_sr();
        void afficher_cm();
        void afficher_pl();
        void afficher_pm();

        friend ostream& operator<< (ostream&,stock&);
        friend istream& operator>> (istream&,stock&);
        void enregistrer();
        void lire();
        void charger_medicaments();
        void modifier_fichier();

    protected:

    private:
};

#endif // STOCK_H

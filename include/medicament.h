#ifndef MEDICAMENT_H
#define MEDICAMENT_H
#include "string"
using namespace std;


class medicament
{
    protected:
        int code_med;
        string nom_med;
        int nb_boite;
        float prix;

    public:
       // medicament(int c=0,string n="",string l="",float p=0.0):code_med(c),nom_med(n),libelle(l),prix(p){};
        medicament(){};
        virtual ~medicament();
        friend ostream& operator<< (ostream&,medicament&);
        friend istream& operator>> (istream&,medicament&);
        virtual void ajouter_med();
        virtual void afficher();
        int getcode();
        int getnb_boite();
        float getprix();
        int getqte();
        string getnom();
        void setcode(int);
        void setnom(string);
        void setnb_boite(int);
        void setprix(float);
        virtual void remplir();
        virtual void charger();



    private:
};

#endif // ME

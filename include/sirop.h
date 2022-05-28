#ifndef SIROP_H
#define SIROP_H

#include <medicament.h>


class sirop : public medicament
{
    public:
        friend class medicament;
//        sirop(string c="",string n="",string l="",float p=0.0,int q=0):medicament(c,n,l,p),quantite(q){};
        sirop();
        virtual ~sirop();
        friend ostream& operator<< (ostream&,sirop&);
        friend istream& operator>> (istream&,sirop&);
        void ajouter_sr();
        void afficher();
        void setquantite(int);
        int getquantite();
        void remplir();
        void charger();


    protected:

    private:
        int quantite;
};

#endif // SIROP_H

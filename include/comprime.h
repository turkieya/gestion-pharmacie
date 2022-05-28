#ifndef COMPRIME_H
#define COMPRIME_H

#include <medicament.h>


class comprime : public medicament
{
    public:
        comprime();
        //comprime(string c="",string n="",string l="",float p=0.0,int nb=0):medicament(c,n,l,p),nb_comp(nb){};
        virtual ~comprime();
        friend ostream& operator<< (ostream&,comprime&);
        friend istream& operator>> (istream&,comprime&);
        void ajouter_cm();
        void afficher();


    protected:

    private:
        int nb_comp;
};

#endif // COMPRIME_H

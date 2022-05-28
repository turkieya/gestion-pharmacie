#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <personne.h>
#include"string"
using namespace std;


class fournisseur : public personne
{
    public:
        fournisseur();
        virtual ~fournisseur();
        int getID () ;
        string getNom () ;
        string getPrenom() ;
        void setId(int) ;
        void setNom (string) ;
        void setPrenom (string) ;
        void affichageF() ;

    protected:

    private:
};

#endif // FOURNISSEUR_H

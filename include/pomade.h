#ifndef POMADE_H
#define POMADE_H

#include <medicament.h>


class pomade : public medicament
{
    public:
        pomade();
        virtual ~pomade();
        friend ostream& operator<< (ostream&,pomade&);
        friend istream& operator>> (istream&,pomade&);
        void afficher();
        void remplir();
        void charger();

    protected:

    private:
        int quantite;
};

#endif // POMADE_H

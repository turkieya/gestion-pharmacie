#ifndef PERSONNE_H
#define PERSONNE_H
#include <string>
using namespace std;

class personne
{
    public:
        personne();
        virtual ~personne();
        friend istream& operator>> (istream& , personne&) ;
        friend ostream& operator<< (ostream& , personne&) ;

    protected:
        int id;
        string nom;
        string prenom;

    private:
};

#endif // PERSONNE_H

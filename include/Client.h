#ifndef CLIENT_H
#define CLIENT_H

#include <personne.h>
#include <string>
#include <iostream>
using namespace std;

class Client : public personne
{
    public:
        Client();
        virtual ~Client();
        int getID () ;
        string getNom () ;
        string getPrenom() ;
        void setId(int) ;
        void setNom (string) ;
        void setPrenom (string) ;
};

#endif // CLIENT_H

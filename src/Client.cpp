#include "Client.h"

Client::Client()
{
    //ctor
}

Client::~Client()
{
    //dtor
}

int Client::getID() {
return id ;
}

string Client::getNom() {
return nom ;
}

string Client::getPrenom() {
return prenom ;
}

void Client::setId (int a) {
id =a ;
}

void Client::setNom (string b ) {
nom =b ;
}
void Client::setPrenom (string c) {
prenom=c ;
}

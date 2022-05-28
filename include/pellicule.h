#ifndef PELLICULE_H
#define PELLICULE_H

#include <medicament.h>


class pellicule : public medicament
{
    public:
        pellicule();
        virtual ~pellicule();
        friend ostream& operator<< (ostream&,pellicule&);
        friend istream& operator>> (istream&,pellicule&);
        void afficher();

    protected:

    private:
        int nb_pel;
};

#endif // PELLICULE_H

#ifndef ORDONNANCEUR_H_INCLUDED
#define ORDONNANCEUR_H_INCLUDED
#include "stat.h"
#include<map>
#include<vector>

class Ordonnanceur {
public:
    Ordonnanceur(){};
    virtual ~Ordonnanceur(){};
    virtual vector<string> ordonnanceur(map <string,vector<Stat> > m)=0;     // trier les resultats

};


#endif // ORDONNANCEUR_H_INCLUDED

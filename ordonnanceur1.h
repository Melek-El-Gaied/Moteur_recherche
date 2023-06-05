#ifndef ORDNEFAITRIEN_H_INCLUDED
#define ORDNEFAITRIEN_H_INCLUDED
#include"ordonnanceur.h"
#include"stat.h"

class Ordonnanceur1:public Ordonnanceur {
public:
    Ordonnanceur1():Ordonnanceur(){};
    ~Ordonnanceur1(){};
    vector<string> ordonnanceur(map <string,vector<Stat> > m);

};


#endif // ORDNEFAITRIEN_H_INCLUDED

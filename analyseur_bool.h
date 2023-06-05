#ifndef ANALNEFAITRIEN_H_INCLUDED
#define ANALNEFAITRIEN_H_INCLUDED
#include"Analyseur.h"
#include<vector>

class Analyseur_Bool : public Analyseur
{
public:
    Analyseur_Bool():Analyseur(){};
    ~Analyseur_Bool(){};
    vector<Stat> analyser(string cheminFile,vector<string> mots);   //existance ou non d'un mot dans un docoument (booléen)

};



#endif // ANALNEFAITRIEN_H_INCLUDED

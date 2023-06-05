#ifndef TRAITEURPONCT_H_INCLUDED
#define TRAITEURPONCT_H_INCLUDED
#include "traiteur.h"
#include <iostream>
#include<vector>

class traiteurPonct : public Traiteur
{
public:
    traiteurPonct():Traiteur(){};
    ~traiteurPonct(){};
    void traitement(vector<string> &mot);   //effacer les ponctuations

};
#endif // TRAITEURPONCT_H_INCLUDED

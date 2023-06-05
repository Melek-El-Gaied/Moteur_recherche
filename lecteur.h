#ifndef LECTEUR_H_INCLUDED
#define LECTEUR_H_INCLUDED
#include <iostream>
#include<vector>
#include <fstream>

using namespace std;

class Lecteur {
public:
    Lecteur(){};
    virtual ~Lecteur(){};
    virtual vector<string> lire(string)=0;

};


#endif // LECTEUR_H_INCLUDED

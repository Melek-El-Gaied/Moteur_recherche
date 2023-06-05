#ifndef TRAITEURTEXT_H_INCLUDED
#define TRAITEURTEXT_H_INCLUDED
#include<vector>
#include<string>

using namespace std;
class Traiteur
{
public:
    Traiteur(){};
    virtual ~Traiteur(){};
    virtual void traitement(vector<string> &mots)=0;
};




#endif // TRAITEURTEXT_H_INCLUDED

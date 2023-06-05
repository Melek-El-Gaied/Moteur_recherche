#ifndef INDEXVECT_H_INCLUDED
#define INDEXVECT_H_INCLUDED
#include"index.h"
#include "stat.h"

class Index1 :public Index
{
private:
    map<string,vector<Stat> > ind1;     //structure de l'index1
public:
    Index1():Index(){};
    ~Index1(){};
    void indexer(vector<Stat>);
    void affichierindex()const;
    void affichierfichiersindexes()const;
    void supprimefichierdelindex(string);
    void restaurerindex();
    void sauvgarderindex()const;
    void restaurerfichiersindexes();
    void sauvgarderfichiersindexes()const;
    map<string,vector<Stat> > rechercheind(vector<string>)const;
    map<string,vector<Stat> > get_ind()const;

};


#endif // INDEXVECT_H_INCLUDED

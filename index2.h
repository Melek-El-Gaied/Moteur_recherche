#ifndef INDEX2_H_INCLUDED
#define INDEX2_H_INCLUDED
#include "stat.h"
#include"index.h"



class Index2 :public Index
{
private:
    vector<Stat> ind2;          //structure de l'index2
public:
    Index2():Index(){};
    ~Index2(){};
    void indexer(vector<Stat>);
    void affichierindex()const;
    void affichierfichiersindexes()const;
    void supprimefichierdelindex(string);
    void restaurerindex();
    void sauvgarderindex()const;
    void restaurerfichiersindexes();
    void sauvgarderfichiersindexes()const;
    map<string,vector<Stat> > rechercheind(vector<string>)const;
    vector<Stat> get_ind()const;

};

#endif // INDEX2_H_INCLUDED

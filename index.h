#ifndef INDEX_H_INCLUDED
#define INDEX_H_INCLUDED
#include "stat.h"
#include <vector>
#include <map>
#include <set>



class Index
{
protected:
        set<string> fichiers_indexes;               //ensemble des fichiers indexes
public:
    Index(){};
    virtual ~Index(){};
    virtual void indexer(vector<Stat>)=0;           //index ou mise a jour d'un vecteur de de stat du meme fichier
    virtual void affichierindex()const=0;           //affichage de l'index
    virtual void affichierfichiersindexes()const=0; //affichage de la liste des fichiers indexes
    virtual void supprimefichierdelindex(string)=0; //supprime le fichier de l'index et de la liste des fichiers indexes en meme temps
    virtual void restaurerindex()=0;                //restaurer l'index apartir d'un fichier
    virtual void sauvgarderindex()const=0;          //sauvgarder l'index dans un fichier
    virtual void restaurerfichiersindexes()=0;      //restaurer les fichiers indexes apartir d'un fichier
    virtual void sauvgarderfichiersindexes()const=0;//sauvgarder les fichiers indexes dans un fichier
    virtual map<string,vector<Stat> > rechercheind(vector<string>)const=0;  //recherche des mots dans l'index et les retournes dans un map

};


#endif // INDEX_H_INCLUDED

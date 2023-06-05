#include <iostream>
#include "moteur.h"
#include<bits/stdc++.h>
#include<string>



void Moteur::chercher(string Req)const
{
    cout<<"\t\t******************Resultat de la recherche*******************"<<endl;
    map<string,vector<Stat> > mr; //map des mots de la Req dans l'index avec ses stat
    vector<string> vects;
    string mot;
    int i=0;

    //mettre la Req dans un veceur de string
    while (i< Req.size())
    {
        if(Req[i]==' ')
        {
            vects.push_back(mot);
            mot="";
        }
        else
        {
            mot+=Req[i];
        }
        i++;
    }
    if(Req[Req.size()]!=' ')
    {
        vects.push_back(mot);
    }
    //*********************

    //traiter la Req
    for (i=0;i<Vectt.size();i++)
    {
        Vectt[i]->traitement(vects);
    }
    //*********************

    //recherche des mot dans l'index et les mettre dans mr
    mr=I->rechercheind(vects);

    //*********************

    //ordonnancer mr et affichier les 10 meilleurs resultats (fichier)
    vects.clear();
    vects=O->ordonnanceur(mr);
    if (vects.size()<10)
    {
        for(auto& s:vects)
        {
            cout<<s<<endl;
        }
    }
    else
    {
        for(int j=0;j<10;j++)
        {
            cout<<vects[j]<<endl;
        }
    }
    //*********************

    cout<<"\t\t*************************************************************"<<endl;
}

void Moteur::indexerfichier(string chemin)
{
    vector<Stat>    vectstat;
    vector<string>  vects;
    vects=L->lire(chemin);
    if(vects.size()!=0) //tester si le fichier est vide ou pas
    {
    //traiter le fichier
    for (int i=0;i<Vectt.size();i++)
    {
        Vectt[i]->traitement(vects);
    }
    //*********************

    //analyser le fichier
    vectstat=A->analyser(chemin,vects);
    //*********************

    //indexer le fichier
    I->indexer(vectstat);
    }
}


void Moteur::supprimefichierdelindexmoteur(string chemin)
{
    I->supprimefichierdelindex(chemin);
}

void Moteur::afficherindexmoteur()const
{
    I->affichierindex();
}

void Moteur::affichierfichiersindexesmoteur()const
{
    I->affichierfichiersindexes();
}

void Moteur::restaurerindexmoteur()
{
    I->restaurerindex();
}

void Moteur::sauvgarderindexmoteur()const
{
    I->sauvgarderindex();
}

void Moteur::restaurerfichiersindexesmoteur()
{
    I->restaurerfichiersindexes();
}

void Moteur::sauvgarderfichiersindexesmoteur()const
{
    I->sauvgarderfichiersindexes();
}



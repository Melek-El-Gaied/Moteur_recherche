#include <iostream>
#include "moteur.h"
#include "Lecteur.h"
#include"lecteur_file.h"
#include"traiteur.h"
#include"traiteurMaj.h"
#include"traiteurPonct.h"
#include"traiteurDet.h"
#include "stat.h"
#include "Analyseur.h"
#include "analyseur_bool.h"
#include "analyseur_freq.h"
#include "analyseur_occ.h"
#include "index.h"
#include "index1.h"
#include "index2.h"
#include "ordonnanceur.h"
#include "ordonnanceur1.h"
#include<bits/stdc++.h>
#include <dirent.h>
#include <chrono>

using namespace std;

int main()
{

    Lecteur* lf= new LecteurFile();
    Traiteur* tmaj= new TraiteurMaj();
    Traiteur* tponc= new traiteurPonct();
    Traiteur* tdet= new TraiteurDet();
    Analyseur* abool= new Analyseur_Bool();
    Analyseur* aocc= new Analyseur_Occ();
    Analyseur* afreq= new Analyseur_Freq();
    Ordonnanceur* o=new Ordonnanceur1();
    Index* i1=new Index1();
    Index* i2=new Index2();



    //lecteur des noms des fichiers
    vector<string> filenames;
    auto dpdf = opendir("corpus");
    if (dpdf != NULL) {
        while (auto epdf = readdir(dpdf)) {
        filenames.push_back(string(epdf->d_name));
        }
    }
    filenames.erase(filenames.begin());
    filenames.erase(filenames.begin());
    // for(auto& s:filenames )
    //     cout<<s<<endl;
    // cout<<filenames.size()<<endl;

    //*********************



    vector<Traiteur*> vectraiteur1={tmaj,tponc,tdet};

    Moteur M (lf,vectraiteur1,afreq,i1,o);

    //indexation des fichiers
    //auto start = chrono::high_resolution_clock::now();
    //for(auto& s:filenames)
    //{
    //   M.indexerfichier(s);
    //}
    //auto stop = chrono::high_resolution_clock::now();
    //auto duration = chrono::duration_cast<chrono::seconds>(stop - start);//choose between nanoseconds, microseconds, milliseconds,seconds, minutes, hours
    //cout<<"finished in "<<duration.count()<<"microseconds"<<endl;

    //*********************



    M.restaurerindexmoteur();

    M.restaurerfichiersindexesmoteur();

    // M.indexerfichier("114.txt");

    // M.afficherindexmoteur();

    // M.supprimefichierdelindexmoteur("137.txt");

    auto start1 = chrono::high_resolution_clock::now();
     M.chercher("station london");
    auto stop1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::milliseconds>(stop1 - start1);//choose between nanoseconds, microseconds, milliseconds,seconds, minutes, hours
    cout<<"finished in "<<duration1.count()<<"microseconds"<<endl;

    // M.affichierfichiersindexesmoteur();

    // M.afficherindexmoteur();

     M.sauvgarderfichiersindexesmoteur();

     M.sauvgarderindexmoteur();

    return 0;
}



    /*
    //menu pour la selection des traiteurs
    vector<Traiteur*> vectraiteur ;
    int n;
    do
    {
        cout<<"Quel est le nombre de traiteurs que vous voullez entre 1 et 3 ?"<<endl;
        cin>>n;
    }while((n<1)||(n>3));

    switch(n)
    {
    case 1:
        int n1;
        do
        {
        cout<<"Quel traiteur vous voullez ?"<<endl;
        cout<<"1) traiteur de maj"<<endl;
        cout<<"2) traiteur de ponc"<<endl;
        cout<<"3) traiteur de det"<<endl;
        cin>>n1;
        }while((n1<1)||(n1>3));

        switch(n1)
        {
            case 1 :
                vectraiteur={tmaj};
                break;
            case 2 :
                vectraiteur={tponc};
                break;
            case 3 :
                vectraiteur={tdet};
                break;
        }
        break;
    case 2:
        int n2;
        do
        {
        cout<<"Quel couple de traiteurs vous voullez ?"<<endl;
        cout<<"1) traiteur de maj et ponc"<<endl;
        cout<<"2) traiteur de maj et det"<<endl;
        cout<<"3) traiteur de ponc et det"<<endl;
        cin>>n2;
        }while((n2<1)||(n2>3));

        switch(n2)
        {
            case 1:
                vectraiteur={tmaj,tponc};
                break;
            case 2:
                vectraiteur={tmaj,tdet};
                break;
            case 3:
                vectraiteur={tdet,tponc};
                break;
        }
        break;
    case 3:
        int n3;
        do
        {
        cout<<"Quel triplet de traiteurs vous voullez ?"<<endl;
        cout<<"1) traiteur de maj et ponc et det"<<endl;
        cin>>n3;
        }while(n3!=1);
        vectraiteur={tmaj,tponc,tdet};
        break;
    }
    //************************************
    */



#ifndef MOTEUR_H_INCLUDED
#define MOTEUR_H_INCLUDED
#include "index.h"
#include"traiteur.h"
#include "Lecteur.h"
#include "Analyseur.h"
#include "ordonnanceur.h"
#include "stat.h"
#include <vector>
#include <map>


using namespace std;

class Moteur{
private:
    Lecteur* L;
    vector<Traiteur*> Vectt;
    Analyseur* A;
    Index* I;
    Ordonnanceur* O;

public:
    Moteur(Lecteur* l,vector<Traiteur*> v,Analyseur* a,Index* i,Ordonnanceur* o):L(l),Vectt(v),A(a),I(i),O(o){};

    ~Moteur(){};

    void chercher(string Req)const;                     //chercher les mots de la req dans l'index

    void indexerfichier(string chemin);                 //indexer ou mise a jour le fichier

    void supprimefichierdelindexmoteur(string chemin);  //supprimer le fichier de l'index du moteur et de la liste des fichiers indexes du moteur en meme temps

    void afficherindexmoteur()const;                    //affichage de l'index du moteur

    void affichierfichiersindexesmoteur()const;         //affichage de la liste des fichiers indexes du moteur

    void restaurerindexmoteur();                        //restaurer l'index du moteur apartir d'un fichier

    void sauvgarderindexmoteur()const;                  //sauvgarder l'index du moteur dans un fichier

    void restaurerfichiersindexesmoteur();              //restaurer les fichiers indexes du moteur apartir d'un fichier

    void sauvgarderfichiersindexesmoteur()const;        //sauvgarder les fichiers indexes du moteur dans un fichier










    /*vector<Stat> Ordonnancer(vector<Stat>);//demander a l'ord d'ordonnacer les resultats de recherhce

    vector<string> lireFichier(string cheminFichier);//demander au lecteur de lire un fichier

    vector<string> traiterText(vector<string>);//demander au traiteur de traiter

    vector<Stat> analyser(vector<string>,string chemin);//demander a l'analyseur d'analyser
    */


};



#endif // MOTEUR_H_INCLUDED

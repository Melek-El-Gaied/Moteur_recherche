#ifndef STAT_H_INCLUDED
#define STAT_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

class Stat
{
private:
    string mot;
    string cheminFile;
    double statMot;
public:
    string get_mot()const;
    string get_cheminFile()const;
    double get_statMot()const;
    void set_mot(string);
    void set_cheminFile(string);
    void set_statMot(double);
    bool operator ==(Stat const&);  //test d'egalite selon le chemin du fichier
};




#endif // STAT_H_INCLUDED

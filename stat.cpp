#include <iostream>
#include <string>
#include "stat.h"

bool Stat::operator == (Stat const& a)
{
    return(this->cheminFile==a.cheminFile);

}

string Stat::get_mot()const
{
    return mot;
}

string Stat::get_cheminFile()const
{
    return cheminFile;
}

double Stat::get_statMot()const
{
    return statMot;
}

void Stat::set_mot(string s)
{
    mot=s;
}

void Stat::set_cheminFile(string s)
{
    cheminFile=s;
}

void Stat::set_statMot(double d)
{
    statMot=d;
}




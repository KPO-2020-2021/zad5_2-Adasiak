#pragma once

#include "Prostopadloscian.hh"
#include "Graniastoslup6.hh"
#include "Przeszkody.hh"
// #include "Scena.hh"
#include <unistd.h>
#include <list>
#include "lacze_do_gnuplota.hh"
#include <iomanip>
#include <memory>
#include <fstream>
#include <string>


class Dron 
{
int licznik_dronow;
int nr1=1;
int nr2=2;
int iddrona;

Vector<3> droga;

double promien=40;
Vector<3> dwojka;

Vector<3> srodekD;

// Matrix<3> mac;
Prostopadloscian  *korpus;
Graniastoslup *wirniki[4];
Prostopadloscian  *korpus1;
Graniastoslup *wirniki1[4];
Prostopadloscian  *czubek[2];
// string PLIK_TRASY_PRZELOTU;
public:

Dron(int id);
void ruch(Vector<3> droga, double katOZ, double katOY /*, double OX*/);
void obrot(double kat);

bool DodajTrasePrzelotu(PzG::LaczeDoGNUPlota &Lacze,double x1, double y1);

void AnimacjaLotuDrona(PzG::LaczeDoGNUPlota &Lacze, double x1, double y1);


void zwiad(Vector<3> promien);//1 wersja 
void zwiad2(PzG::LaczeDoGNUPlota &Lacze,double promien);//2 wersja 

void zapisz();

Vector<3> wspolrzedne();

    void get_srodek() const ;
    

};

std::ostream &operator<<(std::ostream &Strm, /*const*/ Dron &P);
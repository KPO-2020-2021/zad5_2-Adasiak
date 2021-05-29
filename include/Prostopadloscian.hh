#pragma once

#include "BrylaGeometryczna.hh"

// #include "matrix3x3.hh"
// #include "../include/lacze_do_gnuplota.hh"
#include <stdlib.h>

using namespace std;
class Prostopadloscian : public BrylaGeometryczna
{
  

public:
    Prostopadloscian(){};

    Prostopadloscian(Vector<3> pkt, double h, double w, double d, string nazwa_pliku, string nazwa_pliku_do_zapisu);
    
    // Prostopadloscian(double dlugosc, double szerokosc, double wysokosc, string nazwa_pliku, string nazwa_pliku_do_zapisu);


};


std::ostream &operator<<(std::ostream &Strm, const Prostopadloscian &Pr);





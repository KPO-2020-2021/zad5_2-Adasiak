#pragma once

#include "BrylaGeometryczna.hh"
#include "Dron.hh"
#include <iostream>

class Ostroslup : public BrylaGeometryczna
{
    protected:
    int nrprzeszkody;
    public:
    Ostroslup(Vector<3> pkt,double dlugosc ,double szerokosc, double wysokosc, string nazwa_pliku, string nazwa_pliku_do_zapisu);
    // ~Ostroslup();


};

std::ostream &operator<<(std::ostream &Strm,
                         const Ostroslup &Pr);

// Ostroslup::Ostroslup(/* args */)
// {
// }

// Ostroslup::~Ostroslup()
// {
// }

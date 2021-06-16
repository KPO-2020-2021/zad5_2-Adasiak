#pragma once
#include "vector.hh"
#include "matrix3x3.hh"
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class BrylaGeometryczna
{
protected:
    vector<Vector<3>> pkt1;
    Vector<3> Przesuniecie;
    Vector<3>  srodek;
    string nazwa_pliku;
    string nazwa_pliku_do_zapisu;
    double katOZ; // obrot do okola osi Z
    double katOY; // kat wznoszenia i opadania
    double katOX; // kat rotacji np. wirnikow

public:
    Vector<3> operator[](int Ind) const { return pkt1[Ind]; } //wypisywanie
    Vector<3> &operator[](int Ind) { return pkt1[Ind]; } //wpisywanie


   

    void move(const Vector<3> &v);

    void obrotOZ(double kat);
    void obrotP(double kat, Vector<3> a);
    
    void obrotW(double kat);
    void obrotW1(double kat,Vector<3> b);

    string nazwa(){ return nazwa_pliku_do_zapisu;}

    void zapis();

    void set_katOX(double kat){katOX+=kat;}
    void set_katOZ(double kat){katOZ+=kat;}
    void set_katOY(double kat){katOY=kat;}

    void set_Przesuniecie(Vector<3> droga){
        Przesuniecie=Przesuniecie+macierzobrotZ(katOZ)*(macierzobrotX(katOX)* (macierzobrotY(katOY)*droga));
    }

        // string nazwa(){ return nazwa_pliku_do_zapisu;}

};



 // BrylaGeometryczna operator*(Matrix<3> tmp)
    // {
    //     BrylaGeometryczna wynik;
    //     for (int i = 0; i < 7; i++)
    //     {

    //         wynik[i] = tmp * (*this)[i];
    //     }
    //     return wynik;
    // }


    // BrylaGeometryczna operator*(Matrix<3> tmp)
    // {
    //     BrylaGeometryczna wynik;
    //     for (int i = 0; i < 7; i++)
    //     {

    //         wynik[i] = tmp * wynik[i];
    //     }
    //     return wynik;
    // }



    // void OZ(double kat)
    // {
    //     BrylaGeometryczna wynik;
    //     for (int i=0; i < (int)pkt1.size(); )
    //     wynik = wynik * macierzobrotZ(kat);     

    // }
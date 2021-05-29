#include "Prostopadloscian.hh"
#include "../include/lacze_do_gnuplota.hh"
#include <iomanip>


/*!
    \brief
    *Konstruktor Prostopadlosciana. 
    *Tworzymy Prostopadlosciana wzgledem 1 wierzcholak (jego wspolrzednych ), 
    * a nastepnie kolejne wierzcholki dodajac do 1 wierzcholka szerokosc i wysokosc w zaleznosci od kolejnego wierzcholka
    * 
    * a nastepnie zapisujemy je kolejno  do odpowiedniego pliku 
    *
    *  

*/

Prostopadloscian::Prostopadloscian(Vector<3> pkt, double h, double w, double d, string nazwa_pliku, string nazwa_pliku_do_zapisu)
{
    this->nazwa_pliku = nazwa_pliku;
    this->nazwa_pliku_do_zapisu = nazwa_pliku_do_zapisu;
    
    pkt1.resize(8);
    for (int i = 0; i < 8; i++)
    {
        pkt1[i] = pkt;
    }
    pkt1[1][0] += w;

    pkt1[2][1] += h;

    pkt1[3][0] += w;
    pkt1[3][1] += h;

    pkt1[4][1] += h;
    pkt1[4][2] += d;

    pkt1[5][0] += w;
    pkt1[5][1] += h;
    pkt1[5][2] += d;

    pkt1[6][2] += d;

    pkt1[7][0] += w;
    pkt1[7][2] += d;

    ofstream plik;
        plik.open(nazwa_pliku);
    for(int i=0; i<(int)pkt1.size(); i++)
    {
        if(i%2==0)
        plik<<endl;
        plik<<pkt1[i]<<endl;
    }
    plik.close();
    zapis();





}

// Prostopadloscian::Prostopadloscian(double dlugosc, double szerokosc, double wysokosc, string nazwa_pliku, string nazwa_pliku_do_zapisu)
// {
//     this->nazwa_pliku = nazwa_pliku;
//     this->nazwa_pliku_do_zapisu = nazwa_pliku_do_zapisu;
//     katOX = 0;
//     katOY = 0;
//     katOZ = 0;
//     Vector<3> tmp;
//     tmp[0] = -dlugosc / 2;
//     tmp[1] = -szerokosc / 2;
//     tmp[2] = -wysokosc / 2;
//     pkt1.push_back(tmp);
//     tmp[0] = pkt1[0][0] + dlugosc;
//     pkt1.push_back(tmp);
//     tmp[0] = pkt1[0][0];
//     tmp[1] = pkt1[0][1] + szerokosc;
//     pkt1.push_back(tmp);
//     tmp[0] = pkt1[0][0] + dlugosc;
//     tmp[1] = pkt1[0][1] + szerokosc;
//     pkt1.push_back(tmp);

//     tmp[0] = pkt1[0][0];
//     tmp[1] = pkt1[0][1] + szerokosc;
//     tmp[2] = pkt1[0][2] + wysokosc;
//     pkt1.push_back(tmp);
//     tmp[0] = pkt1[0][0] + dlugosc;
//     tmp[1] = pkt1[0][1] + szerokosc;
//     tmp[2] = pkt1[0][2] + wysokosc;
//     pkt1.push_back(tmp);

//     tmp[0] = pkt1[0][0];
//     tmp[1] = pkt1[0][1];
//     tmp[2] = pkt1[0][2] + wysokosc;
//     pkt1.push_back(tmp);
//     tmp[0] = pkt1[0][0] + dlugosc;
//     tmp[1] = pkt1[0][1];
//     tmp[2] = pkt1[0][2] + wysokosc;
//     pkt1.push_back(tmp);

//     pkt1.push_back(pkt1[0]);
//     pkt1.push_back(pkt1[1]);
//     ofstream plik;
//         plik.open(nazwa_pliku);
//     for(int i=0; i<(int)pkt1.size(); i++)
//     {
//         if(i%2==0)
//         plik<<endl;
//         plik<<pkt1[i]<<endl;
//     }
//     plik.close();
//     zapis();
// }




/*!
    \brief
    *Operator wyswietlania 
    dokonujemy wyswietlenia kolejnych punktow graniastoslupa
    *
    *  

*/

std::ostream &operator<<(std::ostream &Strm,
                         const Prostopadloscian &Pr)
{

    for (int i = 0; i < 8; i++)
    {
        Strm << Pr[i] << endl;
        if ((i + 1) % 2 == 0)
            Strm << endl;
    }

    return Strm;
}


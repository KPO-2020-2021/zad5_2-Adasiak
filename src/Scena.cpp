#include "Scena.hh"



// Scena::Scena(Vector<3> scr, double dlugosc, double szerokosc, double glebokosc )
// {
//     katOX = 0;
//     katOY = 0;
//     katOZ = 0;
//     Vector<3> tmp;
//     int m=0;
//     k=0;
//     for(int i=-dlugosc/2; i<=dlugosc/2; i+=10){
//        for(int j=-szerokosc/2; j<=szerokosc/2; j+=10){
//                 tmp[0]=i;
//                 tmp[1]=j;
//                 // if(m%2==0)
//                 tmp[2]=glebokosc;
//                 // else
//                 // tmp[2]=glebokosc+fala;

//                 scr1.push_back(tmp);
//                 m++;
//         }
//         k++;
//     }
//     ofstream plik;
//         plik.open(nazwa_pliku);
//     for(int i=0; i<(int)scr1.size(); i++){
//         if(i%k==0)
//         plik<<endl;
//         plik<<scr1[i]<<endl;
//     }
//     plik.close();
// }


/*!       
    \brief
    konstryktor sceny 
    tworzymy ja za pomoca bazowego punktu tymczasowego wzgledem ktorego dodajemy dlugosc i szerokosc
*/
Scena::Scena(double dlugosc, double szeroksc,double glebokosc, string nazwa_pliku, string nazwa_pliku_do_zapisu){
    this->nazwa_pliku = nazwa_pliku;
    this->nazwa_pliku_do_zapisu = nazwa_pliku_do_zapisu;
    katOX = 0;
    katOY = 0;
    katOZ = 0;
    Vector<3> tmp;
    int m=0;
    k=0;
    for(int i=-dlugosc/2; i<=dlugosc/2; i+=10){
       for(int j=-szeroksc/2; j<=szeroksc/2; j+=10){
                tmp[0]=i;
                tmp[1]=j;
                // if(m%2==0)
                tmp[2]=glebokosc;
                // else
                // tmp[2]=glebokosc+fala;

                scr1.push_back(tmp);
                m++;
        }
        k++;
    }
    ofstream plik;
        plik.open(nazwa_pliku);
    for(int i=0; i<(int)scr1.size(); i++){
        if(i%k==0)
        plik<<endl;
        plik<<scr1[i]<<endl;
    }
    plik.close();
}



/*!       
    \brief
    Funkcja sluzy do zapisu poszczegolnych punktow sceny do pliku
 */
void Scena::zapis()
{
    ofstream plik;
    plik.open(nazwa_pliku_do_zapisu);
    for(int i=0; i<(int)scr1.size(); i++)
    {
        if(i%k==0)
        plik<<endl;
        plik<<scr1[i]<<endl;
    }
    plik.close();
}

   
void Scena::move(const Vector<3> &v)
{
    for (int i = 0; i < (int)scr1.size(); i++)
    {
        scr1[i] = macierzobrotZ(katOZ)*(macierzobrotX(katOX)*(scr1[i]))+v;
    }
}

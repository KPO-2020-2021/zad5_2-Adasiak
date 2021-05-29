#include "BrylaGeometryczna.hh"






// void BrylaGeometryczna::move(const Vector<3> &v)
// {
//     for (int i = 0; i < (int)pkt1.size(); i++)
//     {
//         pkt1[i] = pkt1[i] + v;
//     }
// }



/*!       
    \brief
    move
    opdopwiada za translacje poszczegolnych punktow o zadany wektor
    w przypadku ustawienia wczesnijszego katow dla bryly posiada mozliwosc jednoczesnego obrotu
 */
void BrylaGeometryczna::move(const Vector<3> &v)
{
    for (int i = 0; i < (int)pkt1.size(); i++)
    {
        pkt1[i] = macierzobrotZ(katOZ)*(macierzobrotX(katOX)*(pkt1[i]))+v;
    }
}

/*mozna v zamienic z przesuniecie wtedy "bedzie kontakt z baza" */




/*!       
    \brief
    Funkcja sluzy do obrotu bryly wzgledem srodka ukladu wsplrzednych
 */

void BrylaGeometryczna::obrotOZ(double kat)
{
    // Vector<3> tmp;
    // tmp = (pkt1[1] - pkt1[0])/2 +tmp;
    // tmp = (pkt1[2] - pkt1[0])/2 +tmp; 

    for (int i = 0; i < (int)pkt1.size(); i++)
    {
        pkt1[i] = (macierzobrotZ(kat)*((pkt1[i] ))) ;
    }
}



/*!       
    \brief
    Funkcja sluzy do obrotu Prostopadloscianu wzgledem jego srodka

        kazdy punkt przesuwamy tak aby srodek prostopadloscian znajdowal sie w srodku ukladu wspolrzednych a nastepnie wykoujemy rotacje przez co otrzymujemy obrocona obyle wzgledem jej srodka 
 */

void BrylaGeometryczna::obrotP(double kat, Vector<3> a)
{
    Vector<3> tmp;
    tmp[0]=0;
    tmp[1]=0;
    tmp[2]=0;
    // tmp = (pkt1[1] - a)/2 +tmp ;
    // tmp = (pkt1[2]- a)/2 +tmp;
    double q=15,w=15;
    // q = 
    tmp[0] = (q + a[0]) /*+tmp*/ ;
    tmp[1] = (w + a[1]) /*+tmp*/; 
    
    // tmp[0]= 15;
    // tmp[1]= 15;

    for (int i = 0; i < (int)pkt1.size(); i++)
    {
        pkt1[i] = (macierzobrotZ(kat)*((pkt1[i] - tmp))) + tmp  ;
    }
}



/*!       
    \brief
    Funkcja sluzy do obrotu Graniastoslupa wzgledem jego srodka

    kazdy punkt przesuwamy tak aby srodek graniastoslupa znajdowal sie w srodku ukladu wspolrzednych a nastepnie wykoujemy rotacje przez co otrzymujemy obrocona obyle wzgledem jej srodka 
 */

void BrylaGeometryczna::obrotW(double kat)
{
    Vector<3> tmp;
    tmp= pkt1[0];
    for (int i = 0; i < (int)pkt1.size(); i++)
    {
        pkt1[i] = (macierzobrotZ(kat)*((pkt1[i] - tmp))) + tmp  ;
    }
}


void BrylaGeometryczna::obrotW1(double kat,Vector<3> b)
{
    // Vector<3> ujem;
    // ujem[0]=-1;
    // ujem[1]=-1;
    // ujem[2]=-1;
    // Vector<3> tmp;
    // tmp[0]+= 15;
    // tmp[1]+= 15;
    double z=15;
    Vector<3> tmp;
    tmp[0]=0;
    tmp[1]=0;
    tmp[2]=0;
    tmp[0] = (z + b[0]) /*+tmp*/ ;
    tmp[1] = (z + b[1]) /*+tmp*/; 
    for (int i = 0; i < (int)pkt1.size(); i++)
    {
        pkt1[i] = (macierzobrotZ(kat)*((pkt1[i] - tmp))) + tmp  ;
    }
}



/*!       
    \brief
    Funkcja sluzy do zapisu bryly geometrycznej
    zapisujemy kolejno wspolzedne kazdego z jej punktow
    
*/
void BrylaGeometryczna::zapis(){
    ofstream plik;
    plik.open(nazwa_pliku_do_zapisu);
    for(int i=0; i<(int)pkt1.size(); i++)
    {
        if(i%2==0)
        plik<<endl;
        plik<<pkt1[i]<<endl;//robie enter co 2 linie
    }
    plik.close();
}

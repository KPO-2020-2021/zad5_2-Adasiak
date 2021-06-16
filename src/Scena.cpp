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


void Scena::add_basic_objects(PzG::LaczeDoGNUPlota &Lacze, Vector<3> place, double xwth, double ywth,int k,int rodzaj)
{   
    Vector<3> pomocniczyprzeszkoda;
       pomocniczyprzeszkoda[0]=-50;
       pomocniczyprzeszkoda[1]=-50;
    // int przeszk1=1,maselko=2;
    /*std::*/list<shared_ptr<Przeszkody> > p; /*= std::*p.make_shared<Ostroslup> (pomocniczyprzeszkoda, 50,50,90,"..datasets/prze"+to_string(przeszk1)+".dat","..datasets/prze2"+to_string(maselko)+".dat");*/
    // double tab1[3] = {20, 30, 15};
    // Vector<3> vec(tab1);
    // int k=0;
    // list<shared_ptr<Gran> > g;
    // list<shared_ptr<Prostopadloscian> > p;
    if(k==1)
    {
        std::cout<<"madam"<<std::endl;
        // (*--p.end())->zapis();
        // std::cout<<"troche"<<std::endl;
        // Lacze.DodajNazwePliku( (*--p.end())->nazwa().c_str());
        // std::cout<<"plastikowy"<<std::endl;
        // Lacze.UsunOstatniaNazwe();
        Scena::nr = Scena::nr - 1;
        // std::ostream << p;
        // std::cout<<"kalinka"<<std::endl;
        //  for(list<shared_ptr<Przeszkody> >::iterator i=p.begin(); i!= p.end(); i++)
        // {

        //         std::cout<<"kasia lubi koty "<<std::endl;
        //         (*--i)->zapis();
        //         std::cout<<"marcin lubi kasie  "<<std::endl;
        //                 // Lacze.UsunOstatniaNazwe();
        //                 // Lacze.DodajNazwePliku( (*--p.end())->nazwa().c_str());
        //                 std::cout<<"tomek lubi marcina <3 "<<std::endl;
        // }
        // list<shared_ptr<Przeszkody> >::iterator i = p.end();
        // p.erase(--i,p.end());
        
        // (*--p.end())->zapis();
        // std::cout<<"Malinka"<<std::endl;
        //   (*p.end())->zapis();

        // std::cout<<"placek"<<std::endl;
        // Lacze.DodajNazwePliku( (*p.end())->nazwa().c_str());
        // std::cout<<"kalinka"<<std::endl;
    }
    else
    {
        if(rodzaj==1){
        /*(*p) =*/ p.push_back(make_shared<Ostroslup>(place, xwth,ywth,100,  "../datasets/pyramid_default_sample"+to_string(Scena::nr)+".dat", "../datasets/pyramid_default_final"+to_string(Scena::nr)+".dat"));
        }
        if(rodzaj==2){
        /*(*p) =*/ p.push_back(make_shared<Gran>(place, xwth,ywth,100,  "../datasets/gran_default_sample"+to_string(Scena::nr)+".dat", "../datasets/gran_default_final"+to_string(Scena::nr)+".dat"));
        }
        if(rodzaj==3){
        /*(*p) =*/ p.push_back(make_shared<PPlaskowyz>(place, xwth,ywth,50,  "../datasets/pplaskowyz_default_sample"+to_string(Scena::nr)+".dat", "../datasets/pplaskowyz_default_final"+to_string(Scena::nr)+".dat"));
        }




        Scena::nr = Scena::nr + 1;
        // double tab[3] = {100, 100, 7.5};
        // Vector<3> tran(tab);
        // *p = p->translation(tran);
        //  p->zapis();
        //  Lacze.DodajNazwePliku((p)->nazwa().c_str());
        
        for(list<shared_ptr<Przeszkody> >::iterator i=p.begin(); i!= p.end(); i++)
        {
                //    (*i)->set_katOY(0);
                //  (*i)->set_katOZ(rand()%360);
                //  Vector<3> wek;
                //  wek[0]=rand()%20+20;
        //       (*i)->set_Przesuniecie(wek);
                //  (*i)->translacja();
                // std::cout<<"kasia lubi koty "<<std::endl;
                (*i)->zapis();
                // std::cout<<"marcin lubi kasie  "<<std::endl;
                        Lacze.DodajNazwePliku((*i)->nazwa().c_str());
                        // std::cout<<"tomek lubi marcina <3 "<<std::endl;
        }
    
    }

}
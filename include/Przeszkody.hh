#pragma once 

#include "vector.hh"
#include <vector>
#include  <string>
#include <memory>
#include <unistd.h>
#include <list>
#include <iomanip>


class Przeszkody 
{

public:
    virtual std::string get_nazwa() const=0;
    virtual void zapis()=0;
    virtual Vector<3> wez_srodek() =0 ;
    virtual double promien()=0;
};


#ifndef OOP_CINEMA_H
#define OOP_CINEMA_H
#include "Persoana.h"
#include "Film.h"

class Cinema{
private:
    std::string nume_cinema;
public:
    Cinema(){
        this->nume_cinema="";
    }

    explicit Cinema(std::string nume){  //const parametrizat
        this->nume_cinema=std::move(nume);
    }

    Cinema& operator=(const Cinema& c2){  //operator copiere
        if(this==&c2)
        {
            return *this;
        }
        else
        {
            this->nume_cinema=c2.nume_cinema;
            return *this;
        }
    }
    Cinema(const Cinema &t):Cinema(t.nume_cinema){} //constructor de copiere
    ~Cinema()= default;  //destructor
    //supraincarcare operatori afisare,citire
    friend std::istream& operator>>(std::istream &is, Cinema &t){
        std::cout<<"Alegeti numele cinema-ului:";
        is>>t.nume_cinema;
        while(true) {
            if (t.nume_cinema == "AFI" || t.nume_cinema == "Plaza" || t.nume_cinema == "MegaMall" ||
                t.nume_cinema == "Baneasa")
                return is;
            else{
                std::cout<<"Numele acestui cinema nu exista:"<<std::endl;
                std::cout<<"Alegeti numele cinema-ului:";
                is>>t.nume_cinema;
                std::cout<<std::endl;
            }
        }
    }
    friend std::ostream &operator<<(std::ostream &os,const Cinema &t){
        os<<"Numele cinema-ului este:"<<t.nume_cinema<<std::endl;
        os<<std::endl;
        return os;
    }
    friend void afisare_cinema(const Cinema& cinema);
};

#endif //OOP_CINEMA_H

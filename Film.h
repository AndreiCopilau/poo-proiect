#ifndef OOP_FILM_H
#define OOP_FILM_H
#include "Cinema.h"
#include "Persoana.h"
#include <memory>

class Prototype{
public:
    [[maybe_unused]] [[nodiscard]] virtual Prototype* clone() const = 0;
    virtual ~Prototype() = default;
};

class Persoana;

class Film{
private:
    int nr_film;
    std::string nume_film;
    std::vector<int> sali;
public:
    Film():sali(50,0){
        this->nr_film=0;
        this->nume_film="";
    }

    [[maybe_unused]] Film(const int &nr_film, std::string nume_film) : nr_film(nr_film), nume_film(std::move(nume_film))
    {
    }
    void alegere_film(){  //sali 1,2,3,4,...
        std::cout<<"Alegeti numarul filmului dorit:"<<std::endl;
        std::cout<<"1-Dune"<<std::endl;
        std::cout<<"2-Star-Wars part I"<<std::endl;
        std::cout<<"3-Forrest Gump"<<std::endl;
        std::cout<<"4-Top Gun"<<std::endl;
        std::cout<<"5-Shutter Island"<<std::endl;
        std::cout<<"6-Se7en"<<std::endl;
        std::cin>>nr_film;
        switch (nr_film) {
            case 1: {
                std::cout << "Ati ales filmul 'Dune'." << std::endl;
                nume_film = "Dune";
                break;
            }
            case 2: {
                std::cout << "Ati ales filmul 'Star-Wars part I'." << std::endl;
                nume_film = "Star-Wars part I";
                break;
            }
            case 3: {
                std::cout << "Ati ales filmul 'Forrest Gump'." << std::endl;
                nume_film="Forest Gump";
                break;
            }
            case 4: {
                std::cout << "Ati ales filmul 'Top Gun'." << std::endl;
                nume_film="Top Gun";
                break;
            }
            case 5: {
                std::cout << "Ati ales filmul 'Shutter Island'." << std::endl;
                nume_film="Shutter Island";
                break;
            }
            case 6: {
                std::cout << "Ati ales filmul 'Se7en'." << std::endl;
                nume_film="Se7en";
                break;
            }
        }
        if(nr_film==1 || nr_film==2)
            std::cout<<"Aveti sala-1."<<std::endl;
        else if(nr_film==3 || nr_film==4)
            std::cout<<"Aveti sala-2."<<std::endl;
        else if(nr_film==5 || nr_film==6)
            std::cout<<"Aveti sala-3."<<std::endl;
        std::cout<<std::endl;
    }
    friend void stocare_bilete(const Persoana& p, Film& f);
    virtual ~Film(){
        nr_film=0;
        nume_film="";
    }

    friend void afisare_film(const Film& film);

    [[nodiscard]] Prototype* clone() const {
        return reinterpret_cast<Prototype *>(new Film(*this));
    }
};

#endif //OOP_FILM_H

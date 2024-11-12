#ifndef OOP_PERSOANA_H
#define OOP_PERSOANA_H
#include <iostream>
#include <string>
#include "Film.h"
#include "Cinema.h"
#include <map>

class Persoana{
private:
    std::string nume_persoana;
    int nr_bilete=0;
    int max_bilete=0;
    int copie=0;
    int da_nu=0;
    static const int nrtotal_bilete=50;

public:
    Persoana()=default;
    explicit Persoana(const int &bilete_max){
        this->max_bilete=bilete_max;
    }
    virtual void introducere_nume(){
        std::cout<<"Cate bilete doriti?"<<std::endl;
        std::cin>>nr_bilete;
        std::map<int, std::string> mapare;  //al doilea container utilizat
        copie=nr_bilete;
        if(copie>1 && copie<=10) {
            std::cout<<"Introduceti numele persoanelor:";
            while(copie!=0){
                std::cin>>nume_persoana;
                mapare[nr_bilete]=nume_persoana;
                copie-=1;
            }
            for(const auto& x : mapare)
                std::cout<<x.first<<" bilete- "<<x.second<<std::endl;
        }
        else if(copie==1)
        {
            std::cout<<"Introduceti numele persoanei:";
            std::cin>>nume_persoana;
            mapare[nr_bilete]=nume_persoana;
//            for(const auto& x : mapare)
//                std::cout<<x.first<<" bilete- "<<x.second<<std::endl;
        }
        else if(copie>10) {
            std::cout<<"Ati selectat prea multe bilete. Puteti selecta maximum 10 bilete pentru o rezervare."<<std::endl;
            std::cout<<"Doriti sa rezervati 10 de bilete?"<<std::endl;
            std::cout<<"1-Da."<<std::endl;
            std::cout<<"2-Nu, aleg alt numar de bilete."<<std::endl;
            std::cin>>da_nu;
            switch (da_nu){
                case 1:
                    nr_bilete=10;
                    copie=nr_bilete;
                    std::cout<<"Introduceti numele persoanelor:";
                    while(copie!=0){
                        std::cin>>nume_persoana;
                        mapare[nr_bilete]=nume_persoana;
                        copie-=1;
                    }
//                    for(const auto& x : mapare)
//                        std::cout<<x.first<<" bilete- "<<x.second<<std::endl;
                    break;
                case 2:
                    std::cout<<"Cate bilete doriti?:"<<std::endl;
                    std::cin>>nr_bilete;
                    copie=nr_bilete;
                    std::cout<<"Introduceti numele persoanelor:";
                    while(copie!=0){
                        std::cin>>nume_persoana;
                        mapare[nr_bilete]=nume_persoana;
                        copie-=1;
                    }

//                    for(const auto& x : mapare)
//                        std::cout<<x.first<<" bilete - "<<x.second<<std::endl;
                    break;
            }
        }
    }

    bool operator<(const Persoana& altapers) const{
        return nr_bilete<altapers.max_bilete;
    }

    friend int operator-(const Persoana& altebilete1, const Persoana& altebilete2);

    friend void stocare_bilete(const Persoana& p, Film& f);

    ~Persoana()=default;

    friend void afisare_bilete(const Persoana& pers);

    virtual void afisare_adult(){
        std::cout<<"este adult."<<std::endl;
    }

    virtual void afisare_copil(){
        std::cout<<"este copil."<<std::endl;
    }

    virtual void afisare_detalii() const{};

};

class Adult : public Persoana{
private:
    std::string tip;
public:
    [[maybe_unused]] Adult(std::string tip, const int &max_bilete) : Persoana(max_bilete), tip(std::move(tip))
    {
    }

    Adult()= default;

    Adult(const Adult &aux) : Persoana(aux)  //constructor de copiere
    {
        this->tip=aux.tip;
    }

    void afisare_adult() override{
        std::cout<<"Sunteti incadrat in sectiunea pentru adulti."<<std::endl;
    }

    void afisare_detalii() const override
    {
        std::cout<<"Detalii despre persoana care face rezervarea:"<<std::endl;
    }

    virtual ~Adult()= default;
};

class Copil : public Persoana{
private:
    std::string ani;
public:
    [[maybe_unused]] Copil(std::string ani, const int &max_bilete) : Persoana(max_bilete), ani(std::move(ani))
    {
    }

    Copil()=default;

    Copil(const Copil &aux) : Persoana(aux)  //constructor de copiere
    {
        this->ani=aux.ani;
    }

    void afisare_copil() override{
        std::cout<<"Sunteti incadrat in sectiunea pentru copii."<<std::endl;
    }

    void afisare_detalii() const override
    {
        std::cout<<"Detalii despre persoana care face rezervarea: "<<std::endl;
    }

    virtual ~Copil()=default;
};

#endif //OOP_PERSOANA_H

#ifndef OOP_BILET_H
#define OOP_BILET_H
#include <iostream>

template <typename /*T*/>
class Bilet{
private:
    std::string tip;
public:
    Bilet() = default;

    virtual void pret_bilet(){
        std::cout<<"Detalii pret:";
    }
};

template <typename T>
class Mic : public Bilet<T>{
public:
    void pret_bilet() override{
        std::cout<<"Pretul biletului este de 20 lei."<<std::endl;
        std::cout<<std::endl;
    }
};

template <typename T>
class Mare : public Bilet<T>{
public:
    void pret_bilet() override{
        std::cout<<"Pretul biletului este de 30 lei."<<std::endl;
        std::cout<<std::endl;
    }
};

#endif //OOP_BILET_H

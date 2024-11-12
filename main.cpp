#include <iostream>
#include <string>
#include <vector>
#include "Persoana.h"
#include "Film.h"
#include "Cinema.h"
#include "Bilet.h"
#include <list>
using namespace std;

//class Persoana;

/*class Cinema{
private:
    string nume_cinema;
public:
    Cinema(){
        this->nume_cinema="";
    }

    explicit Cinema(string nume){  //const parametrizat
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
    Cinema(const Cinema &t):Cinema(t.nume_cinema){} //cosntructor de copiere
    ~Cinema()= default;  //destructor
    //operatori afisare/citire
    friend istream &operator>>(istream &is, Cinema &t){
        cout<<"Alegeti numele cinema-ului:";
        is>>t.nume_cinema;
        while(true) {
            if (t.nume_cinema == "AFI" || t.nume_cinema == "Plaza" || t.nume_cinema == "MegaMall" ||
                t.nume_cinema == "Baneasa")
                return is;
            else{
                cout<<"Numele acestui cinema nu exista:"<<endl;
                cout<<"Alegeti numele cinema-ului:";
                is>>t.nume_cinema;
                cout<<endl;
            }
        }
    }
    friend ostream &operator<<(ostream &os,const Cinema &t){
        os<<"Numele cinema-ului este:"<<t.nume_cinema<<endl;
        os<<endl;
        return os;
    }
    friend void afisare_cinema(const Cinema& cinema);
};*/



/*class Film{
private:
    int nr_film;
    string nume_film;
    vector<int> sali;
public:
    Film(){
        this->nr_film=0;
        this->nume_film="";
    }

    [[maybe_unused]] Film(const int &nr_film, string nume_film) : nr_film(nr_film), nume_film(std::move(nume_film))
    {
    }
    void alegere_film(){  //sali 1,2,3,4,...
        cout<<"Alegeti numarul filmului dorit:"<<endl;
        cout<<"1-Dune"<<endl;
        cout<<"2-Star-Wars part I"<<endl;
        cout<<"3-Forrest Gump"<<endl;
        cout<<"4-Top Gun"<<endl;
        cout<<"5-Shutter Island"<<endl;
        cout<<"6-Se7en"<<endl;
        cin>>nr_film;
        switch (nr_film) {
            case 1: {
                cout << "Ati ales filmul 'Dune'." << endl;
                nume_film = "Dune";
                break;
            }
            case 2: {
                cout << "Ati ales filmul 'Star-Wars part I'." << endl;
                nume_film = "Star-Wars part I";
                break;
            }
            case 3: {
                cout << "Ati ales filmul 'Forrest Gump'." << endl;
                nume_film="Forest Gump";
                break;
            }
            case 4: {
                cout << "Ati ales filmul 'Top Gun'." << endl;
                nume_film="Top Gun";
                break;
            }
            case 5: {
                cout << "Ati ales filmul 'Shutter Island'." << endl;
                nume_film="Shutter Island";
                break;
            }
            case 6: {
                cout << "Ati ales filmul 'Se7en'." << endl;
                nume_film="Se7en";
                break;
            }
        }
        if(nr_film==1 || nr_film==2)
            cout<<"Aveti sala-1."<<endl;
        else if(nr_film==3 || nr_film==4)
            cout<<"Aveti sala-2."<<endl;
        else if(nr_film==5 || nr_film==6)
            cout<<"Aveti sala-3."<<endl;
        cout<<endl;
    }
    friend void stocare_bilete(const Persoana& p, Film& f);
    virtual ~Film(){
        nr_film=0;
        nume_film="";
    }

    friend void afisare_film(const Film& film);
};*/



/*class Persoana{
private:
    string nume_persoana;
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
        cout<<"Cate bilete doriti?"<<endl;
        cin>>nr_bilete;
        copie=nr_bilete;
        if(copie>1 && copie<=10) {
            cout<<"Introduceti numele persoanelor:";
            while(copie!=0){
                cin>>nume_persoana;
                copie-=1;
            }
        }
        else if(copie==1)
        {
            cout<<"Introduceti numele persoanei:";
            cin>>nume_persoana;
        }
        else if(copie>10) {
            cout<<"Ati selectat prea multe bilete. Puteti selecta maximum 10 bilete pentru o rezervare."<<endl;
            cout<<"Doriti sa rezervati 10 de bilete?"<<endl;
            cout<<"1-Da."<<endl;
            cout<<"2-Nu, aleg alt numar de bilete."<<endl;
            cin>>da_nu;
            switch (da_nu){
                case 1:
                    nr_bilete=10;
                    copie=nr_bilete;
                    cout<<"Introduceti numele persoanelor:";
                    while(copie!=0){
                        cin>>nume_persoana;
                        copie-=1;
                    }
                    break;
                case 2:
                    cout<<"Cate bilete doriti?:"<<endl;
                    cin>>nr_bilete;
                    copie=nr_bilete;
                    cout<<"Introduceti numele persoanelor:";
                    while(copie!=0){
                        cin>>nume_persoana;
                        copie-=1;
                    }
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
        cout<<"este adult."<<endl;
    }

    virtual void afisare_copil(){
        cout<<"este copil."<<endl;
    }

    virtual void afisare_detalii() const{};

};

class Adult : public Persoana{
private:
    string tip;
public:
    [[maybe_unused]] Adult(string tip, const int &max_bilete) : Persoana(max_bilete), tip(std::move(tip))
    {
    }

    Adult()= default;

    Adult(const Adult &aux) : Persoana(aux)  //constructor de copiere
    {
        this->tip=aux.tip;
    }

    void afisare_adult() override{
        cout<<"Sunteti incadrat in sectiunea pentru adulti."<<endl;
        cout<<endl;
    }

    void afisare_detalii() const override
    {
        cout<<"Detalii despre persoana care face rezervarea:"<<endl;
    }

    virtual ~Adult()= default;
};

class Copil : public Persoana{
private:
    string ani;
public:
    [[maybe_unused]] Copil(string ani, const int &max_bilete) : Persoana(max_bilete), ani(std::move(ani))
    {
    }

    Copil()=default;

    Copil(const Copil &aux) : Persoana(aux)  //constructor de copiere
    {
        this->ani=aux.ani;
    }

    void afisare_copil() override{
        cout<<"Sunteti incadrat in sectiunea pentru copii."<<endl;
        cout<<endl;
    }

    void afisare_detalii() const override
    {
        cout<<"Detalii despre persoana care face rezervarea: "<<endl;
    }

    virtual ~Copil()=default;
};*/



void introducere(){
    cout<<"          Buna ziua!         "<<endl;
    cout<<"      Pagina de pornire";
    cout<<endl;
}

void alegere_cinema(){
    cout<<"Alegeti cinema-ul:"<<endl;
    cout<<"-AFI-"<<endl;
    cout<<"-Plaza-"<<endl;
    cout<<"-MegaMall-"<<endl;
    cout<<"-Baneasa-"<<endl;
    cout<<endl;
}

int operator-(const Persoana&, const Persoana& altebilete2){
    return Persoana::nrtotal_bilete-altebilete2.nr_bilete;
}

void stocare_bilete(const Persoana& p, Film& f){
    if((unsigned long long)p.nr_bilete<=f.sali.size()){
        for (int i = 1; i <= p.nr_bilete; ++i)
            f.sali[i] = 1;
        cout<<"Biletele au fost rezervate cu succes!"<<endl;
    }
    else
        cout<<"Nu sunt suficiente locuri disponibile pentru a rezerva biletele."<<endl;

    /*for (int i = 1; i <= p.nr_bilete; ++i)
            cout<<i<<" - "<<f.sali[i]<<" "<<endl;*/
}

void rezervare(){
    cout<<"                           REZERVARE:                             "<<endl;
    cout<<"--acesta este un mesaj de confirmare al rezervarii dumneavoastra--"<<endl;
}
void afisare_cinema(const Cinema& cinema){
    cout<<"~Numele cinema-ului:"<<cinema.nume_cinema<<endl;
}
void afisare_film(const Film& film){
    cout<<"~Numele filmului:"<<film.nume_film<<endl;
}
void afisare_bilete(const Persoana& pers){
    cout<<"~Numarul de bilete rezervate:"<<pers.nr_bilete<<endl;
}

/*void afisare_detalii_2(const Persoana &persoana){  //downcasting
    persoana.afisare_detalii();
}*/

void display_lista(const list<string>& l){
    for(const string& x : l){
        std::cout<<x<<" ";
        std::cout<<std::endl;
    }

}

void meniu(){
    bool exit = false;
    while(!exit) {
        cout << "Alegeti ce operatiune doriti sa realizati:" << endl;
        cout << "1-Vizualizare cinema-uri." << endl;
        cout << "2-Vizualizare filme." << endl;
        cout << "3-Alegere bilete." << endl;
        cout << "4-Iesire." << endl;
        int bt_meniu;
        int alegere;
        list<string >lista;  //primul container utilizat
        lista.emplace_back("-AFI-");
        lista.emplace_back("-Plaza-");
        lista.emplace_back("-MegaMall-");
        lista.emplace_back("-Baneasa-");
        cin >> bt_meniu;
        switch (bt_meniu) {
            default:
                cout<<"Nu exista aceasta optiune."<<endl;
                break;
            case 4:
                exit=true;
                break;
            case 1:
                display_lista(lista);
//                cout << "-AFI-" << endl;
//                cout << "-Plaza-" << endl;
//                cout << "-MegaMall-" << endl;
//                cout << "-Baneasa-" << endl;
                cout << endl;
                cout << "Doresti sa realizezi alta operatiune?" << endl;
                cout << "1-Da" << endl;
                cout << "2-Nu" << endl;
                cin >> alegere;
                if (alegere == 1)
                    continue;
                    //meniu();
                else {
                    exit = true;
                    break;
                }

            case 2:
                cout << "-Dune-" << endl;
                cout << "-Star-Wars part I-" << endl;
                cout << "-Forrest Gump-" << endl;
                cout << "-Top Gun-" << endl;
                cout << "-Shutter Island-" << endl;
                cout << "-Se7en-" << endl;
                cout << endl;
                cout << "Doresti sa realizezi alta operatiune?" << endl;
                cout << "1-Da" << endl;
                cout << "2-Nu" << endl;
                cin >> alegere;
                if (alegere == 1)
                    //meniu();
                    continue;
                else {
                    exit = true;
                    break;
                }

            case 3:
                Cinema c;
                Cinema c2;
                Persoana p;
                alegere_cinema();
                cin >> c;
                c2 = c;
                cout << c2;
                Film f;
                std::unique_ptr<Prototype> filmClone(f.clone());  //Prototype

                int varsta;
                cout << "Introduceti varsta:";
                cin >> varsta;
                Adult adult;
                Persoana *up1 = &adult;  //upcasting
                Persoana *pa = &adult;  //downcasting
                auto *aa = dynamic_cast<Adult *>(pa);  //asa da
                Bilet<int>* b1 = new Mare<int>();  //clasa template
                //aa = dynamic_cast<Adult *>(&p);  --nu e bine

                Copil copil;
                Persoana *up2 = &copil;  //upcasting
                Persoana *pc = &copil;  //downcasting
                auto *cc = dynamic_cast<Copil *>(pc);  //asa da
                Bilet<int>* b2 = new Mic<int>();  //clasa template
                //cc = dynamic_cast<Copil *>(&p);  ----nu e bine
                if (varsta > 18) {
                    up1->afisare_detalii();
                    up1->afisare_adult();  //upcasting
                    aa->afisare_adult();  //downcasting
                    b1->pret_bilet();
                    std::cout << "RTTI: " << typeid(*b1).name() << std::endl;
                    std::cout<<std::endl;
                    delete b1;
                } else {
                    up2->afisare_detalii();
                    up2->afisare_copil();  //upcasting
                    cc->afisare_copil();  //downcasting
                    b2->pret_bilet();
                    std::cout << "RTTI: " << typeid(*b2).name() << std::endl;
                    std::cout<<std::endl;
                    delete b2;
                }
                //cin >> *p1;
                f.alegere_film();
                p.introducere_nume();
                Persoana p2(50);
                if (p < p2) {
                    int bilete_disp = p2 - p;
                    cout << "Numarul de bilete selectate este mai mic decat numarul maxim de bilete al salii." << endl;
                    cout << "Bilete disponibile:" << bilete_disp << endl;
                } else
                    cout << "Nr de bilete selectate depaseste capacitatea salii." << endl;
                stocare_bilete(p, f);
                rezervare();
                afisare_cinema(c);
                afisare_film(f);
                afisare_bilete(p);
                exit=true;
                break;
                //optiune pentru citire si afisare a n obiecte
                //meniu();
        }
    }
}

int main()
{
    introducere();
    meniu();
    return 0;
}


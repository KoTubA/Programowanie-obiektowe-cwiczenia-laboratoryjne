#include <iostream>
#include <math.h>

class Stanowisko {
public:
    virtual void przyznaj_bonus(double kwota) = 0;
};

class Pracownik: public Stanowisko {
    double pensja;
public:
    Pracownik(double p=5000):pensja(p) {
        std::cout << "Konstruktor Pracownik\n";
    };

    void przyznaj_bonus(double kwota) {
        if(kwota<=pensja/2) {
            std::cout << "Przyznany bonus dla pracownika wynosi: "<<kwota<<std::endl;
        }
        else {
            std::cout << "Odmowa przyznania bonusa (zbyt wysoka cena)"<<std::endl;
        }
    };
};

class Stazysta: public Stanowisko {
    double pensja;
    int czas_stazu;
public:
    Stazysta(double p=2000, int c=1):pensja(p), czas_stazu(c) {
        std::cout << "Konstruktor Stazysta\n";
    };

    void przyznaj_bonus(double kwota) {
        if(kwota<=pensja/2 && czas_stazu>=6) {
            std::cout << "Przyznany bonus dla stazysty wynosi: "<<kwota<<std::endl;
        }
        else {
            std::cout << "Odmowa przyznania bonusa (zbyt wysoka cena lub dlugosc stazu)"<<std::endl;
        }
    };
};

class Kierownik: public Stanowisko {
    double pensja;
    int liczba_podwladnych;
public:
    Kierownik(double p=2000, int l=2):pensja(p), liczba_podwladnych(l) {
        std::cout << "Konstruktor Stazysta\n";
    };

    void przyznaj_bonus(double kwota) {
        if(kwota<=pensja) {
            kwota = kwota + 50*liczba_podwladnych;
            std::cout << "Przyznany bonus dla kierownika wynosi: "<<kwota<<std::endl;
        }
        else {
            std::cout << "Odmowa przyznania bonusa (zbyt wysoka cena)"<<std::endl;
        }
    };
};


int main() {
    Pracownik pracownik;
    Stazysta stazysta;
    Kierownik kierownik;
    Stanowisko *stanowisko = &pracownik;
    stanowisko->przyznaj_bonus(500);
    stanowisko = &stazysta;
    stanowisko->przyznaj_bonus(1000);
    stanowisko = &kierownik;
    stanowisko->przyznaj_bonus(2000);

    return 0;
}

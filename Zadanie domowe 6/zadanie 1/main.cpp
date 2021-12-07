#include <iostream>
#include <fstream>

class Obiekt {
public:
    virtual void zapisz_do_pliku(std::fstream &file) = 0;
};

class Pracownik: public Obiekt {
    double pensja;
public:
    Pracownik(double p=5000):pensja(p) {
        std::cout << "Konstruktor Pracownik\n";
    };

    ~Pracownik() {
        std::cout << "Destruktor Pracownik\n";
    };

    void przyznaj_bonus(double kwota) {
        if(kwota<=pensja/2) {
            std::cout << "Przyznany bonus dla pracownika wynosi: "<<kwota<<std::endl;
        }
        else {
            std::cout << "Odmowa przyznania bonusa (zbyt wysoka cena)"<<std::endl;
        }
    };

    void zapisz_do_pliku(std::fstream &file) {
        file << "Klasa Pracownik:" << std::endl;
        file << "Pensja: " << pensja << std::endl;
    }
};

class Prostokat: public Obiekt {
private:
    double a, b;

public:
    Prostokat(double a=6, double b=7):a(a), b(b) {
        std::cout << "Konstruktor Prostokat\n";
    };

    ~Prostokat() {
        std::cout << "Destruktor Prostokat\n";
    };

    double oblicz_pole() {
        return a*b;
    };

    void zapisz_do_pliku(std::fstream &file) {
        file << "Klasa Prostokat:" << std::endl;;
        file << "Pole: " << this->oblicz_pole() << std::endl;;
    }
};


int main() {
    std::fstream file;
    file.open("../plik.txt", std::ios::out);
    if (file.is_open()) {
        Prostokat prostokat;
        Pracownik pracownik;
        prostokat.zapisz_do_pliku(file);
        pracownik.zapisz_do_pliku(file);
        std::cout<<"Poprawnie zapisano dane"<<std::endl;
        file.close();
    }
    else {
        std::cout<<"Blad otwarcia pliku"<<std::endl;
    }
    return 0;
}

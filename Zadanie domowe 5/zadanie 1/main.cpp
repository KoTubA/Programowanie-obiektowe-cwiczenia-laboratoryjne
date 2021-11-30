#include <iostream>
#include <math.h>

class Wielokat {
public:
    virtual double oblicz_pole() = 0;
};

class Trojkat: public Wielokat {
private:
    double a, b, c;

public:
    Trojkat(double a=3, double b=4, double c=5):a(a), b(b), c(c) {
        std::cout << "Konstruktor Trojkat\n";
    };

    ~Trojkat() {
        std::cout << "Destruktor Trojkat\n";
    };

    double oblicz_pole() {
        double p = 0.5*(a+b+c);
        double pole = sqrt(p*(p-a)*(p-b)*(p-c));
        return pole;
    };
};

class Prostokat: public Wielokat {
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
};

class Kwadrat: public Wielokat {
private:
    double a;

public:
    Kwadrat(double a=8):a(a) {
        std::cout << "Konstruktor Kwadrat\n";
    };

    ~Kwadrat() {
        std::cout << "Destruktor Kwadrat\n";
    };

    double oblicz_pole() {
        return a*a;
    };
};


double oblicz_pola(Wielokat *figury[], int size) {
    double suma_pol;
    for (int i = 0; i < size; i++) {
        suma_pol += figury[i]->oblicz_pole();
    }
    return suma_pol;
};


int main() {
    Wielokat *figury[3];
    figury[0] = new Trojkat;
    figury[1] = new Prostokat;
    figury[2] = new Kwadrat;

    std::cout << "Suma wszytskich figur wynosi: " << oblicz_pola(figury,sizeof(figury)/sizeof (figury[0])) << std::endl;

    return 0;
}

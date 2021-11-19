#include <iostream>
#include <math.h>

class Wielokat {
public:
    double oblicz_pole() {
        return 0;
    };
};

class Trojkat: public Wielokat {
private:
    double a, b, c;

public:
    Trojkat(double a, double b, double c):a(a), b(b), c(c) {
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
    Prostokat(double a, double b):a(a), b(b) {
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
    Kwadrat(double a):a(a) {
        std::cout << "Konstruktor Kwadrat\n";
    };

    ~Kwadrat() {
        std::cout << "Destruktor Kwadrat\n";
    };

    double oblicz_pole() {
        return a*a;
    };
};


int main() {

    Trojkat figura1(3,4,5);
    Prostokat figura2(6,7);
    Kwadrat figura3(8);
    std::cout << "Pole trojkata wynosi: "<<figura1.oblicz_pole()<<std::endl;
    std::cout << "Pole prostokata wynosi: "<<figura2.oblicz_pole()<<std::endl;
    std::cout << "Pole kwadratu wynosi: "<<figura3.oblicz_pole()<<std::endl;
    return 0;
}

#include <iostream>

using namespace std;

class Fraction {
public:
    int a;
    int b;
    double dvalue;

    Fraction(int ap, int bp): a(ap), b(bp) {
        dvalue = (double)ap/bp;
    };

    Fraction&operator=(Fraction &drugi) {
        if (this == &drugi)
            return *this;

        this->a = drugi.a;
        this->b = drugi.b;
        this->dvalue = drugi.dvalue;
        return *this;
    }

    friend std::ostream & operator<<(std::ostream &, Fraction &);
    friend std::istream & operator>>(std::istream &, Fraction &);
};

std::ostream & operator<<(std::ostream & wyjscie, Fraction  &x) {
    wyjscie << "Zawartosc obiektu:\na: " << x.a << endl << "b: " << x.b << endl << "dvalue: " << x.dvalue;
    return wyjscie;
}

std::istream & operator>>(std::istream & wejscie, Fraction  &x) {
    std::cout << "Licznik: ";
    wejscie >> x.a;
    std::cout << "Mianownik: ";
    wejscie >> x.b;
    x.dvalue = x.a / x.b;
    return wejscie;
}

int main()
{
    Fraction x1(1,3);
    Fraction x2(1,2);

    x1 = x2;
    cin >> x2;
    cout << x2 << endl;

    return 0;
}
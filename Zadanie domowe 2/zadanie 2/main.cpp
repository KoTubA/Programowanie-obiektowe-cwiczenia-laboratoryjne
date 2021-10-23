#include <iostream>

using namespace std;

class Fraction {
    public:
        int a;
        int b;
        double dvalue;

    Fraction(int ap, int bp): a(ap), b(bp)
    {
        dvalue = (double)ap/bp;
    };
};

void swap(Fraction &X1, Fraction &X2) {
    int tempA = X1.a;
    int tempB = X1.b;
    double tempDvalue = X1.dvalue;

    X1.a = X2.a;
    X1.b = X2.b;
    X1.dvalue = X2.dvalue;
    X2.a = tempA;
    X2.b = tempB;
    X2.dvalue = tempDvalue;

}

int main()
{
    Fraction x1(1,3);
    Fraction x2(1,2);

    swap(x1,x2);
    cout << "x1.a = " << x1.a << endl;
    cout << "x1.b = " << x1.b << endl;
    cout << "x1.dvalue = " << x1.dvalue << endl;
    cout << "x2.a = " << x2.a << endl;
    cout << "x2.b = " << x2.b << endl;
    cout << "x2.dvalue = " << x2.dvalue << endl;

    return 0;
}
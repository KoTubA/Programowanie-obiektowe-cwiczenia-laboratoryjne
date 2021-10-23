#include <iostream>

using namespace std;

class ComplexNumber {
    public:
        int a;
        int b;

    ComplexNumber(int ap = 1, int bp = 2)
    {
        a = ap;
        b = bp;
    };

    ComplexNumber(const ComplexNumber & X1)
    {
        a = X1.a;
        b = X1.b;
    };

    void print() {
        cout << a << ((b > 0) ? "+" : "") << b << "i" << endl;
    }

    void add(ComplexNumber &X1) {
        cout << a+X1.a << ((b+X1.b > 0) ? "+" : "") << b+X1.b << "i" << endl;
    }

    void subtract(ComplexNumber &X1) {
        cout << a-X1.a << ((b-X1.b > 0) ? "+" : "") << b-X1.b << "i" << endl;
    }
};

void add(ComplexNumber &X1, ComplexNumber &X2) {
    cout << X1.a+X2.a << ((X1.b+X2.b > 0) ? "+" : "") << X1.b+X2.b << "i" << endl;
}

void subtract(ComplexNumber &X1, ComplexNumber &X2) {
    cout << X1.a-X2.a << ((X1.b-X2.b > 0) ? "+" : "") << X1.b-X2.b << "i" << endl;
}

int main()
{
    ComplexNumber x1(1,3);
    ComplexNumber x2(1,-2);
    ComplexNumber x3(x1);
    x1.print();
    x2.print();
    x3.print();
    x1.add(x2);
    x1.subtract(x2);
    add(x1,x2);
    subtract(x2,x3);

    return 0;
}
#include <iostream>

class First {
private:
    int a;
public:
    First(int a):a(a) {
        std::cout << "Konstruktor First\n";
    };

    ~First() {
        std::cout << "Destruktor First\n";
    };

    void print(){
        std::cout << "A: " << a << "\n";
    }

};

class Second : public First {
private:
    int b;
public:
    Second(int a, int b):First(a), b(b) {
        std::cout << "Konstruktor Second\n";
    };

    ~Second() {
        std::cout << "Destruktor Second\n";
    };

    void print(){
        First::print();
        std::cout << "B: " << b << "\n";
    }
};

class Third : public Second {
private:
    int c;
public:
    Third(int a, int b, int c): Second(a, b), c(c) {
        std::cout << "Konstruktor Third\n";
    };

    ~Third() {
        std::cout << "Destruktor Third\n";
    };

    void print(){
        Second::print();
        std::cout << "C: " << c << "\n";
    }
};

int main() {
    First f(1);
    f.print();

    Second s(1, 2);
    s.print();

    Third t(1, 2, 3);
    t.print();

    return 0;
}

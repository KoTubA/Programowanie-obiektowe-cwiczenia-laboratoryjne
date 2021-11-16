#include <iostream>
#include <math.h>

class Point2D {
    int x, y;

public:
    Point2D(int px=1, int py=1): x(px), y(py){}

    void change_Cord(int newx, int newy) {
        x = newx;
        y = newy;
    }

    int get_x() { return x; }
    int get_y() { return y; }
};

class Circle {
    Point2D s;
    int r;

public:
    Circle(int pr=1, int px=1, int py=1): s(px,py), r(pr){}

    Circle(const Circle &x): s(x.s), r(x.r){}

    int get_r() { return r; }

    void print_cord() {
        std::cout << "X:" << s.get_x() << " Y:" << s.get_y() << std::endl;
    }

    void change_r(int newr) {
        r = newr;
    }

    friend float distance(Circle&, Circle&);
};

float distance(Circle& circle1, Circle& circle2) {
    return sqrt(pow(circle1.s.get_x()-circle2.s.get_x(),2)-pow(circle1.s.get_y()-circle2.s.get_y(),2))-circle1.get_r()-circle2.get_r();
}

int main() {
    Circle circle1;
    Circle circle2(1, 10, 1);

    //wszytko na lewo od * dotyczy wskaznika, za to wszytko na prawo dotyczy na to co wskauzje wskaznik
    const Circle *cptr1 = new Circle(0,0,5);
    //Możesz zmienić wartość wskaźnika, ale nie możesz zmienić wartości obiektu (Cricle), na który wskazuje wskaźnik
    Circle const *cptr2 = new Circle(0,0,5);
    //Możesz zmienić wartość wskaźnika, ale nie możesz zmienić wartości obiektu (Cricle), na który wskazuje wskaźnik
    Circle * const cptr3 = new Circle(0,0,5);
    //Nie możesz zmienić wartość wskaźnika, ale możesz zmienić wartości obiektu (Cricle), na który wskazuje wskaźnik
    const Circle * const cptr4 = new Circle(0,0,5);
    //Nie możesz zmienić wartość wskaźnika oraz wartości obiektu (Cricle), na który wskazuje wskaźnik
    Circle const * const cptr5 = new Circle(0,0,5);
    //Nie możesz zmienić wartość wskaźnika oraz wartości obiektu (Cricle), na który wskazuje wskaźnik
};
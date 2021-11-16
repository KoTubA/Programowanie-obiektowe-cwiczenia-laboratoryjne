#include <iostream>
using namespace std;

class Class1 {
public:
    virtual void f() {
        cout << " Function f() in Class1 \n";
    }
    void g() {
        cout << " Function g() in Class1 \n";
    }
};
class Class2 {
public:
    virtual void f() {
        cout << " Function f() in Class2 \n";
    }
    void g() {
        cout << " Function g() in Class2 \n";
    }
};
class Class3 {
public:
    virtual void h() {
        cout << " Function h() in Class3 \n";
    }
};
int main () {
    Class1 object1, *p;
    Class2 object2;
    Class3 object3;
    p = &object1;
    p->f(); //Function f() in Class1
    p->g(); //Function g() in Class1
    p = (Class1*) &object2;
    p->f(); // Function f() in Class2
    p->g(); //Function g() in Class1
    p = (Class1*) &object3;
    p->f(); //Function h() in Class3
    p->g(); //Function g() in Class1
    //p->h (); h() is not a member
    //of Class1;
    return 0;
}
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <algorithm>

using namespace std;

class Student{
    public:
        string name;
        string surname;
        int number;
};

Student *group;
int l;
void get_students();
void show_students();
void save_list();

int main(){
    cout<<"Podaj liczbe studentow:";
    cin>>l;
    group=new Student[l];
    get_students();
    show_students();
    save_list();
    delete [] group;
    return 0;
}

void get_students(){
    string name;
    string surname;
    int number;

    for(int i=0;i<l;i++){
        cout<<"Podaj kolejno imie nazwisko i numer albumu:"<<endl;
        cin>>name>>surname>>number;
        transform(name.begin(), name.begin()+1, name.begin(), ::toupper);
        transform(surname.begin(), surname.begin()+1, surname.begin(), ::toupper);
        while(to_string(number).length()!=6) {
            cout<<"Numer powinien zawierac 6 cyfr."<<endl<<"Podaj jeszcze raz poprawny numer:";
            cin>>number;
        }
        group[i].number=number;
        group[i].name=name;
        group[i].surname=surname;
    }
}

void show_students(){
    for(int i=0;i<l;i++) {
        cout << group[i].name << " ";
        cout << group[i].surname << " ";
        cout << group[i].number <<endl;
    }
}

void save_list(){
    fstream file;
    file.open("../students.txt",ios::out);

    for(int i=0;i<l;i++) {
        file << group[i].name << " ";
        file << group[i].surname << " ";
        file << group[i].number << endl;
    }
    file.close();
}
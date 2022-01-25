#include <iostream>
#include <stdexcept>


template<typename T>
class Tablica {
private:
    T* tab;
    int size;
public:
    Tablica(int s=1) : size(s){
        tab = new T[s];
        for (int i = 0; i < s; i++){
            tab[i] = 0;
        }
    }
    Tablica(T* table, int tableSize) : size(tableSize){
        tab = new T[tableSize];
        for (int i = 0; i < tableSize; i++){
            tab[i] = table[i];
        }
    }

    Tablica(const Tablica<T> &table){
        size = table.size;
        tab = new T[size];
        for (int i = 0; i < size; i++){
            tab[i] = table.tab[i];
        }

    }

    ~Tablica(){
        if (tab != NULL){
            delete[] tab;
        }
    }

    void printTable(){
        for (int i = 0; i < size; i++){
            std::cout << tab[i] << " ";
        }
        std::cout << "\n";
    }

    T operator[](int i){
        if (i > size - 1){
            throw std::out_of_range("Bledna wartosc indeksu!");
        }
        return this->tab[i];
    }

    Tablica<T> & operator=(Tablica<T> &drugi)
    {
        if (this == &drugi)
            return *this;

        this->size = drugi.size;
        this->tab = new T[size];
        for (int i = 0; i < size; i++){
            tab[i] = drugi.tab[i];
        }

        return *this;
    }
};

int main()
{
    Tablica<int> tab(20);
    std::cout << "Konstruktor domyslny:" << std::endl;
    tab.printTable();

    auto *t = new double[10];
    for (int i = 0; i < 10; i++) {
        t[i] = 2.71;
    }
    Tablica<double> tab2(t, 10);
    std::cout << "Konstruktor paramatrowy:" << std::endl;
    tab2.printTable();

    Tablica<int> tabCopy = tab;
    std::cout << "Konstruktor kopiujacy:" << std::endl;
    tabCopy.printTable();

    try {
        std::cout << "Przeciazenia operatora [] " << std::endl;
        std::cout << tab[2115];
    }
    catch (std::out_of_range &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "Operator przypisania:" << std::endl;
    tab = tabCopy;
    tab.printTable();

    return 0;
}

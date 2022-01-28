#include <iostream>

class RefuelCarException {
public:
    void what() {
        std::cout << "Za duzo chcesz zatankowac!" << std::endl;
    };
};

class Silnik {
    bool stateCar = false;
    int gear = 1;
    public:
        void changeStateCar(bool sc){
            stateCar = sc;
        }

        void changeGear(int g){
            gear = g;
        }

        bool getStateCar() const {
            return stateCar;
        }

        int getGear() const {
            return gear;
        }
};

class PojazdSilnikowy {
    public:
        Silnik state;
        double capacity = 0,
        carMileage = 0;
        std::string model;
        int yearCar;

        PojazdSilnikowy(std::string m, int r, double f) : model(m), yearCar(r), capacity(f){};

        PojazdSilnikowy(const PojazdSilnikowy &car){
            state.changeStateCar(car.state.getStateCar());
            state.changeGear(car.state.getGear());
            capacity = car.capacity;
            carMileage = car.carMileage;
            model = car.model;
            yearCar = car.yearCar;
        }

        void startEngine() {
            if(!state.getStateCar()) {
                state.changeStateCar(true);
                std::cout << "Uruchomiono slinik"<< std::endl;
            }
            else {
                std::cout << "Samochod jest juz uruchomiony!"<< std::endl;
            }
        }

        void stopEngine() {
            if(state.getStateCar()) {
                state.changeStateCar(false);
                std::cout << "Zgaszono slinik"<< std::endl;
            }
            else {
                std::cout << "Samochod jest juz zgaszony!"<< std::endl;
            }
        }

        virtual void drive() = 0;
};

class Samochod : public PojazdSilnikowy {
    double fuelLevel = 0,
    averageConsumption = 0;

    public:
        Samochod( std::string m, int r, double f, double a)
                : PojazdSilnikowy(m, r, f), averageConsumption(a) {};

        Samochod(const Samochod &car) : PojazdSilnikowy(car) {
            fuelLevel = car.fuelLevel;
            averageConsumption = car.averageConsumption;
        }

        void refuelCar() {
            std::cout << "Ile paliwa chcesz zatankowac?" << std::endl;
            double tempAmount;
            std::cin >> tempAmount;
            if(capacity<tempAmount+fuelLevel) {
                throw RefuelCarException();
            }
            else {
                fuelLevel += tempAmount;
                std::cout << "Twoj poziom baku wynosi: "<< fuelLevel << std::endl;
            }
        }

        void drive() {
            std::cout << "Ile kliometrow chcesz przejechac?" << std::endl;
            double len;
            std::cin >> len;
            if(len*averageConsumption/100>fuelLevel) {
                std::cout<<"Za dlugi dystans chcesz przejachac. Zbiornik zawiera tylko "<< fuelLevel << " litrow." << std::endl;
                std::cout<<"Mozesz przejechac tylko: "<< (fuelLevel*averageConsumption) << " kilometrow." << std::endl;
            }
            else {
                carMileage += len;
                fuelLevel -= len*averageConsumption/100;
            }
        }

        friend std::ostream & operator<<(std::ostream &, Samochod &);
};

std::ostream & operator<<(std::ostream & output, Samochod &x) {
    std::string statusText = x.state.getStateCar() ? "uruchomiony" : "zgaszony";

    output << "Dane o samochodzie:" << std::endl <<
    "Model: " << x.model << std::endl <<
    "Rok produkcji: " << x.yearCar << std::endl <<
    "Slinik: " << statusText << std::endl <<
    "Obecny bieg: " << x.state.getGear() << std::endl <<
    "Poziom paliwa: " << x.fuelLevel << std::endl <<
    "Pojemnosc baku: " << x.capacity << std::endl <<
    "Srednie spalanie: " << x.averageConsumption << std::endl <<
    "Przebieg: " << x.carMileage << std::endl;
    return output;
}

class SamochodElektryczny : public PojazdSilnikowy {
    double batteryLevel = 0;

public:
    static int counter;

    SamochodElektryczny(std::string m, int r, double f) : PojazdSilnikowy(m, r, f) {
        counter++;
    };

    SamochodElektryczny(const SamochodElektryczny &car) : PojazdSilnikowy(car) {
        batteryLevel = car.batteryLevel;
        counter++;
    }

    ~SamochodElektryczny() {
        counter--;
    }

    void rechargeCar() {
        batteryLevel = capacity;
        std::cout << "Twoj poziom naladowania wynosi: "<< batteryLevel << std::endl;
    }

    void drive() {
        std::cout << "Ile kliometrow chcesz przejechac?" << std::endl;
        double len;
        std::cin >> len;
        if(len>batteryLevel) {
            std::cout<<"Za dlugi dystans chcesz przejachac." << std::endl;
            std::cout<<"Mozesz przejechac tylko: "<< batteryLevel << " kilometrow." << std::endl;
        }
        else {
            carMileage += len;
            batteryLevel -= len;
        }
    }

    static void printObjCount()
    {
        std::cout << "Count: " << counter<< "\n";
    }

    friend std::ostream & operator<<(std::ostream &, SamochodElektryczny &);
};

std::ostream & operator<<(std::ostream & output, SamochodElektryczny &x) {
    std::string statusText = x.state.getStateCar() ? "uruchomiony" : "zgaszony";

    output << "Dane o samochodzie:" << std::endl <<
    "Model: " << x.model << std::endl <<
    "Rok produkcji: " << x.yearCar << std::endl <<
    "Slinik: " << statusText << std::endl <<
    "Obecny bieg: " << x.state.getGear() << std::endl <<
    "Poziom naladowania baterii: " << x.batteryLevel << std::endl <<
    "Maksymalny zasieg: " << x.capacity << std::endl <<
    "Przebieg: " << x.carMileage << std::endl;
    return output;
}

int SamochodElektryczny::counter = 0;
int main() {
    PojazdSilnikowy *s1[0];
    s1[0] = new SamochodElektryczny("Tesla", 2020, 500);
    Samochod *s2 = new Samochod("M2", 2010, 45, 10);
    SamochodElektryczny *s3 = new SamochodElektryczny("Tesla", 2015, 450);

    std::cout << "Pojazd silinikowy:" << std::endl;
    std::cout << "------------------" << std::endl;
    s1[0]->startEngine();
    std::cout << "------------------" << std::endl;
    s1[0]->drive();
    std::cout << "------------------" << std::endl;

    std::cout << "Pojazd spalinowy:" << std::endl;
    std::cout << "------------------" << std::endl;
    s2->startEngine();
    std::cout << "------------------" << std::endl;
    try {
        s2->refuelCar();
    }
    catch (RefuelCarException &e) {
        e.what();
    }
    std::cout << "------------------" << std::endl;
    std::cout << *s2;
    std::cout << "------------------" << std::endl;

    std::cout << "Pojazd elektryczny:" << std::endl;
    std::cout << "------------------" << std::endl;
    s3->startEngine();
    std::cout << "------------------" << std::endl;
    s3->rechargeCar();
    std::cout << "------------------" << std::endl;
    s3->drive();
    std::cout << "------------------" << std::endl;
    std::cout << *s3;
    std::cout << "------------------" << std::endl;
    SamochodElektryczny::printObjCount();
    std::cout << "------------------" << std::endl;
    return 0;
}

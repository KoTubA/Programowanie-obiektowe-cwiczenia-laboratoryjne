#include <iostream>

class TimeRangeException
{
public:
    virtual char *what() { return "Blad - nie mozna wykonac takiego dzialania!";};
};

class HoursException : public TimeRangeException
{
public:
    char *what() { return "Liczba godzin nie może być ujemna";};
};
class MinutesException : public TimeRangeException
{
public:
    char *what() { return "Liczba minut nie moze byc z poza zakresu 0-59";};
};
class SecondsException : public TimeRangeException
{
public:
    char *what() { return "Liczba sekund nie moze byc z poza zakresu 0-59";};
};

int convertToSeconds(int, int, int);

int main()
{
    int h,m,s,cs;
    std::cout << "Podaj liczbe godzin:"<< std::endl;
    std::cin >> h;
    std::cout << "Podaj liczbe minut:"<< std::endl;
    std::cin >> m;
    std::cout << "Podaj liczbe sekund:"<< std::endl;
    std::cin >> s;

    try
    {
        cs = convertToSeconds(h, m, s);
        std::cout << "Liczba sekund wynosi: " << cs << std::endl;
    }
    catch (TimeRangeException &e)
    {
        std::cout << e.what();
    }

    return 0;
}

int convertToSeconds(int h, int m, int s)
{
    if (h<0) throw HoursException();
    if (m<0 || m>59) throw MinutesException();
    if (s<0 || s>59) throw SecondsException();

    return h*3600+m*60+s;
}
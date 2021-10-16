#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Film{
    int date;
    string title;
};

Film *list;
int number_of_lines = 0;
void show_list();
void get_list();

int main(){
    get_list();
    show_list();
    delete [] list;
    return 0;
}

void get_list(){
    fstream file;
    file.open("../movies.txt", ios::in);

    if (file.is_open()) {
        string line;
        while (getline(file, line))
            ++number_of_lines;

        //back to start
        file.clear();
        file.seekg(0, std::ios::beg);
        list = new Film[number_of_lines];

        int i = 0;
        while (getline(file, line)) {
            int len = line.length();
            list[i].date = stoi(line.substr(len-5,len-1));
            list[i].title = line.substr(0,len-5);
            i++;
        }
        file.close();
    }
}

void show_list(){
    for(int i=0; i<number_of_lines; i++) {
        cout << list[i].title << " ";
        cout << list[i].date << endl;
    }
}
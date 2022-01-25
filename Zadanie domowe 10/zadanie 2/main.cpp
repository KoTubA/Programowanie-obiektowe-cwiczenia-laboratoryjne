#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream file("../text.txt");
    char ch;
    std::vector<int> count = {0};
    if(file.fail()) {
        std::cout << "Nie mozna bylo otworzyc pliku!";
    }
    else {
        while(file.get(ch)){
            if (isalpha(ch)) count[0]++;
        }
        std::cout << count[0] << " characters\n";
    }

    return 0;
}

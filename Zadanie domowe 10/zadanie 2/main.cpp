#include <iostream>
#include <fstream>
#include <map>

int main() {
    std::ifstream file("../text.txt");
    char ch;
    std::map<char, int> letters;
    if(file.fail()) {
        std::cout << "Nie mozna bylo otworzyc pliku!";
    }
    else {
        while(file.get(ch)){
            if (isalpha(ch)) {
                auto search = letters.find(ch);
                if(search != letters.end()) {
                    letters[ch]++;
                }
                else {
                    letters.insert(std::pair<char,int>(ch, 1));
                }
            }
        }
        for(const auto& elem : letters) {
            std::cout << elem.first << " " << elem.second << std::endl;
        }
    }

    return 0;
}

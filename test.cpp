#include "search_algs.h"
#include <random>
#include <algorithm>
#include <fstream>


int main() {
    ///RANDOM NUMBER GENERATOR SETTINGS
    std::random_device rd;
    std::mt19937::result_type seed = rd();
    std::mt19937 gen(seed);
    std::uniform_int_distribution UpperCaseLetters('A','Z');
    ///RANDOM NUMBER GENERATOR SETTINGS


    // dependence on text len tests
    string pattern;
    string txt;
    while(pattern.length() != 5){
        pattern+=(static_cast<char>(UpperCaseLetters(gen)));
    }
    std::ofstream to_save_1("Text_Len_Dependence_A-Z.txt");
    if(to_save_1.is_open()) {
        to_save_1 << "N NAIVE SUNDAY BOYER_MOORE\n";
        while (txt.length() < 10000) {

            txt += (static_cast<char>(UpperCaseLetters(gen)));
            std::shuffle(txt.begin(), txt.end(), std::mt19937(std::random_device()()));

            to_save_1 << txt.length() << ' ';
            operation_counter = 0;

            NaiveSearch(pattern, txt);

            to_save_1 << operation_counter << ' ';
            operation_counter = 0;

            SundaySearch(txt, pattern);

            to_save_1 << operation_counter << ' ';
            operation_counter = 0;

            BoyerMooreSearch(txt, pattern);

            to_save_1 << operation_counter << endl;
        }
        to_save_1.close();
    }

    return 0;
}

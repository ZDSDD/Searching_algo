#include "search_algs.h"
#include <random>
#include <algorithm>
#include <fstream>


int main() {
    ///RANDOM NUMBER GENERATOR SETTINGS
    std::random_device rd;
    std::mt19937::result_type seed = rd();
    std::mt19937 gen(seed);
    std::uniform_int_distribution UpperCaseLetters('A','E');
    ///RANDOM NUMBER GENERATOR SETTINGS


    // dependence on pattern len tests
    string pattern;
    string text;

    while(text.length() != 10000) {
        text += (static_cast<char>(UpperCaseLetters(gen)));
    }

    std::ofstream to_save_2("Pattern_Len_Dependence_A-E.txt");
    if(to_save_2.is_open()) {
        to_save_2 << "N NAIVE SUNDAY BOYER_MOORE\n";
        while (pattern.length() < 50) {

            pattern+=(static_cast<char>(UpperCaseLetters(gen)));
            std::shuffle(text.begin(), text.end(), std::mt19937(std::random_device()()));

            to_save_2 << pattern.length() << ' ';
            operation_counter = 0;

            NaiveSearch(pattern, text);

            to_save_2 << operation_counter << ' ';
            operation_counter = 0;

            SundaySearch(text, pattern);

            to_save_2 << operation_counter << ' ';
            operation_counter = 0;

            BoyerMooreSearch(text, pattern);

            to_save_2 << operation_counter << endl;
        }
        to_save_2.close();
    }


    return 0;
}

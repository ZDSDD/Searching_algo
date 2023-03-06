#include "search_algs.h"
#include <random>
#include <algorithm>
#include <fstream>
#include <vector>
#include <iterator>

template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
    std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
    std::advance(start, dis(g));
    return start;
}

template<typename Iter>
Iter select_randomly(Iter start, Iter end) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return select_randomly(start, end, gen);
}

int main() {
    ///RANDOM NUMBER GENERATOR SETTINGS
    std::random_device rd;
    std::mt19937::result_type seed = rd();
    std::mt19937 gen(seed);
    std::uniform_int_distribution UpperCaseLetters('A', 'Z');
    ///RANDOM NUMBER GENERATOR SETTINGS


    // dependence on alphabet len tests
    string pattern;
    string text;
    std::vector<char> alphabet{'A'};


    std::ofstream to_save_3("Alphabet_Len_Dependence_A-Z.txt");
    if (to_save_3.is_open()) {
        to_save_3 << "N NAIVE SUNDAY BOYER_MOORE\n";
        while (alphabet.back() != 'Z'+1) {
            text.clear();
            while (text.length() != 10000) {
                text += *select_randomly(alphabet.begin(),alphabet.end());
            }
            pattern.clear();
            while (pattern.length() != 10) {
                pattern += *select_randomly(alphabet.begin(),alphabet.end());
            }

            to_save_3 << alphabet.size() << ' ';
            operation_counter = 0;

            NaiveSearch(pattern, text);

            to_save_3 << operation_counter << ' ';
            operation_counter = 0;

            SundaySearch(text, pattern);

            to_save_3 << operation_counter << ' ';
            operation_counter = 0;

            BoyerMooreSearch(text, pattern);

            to_save_3 << operation_counter << endl;

            alphabet.push_back(++alphabet.back());
        }
        to_save_3.close();
    }


    return 0;
}

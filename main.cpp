#include <iostream>
#include <cstring>
#include <map>

using std::string;
using std::cout;
using std::endl;

bool matchesAt(const string &text, int p, const string &pattern) {
    for (char const &item: pattern) {
        if (item != text[p++]) {
            return false;
        }
    }
    return true;
}

void NaiveSearch(char *pat, char *txt) {
    size_t M = strlen(pat);
    size_t N = strlen(txt);
    if (N < M) {
        std::cout << "pattern is longer than text\n" << std::endl;
        return;
    }
    for (int i = 0; i <= N - M; i++) {
        if (matchesAt(txt, i, pat))
            std::cout << "Pattern found at index " << i << std::endl;
    }
}


void SundaySearch(string text, string pattern) {

    if (pattern.empty()) {
        std::cout << "Pattern is empty\n" << std::endl;
        return;
    }

    int text_len = text.length();
    int pattern_len = pattern.length();

    if (text_len < pattern_len) {
        std::cout << "pattern is longer than text\n" << std::endl;
        return;
    }

    std::map<char, int> mapping;
    for (int i = 0; i < pattern_len; ++i)
        mapping[pattern[i]] = i;

    //map print
/*    for (auto const &item: mapping) {
        printf("[%c]:[%d]\n", item.first, item.second);
    }*/
    int p{0};

    while (p <= text_len - pattern_len) {
        char c = text[p + pattern_len];
        if (matchesAt(text, p, pattern)) {
            std::cout << "found at " << p << std::endl;
        }
        if (mapping.find(c) == mapping.end()) {
            p += pattern_len + 1;
        } else {
            p += pattern_len - mapping[c];
        }
    }
}

# define NO_OF_CHARS 256

void badCharHeuristic(const string & str,const int & size,int badchar[NO_OF_CHARS]) {
    int i;
    // Initialize all occurrences as -1
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;
    for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}

void BoyerMooreSearch(const string & txt,const string & pat) {
    int patt_len = pat.size();
    int txt_len = txt.size();

    int badchar[NO_OF_CHARS];
    badCharHeuristic(pat, patt_len, badchar);

    int p = 0; // p is shift of the pattern with
    while (p <= (txt_len - patt_len)) {
        int j = patt_len - 1;
        while (j >= 0 && pat[j] == txt[p + j])
            j--;
        if (j < 0) {
            cout << "pattern occurs at shift = " << p << endl;
            p += (p + patt_len < txt_len) ? patt_len - badchar[txt[p + patt_len]] : 1;
        } else
            p += std::max(1, j - badchar[txt[p + j]]);
    }
}


#ifndef SEARCH_ALGS
#define SEARCH_ALGS

#include <iostream>
#include <cstring>
#include <map>

using std::string;
using std::cout;
using std::endl;

static int operation_counter{0};

//static int memory_counter{0};
bool matchesAt(const string &text, size_t p, const string &pattern) {
    for (char const &item: pattern) {
        operation_counter++;
        if (item != text[p++]) {
            return false;
        }
    }
    return true;
}

void NaiveSearch(const string &pattern, const string &text) {
    if (pattern.empty()) {
        return;
    }
    int pattern_len = pattern.length();
    int text_len = text.length();

    if (text_len < pattern_len) {
        return;
    }
    for (int i = 0; i <= text_len - pattern_len; i++) {
        if (matchesAt(text, i, pattern)) {
            //std::cout << "Pattern found at index " << i << std::endl;
        }

    }
}


void SundaySearch(const string & text,const string & pattern) {

    if (pattern.empty()) {
        return;
    }

    int text_len = text.length();
    int pattern_len = pattern.length();

    if (text_len < pattern_len) {
        return;
    }

    std::map<char, int> mapping;
    for (int i = 0; i < pattern_len; ++i) {
        mapping[pattern[i]] = i;
    }

    int p{0};
    while (p <= text_len - pattern_len) {
        char c = text[p + pattern_len];
        if (matchesAt(text, p, pattern)) {
            //printf("Pattern occurs at = %d\n", p);
        }
        if (mapping.find(c) == mapping.end()) {
            p += pattern_len + 1;
        } else {
            p += pattern_len - mapping[c];
        }
    }
}


/* A pattern searching function that uses Bad
Character Heuristic of Boyer Moore Algorithm */
void BoyerMooreSearch(const string &text, const string &pattern) {
    int pattern_len = pattern.size();
    int text_len = text.size();

    std::map<char, int> mapping;
    for (int i = 0; i < pattern_len; ++i) {
        mapping[pattern[i]] = i;
    }

    int p = 0; // p is shift of the pattern with
    while (p <= (text_len - pattern_len)) {
        int j = pattern_len - 1;
        while (j >= 0 && pattern[j] == text[p + j]) {
            operation_counter++;
            j--;
        }
        if (j < 0) {
            //cout << "pattern occurs at shift = " << p << endl;
            p += (p + pattern_len < text_len) ? pattern_len - mapping[text[p + pattern_len]] : 1;

        } else
            p += std::max(1, j - mapping[text[p + j]]);
    }
}

#endif //SEARCH_ALGS

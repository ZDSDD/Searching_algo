#include "main.cpp"



int main() {
    char txt[] = "AABAACAADAAABCBAAABAAABCC";
    char pat[] = "AAA";
    NaiveSearch(pat, txt);
    SundaySearch(txt, pat);
    BoyerMooreSearch(txt,pat);
    return 0;
}

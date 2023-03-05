#include "search_algs.h"



int main() {
    char txt[] = "AACBACCACAADACCCCCCCCCCAACCBCCBCABCCAAACCCCBAAABCC";
    char pat[] = "CAB";
    NaiveSearch(pat, txt);
    SundaySearch(txt, pat);
    BoyerMooreSearch(txt,pat);
    return 0;
}

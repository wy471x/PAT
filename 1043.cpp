#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#define N 128

int main(void) {
    string str;
    getline(cin, str);
    int alphabets[N] = {0};
    int length = str.length();
    for (int i = 0; i < length; ++i) {
        if (isalpha(str[i])) {
            alphabets[str[i]]++;
        }
    }
    while ( alphabets['P'] > 0 || alphabets['A'] > 0 
        || alphabets['T'] > 0 || alphabets['e'] > 0
        || alphabets['s'] > 0 || alphabets['t'] > 0) {
            if (alphabets['P'] > 0) {
                cout << 'P';
                alphabets['P']--;
            } 
            if (alphabets['A'] > 0) {
                cout << 'A';
                alphabets['A']--;
            }
            if (alphabets['T'] > 0) {
                cout << 'T';
                alphabets['T']--;
            }
            if (alphabets['e'] > 0) {
                cout << 'e';
                alphabets['e']--;
            }
            if (alphabets['s'] > 0) {
                cout << 's';
                alphabets['s']--;
            }
            if (alphabets['t'] > 0) {
                cout << 't';
                alphabets['t']--;
            }
    }
    return 0;
}
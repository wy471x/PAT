#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    string a;
    cin >> a;
    char integerSignBit = a[0], exponentSignBit = a[a.find('E') + 1];
    //cout << integerSignBit << " " << exponentSignBit << endl;
    string integerStr = a.substr(1, a.find('E') - 1), exponentStr = a.substr(a.find('E') + 2);
    //cout << integerStr << endl;
    integerStr.erase(find(integerStr.begin(), integerStr.end(), '.'));
    //cout << integerStr << " " << exponentStr << endl;
    unsigned int exp = stoi(exponentStr);
    //cout << exp << endl;
    if (exponentSignBit == '-') {
        integerStr.insert(0, exp, '0');
        integerStr.insert(1, ".");
    } else {
        if (exp >= integerStr.size()-1) {
            integerStr.insert(integerStr.size(), exp - integerStr.size() + 1, '0');
        } else {
            integerStr.insert(exp + 1, ".");
        }
    }
    if (integerSignBit == '-') {
        integerStr.insert(0, "-");
        cout << integerStr;
    } else {
        cout << integerStr;
    }
    return 0;
}
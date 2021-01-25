#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int main(void) {
    string a, b;
    cin >> a >> b;
    vector<char> res;
    int i = 0, j = 0;
    while (j < b.size()) {
        if (a[i] != b[j]) {
            char temp = a[i];
            if (a[i] >= 'a' && a[i] <= 'z') {
                temp = toupper(temp);
            } 
            //cout << temp << endl;
            if (find(res.begin(), res.end(), temp) == res.end()) {
                res.push_back(temp);
            }
        } else {
            j++;
        }
        i++;
    }
    // note : edge case
    while (i < a.size()) {
        char temp = a[i];
        if (a[i] >= 'a' && a[i] <= 'z') {
            temp = toupper(a[i]);
        }
        if (find(res.begin(), res.end(), temp) == res.end()) {
            res.push_back(temp);
        }
        i++;
    }

    for (auto c : res) {
        cout << c;
    }
    return 0;
}

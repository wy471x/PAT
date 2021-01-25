#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool comparator(char c1, char c2) {
    return c1 > c2;
}

int main(void) {
    string n;
    string max, min;
    int diff;
    cin >> n;
    while (1) {
        sort(n.begin(), n.end(), comparator);
        max = n;
        cout << max << " - ";
        sort(n.begin(), n.end());
        min = n;
        cout << min << " = ";
        diff = stoi(max) - stoi(min); 
        if (diff == 0) {
            cout << "0000";
            break;
        }
        n = diff < 1000 ? "0" + to_string(diff) : to_string(diff); 
        cout << n << endl;
        if (diff == 6174) {
            break;
        }     
    }
    return 0;
}

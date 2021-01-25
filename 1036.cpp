#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    char c;
    cin >> c;
    int row = round((double)n / 2), column = n;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if (i == 0 || i == row - 1) {
                cout << c;
            } else {
               if (j == 0 || j == column - 1) {
                   cout << c;
               } else {
                   cout << " ";
               }
            }
        }
        cout << endl;
    } 
    return 0;
}
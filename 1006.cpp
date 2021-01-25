#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void numberToString(int, string&);

int main(void) {
    int n;
    cin>>n;
    string res = "";
    numberToString(n, res);
    reverse(res.begin(), res.end());
    cout<<res<<endl;
    return 0;
}

void numberToString(int n, string &str) {
    int digits = 1;
    while (n != 0) {
        int temp = n % 10;
        if (digits == 1) {
            for (int i = temp; i > 0; --i) {
                str += to_string(i);
            }
        } else if (digits == 2) {
            for (int i = 0; i < temp; ++i) {
                str += "S";
            }
        } else if (digits == 3) {
            for (int i = 0; i < temp; ++i) {
                str += "B";
            }
        }
        n /= 10;
        digits++;
    }
}
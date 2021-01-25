#include <iostream>
using namespace std;

int main(void) {
    int a, b, d;
    cin >> a >> b >> d;
    int res[31] = {0}, len = 0, sum = a + b;
    do {
        res[len++] = sum % d;
        sum /= d;
    }  while (sum != 0);
    for (int i = len - 1; i >= 0; --i) {
        cout << res[i];
    }
    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;
int counter(int, int);

int main(void) {
    int a, dA, b, dB;
    cin >> a >> dA >> b >> dB;
    int cntDa = counter(a, dA), cntDb = counter(b, dB);
    int pA = 0, pB = 0;
    for (int i = 0; i < cntDa; ++i) {
        pA += pow(10, i) * dA;
    }
    for (int i = 0; i < cntDb; ++i) {
        pB += pow(10, i) * dB;
    }
    cout << pA + pB;
    return 0;
}

int counter(int n, int d) {
    int cnt = 0;
    while (n) {
        if (n % 10 == d) {
            cnt++;
        }
        n /= 10; 
    }
    return cnt;
}
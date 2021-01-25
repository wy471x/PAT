#include<iostream>
#include<string>
#include<cmath>
using namespace std;
/*
dn = pn + pn-1
*/
bool isPrime(int);

int main(void) {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 2; i <= n - 2; ++i) {
        if (isPrime(i) && isPrime(i+2)) {
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}

bool isPrime(int num) {
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
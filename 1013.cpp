#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool isPrime(int);

int main(void) {
    int m, n;
    cin >> m >> n;
    int nums[n- m + 1];
    int i = 0, pos = 0;
    for (int j = 2; ; ++j) {
        if (isPrime(j)) {
            pos++;
            if (pos >= m && pos <= n) {
                nums[i++] = j;
                
                if (pos == n) {
                    break;
                }
            }
        }
    }
    string res = "";
    int rows = (n - m + 1) / 10, cols = 10, remainder = (n - m + 1) % 10;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            res += to_string(nums[i * cols + j]) + " ";
        }
        res = res.erase(res.find_last_not_of(" ") + 1) + "\n";
    }
    for (int i = 0; i < remainder; ++i) {
        res += to_string(nums[rows * cols + i]) + " ";
    }
    if (remainder != 0) res.erase(res.find_last_not_of(" ") + 1);
    cout<<res;
    return 0; 
}

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}
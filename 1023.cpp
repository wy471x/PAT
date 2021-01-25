#include <iostream>
using namespace std;

/*
输入在一行中给出 10 个非负整数，顺序表示我们拥有数字 0、数字 1、……数字 9 的个数。
整数间用一个空格分隔。10 个数字的总个数不超过 50，且至少拥有 1 个非 0 的数字。
*/
int main(void) {
    int num[10];
    int bitNum = 0;
    for (int i = 0; i < 10; ++i) {
        cin >> num[i];
        bitNum += num[i];
    }
    int res[bitNum] = {0};
    for (int i = 1; i < 10; ++i) {
        if (num[i] != 0) {
            res[0] = i;
            num[i]--;
            break;
        }
    }
    for (int i = 1; i < bitNum; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (num[j] != 0) {
                res[i] = j;
                num[j]--;
                break;
            }
        }
    }
    for (int i = 0; i < bitNum; ++i) {
        cout << res[i];
    }
    return 0;
}
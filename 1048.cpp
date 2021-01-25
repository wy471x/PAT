// ---------------------------------------------------------------- 题目描述 -----------------------------------------------------------
/*
                                                            1048 数字加密 (20分)
本题要求实现一种数字加密方法。首先固定一个加密用正整数 A，对任一正整数 B，将其每 1 位数字与 A 的对应位置上的数字进行以下运算：对奇数位，对应位的数字相加后对 13 取余——这里用 J 代表 10、Q 代表 11、K 代表 12；对偶数位，用 B 的数字减去 A 的数字，若结果为负数，则再加 10。这里令个位为第 1 位。

输入格式：
输入在一行中依次给出 A 和 B，均为不超过 100 位的正整数，其间以空格分隔。

输出格式：
在一行中输出加密后的结果。

输入样例：
1234567 368782971
输出样例：
3695Q8118
*/
// ---------------------------------------------------------------- 题目实现 -----------------------------------------------------------
/*
    算法思想：
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

char hash_map[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};

char Calculation(int index, int a, int b);

int main(void) {
    string num_str[2];
    cin >> num_str[0] >> num_str[1];
    // 分为两种情况： 1. A长于B 2. A短于B
    string result = "";
    int length = num_str[1].size();
    for (int i = num_str[1].size() - 1, j = num_str[0].size() - 1; i >= 0; i--) {
        if (j >= 0) {
            result += Calculation(length - i, num_str[0][j], num_str[1][i]);
            j--;
        } else {
            result += num_str[1][i];
        }
    }
    reverse(result.begin(), result.end());
    cout << result;
    return 0;
}

char Calculation(int index, int a, int b) {
    char res_char;
    if (index % 2 == 0) {
        if (b - a < 0) {
            res_char = '0' + (b - a) + 10;
        } else {
            res_char = '0' + (b - a);
        }
    } else {
        res_char = hash_map[(a + b) % 13];
    }
    return res_char;
}
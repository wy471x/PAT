#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

/*
字符串 APPAPT 中包含了两个单词 PAT，
其中第一个 PAT 是第 2 位(P)，第 4 位(A)，第 6 位(T)；
第二个 PAT 是第 3 位(P)，第 4 位(A)，第 6 位(T)。
现给定字符串，问一共可以形成多少个 PAT？

输入格式：
输入只有一行，包含一个字符串，长度不超过10^5，只包含 P、A、T 三种字母。

输出格式：
在一行中输出给定字符串中包含多少个 PAT。
由于结果可能比较大，只输出对 1000000007 取余数的结果。

输入样例：
APPAPT
输出样例：
2
*/
// time complexity: O(n^3)
/* solution 1:
string inputStr;
    cin >> inputStr;
    int cnt = 0;
    for (int i = 0; i < inputStr.size() - 2; ++i) {
        if ('P' == inputStr[i]) {
            for (int j = i + 1; j < inputStr.size() - 1; ++j) {
                if ('A' == inputStr[j]) {
                    for (int k = j + 1; k < inputStr.size(); ++k) {
                        if ('T' == inputStr[k]) {
                            cnt++;
                        }
                    }
                }
            }
        }
    }
    cout << cnt % 1000000007   << endl;
*/
/* solution 2:
    string s;
    cin >> s;
    int len = s.size(), result = 0, countp = 0, countt = 0;
    for (int i = 0; i < len; ++i) {
        if ('T' == s[i]) {
            countt++;
        }
    }

    for (int i = 0; i < len; ++i) {
        if ('P' == s[i]) {
            countp++;
        }
        if ('T' == s[i]) {
            countt--;
        }
        if ('A' == s[i]) {
            result = (result + countp * countt) % 1000000007;
        }
    }
    cout << result << endl;
    return 0;
*/
#define MAX 1000000007
int main(void) {
    char c;
    int countP = 0, countPA = 0, countPAT = 0;
    while (c = getc(stdin)) {
        if ('P' == c) {
            countP++;
        }
        if ('A' == c) {
            countPA += countP;
        }
        if ('T' == c) {
            countPAT = (countPAT + countPA) % MAX;
        }
    }
    cout << countPAT << endl;
    return 0;
}
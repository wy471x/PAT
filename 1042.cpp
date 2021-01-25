#include <iostream>
#include <string>
using namespace std;
/*
输入格式：
输入在一行中给出一个长度不超过 1000 的字符串。
字符串由 ASCII 码表中任意可见字符及空格组成，至少包含 1 个英文字母，以回车结束（回车不算在内）。

输出格式：
在一行中输出出现频率最高的那个英文字母及其出现次数，其间以空格分隔。
如果有并列，则输出按字母序最小的那个字母。统计时不区分大小写，输出小写字母。
*/
int main(void) {
    string str;
    getline(cin, str);
    int hashTable[26] = {0};
    int length = str.length();
    for (int i = 0; i < length; ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            hashTable[str[i] - 'A']++;
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            hashTable[str[i] - 'a']++;
        }
    }
    int max = 0;
    for (int i = 0; i < 26; ++i) {
        if (hashTable[i] > hashTable[max]) {
            max = i;
        }
    }
    cout <<  (char)('a' + max) << " " << hashTable[max] << endl;
    return 0;
}
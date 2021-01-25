#include <iostream>
#include <cctype>
#include <string>
using namespace std;
/*
火星人是以 13 进制计数的：
地球人的 0 被火星人称为 tret。
地球人数字 1 到 12 的火星文分别为：jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec。
火星人将进位以后的 12 个高位数字分别称为：tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou。
例如地球人的数字 29 翻译成火星文就是 hel mar；而火星文 elo nov 对应地球数字 115。
为了方便交流，请你编写程序实现地球和火星数字之间的互译。

输入格式：
输入第一行给出一个正整数 N（<100），随后 N 行，每行给出一个 [0, 169) 区间内的数字 —— 或者是地球文，
或者是火星文。

输出格式：
对应输入的每一行，在一行中输出翻译后的另一种语言的数字。
*/
const string unitDigits[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
const string tenDigits[12] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

void print(string::size_type n, string const &s);
void test();

int main(void) {
    int N;
    cin >> N;
    int i = 0; 
    while (i < N) {
        string numStr;
        cin >> numStr;
        if (isdigit(numStr[0])) {
            int num = stoi(numStr);
            int tenDigit = num / 13;
            if (tenDigit > 0) {
              cout << tenDigits[tenDigit - 1] << " ";
            }
            int unitDigit = num % 13;
            cout << unitDigits[unitDigit] << endl;
        } else {
            int n = numStr.find(' ');
            cout << " n : " << n << endl;
            int total = 0;
            if (n == string::npos) {
                string unitDigit = numStr.substr(0);
                cout << " unit : " << unitDigit << endl;
                for (int i = 0; i < 13; ++i) {
                    if (unitDigit == unitDigits[i]) {
                        total = i;
                        break;
                    }
                }
            } else {
                string tenDigit = numStr.substr(0, n-1);
                cout << " ten : " << tenDigit << endl;
                for (int i = 0; i < 12; ++i) {
                    if (tenDigit == tenDigits[i]) {
                        total += (i + 1) * 13;
                        break;
                    }
                }

                string unitDigit = numStr.substr(n + 1);
                cout << " unit : " << unitDigit << endl;
                for (int i = 0; i < 13; ++i) {
                    if (unitDigit == unitDigits[i]) {
                        total += i;
                        break;
                    }
                }
            }
            cout << total << endl;    
        }
        i++;
    }

    //test();
    return 0;
}

void print(string::size_type n, string const &s) {
    if (n == string::npos) {
        cout << "not found\n";
    } else {
        cout << "found: " << s.substr(n) << "\n";
    }
}

void test() {
    string::size_type n;
    string const s = "This is a string";

    n = s.find("is");
    cout << n << endl;
    cout << s.substr(0, n) << endl;
    print(n, s);
    
    n = s.find("is", 5);
    cout << n << endl;
    print(n ,s);

    n = s.find('a');
    cout << n << endl;
    print(n, s);

    n = s.find('q');
    //cout << (string::size_type)n << endl;
    print(n, s);

    n = s.find(" ");
    cout << s.substr(n)  << endl;
    //print(n, s);
}
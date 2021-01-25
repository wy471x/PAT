#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string firstStr1, firstStr2, secondStr1, secondStr2;
    cin >> firstStr1 >> firstStr2 >> secondStr1 >> secondStr2;
    int cnt = 1;
    string res = "";
    // first pair
    for (unsigned int i = 0, j = 0; i < firstStr1.size() && j < firstStr2.size(); ++i, ++j)
    {
        if ('A' <= firstStr1[i] && firstStr1[i] <= 'G' &&
            'A' <= firstStr2[j] && firstStr2[j] <= 'G' &&
            firstStr1[i] == firstStr2[j] && cnt == 1)
        {
            if (1 == cnt)
            {
                switch (firstStr1[i])
                {
                case 'A':
                    res += "MON ";
                    break;
                case 'B':
                    res += "TUE ";
                    break;
                case 'C':
                    res += "WED ";
                    break;
                case 'D':
                    res += "THU ";
                    break;
                case 'E':
                    res += "FRI ";
                    break;
                case 'F':
                    res += "SAT ";
                    break;
                case 'G':
                    res += "SUN ";
                    break;
                default:
                    break;
                }
            }
            cnt++;
        } 
        else if ((('0' <= firstStr1[i] && firstStr1[i] <= '9') || (firstStr1[i] >= 'A' && firstStr1[i] <= 'N')) && 
                    (('0' <= firstStr2[j] && firstStr2[j] <= '9') || (firstStr2[j] >= 'A' && firstStr2[j] <= 'N')) &&
                    firstStr1[j] == firstStr2[j] && cnt == 2) {
                        if ('0' <= firstStr1[i] && firstStr1[i] <= '9') {
                            res += "0" + to_string(firstStr1[i] - '0') + ":";
                        } else if (firstStr1[i] >= 'A' && firstStr1[i] <= 'N') {
                            res += to_string(10 + firstStr1[i] - 'A') + ":";
                        }
                        break;
                    }
    }
    // second pair
    for (unsigned int i = 0, j = 0; i < secondStr1.size() && j < secondStr2.size(); ++i, ++j) {
        if (((secondStr1[i] >= 'a' && secondStr1[i] <= 'z') || (secondStr1[i] >= 'A' && secondStr1[i] <= 'Z')) &&
            ((secondStr2[j] >= 'a' && secondStr2[j] <= 'z') || (secondStr2[j] >= 'A' && secondStr2[j] <= 'Z')) &&
            secondStr1[i] == secondStr2[j]) {
                if (i <= 9) {
                    res += "0" + to_string(i);
                } else {
                    res += to_string(i);
                }
                break;
            }
    }
    cout<<res;
    return 0;
}
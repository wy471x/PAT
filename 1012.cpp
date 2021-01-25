#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;
/*
A​1​​ = 能被 5 整除的数字中所有偶数的和；// a1 ==> A1
A​2​​ = 将被 5 除后余 1 的数字按给出顺序进行交错求和，即计算 n​1​​−n​2​​+n​3​​−n​4​​⋯；// exp ==> A2
A​3​​ = 被 5 除后余 2 的数字的个数； // a3 ==> A3
A​4​​ = 被 5 除后余 3 的数字的平均数，精确到小数点后 1 位；// cntA4 ==> A4
A​5​​ = 被 5 除后余 4 的数字中最大数字。 // cntA5 ==> A5
*/
int main(void)
{
    int n;
    cin >> n;
    int nums[n];
    int i = 0;
    while (i < n)
    {
        cin >> nums[i];
        ++i;
    }
    int a1 = 0, a2 = 0, a3 = 0, a5 = nums[0], cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, cnt5 = 0;
    float a4 = 0, sum = 0;
    for (int j = 0; j < n; ++j)
    {
        if (0 == nums[j] % 5 &&  0 == nums[j] % 2)
        {
            cnt1++;
            a1 += nums[j];
        }
        if (1 == nums[j] % 5)
        {
           a2 += pow(-1, cnt2) * nums[j];
           cnt2++;
        }
        if (2 == nums[j] % 5)
        {
            a3++;
            cnt3++;
        }
        if (3 == nums[j] % 5)
        {
            cnt4++;
            sum += nums[j];
        }
        if (4 == nums[j] % 5)
        {
            a5 = max(a5, nums[j]);
            cnt5++;
        }
    }
    cnt1 == 0 ? cout << "N" << " " : cout << a1 << " ";
    cnt2 == 0 ? cout << "N" << " " : cout << a2 << " ";
    cnt3 == 0 ? cout << "N" << " " : cout << a3 << " "; 
    cnt4 == 0 ? cout << "N" << " " : cout << setprecision(2) << (a4 = sum / cnt4) << " ";
    cnt5 == 0 ? cout << "N" : cout << a5;
    return 0;
}
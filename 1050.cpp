// ---------------------------------------------------------------- 题目描述 -----------------------------------------------------------
/*
                                                            1050 螺旋矩阵 (25分)
本题要求将给定的 N 个正整数按非递增的顺序，填入“螺旋矩阵”。所谓“螺旋矩阵”，是指从左上角第 1 个格子开始，按顺时针螺旋方向填充。
要求矩阵的规模为 m 行 n 列，满足条件：m×n 等于 N；m≥n；且 m−n 取所有可能值中的最小值。

输入格式：
输入在第 1 行中给出一个正整数 N，第 2 行给出 N 个待填充的正整数。所有数字不超过 10^4，相邻数字以空格分隔。

输出格式：
输出螺旋矩阵。每行 n 个数字，共 m 行。相邻数字以 1 个空格分隔，行末不得有多余空格。

输入样例：
12
37 76 20 98 76 42 53 95 60 81 58 93
输出样例：
98 95 93
42 37 81
53 20 76
58 60 76
*/
// ---------------------------------------------------------------- 题目实现 -----------------------------------------------------------
/*
    算法思想：
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {
    int N;
    scanf("%d", &N);
    int nums[N];
    int i = 0;
    while (i < N) {
        scanf("%d", nums[i++]);
    }
    sort(nums, nums + N);
    reverse(nums, nums + N);
    int m = 0, n = 0;
    for (i = sqrt(N); i <= N; ++i) {
        if (N % i == 0) {
            m = i > sqrt(N) ? i : N / i;
            n = N / m;
            break;
        }
    }
    cout << m << " "<< n << endl;
    int j, k = -1, a[m][n];
    for (i = 0; k < m * n - 1; ++i) {
        for (j = i; j < n - i && k < m * n - 1; ++j) {
            a[i][j] = nums[++k];
        }
        for (j = i + 1; j < m - i && k < m * n - 1; ++j) {
            a[j][n - i - 1] = nums[++k];
        }
        for (j = m - 2 - i; j >= i + 1 && k < m * n - 1; --j) {
            a[m - i - 1][j] = nums[++k];
        }
        for (j = m - 2 - i; j >= i + 1 && k < m * n - 1; --j) {
            a[j][i] = nums[++k];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d", a[i][j]);
            if (j != N - 1) {
                printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}

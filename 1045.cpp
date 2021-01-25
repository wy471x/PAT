/*
                                                                1045 快速排序 (25分)
著名的快速排序算法里有一个经典的划分过程：
我们通常采用某种方法取一个元素作为主元，通过交换，把比主元小的元素放到它的左边，比主元大的元素放到它的右边。 
给定划分后的 N 个互不相同的正整数的排列，请问有多少个元素可能是划分前选取的主元？

例如给定 $N = 5$, 排列是1、3、2、4、5。则：

1 的左边没有元素，右边的元素都比它大，所以它可能是主元；
尽管 3 的左边元素都比它小，但其右边的 2 比它小，所以它不能是主元；
尽管 2 的右边元素都比它大，但其左边的 3 比它大，所以它不能是主元；
类似原因，4 和 5 都可能是主元。
因此，有 3 个元素可能是主元。

输入格式：
输入在第 1 行中给出一个正整数 N（≤10^5）； 第 2 行是空格分隔的 N 个不同的正整数，每个数不超过 10^9。

输出格式：
在第 1 行中输出有可能是主元的元素个数；在第 2 行中按递增顺序输出这些元素，其间以 1 个空格分隔，行首尾不得有多余空格。

输入样例：
5
1 3 2 4 5
输出样例：
3
1 4 5
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
/*
    算法思想：原始的元素位置与排完序后的元素位置保持一致，且它的值为其之前元素至其当前位置
             的元素值为最大时，该元素可能为主元。
*/
int main()
{
    int n;
    scanf("%d", &n);
    int num[n], num_original[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
        num_original[i] = num[i];
    }
    sort(num_original, num_original + n);
    int count = 0, max = 0;
    int res[n];
    for (int i = 0; i < n; i++) {
        if (num[i] > max) {
            max = num[i];
        }
        if (max == num[i] && num[i] == num_original[i]) {
            res[count++] = num[i];
        }
    }
    printf("%d\n", count);
    for (int i = 0; i < count; ++i) {
        if (0 == i) {
            printf("%d", res[i]);
        } else {
            printf(" %d", res[i]);
        }
    }
    printf("\n");
    return 0;
}
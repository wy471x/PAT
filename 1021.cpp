#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void)
{
    char n[1001];
    scanf("%s", n);
    int digits[10] = {0};
    int len = strlen(n);
    for (int i = 0; i < len; ++i) {
        digits[n[i] - '0']++;
    }
    for (int i = 0; i < 10; ++i) {
        if (digits[i] != 0) {
            printf("%d:%d\n", i, digits[i]);
        }
    }

    return 0;
}
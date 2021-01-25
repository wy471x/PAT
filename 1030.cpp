#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int n, p;
    cin >> n >> p;
    int nums[n];
    int i = 0;
    while (i < n) {
        cin >> nums[i++];
    }
    sort(nums, nums + n);
    int res = 1;
    for (int i = 0; i < n; ++i) {
        int j = upper_bound(nums + i + 1, nums + n, (long long) nums[i] * p) - nums;
        res = max(res, j - i);
    }
    cout << res;
    return 0;
}
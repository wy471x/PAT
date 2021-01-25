#include <iostream>
#include <vector>
using namespace std;

void reverse(int[], int, int);

int main(void) {
    int n, m;
    cin>>n>>m;
    int nums[n];
    for (int i = 0; i < n; ++i) {
        cin>>nums[i];
    }
    // note m > n
    if (m > n) {
        m = m % n;
    }
    reverse(nums, 0, n - 1);
    reverse(nums, 0, m - 1);
    reverse(nums, m, n - 1);
    string res = "";
    for (int i = 0; i < n; ++i) {
        res += to_string(nums[i]) + " ";
    }
    cout<<res.erase(res.find_last_not_of(" ") + 1)<<endl;
    return 0;
}

void reverse(int nums[], int start, int end) {
    for (int i = start, j = end; i < j; ++i, --j) {
       int temp = nums[i];
       nums[i] = nums[j];
       nums[j] = temp; 
    }
}
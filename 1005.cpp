#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

void execute(map<int, bool>&, int);

int main(void) {
    int n;
    cin >> n;
    int nums[n];
    int i = 0;
    while (i < n) {
        cin >> nums[i];
        i++;
    }

    map<int, bool> map;
    for (int j = 0; j < n; ++j) {
        execute(map, nums[j]);
    }
    string res = "";
    sort(nums, nums+n);
    for (int k = n - 1; k >= 0; --k) {
        if (map[nums[k]] != true) {
            res += to_string(nums[k]) + " ";
        }
    }
    cout<<res.erase(res.find_last_not_of(" ") + 1)<<endl;
    return 0;
}

void execute(map<int, bool> &map, int num) {
    while (num > 1) { 
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = (num * 3 + 1) / 2;
        }
        map[num] = true;       
    }
}
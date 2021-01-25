#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    string nums[n];
    int i = 0;
    while (i < n) {
        cin >> nums[i++];
    }

    int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char zm[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int last = 0;
        int j = 0;
        for (; j < nums[i].size(); ++j) { 
            if (j == nums[i].size() - 1) {
                //cout << last << endl;
                if (nums[i][j] != zm[last % 11]) {
                    break;
                }
            } else if ( nums[i][j] < '0' || nums[i][j] > '9') {
                break;
            }

            last += (nums[i][j] - '0') * weight[j];
        }

        if (j != nums[i].size()) {
            cout << nums[i] << endl;
            cnt++;
        }
    }
    if (cnt == 0) {
        cout << "All passed" <<endl;
    }
    return 0;
}
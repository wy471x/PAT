#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

//
struct {
    bool operator()(const pair<char, int> obj1, const pair<char, int> obj2) {
        if (obj1.second != obj2.second) {
            return obj1.second > obj2.second;
        } else {
            return obj1.first < obj2.first;
        }
    }
}comparator;

int main(void) {
    int n;
    cin >> n;
    int i = 0;
    int aWin = 0, aLose = 0, aDraw = 0, bWin = 0, bLose = 0, bDraw = 0;
    vector<pair<char, int>> a, b;
    pair<char, int> icp[2][3];
    for (int i = 0; i < 2; ++i) {
        icp[i][0].first = 'C';
        icp[i][1].first = 'J';
        icp[i][2].first = 'B';
    } 
    while (i < n) {
        char cA, cB;
        cin >> cA >> cB;
        if (cA == 'C' && cB == 'J') {
            icp[0][0].second++;
            aWin++;
            bLose++;
        } else if (cA == 'J' && cB == 'B') {
            icp[0][1].second++;
            aWin++;
            bLose++;
        } else if (cA == 'B' && cB == 'C') {
            icp[0][2].second++;
            aWin++;
            bLose++;
        } else if (cA == cB) {
            aDraw++;
            bDraw++;
        } else if (cB == 'C' && cA == 'J') {
            icp[1][0].second++;
            bWin++;
            aLose++;
        } else if (cB == 'J' && cA == 'B') {
            icp[1][1].second++;
            bWin++;
            aLose++;
        } else if (cB == 'B' && cA == 'C') {
            icp[1][2].second++;
            bWin++;
            aLose++;
        }
        i++;
    }
    for (int i = 0; i < 3; ++i) {
        a.push_back(icp[0][i]);
        b.push_back(icp[1][i]);
    }
    sort(a.begin(), a.end(), comparator);
    sort(b.begin(), b.end(), comparator);
    cout << aWin << " " << aDraw << " " << aLose << endl;
    cout << bWin << " " << bDraw << " " << bLose << endl;
    cout << a.begin()->first << " " << b.begin()->first;
    return 0;
}
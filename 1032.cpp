#include <iostream>
using namespace std;
#define MAX 100001
/**
 * 为了用事实说明挖掘机技术到底哪家强，
 * PAT 组织了一场挖掘机技能大赛。
 * 现请你根据比赛结果统计出技术最强的那个学校。
 * */
int main(void) {
    int n;
    cin >> n;
    int schools[MAX] = {0}, index = 0;
    int id, scord, max = 0;
    while (n--) {
        cin >> id >> scord;
        schools[id] += scord;
        if (schools[id] > max) {
            max = schools[id];
            index = id;
        }
    }
    cout << index << " " << max << endl;
    return 0;
}
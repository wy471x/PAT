#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Examinee {
    int id;
    int record1;
    int record2;
}examinee;

bool comparator(examinee e1, examinee e2) {
    if (e1.record1 + e1.record2 != e2.record1 + e2.record2 ) {
        return e1.record1 + e1.record2 > e2.record1 + e2.record2;
    } else if (e1.record1 != e2.record1) {
        return e1.record1 > e2.record1;
    } else {
        return e1.id < e2.id;
    }
}

int main(void)
{
    int n, l, h;
    cin >> n >> l >> h;
    vector<examinee> c1, c2, c3, c4;
    examinee temp;
    for (int i = 0; i < n; ++i) {
        //cin >> temp.id >> temp.record1 >> temp.record2;
        scanf("%d %d %d", &temp.id, &temp.record1, &temp.record2);
        if (temp.record1 >= h && temp.record2 >= h) {
            c1.push_back(temp);
        } else if (temp.record1 >= h && temp.record2 >= l && temp.record2 < h) {
            c2.push_back(temp);
        } else if (temp.record1 < h && temp.record1 >= l && temp.record2 < h &&
                temp.record2 >= l && temp.record1 >= temp.record2) {
                    c3.push_back(temp);
        } else if (temp.record1 >= l && temp.record2 >= l) {
                    c4.push_back(temp);
        }
    }
    // sort
    sort(c1.begin(), c1.end(), comparator);
    sort(c2.begin(), c2.end(), comparator);
    sort(c3.begin(), c3.end(), comparator);
    sort(c4.begin(), c4.end(), comparator);

    // output
    int m = c1.size() + c2.size() + c3.size() + c4.size();
    cout << m << endl;
    for (auto  examinee : c1) {
        cout << examinee.id << " " << examinee.record1 << " " << examinee.record2 << endl;
    }
    for (auto  examinee : c2) {
        cout << examinee.id << " " << examinee.record1 << " " << examinee.record2 << endl;
    }
    for (auto  examinee : c3) {
        cout << examinee.id << " " << examinee.record1 << " " << examinee.record2 << endl;
    }
    for (auto  examinee : c4) {
        cout << examinee.id << " " << examinee.record1 << " " << examinee.record2 << endl;
    }
    return 0;
}
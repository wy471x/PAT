#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student{
    string name;
    string studentId;
    int scords;
};
bool comparator(struct Student stu1, struct Student stu2) {
    return stu1.scords >= stu2.scords;
}
int main(void) {
    int n;
    cin >> n;
    struct Student stu[n];
    int i = 0;
    // input process
    while (i < n) {
        cin>>stu[i].name;
        cin>>stu[i].studentId;
        cin>>stu[i].scords;
        i++;
    }
    // output process first solution
    // struct Student *maxStu, *minStu;
    // int maxScords = -1, minScords = 101;
    // for (int j = 0; j < n; ++j) {
    //     if (stu[j].scords > maxScords) {
    //         maxScords = stu[j].scords;
    //         maxStu = &stu[j];
    //     }
    //     if (stu[j].scords < minScords) {
    //         minScords = stu[j].scords;
    //         minStu = &stu[j];
    //     }
    // }

    // cout<<maxStu->name<<" "<<maxStu->studentId<<endl;
    // cout<<minStu->name<<" "<<minStu->studentId<<endl;
    
    // second solution
    sort(stu, stu+n, comparator);
    cout << stu[0].name << " " << stu[0].studentId << endl;
    cout << stu[n-1].name << " " << stu[n-1].studentId << endl;
    return 0;
}
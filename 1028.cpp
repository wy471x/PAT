#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
输入在第一行给出正整数 N，取值在(0,10^5]；
随后 N 行，每行给出 1 个人的姓名（由不超过 5 个英文字母组成的字符串）、
以及按 yyyy/mm/dd（即年/月/日）格式给出的生日。
题目保证最年长和最年轻的人没有并列。
*/
typedef struct {
    char name[10];
    int year, month, day;
} Person;

bool cmp(Person a, Person b) {
    if (a.year != b.year) {
        return a.year < b.year;
    } else if (a.month != b.month) {
        return a.month < b.month;
    } else if (a.day != b.day) {
        return a.day < b.day;
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    vector<Person> valid;
    int i = 0;
    while (i < n) {
        Person temp;
        scanf("%s %d/%d/%d", temp.name, &temp.year, &temp.month, &temp.day);
        if (temp.year < 1814 || (temp.year == 1814 && (temp.month < 9 || (temp.month == 9 && temp.day < 6))) || 
            (temp.year == 2014 && (temp.month > 9 || (temp.month == 9 && temp.day > 6))) || temp.year > 2014) {
            i++;
            //cout << "fail" << endl;
            continue;
        }
        valid.push_back(temp);
        i++;
    }
    sort(valid.begin(), valid.end(), cmp);

    // edge case
    if (valid.size() == 0) {
        cout << valid.size();
        return 0;
    }
    cout << valid.size() << " " << valid[0].name << " " << valid[valid.size()-1].name;
    return 0;
}

#include <iostream>
#include <map>
#include <utility>
using namespace std;

int main(void) {
    string str1, str2;
    cin >> str1;
    cin >> str2;

    map<char, int> numOfStr1, numOfStr2;
    for (int i = 0; i < str1.size(); ++i) {
        if (numOfStr1.find(str1[i]) == numOfStr1.end()) {
            numOfStr1.insert(make_pair(str1[i], 1));
        } else {
            numOfStr1[str1[i]]++;
        }
    }
    for (int i = 0; i < str2.size(); ++i) {
        if (numOfStr2.find(str2[i]) == numOfStr2.end()) {
            numOfStr2.insert(make_pair(str2[i], 1));
        } else {
            numOfStr2[str2[i]]++;
        }
    }

    int difference = 0;
    for (auto it = numOfStr2.begin(); it != numOfStr2.end(); ++it) {
        map<char, int>::iterator temp;
        if ((temp = numOfStr1.find(it->first)) != numOfStr1.end()) {
            if(temp->second < it->second) {
                difference += it->second - temp->second;
            }
        } else {
            difference += it->second; 
        }
    }
    if (difference > 0) { 
        cout << "No" << " " << difference << endl;
    } else {
        cout << "Yes" << " " << str1.size() - str2.size() << endl;
    }

    return 0;
}
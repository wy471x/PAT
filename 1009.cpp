#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(void) {
    string input;
    getline(cin, input);
    istringstream iss(input);
    string res = "", word;
    while (iss >> word) {
        res = word + " " + res;
    }
    cout<<res.erase(res.find_last_not_of(" ") + 1)<<endl;
    return 0;
}
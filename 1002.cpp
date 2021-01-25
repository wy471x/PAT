#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    string n;
    cin>>n;
    string res = "";
    int sum = 0;
    for (unsigned int i = 0; i < n.size(); ++i) {
        sum += n[i] - '0';
    }
    cout<<sum;
    while (sum > 0) {
        int temp = sum % 10;
        switch (temp) {
            case 0: res = "ling " + res; break;
            case 1: res = "yi " + res; break;
            case 2: res = "er " + res; break;
            case 3: res = "san " + res; break;
            case 4: res = "si " + res; break;
            case 5: res = "wu " + res; break;
            case 6: res = "liu " + res; break;
            case 7: res = "qi " + res; break;
            case 8: res = "ba " + res; break;
            case 9: res = "jiu " + res; break;
        }
        sum /= 10;
    }
    res.erase(res.find_last_not_of(" ") + 1);
    cout<<res;
    return 0;
}
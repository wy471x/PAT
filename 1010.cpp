#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> ivec;
    int n;
    while (cin >> n)
    {
        ivec.push_back(n);
        if (cin.get() == '\n') {
            break;
        }
    }
    auto it = ivec.begin();
    for (; it != ivec.end() && *(it+1) != 0; it += 2)
    {
       if (*it == 0) {
           break;
       }
       *it *= *(it+1);
       *(it+1) -= 1;
    }
    it = ivec.erase(it, ivec.end());
    if (ivec.size() == 0) {
        cout<<"0 0"<<endl;
        return 0;
    }
    string res = "";
    for (it = ivec.begin(); it != ivec.end(); ++it) {
        res += to_string(*it) + " ";
    }

    cout<<res.erase(res.find_last_not_of(" ") + 1)<<endl;
    return 0;
}
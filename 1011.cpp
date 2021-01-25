#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int n;
    cin>>n;
    signed long a, b, c;
    int i = 1;
    while (i <= n) {
        cin>>a>>b>>c;
        if (a + b > c) {
            cout<<"Case #"<<i<<": "<<"true"<<endl;
        } else {
            cout<<"Case #"<<i<<": "<<"false"<<endl;
        }
        i++;
    }
    return 0;
}
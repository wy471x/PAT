#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct Bign{ 
    int d[1000];
    int len;
    Bign() {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

Bign change(char[]);
Bign divide(Bign, int, int&);

int main(void) {
    char a[1000] = {0};
    int b;
    scanf("%s %d", a, &b);
    // string a;
    // cin >> a;
    // cin >> b;
    struct Bign dividend = change(a);
    int r;
    struct Bign q = divide(dividend, b, r);
    for (int i = q.len - 1; i >= 0; --i) {
        cout << q.d[i];
    }
    cout << " " << r;
    return 0;
}

Bign change(char str[]) {
    Bign a;
    a.len = strlen(str);
    for (int i = 0; i < a.len; i++) {
        a.d[i] = str[a.len-i-1] - '0';
    }
    return a;
}

// r : remainder 
Bign divide(Bign a, int b, int &r) {
    Bign c;
    c.len = a.len;
    // divide operation
    for (int i = a.len - 1; i >= 0; --i) {
        r = r * 10 + a.d[i];
        if (r < b) c.d[i] = 0;
        else {
            c.d[i] = r / b;
            r = r % b;
        }
    }
    // remove zero of low digit
    while (c.len - 1 >= 1 && c.d[c.len - 1] == 0) {
        c.len--;
    }
    return c;
}
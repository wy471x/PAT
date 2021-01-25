#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define CLOCK_TICK 100

int main(void) {
    int c1, c2;
    cin >> c1 >> c2;
    int useSeconds = round((double)(c2 - c1) / CLOCK_TICK);
    //cout << useSeconds << " " << round((c2 - c1) / CLOCK_TICK) << endl;
    int hours = useSeconds / 3600, minutes = (useSeconds % 3600) / 60, seconds = (useSeconds % 3600) % 60;
    cout << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds;
    return 0;
}
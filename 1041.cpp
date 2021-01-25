#include <iostream>
#include <cstdio>
using namespace std;

/*
输入格式：
输入第一行给出一个正整数 N（≤1000），随后 N 行，每行给出一个考生的信息：准考证号 试机座位号 考试座位号。
其中准考证号由 16 位数字组成，座位从 1 到 N 编号。
输入保证每个人的准考证号都不同，并且任何时候都不会把两个人分配到同一个座位上。
考生信息之后，给出一个正整数 M（≤N），随后一行中给出 M 个待查询的试机座位号码，以空格分隔。

输出格式：
对应每个需要查询的试机座位号码，在一行中输出对应考生的准考证号和考试座位号码，中间用 1 个空格分隔。
*/
typedef struct {
    char admissionTicketNumber[17];
    int testSeatNumber;
    int examSeatNumber;
} Candidate;

int find(Candidate candidates[], int size, int testSeatNumber);

int main(void) {
    int N;
    cin >> N;
    Candidate candidates[N];
    int i = 0;
    while (i < N) {
        cin >> candidates[i].admissionTicketNumber 
            >> candidates[i].testSeatNumber 
            >> candidates[i].examSeatNumber;
        i++;
    }
    int M, testSeatNumber;
    cin >> M;
    i = 0;
    while (i < M) {
        cin >> testSeatNumber;
        int index;
        if ((index = find(candidates, N, testSeatNumber)) != -1) {
            cout << candidates[index].admissionTicketNumber 
                 << " " << candidates[index].examSeatNumber << endl;
        }
        i++;
    }
    return 0;
}
/**
 * find index of candidates specified test seat number
 **/
int find(Candidate candidates[], int size, int testSeatNumber) {
    for (int i = 0; i < size; ++i) {
        if (testSeatNumber == candidates[i].testSeatNumber) {
            return i;
        }
    }
    return -1;
}
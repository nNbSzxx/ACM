#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
//NO.10
//an emirp is a prime number whose reverse is a different prime number
// your task is to find the nth emirp
const int MAX = 1e6 + 10;
int prime[MAX];
int getr(int x)
{
    int ret = 0;
    while (x) {
        ret = ret * 10 + (x % 10);
        x /= 10;
    }
    return ret;
}

int main()
{
    memset(prime, -1, sizeof(prime));
    prime[0] = prime[1] = 0;
    for (int i = 2; i < MAX; i ++) {
        if (prime[i]) {
            for (int j = 2 * i; j < MAX; j += i) {
                prime[j] = 0;
            }
        }
    }
    int cnt = 1;
    int a[12000];
    a[11185] = -1;
    int r;

    for (int i = 13; i < MAX && cnt <= 11184; i ++) {
        if (prime[i] == -1) {
            r = getr(i);
            if (r != i && prime[r] && prime[i]) {
                a[cnt ++] = i;
                prime[r] = 2;
            }
        } else if (prime[i] == 2) {
            a[cnt ++] = i;
        }
    }
    int n;
    cin >> n;
    cout << a[n] << endl;
    return 0;
}

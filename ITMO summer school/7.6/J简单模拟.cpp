#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[110];
    for (int i = 1; i <= k; i ++) {
        cin >> a[i];
    }
    int leader = 0;
    int m = n;
    int live[110];
    int flag = 0;
    memset(live, 1, sizeof(live));
    for (int i = 1; i <= k; i ++) {
        int times = a[i] % m;
        int loc = leader;
        for (int j = 1; j <= times; j ++) {
            loc = (loc + 1) % n;
            while (!live[loc]) loc = (loc + 1) % n;
        }
        if (flag) {
            cout << " ";
        }
        flag = 1;
        cout << loc + 1;
        live[loc] = 0;
        leader = (loc + 1) % n;
        while (!live[leader]) leader = (leader + 1) % n;
        m --;
    }

    return 0;
}


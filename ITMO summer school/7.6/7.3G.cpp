#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int MAX = 110;
int main()
{
    int n;
    cin >> n;
    int a[MAX], loc[MAX];
    priority_queue<int> q;
    int sum = 0, t = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 1; i <= n; i ++) {
        cin >> loc[i];
    }
    for (int i = n; i >= 1; i -= 2) {
        q.push(a[loc[i]]);
        q.push(a[loc[i - 1]]);
        t += q.top(); q.pop();
    }
    cout << t - (sum - t) << endl;
}


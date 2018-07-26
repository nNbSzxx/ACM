#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int MAX = 1010;
int vis[MAX];
int ans[MAX];
int sum, flag, num, n;

int main()
{
    int n;
    cin >> n;
    if (n == 0) {
        cout << "0" << endl;
        return 0;
    }
    if (n == 1) {
        cout << "1" << endl << "1" << endl;
        return 0;
    }
    int sum = 0, num = 0;
    queue<int> q;
    for (int i = 1; i <= n; i ++) {
        sum += i;
        num ++;
        q.push(i);
        if (sum > n) {
            break;
        }
    }
    int forbid = sum - n;
    cout << num - 1 << endl;
    int flag = 0;
    while (!q.empty()) {
        if (flag) {
            cout << " ";
        }
        int now = q.front(); q.pop();
        if (now != forbid) {
            cout << now;
            flag = 1;
        }
    }
    cout << endl;
    return 0;
}

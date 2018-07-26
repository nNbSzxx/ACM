#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

bool check(const string& s)
{
    for (int i = 1; i < s.size(); i ++) {
        if (s[i] != s[0]) {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int ans = 1;
    if (!check(s)) {
        ans = 0;
    }
    char flag = s[0];
    for (int i = 1; i < n; i ++) {
        cin >> s;
        if (flag == s[0]) {
            ans = 0;
        }
        if (!check(s)) {
            ans = 0;
        }
        flag = s[0];
    }
    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}

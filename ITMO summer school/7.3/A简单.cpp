#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
const int MAX = 1e5 + 10;

int main()
{
    int n;
    string s, arrs[MAX];
    cin >> n;
    cin >> s;
    s += "a";

    int maxlen = 0;
    char cur = s[0];
    int curlen = 1;
    int cnt = 0;
    for (int i = 1; i <= n; i ++) {
        if (cur == s[i]) {
            curlen ++;
        } else {
            if (curlen > maxlen) {
                maxlen = curlen;
                cnt = 1;
            } else
            if (curlen == maxlen) {
                ++ cnt;
            }
            curlen = 1;
            cur = s[i];
        }
    }

    cur = s[0];
    curlen = 1;
    int k = 0;
    cout << cnt << endl;
    for (int i = 1; i <= n; i ++) {
        if (cur == s[i]) {
            curlen ++;
        } else {
            if (curlen == maxlen) {
                for (int j = 0; j < maxlen; j ++) {
                    arrs[k] += s[i - 1];
                }
                k ++;
            }
            curlen = 1;
            cur = s[i];
        }
    }
    sort(arrs, arrs + cnt);
    for (int i = 0; i < cnt; i ++) {
        cout << arrs[i] << endl;
    }
    return 0;
}


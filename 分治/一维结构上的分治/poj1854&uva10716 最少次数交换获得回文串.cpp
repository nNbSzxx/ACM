/*
 * ֻ�ܽ������ڵ���ĸ�������ٵĽ�������ʹ�ô���ɻ��Ĵ�
 * ��һ�����ۣ���������������ַ���ʼ����
 * ������ʹ��ߵĻ����ұߵĻ��ǰ��ұߵĻ�����ߵģ�
 * ����С���⣬��������ʹ���ŵ�
 */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1e5 + 10;

char s[MAX];
int n, cnt[30];
int ans;

void solve(int l, int r)
{
    if (s[l] == s[r]) {
        return ;
    }
    int i = l, j = r;
    for (; i <= r; i ++) {
        if (s[i] == s[r]) {
            break;
        }
    }
    for (; j >= l; j --) {
        if (s[j] == s[l]) {
            break;
        }
    }
    if (i - l < r - j) {
        ans += i - l;
        char c = s[i];
        i --;
        for (; i >= l; i --) {
            s[i + 1] = s[i];
        }
        s[l] = c;
    } else {
        ans += r - j;
        char c = s[j];
        for (int i = j + 1; i <= r; i ++) {
            s[i - 1] = s[i];
        }
        s[r] = c;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf(" %s", s);
        n = strlen(s);
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < n; i ++) {
            cnt[s[i] - 'a'] ++;
        }
        int sumodd = 0;
        for (int i = 0; i < 26; i ++) {
            if (cnt[i] & 1) {
                ++ sumodd;
            }
        }
        if (sumodd > 1) {
            puts("Impossible");
            continue;
        }
        ans = 0;
        for (int l = 0, r = n - 1; l < r; l ++, r --) {
            solve(l, r);
        }
        printf("%d\n", ans);
    }

    return 0;
}

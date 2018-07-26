#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
//	freopen("1011.in", "r", stdin);
//	freopen("1011.out", "w", stdout);
    char s[10][30];
    int step[3] = {6, 13, 18};
    int t;
    int a, b, c = -1, d;
    scanf("%d", &t);
    while (t --) {
        for (int i = 1; i <= 7; i ++) {
            scanf(" %s", s[i] + 1);
        }
//      for (int i = 1; i <= 7; i ++) {
//        	for (int j = 1; j <= 21; j ++) {
//        		cout <<s[i][j];
//			}
//			cout << endl;
//		}
        if (s[2][1] == 'X') a = 0;
        else if (s[1][2] == 'X') a = 2;
        else a = 1;

        int ans;
        for (int i = 0; i < 3; i ++) {
            int cc = step[i];
            if (s[2][cc] == '.') {
                if (s[1][cc + 1] == '.') ans = 1;
                else if (s[5][cc + 3] == '.') ans = 2;
                else if (s[4][cc + 1] == '.') ans = 7;
                else ans = 3;
            } else {
                if (s[5][cc] == '.') {
                    if (s[1][cc + 1] == '.') ans = 4;
                    else if (s[2][cc + 3] == '.') ans = 5;
                    else ans = 9;
                } else {
                    if (s[2][cc + 3] == '.') ans = 6;
                    else if (s[4][cc + 1] == '.') ans = 0;
                    else ans = 8;
                }
            }
            if (i == 0) b = ans;
            else if (i == 1) c = ans;
            else d = ans;
        }
        printf("%d%d:%d%d\n", a, b, c, d);
    }
}

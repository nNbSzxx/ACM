#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int time[30];
    int n;
    memset(time, 0 , sizeof(time));
    scanf("%d", &n);
    for (int i = 1;i <= n; i ++) {
        int a, b;
        scanf("%d%d", &a, &b);
        for (int j = a + 1; j <= b; j ++) {
            time[j] ++;
        }
    }
    int maxx = -1;
    for (int i = 0; i <= 24; i ++) {
        if (time[i] > maxx) {
            maxx = time[i];
        }
    }
    printf("%d\n", maxx);
    return 0;
}

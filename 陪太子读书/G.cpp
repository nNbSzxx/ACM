#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int strength[110];
int p[110];
priority_queue<int> q;

int main()
{
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &strength[i]);
        sum += strength[i];
    }
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &p[i]);
    }
    int my = 0;

    for (int i = n; i >= 1; i -= 2) {
        int pick1 = p[i];
        int pick2 = p[i - 1];
        q.push(strength[pick1]);
        q.push(strength[pick2]);
        my += q.top();
        q.pop();
    }
    printf("%d\n", my - (sum - my));
    return 0;
}

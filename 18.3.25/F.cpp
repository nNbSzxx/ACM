// F.cpp
#include<bits/stdc++.h>
using namespace std;
const int MAX = 5000000 + 10;
long long  W;
int N;

int main()
{
    while (~scanf("%lld", &W)) {
        scanf("%d", &N);
        long long sum = 0;
        for (int i = 1; i <= N; i ++) {
            long long a, b;
            scanf("%lld%lld", &a, &b);
            sum += a * b;
        }
        printf("%lld\n", sum / W);
    }
}

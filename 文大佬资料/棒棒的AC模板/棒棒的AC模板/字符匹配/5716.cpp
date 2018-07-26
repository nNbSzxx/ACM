#include<bits/stdc++.h> 
bitset<M>w[300],P[2];
int main()
{
    int i,j,n,bo,len,now;
    while (gets(s+1)) {
        scanf("%d", &n);
        for (i=0;i<256;i++) w[i].reset();
        for (i=1;i<=n;i++) {
            scanf("%d%s", &len, t+1);
            for (j=1;j<=len;j++) w[t[j]][i]=1;
        }
        bo=now=0;
        P[now].reset();P[now][0]=1;
        for (i=1;s[i];i++) {
            P[!now]=(P[now]<<1)&w[s[i]];
            now^=1;P[now][0]=1;
            if (P[now][n]) {
                bo=1;printf("%d\n", i-n+1);
            }
        }
        if (!bo) printf("NULL\n");
        getchar();
    }
    return 0;
}


#include<bits/stdc++.h> 
using namespace std;

const int N = 215;
char str[N];  //原始字符串
char ans[N]; //置换后的字符串
int key[N];  //置换规则
int cnt; //循环节数量
int num[N]; //每个循环节的长度
int cir[N][N]; //cir[i][j]表示第i个循环节中的第j个元素对应的位置
int vis[N]; //记录每个数是否访问过

int n;

void get_circle() {
    memset(vis, 0, sizeof(vis));
    memset(num, 0, sizeof(num));
    cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            vis[i] = 1;
            num[cnt] = 0;
            int tmp = key[i];
            cir[cnt][num[cnt]++] = tmp;
            while(!vis[tmp]) {
                vis[tmp] = 1;
                tmp = key[tmp];
                cir[cnt][num[cnt]++] = tmp;
            }
            cnt++;
        }
    }
}

int main() {
    int k;
    while(~scanf("%d",&n) && n) {
        for(int i = 1; i <= n; i++)
            scanf("%d", &key[i]);
        get_circle();
        while(~scanf("%d", &k) && k) {
            gets(str);
            int len = strlen(str);
            for(int i = len; i <= n; i++)
                str[i] = ' ';
            for(int i = 0; i < cnt; i++) {
                for(int j = 0; j < num[i]; j++) {
                    ans[cir[i][(j+k)%num[i]]] = str[cir[i][j]];
                } //第i个循环节中的第j个元素置换k次之后的位置为第（j+k）% num[i]
            }
            ans[n+1] = '\0';
            printf("%s\n", ans+1);
        }
        printf("\n");
    }
    return 0;
}

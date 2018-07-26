#include<bits/stdc++.h> 
using namespace std;

const int N = 215;
char str[N];  //ԭʼ�ַ���
char ans[N]; //�û�����ַ���
int key[N];  //�û�����
int cnt; //ѭ��������
int num[N]; //ÿ��ѭ���ڵĳ���
int cir[N][N]; //cir[i][j]��ʾ��i��ѭ�����еĵ�j��Ԫ�ض�Ӧ��λ��
int vis[N]; //��¼ÿ�����Ƿ���ʹ�

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
                } //��i��ѭ�����еĵ�j��Ԫ���û�k��֮���λ��Ϊ�ڣ�j+k��% num[i]
            }
            ans[n+1] = '\0';
            printf("%s\n", ans+1);
        }
        printf("\n");
    }
    return 0;
}

#include<bits/stdc++.h>  
using namespace std;  
  
const int maxn=1e5+50;   
int a[maxn][20],T,n,m;  
map<int,long long> mp;  
  
int gcd(int x,int y){  
    return y==0?x:gcd(y,x%y);  
}  
  
void init(){  
    for(int j=1;(1<<j)<=n;j++)  
        for(int i=1;i+(1<<j)-1<=n;i++)  
            a[i][j]=gcd(a[i][j-1],a[i+(1<<(j-1))][j-1]);  
}  
  
int GETGCD(int L,int R){  
    int K=(int)log2((double)(1.0*(R-L+1)));  
    return gcd(a[L][K],a[R-(1<<K)+1][K]);  
}  
  
void getans(){  
    mp.clear();  
    int l,r,g,i,j,mid;  
    for(i=1;i<=n;i++){  
        g=a[i][0];  
        j=i;  
        while(j<=n){  
            l=j,r=n;  
            while(l<r){  
                mid=(l+r+1)>>1;  
                if (GETGCD(i,mid)==g) l=mid;  
                else r=mid-1;  
            }  
            mp[g]+=(l-j+1);  
            j=l+1;  
            g=GETGCD(i,j);  
        }  
    }  
}  
  
int main(){  
    //freopen("input.txt","r",stdin);  
    scanf("%d",&T);  
    for(int Case=1;Case<=T;Case++){  
        scanf("%d",&n);  
        for(int i=1;i<=n;i++) scanf("%d",&a[i][0]);  
        init();  
        getans();  
        printf("Case #%d:\n",Case);  
        scanf("%d",&m);  
        int l,r,g;  
        while(m--){  
            scanf("%d%d",&l,&r);  
            g=GETGCD(l,r);  
            printf("%d %I64d\n",g,mp[g]);  
        }  
    }  
    return 0;  
}  

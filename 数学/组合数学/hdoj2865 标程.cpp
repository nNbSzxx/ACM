#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
#include<cmath>  
#define N 10000003  
#define p 1000000007  
#define LL long long   
using namespace std;  
int pd[N],prime[N],phi[N],f[3],n; LL k;  
struct data{  
    LL a[3][3];  
}ch,e,b;  
void init(int n)  
{  
    phi[1]=1;  
    for (int i=2;i<=n;i++) {  
        if (!pd[i]) {  
            prime[++prime[0]]=i;  
            phi[i]=i-1;  
        }  
        for (int j=1;j<=prime[0];j++) {  
            if(prime[j]*i>n) break;  
            pd[i*prime[j]]=1;  
            if (i%prime[j]==0) {  
                phi[i*prime[j]]=phi[i]*prime[j];  
                break;  
            }  
            else phi[i*prime[j]]=phi[i]*(prime[j]-1);  
        }  
    }  
}  
LL getphi(int x)  
{  
    if (x<=1000000) return (LL)phi[x];  
    int ans=x;  
    for (int i=1;prime[i]*prime[i]<=x;i++)  
     if (x%prime[i]==0) {  
        ans=ans/prime[i]*(prime[i]-1);  
        while (x%prime[i]==0) x/=prime[i];  
     }  
    if(x>1) ans=ans/x*(x-1);  
    return (LL)ans%p;  
}  
void clear(data &a)  
{  
    for (int i=1;i<=2;i++)   
     for (int j=1;j<=2;j++) a.a[i][j]=e.a[i][j];  
}  
data mul(data a,data b)  
{  
    data c;  
    for (int i=1;i<=2;i++)  
     for (int j=1;j<=2;j++) {  
        c.a[i][j]=0;  
        for (int k=1;k<=2;k++) c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j])%p;  
     }  
    return c;  
}  
data quickpow(data num,int x)  
{  
    data ans; clear(ans);  
    data base; base=num;  
    while (x) {  
        if (x&1) ans=mul(ans,base);  
        x>>=1;  
        base=mul(base,base);  
    }  
    return ans;  
}  
LL calc(int i)  
{  
    if (i<=2) return f[i];  
    data t=quickpow(ch,i-2);
	cout << "i: " << i << endl;  
    for (int i = 1; i <= 2; i ++) {
    	for (int j = 1; j <= 2; j ++) {
    		cout << t.a[i][j] << " ";
		}
		cout << endl;
	}
    t=mul(b,t);  
    return t.a[1][2];  
}  
LL quickpow(LL num,int x)  
{  
    LL ans=1; LL base=num%p;  
    while (x) {  
        if (x&1) ans=ans*base%p;  
        x>>=1;  
        base=base*base%p;  
    }  
    return ans;  
}  
int main()  
{  
//    freopen("a.in","r",stdin);  
    init(1000000);  
    ch.a[1][1]=0; ch.a[1][2]=1; ch.a[2][1]=1; ch.a[2][2]=1;  
    for (int i=1;i<=2;i++) e.a[i][i]=1;  
    while (scanf("%d%I64d",&n,&k)!=EOF) {  
        k--; f[1]=0; f[2]=k*(k-1)%p;  
        b.a[1][1]=f[1]; b.a[1][2]=f[2];  
        b.a[2][1]=0; b.a[2][2]=0;  
        ch.a[1][1]=0; ch.a[2][1]=1; ch.a[1][2]=k-1; ch.a[2][2]=k-2;   
        LL ans=0;   
        for (int i=1;i*i<=n;i++)   
         if (n%i==0){  
            LL t=calc(n/i);   
            ans+=(LL)t*getphi(i); ans%=p;  
            if (i*i!=n) {  
                LL t=calc(i);  
                ans+=(LL)t*getphi(n/i);  
            }  
            ans%=p;  
            cout << i << " " << ans << endl; 
        }  
//        cout << calc(n) << endl;
        ans=ans*(k+1)%p*quickpow(n,p-2)%p;  
        printf("%I64d\n",ans);  
    }  
}  

#include<cstdio>  
#include<string>  
#include<cstring>  
#include<iostream>  
#include<algorithm>  
using namespace std;  
int k;  
long long sx[65537],tsx[65537];  
inline int cale(long long n)  
{  
    if(n==1)  
        return 1;  
    else if(n%2==1)  
        return (3*cale((n-1)/2)+1)%k;  
    else  
        return 3*cale(n/2)%k;  
}  
inline void fx(long long n)  
{  
    if(n==1)  
    {  
        sx[1]=1;  
        return ;  
    }  
    int i;  
    if(n%2==0)  
    {  
        fx(n/2);  
        memset(tsx,0,sizeof(tsx));  
        for(i=0;i<=k-1;i++)  
        {  
            tsx[i*3%k]+=sx[i];  
            tsx[(i*3+1)%k]+=sx[i];  
        }  
        for(i=0;i<=k-1;i++)  
            sx[i]=tsx[i];  
        sx[1]++;  
        sx[cale(n+1)]--;  
    }  
    else  
    {  
        fx(n-1);  
        sx[cale(n)]++;  
    }  
}  
int main()  
{  
    //freopen("k.in","r",stdin);  
    //freopen("k.out","w",stdout);  
    int T;  
    scanf("%d",&T);  
    while(T>0)  
    {  
        T--;  
        int i;  
        long long n;  
        scanf("%lld%d",&n,&k);  
        memset(sx,0,sizeof(sx));  
        fx(n);   
        long long ans=0, sum = 0;  
        for(i=0;i<=k-1;i++)  
            ans=(ans^sx[i]), sum += sx[i];  
    //  for(i=0;i<=k-1;i++)  
    //      printf("%lld ",sx[i]);  
    //  printf("\n");  
//    	cout << sum << endl;
        printf("%lld\n",ans);  
    }  
    return 0;  
}  

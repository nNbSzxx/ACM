#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;
typedef unsigned long long ULL;
ULL  n,K;
const int M = 100;
ULL work(){
    if(n % 4 == 0) return n;
    if(n % 4 == 1) return 1;
    if(n % 4 == 2) return n+1;
    if(n % 4 == 3) return 0;
}
ULL ans;
ULL l[M],r[M],s[M],sd[M];
ULL solve(int deep,ULL left,ULL right){
    if(deep<=0) return 0;
    l[deep]=l[deep+1]/K;
    r[deep]=sd[deep]-l[deep]-1;
    s[deep]=l[deep+1]%K*left+r[deep+1]%K*right+s[deep+1]+1;

    ULL tleft=left*K+1;
    ULL tright=right*K+1;
    ans=ans^s[deep];
    if(l[deep]&1) ans=ans^tleft;
    if(r[deep]&1) ans=ans^tright;
    solve(deep-1,tleft,tright);
    return 0;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n>>K;
        if(n==1){
            printf("1\n");
            continue;
        }
        if(K==1){
        cout<<work()<<endl;
            continue;
        }
        ULL sum=1,tsum=0;
        ULL deep=1;
        ULL tmp=1;
        sd[1]=1;
        while(sum<n){
            tmp=tmp*K;
            tsum=sum;
            sum=sum+tmp;
            deep++;
            sd[deep]=sd[deep-1]*K;
        }
        l[deep]=n-tsum-1;
        r[deep]=0;
        s[deep]=1;

        ans=1;
        if(l[deep]&1) ans=ans^1;
        solve(deep-1,1,0);
        cout<<ans<<endl;
    }
    return 0;
}

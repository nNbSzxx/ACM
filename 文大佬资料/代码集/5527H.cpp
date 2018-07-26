#include<bits/stdc++.h> 
using namespace std;
long long c[12];
long long p;
long long d[12]={0,1,5,10,20,50,100,200,500,1000,2000};
long long sum;
long long  n;
long long anss;
/*int w[12];
int work(int num,int res){
    w[num]=res/d[num];
    return res-res/d[num]*d[num];
}*/

int solve(int num,long long res,long long len){
    //printf("%d %d %d\n",num,res,len);
    if(res==0){
        anss=max(anss,len);
        return 0;
    }
    if(num==0) return 0;
    int t=res/d[num];
    if(c[num]>=t){
        solve(num-1,res-t*d[num],len-t);
    }
    else {
        solve(num-1,res-c[num]*d[num],len-c[num]);
    }
    if(num==5||num==8){
        if(c[num]>=t){
            //if(t) 
            solve(num-1,res-t*d[num]+d[num],len-t+1);
        }
        else {
            //if(c[num]) 
            solve(num-1,res-c[num]*d[num]+d[num],len-c[num]+1);
        }
    }
    return 0;
}

int main(){
    freopen("A.in","r",stdin);
    int T;
    cin>>T;
    while(T--){
        n=0;sum=0;anss=-1;
        cin>>p;
        for(int i=1;i<=10;i++){
             scanf("%lld",&c[i]);
             n+=c[i];
             sum+=c[i]*d[i];
        }
        int res=sum-p;
        if(res<0){
            printf("-1\n");
            continue;
        }
        //printf("AA%d %d\n",res,n);
        solve(10,res,n);
        if(anss==-1){
            printf("-1\n");
            continue;
        }
        printf("%lld\n",anss);
    }
    return 0;
} 

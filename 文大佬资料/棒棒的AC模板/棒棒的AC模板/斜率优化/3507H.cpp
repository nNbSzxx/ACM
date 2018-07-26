#include<iostream>
#include<string>
using namespace std;
const int M = 1234567;
int dp[M];
int q[M];
int sum[M];
int head,tail,n,m;

int getDP(int i,int j){
    return dp[j]+m+(sum[i]-sum[j])*(sum[i]-sum[j]);
}

int getUP(int j,int k){  //yj-yk�Ĳ���{
    return dp[j]+sum[j]*sum[j]-(dp[k]+sum[k]*sum[k]);
}

int getDOWN(int j,int k){ //xj-xk�Ĳ���
    return 2*(sum[j]-sum[k]);
}

int main(){
	freopen("A.in","r",stdin);
    int i;
    while(cin>>n>>m){
        for(i=1;i<=n;i++)
            scanf("%d",&sum[i]);
        sum[0]=dp[0]=0;
        for(i=1;i<=n;i++)
            sum[i]+=sum[i-1];
        head=tail=0;
        q[tail++]=0;
        for(i=1;i<=n;i++){
        	
        	 while(head+1<tail&& getUP(q[head+1],q[head])<=sum[i]*getDOWN(q[head+1],q[head]))
                head++;
                
            dp[i]=getDP(i,q[head]);
        	while(head+1<tail && getUP(i,q[tail-1])*getDOWN(q[tail-1],q[tail-2])<=getUP(q[tail-1],q[tail-2])*getDOWN(i,q[tail-1]))
                tail--;
            	q[tail++]=i;
        	
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}

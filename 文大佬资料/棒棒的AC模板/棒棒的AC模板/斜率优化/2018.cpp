#include<iostream>
using namespace std;
const int M = 1234567;
double ans;
int q[M];
int sum[M];
int head,tail,n,m;
double getUP(int j,int k){  //yj-yk的部分{
    return (double)(sum[j]-sum[k]);
}
double getDOWN(int j,int k){ //xj-xk的部分
    return  (double)j-k;
}
double getDP(int i,int j){
    return getUP(i,j)/getDOWN(i,j); 
}
int main(){
	freopen("A.in","r",stdin);
	cin>>n>>m;
    for(int i=1;i<=n;i++)
        scanf("%d",&sum[i]);
    for(int i=1;i<=n;i++)
        sum[i]+=sum[i-1];
    head=tail=0;
    q[tail++]=0;
    for(int i=m;i<=n;i++){
    	while(head+1<tail&&getDP(i,q[head+1])>=getDP(i,q[head]))
            head++;
		ans=max(ans,getDP(i,q[head])); 
      	int num=i-m+1;
		while(head+1<tail && getUP(num,q[tail-1])*getDOWN(q[tail-1],q[tail-2])<=getUP(q[tail-1],q[tail-2])*getDOWN(num,q[tail-1]))
            tail--;
        	q[tail++]=num;    	
    }
    printf("%d\n",(int)(ans*1000));
    return 0;
}

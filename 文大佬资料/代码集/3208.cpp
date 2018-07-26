#include<bits/stdc++.h> 
using namespace std;

struct Matrix{
	int r,c;
	long long f[10][10];

	int clear(){
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				f[i][j]=0;
			}
		}
		return 0;
	}
	int init(){
		for(int i=1;i<=r;i++){
			f[i][i]=1;
		}
		return 0;
	}
};
Matrix t;
Matrix mul(Matrix A,Matrix B){
	Matrix C;
	C.r=A.r;
	C.c=B.c; 
	C.clear();
	for(int k=1;k<=A.c;k++){
		for(int i=1;i<=A.r;i++){
			for(int j=1;j<=B.c;j++){
				C.f[i][j]+=A.f[i][k]*B.f[k][j];			
			}
		}
	}
	return C;
}
int prin(Matrix A){
	for(int i=1;i<=A.r;i++){
		for(int j=1;j<=A.c;j++){
			printf("%lld ",A.f[i][j]);
		}
		printf("\n");
	}
	return 0;
}
long long  pre_list[]={
0,
0,
0,
1,
19,
280,
3700,
45991,
549739,
6394870,
72915400,
818740081,
9082453159,
99766977760,
1087013539000,
11762766729271,

};

int pre_work(){//打表 pre_list[i]，即i位数666有多少个 
	freopen("A.out","w",stdout);
	t.r=6;
	t.c=6;
	t.f[1][2]=1;
	t.f[1][3]=8;
	t.f[1][4]=1;
	t.f[2][2]=10;
	t.f[3][3]=9;
	t.f[3][4]=1;
	t.f[4][3]=9;
	t.f[4][5]=1;
	t.f[5][3]=9;
	t.f[5][6]=1;
	t.f[6][6]=10;
	Matrix s;
	s.r=6;
	s.c=6;
	s.clear();
	s.init();
	prin(s);
	long long tmp=0; 
	for(int i=1;i<=15;i++){
		s=mul(s,t);
		//prin(s);
		tmp+=s.f[1][6]; 
		printf("%lld\n",tmp);
	}
	return 0;
}
int len;
int st[12];
int dfs(int num,long long  K,int ct,long long last){
	if(ct==3){//三个连续的6已经出现 
		for(int i=len;i>num;i--){
			printf("%d",st[i]);
		}
		if(!num){
			printf("\n"); 
			return 0;
		}
		int tmp=1;
		K--;
		while(K) {
			st[tmp]=K%10;
			K=K/10;
			tmp++;
		}
		for(int i=num;i>0;i--)
			printf("%d",st[i]);
		printf("\n");
		return 0;
	}
	long long f0=pre_list[num-1];
	long long f6=last-9*pre_list[num-1];
	//printf("%lld %lld %d\n",f0,f6,K);
	long long tmp=0,tmp2=0;
	for(int i=0;i<=9;i++){
		if(i!=6) tmp+=f0;
		else tmp+=f6;
		if(K<=tmp){
			st[num]=i;
			if(i!=6)dfs(num-1,K-tmp2,0,f0);
			else dfs(num-1,K-tmp2,ct+1,f6);
			break;
		}
		tmp2=tmp;
	}
	return 0;
} 


int main(){
	//pre_work();//打表求pre_list 
	freopen("A.in","r",stdin);
	int u=3,p=2;
	int T;
	cin>>T;
	while(T--){
		long long n;
		memset(st,0,sizeof(st));
		cin>>n;
		for(int i=1;;i++){
			if(pre_list[i]>=n){
				len=i;break;
			}
		}
		dfs(len,n,0,pre_list[len]);
	}
	return 0;
} 

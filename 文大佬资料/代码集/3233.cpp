#include<bits/stdc++.h> 

using namespace std;
const int M = 100;
int n,m,K;
struct matrix{
	int r,c;
	unsigned int mat[M][M];
	matrix(){
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				mat[i][j]=0;
			}
		}
	}
	matrix prin(){
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				printf("%d ",mat[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
};

matrix add(matrix A,matrix B){
	matrix t;
	t.r=A.r;t.c=A.c;
	for(int i=1;i<=A.r;i++){
		for(int j=1;j<=A.c;j++){
			t.mat[i][j]=A.mat[i][j]+B.mat[i][j];
			if(t.mat[i][j]>=m) t.mat[i][j]%=m;
		}
	}
	return t;
}

matrix mul(matrix A,matrix B){
	matrix t;
	t.r=A.r;t.c=B.c;
	//printf("%d %d\n",t.r,t.c);	
	for(int i=1;i<=A.r;i++){
		for(int j=1;j<=B.c;j++){
			for(int k=1;k<=A.c;k++){
				t.mat[i][j]+=A.mat[i][k]*B.mat[k][j];
				if(t.mat[i][j]>=m) t.mat[i][j]%=m;
			}
		}
	}
	return t;
}
matrix st[50];
matrix work(int L,int R,int D){
	printf("??%d %d %d\n",L,R,D);
	if(L==R){return st[0];}
	if(L+1==R){return add(st[0],st[1]);}
	int mid=L+(1<<D)-1;
	if(R<=mid) return work(L,R,D-1);
	else {
		printf("A");
		matrix q=work(mid+1,R,D-1);
		printf("B");
		matrix s=mul(st[D],q);
		printf("C");
		matrix kmp=add(work(L,mid,D-1),s);
		printf("D");
		return kmp;
		//return add(work(L,mid,D-1),mul(st[D],work(mid+1,R,D-1)));
	}	
}
int main(){
	freopen("A.in","r",stdin);
	//freopen("A.out","w",stdout);
	cin>>n>>K>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>st[0].mat[i][j];
			st[0].mat[i][j]%=m; 
		} 
	}
	st[0].c=n,st[0].r=n;
	int tmp=K,tmp2=-1;
	while(tmp){
		tmp2++;
		tmp=tmp/2;
	}
	for(int i=1;i<=30;i++){
		st[i]=mul(st[i-1],st[i-1]);
	}
	matrix ans=work(1,K,tmp2);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",ans.mat[i][j]); 
		}
		printf("\n"); 
	}
	return 0;
}

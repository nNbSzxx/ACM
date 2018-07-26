#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define M 1123
using namespace std;
int n,m;
int lowbit(int t){
	return t&(-t);
}
int c[M][M];

int update(int x,int y,int val){
	register int tx=x,ty;
	while(tx<=n){
		ty=y;
		while(ty<=n){
			//printf("ABC%d %d\n",tx,ty);
			c[tx][ty]+=val;
			ty=ty+lowbit(ty); 
		}
		tx=tx+lowbit(tx);
	}
	return 0;
}

int query(int x,int y){
	register int tx=x,ty,sum=0;
	while(tx>0){
		ty=y;
		while(ty>0){
			//printf("QQQ%d %d\n",tx,ty);
			
			sum+=c[tx][ty];
			ty=ty-lowbit(ty); 
		}
		tx=tx-lowbit(tx);
	}
	return sum;
}
char flag[5050];
int main(){
	freopen("A.txt","r",stdin); 
	int T;
	scanf("%d",&T);
	while(T--){
		
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				c[i][j]=0;
			}
		}
		//n++;
		for(int i=1;i<=m;i++) {
				int t;
				scanf("%s",flag);
				int x1,x2,y1,y2;
				cin>>x1>>y1;
				//x1++,y1++;
				if(flag[0]==67){
					cin>>x2>>y2;
					//x2++;y2++;
					update(x1,y1,1);
					//puts("");
					update(x1,y2+1,1);
					//puts("");
					update(x2+1,y1,1);
					//puts("");
					update(x2+1,y2+1,1); 
					//puts("");
				
				}
				else {
					printf("%d\n",1&query(x1,y1));
				}
		}
		printf("\n");
		
	}
	return 0; 
}

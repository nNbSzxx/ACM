#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
const int M  = 10000000+123;
using namespace std;
int tree[M][5];
int ans,sz=1,n,m;
int build(int num,int x1,int x2,int y1,int y2){
	int midx=(x1+x2)>>1,midy=(y1+y2)>>1;
	if(x1!=x2){
		tree[num][1]=++sz;
		build(sz,x1,midx,y1,midy);
		tree[num][2]=++sz;
		build(sz,midx+1,x2,y1,midy);
		if(y1!=y2){
			tree[num][3]=++sz;
			build(sz,x1,midx,midy+1,y2);
			tree[num][4]=++sz;
			build(sz,midx+1,x2,midy+1,y2); 
		}
	}
	else if(y1!=y2){
		tree[num][1]=++sz;
		build(sz,x1,x2,y1,midy);
		tree[num][3]=++sz;
		build(sz,x1,x2,midy+1,y2); 
	}
	return 0;
}
int query(int x1,int x2,int y1,int y2,int num,int X1,int X2,int Y1,int Y2){
	ans=ans+(X2-X1+1)*(Y2-Y1+1)*tree[num][0];
	if(X1<=x1&&Y1<=y1&&X2>=x2&&Y2>=y2)return 0;
	int midx=(x1+x2)>>1,midy=(y1+y2)>>1;
	
	if(X1<=midx&&Y1<=midy&&tree[num][1]){query(x1,midx,y1,midy,tree[num][1],max(x1,X1),min(midx,X2),max(y1,Y1),min(midy,Y2));}
	if(X2>midx&&Y1<=midy&&tree[num][2]) {query(midx+1,x2,y1,midy,tree[num][2],max(midx+1,X1),min(x2,X2),max(y1,Y1),min(midy,Y2));}
	if(X1<=midx&&Y2>midy&&tree[num][3]) {query(x1,midx,midy+1,y2,tree[num][3],max(x1,X1),min(midx,X2),max(midy+1,Y1),min(y2,Y2));}
	if(X2>midx&&Y2>midy&&tree[num][4])  {query(midx+1,x2,midy+1,y2,tree[num][4],max(midx+1,X1),min(x2,X2),max(midy+1,Y1),min(y2,Y2));}
	return 0;
}

int modefy(int x1,int x2,int y1,int y2,int num,int X1,int X2,int Y1,int Y2,int val){
	if(X1<=x1&&Y1<=y1&&X2>=x2&&Y2>=y2){
		tree[num][0]+=val;
		return 0;
	}
	int midx=(x1+x2)>>1,midy=(y1+y2)>>1;
	
	if(X1<=midx&&Y1<=midy&&tree[num][1]){modefy(x1,midx,y1,midy,tree[num][1],X1,X2,Y1,Y2,val);}
	if(X2>midx&&Y1<=midy&&tree[num][2]) {modefy(midx+1,x2,y1,midy,tree[num][2],X1,X2,Y1,Y2,val);}
	if(X1<=midx&&Y2>midy&&tree[num][3]) {modefy(x1,midx,midy+1,y2,tree[num][3],X1,X2,Y1,Y2,val);}
	if(X2>midx&&Y2>midy&&tree[num][4])  {modefy(midx+1,x2,midy+1,y2,tree[num][4],X1,X2,Y1,Y2,val);}
	return 0;
}
int prin(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ans=0;
			query(1,m,1,n ,1,j,j,i,i);
			printf("%d ",ans);
		}
		printf("\n");
	}
}
int main(){
	freopen("A.in","r",stdin);
	scanf("%d%d",&n,&m);
	int t;
	scanf("%d",&t);
	build(1,1,m,1,n);
	while(t--){
		int c;
		int x1,x2,y1,y2,val;
		cin>>c;
		cin>>x1>>y1>>x2>>y2;
		swap(x1,y1);swap(y2,x2);
		if(c==1) {
			cin>>val;
			modefy(1,m,1,n,1,x1,x2,y1,y2,val);			
		}
		else {
			ans=0;
			query(1,m,1,n ,1,x1,x2,y1,y2);
			printf("%d\n",ans);
		}
	}
	return 0;
} 

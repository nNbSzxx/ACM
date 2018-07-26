#include<bits/stdc++.h> 
const int M  = 10000000+123;
using namespace std;

int tree[M][5];

int sz=1;
int nb;
int sum[M],ct[M];
int build(int num,int x1,int x2,int y1,int y2){
	ct[num]=(x2-x1+1)*(y2-y1+1);
	int midx=(x1+x2)>>1;
	int midy=(y1+y2)>>1;
	
	//if(x1==x2&&y1==y2){nb++;printf(" %d %d %d %d %d %d\n",nb,y1,x1,y2,x2);}
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

int ans;


int update(int num){
	for(int i=1;i<=4;i++){
		if(tree[num][i]){
			tree[tree[num][i]][0]=tree[num][0];
			sum[tree[num][i]]=(tree[num][0]==1?ct[tree[num][i]]:0);
		}
	}
	tree[num][0]=0;
	return 0;
}

int cl;
int query(int x1,int x2,int y1,int y2,int num,int X1,int X2,int Y1,int Y2){
	//cl++;
	//if(cl>=30) return 0;
	//printf("%d abc%d\n %d %d %d %d\n %d %d %d %d\n",cl,num,y1,x1,y2,x2,Y1,X1,Y2,X2);
	//if(tree[num][0]) printf("AAAAAAAAAAAAA%d %d %d %d %d \n %d %d %d %d\n",tree[num][0],y1,x1,y2,x2,Y1,X1,Y2,X2);
	if(X1<=x1&&Y1<=y1&&X2>=x2&&Y2>=y2){
		ans=ans+sum[num];
		return 0;
	}
	if(tree[num][0])update(num);	
	int midx=(x1+x2)>>1;
	int midy=(y1+y2)>>1;
	if(X1<=midx&&Y1<=midy&&tree[num][1]){query(x1,midx,y1,midy,tree[num][1],max(x1,X1),min(midx,X2),max(y1,Y1),min(midy,Y2));}
	if(X2>midx&&Y1<=midy&&tree[num][2]) {query(midx+1,x2,y1,midy,tree[num][2],max(midx+1,X1),min(x2,X2),max(y1,Y1),min(midy,Y2));}
	if(X1<=midx&&Y2>midy&&tree[num][3]) {query(x1,midx,midy+1,y2,tree[num][3],max(x1,X1),min(midx,X2),max(midy+1,Y1),min(y2,Y2));}
	if(X2>midx&&Y2>midy&&tree[num][4])  {query(midx+1,x2,midy+1,y2,tree[num][4],max(midx+1,X1),min(x2,X2),max(midy+1,Y1),min(y2,Y2));}
	return 0;
}

int getsum(int num){
	sum[num]=0;
	for(int i=1;i<=4;i++){
		if(tree[num][i])sum[num]+=sum[tree[num][i]];
	}
	return 0;
}

int ck;
int modefy(int x1,int x2,int y1,int y2,int num,int X1,int X2,int Y1,int Y2,int val){
	//ck++;
	//if(ck>=100) return 0;
	//printf("%d abc%d\n %d %d %d %d\n %d %d %d %d\n",ck,num,y1,x1,y2,x2,Y1,X1,Y2,X2);
	//system("pause");
	if(X1<=x1&&Y1<=y1&&X2>=x2&&Y2>=y2){
		tree[num][0]=val;
		if(val==1)sum[num]=(x2-x1+1)*(y2-y1+1);
		else sum[num]=0;
		//printf("%d %d %d %d\n",y1,x1,y2,x2);
		//printf("%d abc%d\n %d %d %d %d\nMMM %d %d %d %d\n",sum[num],num,y1,x1,y2,x2,Y1,X1,Y2,X2);
		//printf("%d\n",val);
		return 0;
	}
	if(tree[num][0])update(num); 
	
	int midx=(x1+x2)>>1;
	int midy=(y1+y2)>>1;
	
	if(X1<=midx&&Y1<=midy&&tree[num][1]){modefy(x1,midx,y1,midy,tree[num][1],X1,X2,Y1,Y2,val);}
	if(X2>midx&&Y1<=midy&&tree[num][2]) {modefy(midx+1,x2,y1,midy,tree[num][2],X1,X2,Y1,Y2,val);}
	if(X1<=midx&&Y2>midy&&tree[num][3]) {modefy(x1,midx,midy+1,y2,tree[num][3],X1,X2,Y1,Y2,val);}
	if(X2>midx&&Y2>midy&&tree[num][4]) {modefy(midx+1,x2,midy+1,y2,tree[num][4],X1,X2,Y1,Y2,val);}
	
	getsum(num);
	return 0;
}

char s[50]; 
int main(){
	freopen("A.in","r",stdin);
	int n=150,m=150;
	int t;
	scanf("%d",&t);
	build(1,1,m,1,n);
	while(t--){
		cin>>s;
		int x1,x2,y1,y2,val,L;
		cin>>x1>>y1>>L;
		swap(x1,y1);
		x2=x1+L-1;y2=y1+L-1;
		if(s[0]=='T'){
			ans=0;
			query(1,m,1,n ,1,x1,x2,y1,y2);
			printf("%d\n",ans);
		}		
		else {
			val=(s[0]=='B'?1:2);
			modefy(1,m,1,n,1,x1,x2,y1,y2,val);
		}
		/*puts("");
		for(int i=1;i<=6;i++){
			for(int j=1;j<=6;j++){
				ans=0;
				query(1,m,1,n ,1,j,j,i,i);
				printf("%d ",ans);
			}
			printf("\n");
		}*/
	}
		
	return 0;

} 

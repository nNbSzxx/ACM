#include<bits/stdc++.h> 
using namespace std;
const int M = 123;
const int N = M*M;
int vis[M][M];
int vis1[M][M];
int vis2[M][M][5];
char s[M*M];
int d[M][M][2];
int c[M*M][2];
// right1 left2 down 3 up 4

int dx[5]={0,1,-1,0,0};
int dy[5]={0,0,0,-1,1};

struct pos{
	int x,y;
	pos(int x=0,int y=0):x(x),y(y){};
};
int X,Y,m;
int endx,endy;
int change(int x1,int y1,int x2,int y2){
	if(x1==x2-1) return 1;
	if(x1==x2+1) return 2; 
	if(y1==y2+1) return 3;
	if(y1==y2-1) return 4;
	return 0; 
}

int make_tab(int num,int x,int y){
	if(x<=0||y<=0||x>X||y>Y) return 1;
	vis[x][y]=1;
	if(num==strlen(s)){endx=x,endy=y; return 0;}
	if(s[num]=='U') y=y+1;
	if(s[num]=='D') y=y-1;
	if(s[num]=='L') x=x-1;
	if(s[num]=='R') x=x+1;
	
	make_tab(num+1,x,y);
	return 0;
}

int init(){
	for(int i=1;i<=X;i++){
		for(int j=1;j<=Y;j++){
			for(int k=1;k<=4;k++){
				vis2[i][j][k]=0;
			}
			d[i][j][0]=N;
			d[i][j][1]=N;
			vis[i][j]=0;
		}
	}
	return 0;
}

int read(){
	cin>>X>>Y;
	cin>>s;
	cin>>m;
	int cnt=0;
	init();
	int x1,y1,x2,y2;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		x1++,y1++,x2++,y2++;
		c[++cnt][0]=x1;c[cnt][1]=y1;
		c[++cnt][0]=x2;c[cnt][1]=y2;
		vis2[x1][y1][change(x1,y1,x2,y2)]=1;
		swap(x1,x2);swap(y1,y2);
		vis2[x1][y1][change(x1,y1,x2,y2)]=1;
	}
	return 0;
}

queue<pos>q;
int spfa(int num){
	if(num==0){
		q.push(pos(1,1));
		d[1][1][0]=0;
	}
	if(num==1){
		q.push(pos(endx,endy));
		d[endx][endy][1]=0;
	}
	while(!q.empty()){
		pos t=q.front();
		q.pop();
		int tx=t.x,ty=t.y;
		vis1[tx][ty]=0;
		for(int i=1;i<=4;i++){
			if(vis2[tx][ty][i]) continue;
			int px=tx+dx[i];
			int py=ty+dy[i];
			if(px<=0||px>X) continue;
			if(py<=0||py>Y) continue;
			 
			if(d[tx][ty][num]<d[px][py][num]){
				d[px][py][num]=d[tx][ty][num]+1;
				if(vis1[px][py]==0){
					vis1[px][py]=1;
					q.push(pos(px,py));
				}
			}
		}
	} 
	return 0;
}

int check(){
	for(int i=1;i<=X;i++){
		for(int j=1;j<=Y;j++){
			if(d[i][j][0]+d[i][j][1]==d[1][1][0]+d[1][1][1]&&vis[i][j]==0){return 1;}					
			if(d[i][j][0]+d[i][j][1]>N) return 1;
		}
	}
	for(int i=1;i<=m*2;i=i+2){
		int x1=c[i][0];
		int y1=c[i][1];
		int x2=c[i+1][0];
		int y2=c[i+1][1];
		if((d[x1][y1][0]+d[x2][y2][1]>=d[1][1][0]+d[1][1][1])&&(d[x2][y2][0]+d[x1][y1][1]>=d[1][1][0]+d[1][1][1])){  return 1;}
		
	} 
	return 0;
}
int prin(){
	printf("%d %d\n",endx,endy);
	for(int i=Y;i>=1;i--){
		for(int j=1;j<=X;j++){
			printf("%-3d",d[j][i][0]); 
		} 
		puts("");
	}
	printf("\n\n");
	for(int i=Y;i>=1;i--){
		for(int j=1;j<=X;j++){
			printf("%-3d",d[j][i][1]); 
		} 
		puts("");
	}
	return 0;
}
int main(){
	freopen("A.in","r",stdin);
	//freopen("A.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		read();
		make_tab(0,1,1);
		spfa(0);
		spfa(1);
		prin();
		if(check()) printf("IN");
		printf("CORRECT\n"); 
	} 

}
 





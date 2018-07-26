#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int c[105][105][105];
int n;
int lowbit(int x){
    return x&-x;
}
int update(int x,int y,int z,int k){
    for(int i=x; i<=n; i+=lowbit(i))
        for(int j=y; j<=n; j+=lowbit(j))
            for(int l=z; l<=n; l+=lowbit(l))
        		c[i][j][l]+=k;
   	return 0; 
}
int sum(int x,int y,int z){
    int sum=0;
    for(int i=x; i>0; i-=lowbit(i))
        for(int j=y; j>0; j-=lowbit(j))
            for(int k=z; k>0; k-=lowbit(k))
                sum+=c[i][j][k];
    return sum;
}
int main(){
    int m;
    int x2,x1,y2,y1,z2,z1,k;
    while(~scanf("%d %d",&n,&m)){
        memset(c,0,sizeof(c));
        for(int i=0; i<m; i++){
            scanf("%d %d %d %d",&k,&x1,&y1,&z1);
            if(k==0)
                printf("%d\n",sum(x1,y1,z1)%2);
            else{
                scanf("%d %d %d",&x2,&y2,&z2);
                update(x1,y1,z1,1);
                update(x1,y1,z2+1,1);
                update(x1,y2+1,z1,1);
                update(x1,y2+1,z2+1,1);
                update(x2+1,y1,z1,1);
                update(x2+1,y1,z2+1,1);
                update(x2+1,y2+1,z1,1);
                update(x2+1,y2+1,z2+1,1);
            }
        }
    }
    return 0;
}

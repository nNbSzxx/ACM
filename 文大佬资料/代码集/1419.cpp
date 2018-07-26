#include<bits/stdc++.h> 
using namespace std;

const int MAXV=100+3;
int V,E,ans;
bool G[MAXV][MAXV];//补图
int the_max[MAXV];//在第i个到最后一个点形成的子图中最大团的大小
int save[MAXV];//最大团
int select[MAXV];//当前团

int init(){
    for(int i=1;i<=V;++i)
        for(int j=1;j<=V;++j)
            G[i][j]=true;
   	return 0;
}

int dfs(int u,int num){
    if(num>ans){//找到更大的团，更新答案
        ans=num;
        	for(int i=0;i<num;++i)
            	save[i]=select[i];
    }
    for(int v=u+1;v<=V;++v){
		//剪枝：只选择比当前节点编号大的节点，避免重复搜索
        if(the_max[v]+num<=ans) continue;
		//A*剪枝，如果继续搜最优情况也不能更新答案
        if(G[u][v]){
            int i;
            for(i=0;i<num;++i){
                if(!G[v][select[i]])break;
            }
            if(i==num){//和现在团中每个顶点都相邻
                select[num]=v;
                dfs(v,num+1);
            }
        }
    }
    return 0;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&V,&E);
        init();
        ans=0;
        for(int i=0;i<E;++i){
            int u,v;
            scanf("%d%d",&u,&v);
            G[u][v]=G[v][u]=false;
        }
        for(int u=V;u>0;u--){//不断增大搜索的范围，用于得到估值函数
            select[0]=u;//添加到当前团中
            dfs(u,1);
            the_max[u]=ans;//得到估值函数中的一个值
            //the_max[v]保存的是由编号只由比v大的点组成的子集的当前最优解，
			//故最终答案是the_max[1]
        }
        printf("%d\n",the_max[1]);
        for(int i=0;i<the_max[1];i++){
        	if(i!=0) printf(" ");	
            printf("%d",save[i]);
        }
    	printf("\n");
	}
    return 0;
}

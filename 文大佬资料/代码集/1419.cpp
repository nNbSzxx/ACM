#include<bits/stdc++.h> 
using namespace std;

const int MAXV=100+3;
int V,E,ans;
bool G[MAXV][MAXV];//��ͼ
int the_max[MAXV];//�ڵ�i�������һ�����γɵ���ͼ������ŵĴ�С
int save[MAXV];//�����
int select[MAXV];//��ǰ��

int init(){
    for(int i=1;i<=V;++i)
        for(int j=1;j<=V;++j)
            G[i][j]=true;
   	return 0;
}

int dfs(int u,int num){
    if(num>ans){//�ҵ�������ţ����´�
        ans=num;
        	for(int i=0;i<num;++i)
            	save[i]=select[i];
    }
    for(int v=u+1;v<=V;++v){
		//��֦��ֻѡ��ȵ�ǰ�ڵ��Ŵ�Ľڵ㣬�����ظ�����
        if(the_max[v]+num<=ans) continue;
		//A*��֦������������������Ҳ���ܸ��´�
        if(G[u][v]){
            int i;
            for(i=0;i<num;++i){
                if(!G[v][select[i]])break;
            }
            if(i==num){//����������ÿ�����㶼����
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
        for(int u=V;u>0;u--){//�������������ķ�Χ�����ڵõ���ֵ����
            select[0]=u;//��ӵ���ǰ����
            dfs(u,1);
            the_max[u]=ans;//�õ���ֵ�����е�һ��ֵ
            //the_max[v]��������ɱ��ֻ�ɱ�v��ĵ���ɵ��Ӽ��ĵ�ǰ���Ž⣬
			//�����մ���the_max[1]
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

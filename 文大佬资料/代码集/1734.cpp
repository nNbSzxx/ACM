#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std; 
const int N = 123;
const int INF = 0x7ffffff;
int mat[N][N],dist[N][N],pre[N][N],path[N],n;

int main(){
	int i,j,k,m,a,b,c;
	int num;
	while(~scanf("%d%d",&n,&m)){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				mat[i][j]=dist[i][j]=INF;
				pre[i][j]=i;
			}
		}
		while(m--){
			scanf("%d%d%d",&a,&b,&c);
			mat[a][b]=mat[b][a]=dist[a][b]=dist[b][a]=min(mat[a][b],c);
		}

		int min=INF;
		for(k=1;k<=n;k++){
			//���·����һ�㽫���·��β����,��ô�͵õ�һ����С��
			for(i=1;i<k;i++){
				for(j=i+1;j<k;j++){
				/*����С����������������·�ɳ�,��Ϊ(i,k)֮������·,
				��Ϊ(k,j)֮������·�������غϵĲ���
				����mat[][]��ʵ�ǲ����µ�,����͵�����floyd���·��һ��
				dist[i][j]������� i �� j �����·Ȩֵ��*/	
				int tmp=dist[i][j]+mat[i][k]+mat[k][j];
				//���� k �ֱ�� i ���� j ��mat��ֱ������
					if(tmp<min){
						min=tmp;
						num=0;
						int p=j;
						while(p!=i){//����
							path[num++]=p;
							p=pre[i][p];
							//pre[i][j]��ʾi��j���·���� j ǰ���һ����
						}
						path[num++]=i;
						path[num++]=k;
					}
				}
			}
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					if(dist[i][j]>dist[i][k]+dist[k][j]){
						dist[i][j]=dist[i][k]+dist[k][j];
						pre[i][j]=pre[k][j];
						//��¼��i��j·������j����ĵ���˭������·��ѹ���� 
					}
				}
			}
		}
		if(min==INF)puts("No solution.");
		else{
			printf("%d",path[0]);
			for(i=1;i<num;i++)
				printf(" %d",path[i]);
			puts("");
		}
	}
	return 0;
}

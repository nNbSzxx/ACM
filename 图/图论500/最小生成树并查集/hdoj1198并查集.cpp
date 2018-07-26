#include<cstdio>
#include<cstring>

const int MAX = 3000+10;

int father[MAX];
int road[12][4]=//方向为上左右下,有管道即为1.  按上左右下排序 有利于下面的计算 
{
    0,0,0,0,
    1,1,0,0,
    1,0,1,0,
    0,1,0,1,
    0,0,1,1,
    1,0,0,1,
    0,1,1,0,
    1,1,1,0,
    1,1,0,1,
    0,1,1,1,
    1,0,1,1,
    1,1,1,1
};
char map[55][55];
int find(int x)
{
    while (x != father[x]) {
    	father[x] = father[father[x]];
    	x = father[x];
	}
	return x;
}
void merge(int x,int y)
{
    x = find(x);
    y = find(y);
    if(x != y)
    	father[x]=y;
}
int main()
{
    int n,m,i,j,k,sum;
    int move[4][2]={-1,0,0,-1,0,1,1,0};
    int next_x,next_y;
    char c;
    while(scanf("%d%d",&n,&m), n != -1 || m != -1)
    {
        for(i = 1; i <= n * m; i ++)
        	father[i]=i;
        for(i = 1; i <= n; i ++)
        {
            for(j = 1; j <= m;j ++)
            {
                scanf(" %c",&map[i][j]);
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                for(k=0;k<4;k++)
                {
                    next_x = i + move[k][0];
                    next_y = j + move[k][1];
                    if(next_x>=1&&next_x<=n&&next_y>=1&&next_y<=m)
                    {
                        if(road[map[next_x][next_y]-'A'+1][3-k]&&road[map[i][j]-'A'+1][k])
                    		merge(next_y+m*(next_x-1),j+m*(i-1)); 
                    }
                }
            }
        }
        sum=0;
        for(i=1;i<=n*m;i++)
        {
            if(father[i] == i)
            sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}

//每次从行最低的最左边开始放 
#include<bits/stdc++.h> 
using namespace std;
int col[41],cake[11],size,number;
int GetMinRow(){
    int i,minRow,min=41;
    for(i=1;i<=size;i++)
        if(col[i]<min){
            min=col[i];
            minRow=i;
        }
    return minRow;
}
int dfs(int curNum){
    int j,i,minRow;
    bool ok=false;
    if(curNum==number)  return 1;
    minRow=GetMinRow();
 
    for(j=10;j>0;j--){
        ok=false;
        if(cake[j] && minRow+j-1<=size && col[minRow]+j<=size){
            for(i=minRow;i<minRow+j;i++){
                if(col[i]>col[minRow]) break;
            }
            if(i==minRow+j) ok=true;
        }
        if(ok){
            cake[j]--;
            for(i=minRow;i<minRow+j;i++)
            {
                col[i]+=j;
            }
 
            if(dfs(curNum+1)) return 1;
 
            for(i=minRow;i<minRow+j;i++)
            {
                col[i]-=j;
            }
            cake[j]++;
        }
    }
    return 0;
}
int main(){
	freopen("A.in","r",stdin); 
    int i,n,sum,c;
    scanf("%d",&n);
    while(n--){
        memset(cake,0,sizeof(cake));
        scanf("%d%d",&size,&number);
        for(sum=0,i=0;i<number;i++){
            scanf("%d",&c);
            cake[c]++;
            sum+=c*c;
        }
        if(sum!=size*size) {
            printf("HUTUTU!\n");
            continue;
        }
        memset(col,0,sizeof(col));
        if(dfs(0)==0)
            printf("HUTUTU!\n");
        else
            printf("KHOOOOB!\n");
    }
    return 0;
}

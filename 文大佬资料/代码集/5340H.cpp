#include<bits/stdc++.h>
using namespace std; 
const int maxn=50000;
char str[maxn];//原字符串 
char tmp[maxn<<1];//转换后的字符串 
int Len[maxn<<1]; 
//转换原始串 
int init(char *st) { 
    int i,len=strlen(st); 
    tmp[0]='@';//字符串开头增加一个特殊字符，防止越界 
    for(i=1;i<=2*len;i+=2){ 
        tmp[i]='#'; 
        tmp[i+1]=st[i/2]; 
    } 
    tmp[2*len+1]='#'; 
    tmp[2*len+2]='$';//字符串结尾加一个字符，防止越界 
    tmp[2*len+3]=0; 
    return 2*len+1;//返回转换字符串的长度 
} 
//Manacher算法计算过程 
int ans;
int manacher(char *st,int len) { 
     int mx=0,po=0;//mx即为当前计算回文串最右边字符的最大值 
     for(int i=1;i<=len;i++){ 
         if(mx>i) 
         Len[i]=min(mx-i,Len[2*po-i]);//在Len[j]和mx-i中取个小 
         else 
         Len[i]=1;//如果i>=mx，要从头开始匹配 
         while(st[i-Len[i]]==st[i+Len[i]]) 
         Len[i]++; 
         if(Len[i]+i>mx)//若新计算的回文串右端点位置大于mx，要更新po和mx的值 
         { 
             mx=Len[i]+i; 
             po=i; 
         } 
         ans=max(ans,Len[i]); 
     } 
     //return ans-1;//返回Len[i]中的最大值-1即为原串的最长回文子串长度  
	return 0;
}

int l[maxn],r[maxn];
int main(){

	freopen("A.in","r",stdin);
	int T;
	cin>>T;
	while(T--){
		ans=0;//最长回文长度 
		cin>>str;
		int len=init(str);
		len=init(str);
		manacher(tmp,len);/*
		printf("%s\n",tmp);
		printf(" ");
		for(int i=1;i<=len;i++){
			printf("%d",Len[i]);
		}
		printf("\n");*/
		int flag=1;
		l[0]=0,r[0]=0;
		for(int i=2;i<=len;i+=2){
			int x=(i+2)/2;
			if(Len[x]>i/2) l[++l[0]]=i;
		}
		for(int i=2;i<=len;i+=2){
			int y=(len-1+i)/2;
			if(Len[y]>(len+1-i)/2) r[++r[0]]=i;
		}
		//无耻卡常数，所以只记录能够哪些点可以作为第一个串和第三个串 
		for(int i=1;i<=l[0];i++){
			int x=l[i];
			for(int j=r[0];j>=1;j--){
				int y=r[j];
				if(x+4>y) break;
				int z=(x+y)/2;
				if(Len[z]>(y-x-2)/2){
					//printf("PP%d %d \n",x,y);
					flag=0;break;
				}
			}
		}
		if(flag)printf("No\n");
		else printf("Yes\n");
	}
	return 0;
} 

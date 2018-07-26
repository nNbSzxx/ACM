#include<bits/stdc++.h>
 using namespace std;
const int M = 1000000+123;
const int N= 250000; 
int sum[M];
int trank[M],rank[M];
int sa[M],tsa[M];	
int s[M];
int height[M];
int p[M];
int vis[M];
int len;
int maxlen=M-1;  

 void sorting(int j){//基数排序
 	memset(sum,0,sizeof(sum));
 	for (int i=1; i<=len; i++) sum[ rank[i+j] ]++;
 	for (int i=1; i<=maxlen; i++) sum[i]+=sum[i-1];
 	for (int i=len; i>0; i--)
             tsa[ sum[ rank[i+j] ]-- ]=i;
        //对第二关键字计数排序，tsa代替sa为排名为i的后缀是tsa[i] 
 
 	memset(sum,0,sizeof(sum));
 	for (int i=1; i<=len; i++) sum[ rank[i] ]++;
 	for (int i=1; i<=maxlen; i++) sum[i]+=sum[i-1];
 	for (int i=len; i>0; i--)
             sa[ sum[ rank[ tsa[i] ] ]-- ]= tsa[i]; 
        //对第一关键字计数排序,构造互逆关系 
} 
void get_sa(){
 	int p;
 	for (int i=0; i<len; i++) trank[i+1]=s[i];
 	for (int i=1; i<=len; i++) sum[ trank[i] ]++;
 	for (int i=1; i<=maxlen; i++) sum[i]+=sum[i-1];
 	for (int i=len; i>0; i--) 
 		sa[ sum[ trank[i] ]-- ]=i;
 	rank[ sa[1] ]=1;
 	for (int i=2,p=1; i<=len; i++){
 		if (trank[ sa[i] ]!=trank[ sa[i-1] ]) p++;
 		rank[ sa[i] ]=p;
 	}//第一次的sa与rank构造完成
 	for (int j=1; j<=len; j*=2){
 		sorting(j);
 		trank[ sa[1] ]=1; p=1; //用trank代替rank 
 		for (int i=2; i<=len; i++){
 			if ((rank[ sa[i] ]!=rank[ sa[i-1] ]) || (rank[ sa[i]+j ]!=rank[ sa[i-1]+j ])) p++;
 			trank[ sa[i] ]=p;//空间要开大一点，至少2倍
 		}
 		for (int i=1; i<=len; i++) rank[i]=trank[i];
 	}
}
void get_height(){
 	for (int i=1,j=0; i<=len; i++){//用j代替上面的h数组
 		if (rank[i]==1) continue;
 		for (; s[i+j-1]==s[ sa[ rank[i]-1 ]+j-1 ]; ) j++;//注意越界之类的问题 
 		height[ rank[i] ]=j;
 		if (j>0) j--;
 	}
}

char ss[M];
char ts[M];
int prin();
int ll[M];
int main(){
	freopen("A.in","r",stdin);	
	int T;
	cin>>T;
	int ct=0;
	while(T--){
		memset(sum,0,sizeof(sum));
		memset(s,0,sizeof(s));
		ct++;
		printf("Case #%d: ",ct);
		int n;
		cin>>n;
		len=0;
		for(int i=1;i<=n;i++){
			s[len++]=i+N;
			p[len]=0;
			cin>>ss;
			int L=strlen(ss);
			for(int j=0;j<L;j++){
			
				s[len++]=ss[j]-'a'+1;
				p[len]=i;
			}	
		}
		
 		p[len+1]=0;
		get_sa();
		get_height();
		int ans=0;
		int flag=1;
		int Ans=len;
		for(int i=len;i>=1;i--){
			if(p[sa[i]]==1){
					ll[i]=ans;
				ans=min(ans,height[i]);
			}
			else ans=height[i]; 
		}
		ans=0;
		for(int i=1;i<=len;i++){
			if(p[sa[i]]==1){
				ans=min(ans,height[i]);
				ll[i]=max(ll[i],ans);
				if(p[sa[i]+ll[i]]==1) Ans=min(Ans,ll[i]);
			}
			else ans=len;
		}
		for(int i=1;i<=len;i++){
			if(p[sa[i]]==1){
				if(p[sa[i]+ll[i]]==1&&Ans==ll[i]){
					flag=0;
					for(int j=sa[i];j<=sa[i]+ll[i];j++){
						printf("%c",s[j-1]+'a'-1);
					}
					printf("\n");
					break;
				}
				
			}
			else ans=len;
		}
		if(flag){
			printf("Impossible\n");
		}
	}
	return 0; 
}


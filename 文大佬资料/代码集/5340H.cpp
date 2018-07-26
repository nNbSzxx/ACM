#include<bits/stdc++.h>
using namespace std; 
const int maxn=50000;
char str[maxn];//ԭ�ַ��� 
char tmp[maxn<<1];//ת������ַ��� 
int Len[maxn<<1]; 
//ת��ԭʼ�� 
int init(char *st) { 
    int i,len=strlen(st); 
    tmp[0]='@';//�ַ�����ͷ����һ�������ַ�����ֹԽ�� 
    for(i=1;i<=2*len;i+=2){ 
        tmp[i]='#'; 
        tmp[i+1]=st[i/2]; 
    } 
    tmp[2*len+1]='#'; 
    tmp[2*len+2]='$';//�ַ�����β��һ���ַ�����ֹԽ�� 
    tmp[2*len+3]=0; 
    return 2*len+1;//����ת���ַ����ĳ��� 
} 
//Manacher�㷨������� 
int ans;
int manacher(char *st,int len) { 
     int mx=0,po=0;//mx��Ϊ��ǰ������Ĵ����ұ��ַ������ֵ 
     for(int i=1;i<=len;i++){ 
         if(mx>i) 
         Len[i]=min(mx-i,Len[2*po-i]);//��Len[j]��mx-i��ȡ��С 
         else 
         Len[i]=1;//���i>=mx��Ҫ��ͷ��ʼƥ�� 
         while(st[i-Len[i]]==st[i+Len[i]]) 
         Len[i]++; 
         if(Len[i]+i>mx)//���¼���Ļ��Ĵ��Ҷ˵�λ�ô���mx��Ҫ����po��mx��ֵ 
         { 
             mx=Len[i]+i; 
             po=i; 
         } 
         ans=max(ans,Len[i]); 
     } 
     //return ans-1;//����Len[i]�е����ֵ-1��Ϊԭ����������Ӵ�����  
	return 0;
}

int l[maxn],r[maxn];
int main(){

	freopen("A.in","r",stdin);
	int T;
	cin>>T;
	while(T--){
		ans=0;//����ĳ��� 
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
		//�޳ܿ�����������ֻ��¼�ܹ���Щ�������Ϊ��һ�����͵������� 
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

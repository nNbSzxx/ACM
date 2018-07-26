#include<stdio.h>  
#include<string.h>  
#include<math.h>  
#include<iostream>  
#include<algorithm>  
#define MAXN 110  
#define MAX(a,b) a>b?a:b  
using namespace std;  
char s1[MAXN];  
char s2[MAXN];  
int v[MAXN];  
char ans[MAXN];  
int dp[110][110];  
int main()  
{  
    int i,j;  
    while(scanf("%s%s",s1+1,s2+1)!=EOF)//刚开始从0开始写，但是写着写着发现乱了，然后又滚回来从1写  
    {  
        int len1=strlen(s1+1);  
        int len2=strlen(s2+1);  
        memset(dp,0,sizeof(dp));  
        for(i=1;i<=len1;i++)  
        {  
            for(j=1;j<=len2;j++)  
            {  
                dp[i][j]=s1[i]==s2[j]?(dp[i-1][j-1]+1):max(dp[i-1][j],dp[i][j-1]);  
            }  
        }  
        int cnt=0;  
        while(dp[len1][len2])  
        {  
            if(s1[len1]==s2[len2])  
            {  
                ans[cnt++]=s1[len1];  
                len1--;len2--;  
            }  
            else  
            dp[len1-1][len2]>dp[len1][len2-1]?ans[cnt++]=s1[len1--]:ans[cnt++]=s2[len2--];  
        }  
        while(len1>0)  
        ans[cnt++]=s1[len1--];  
        while(len2>0)  
        ans[cnt++]=s2[len2--];  
        for(i=cnt-1;i>=0;i--)  
        printf("%c",ans[i]);  
        printf("\n");  
    }  
    return 0;  
}  

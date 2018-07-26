#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
typedef long long ll;

using namespace std;
char a[105];
char flag[27];
int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        memset(a,0,sizeof(a));
        memset(flag,0,sizeof(flag));
        char c;
        for(int i = 0; i < n; i++)
        {
            cin>>c;
            flag[c-'a']++;
        }
        int stda = n/k;
        int cnt = 0;
        for(int i = 0; i < k-n%k; i++)
        {
            for(int j = 0; j < 26; j++)
            {
                if(flag[j] > 0)
                {
                    flag[j]--;
                    cnt++;
                }
                if(cnt == stda)
                {
                    cnt = 0;break;
                }
            }
           if(cnt < stda && cnt!= 0){
                break;}
        }
        if(cnt == 0)
        {
            for(int i = k-n%k; i < k; i++)
            {
                for(int j = 0; j < 26; j++)
                {
                    if(flag[j] > 0)
                    {
                        flag[j]--;
                        cnt++;
                    } 
                    if(cnt == stda)
                    {
                        cnt = 0;break;
                    }
                }
            if(cnt < stda)
                    break;
            }
        }
        if(cnt!=0)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}

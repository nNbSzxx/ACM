#include<cstdio>
#include<queue>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
queue<int>q;
#define MOD 998244353
int child[2645][2],fail[2645],size,f[2][2645][64],tag[2645],tag2[2645];
void Insert(string S,int id)
{
    int len=S.length();
    int now=0;
    for(int i=0;i<len;++i)
      {
        if(!child[now][S[i]-'0'])
          child[now][S[i]-'0']=size++;
        now=child[now][S[i]-'0'];
      }
    tag[now]|=(1<<id);
}
void Inser2(string S,int id){
    int len=S.length();
    int now=0;
    for(int i=0;i<len;++i)
      {
        if(!child[now][S[i]-'0'])
          child[now][S[i]-'0']=size++;
        now=child[now][S[i]-'0'];
      }
    tag2[now]|=(1<<id);
}
void build()
{
    fail[0]=-1;
    q.push(0);
    while(!q.empty())
      {
        int U=q.front(); q.pop();
        for(int i=0;i<2;++i)
          if(child[U][i])
            {
              int V=fail[U];
              while(V!=-1)
                {
                  if(child[V][i])
                    {
                      fail[child[U][i]]=child[V][i];
                      break;
                    }
                  V=fail[V];
                }
              if(V==-1)
                fail[child[U][i]]=0;
              tag[child[U][i]]|=tag[fail[child[U][i]]];
              tag2[child[U][i]]|=tag2[fail[child[U][i]]];
              q.push(child[U][i]);
            }
          else if(U)
            child[U][i]=child[fail[U]][i];
      }
}
void Init()
{
    memset(child,0,sizeof(child));
    memset(fail,0,sizeof(fail));
    memset(tag,0,sizeof(tag));
    memset(tag2,0,sizeof(tag2));
    size=1;
}
int n,m,T;
int main()
{
//  freopen("b.in","r",stdin);
    scanf("%d",&T);
    string s;
    for(;T;--T){
        scanf("%d%d",&m,&n);
        Init();
        for(int i=0;i<m;++i){
            cin>>s;
            int len=s.length();
//              cout<<"::"<<s<<endl;
            Insert(s,i);
            string t=s;
            reverse(t.begin(),t.end());
            for(int j=0;j<len;++j){
                t[j]=((t[j]-'0')^1)+'0';
            }
//              cout<<"::"<<t<<endl;
            Insert(t,i);
            for(int j=0;j<min(len,n);++j){
                bool flag=1;
                for(int k=j+1,l=j;k<s.length() && l>=0;++k,--l){
                    if((s[k]-'0')^(s[l]-'0')!=1){
                        flag=0;
                        break;
                    }
                }
                if(!flag){
                    continue;
                }
                t=s.substr(0,j+1);
                for(int k=(j+1)*2;k<s.length();++k){
                    t=(char)(((s[k]-'0')^1)+'0')+t;
                }
//              cout<<":"<<t<<endl;
                Inser2(t,i);
            }
        }
        build();
        memset(f,0,sizeof(f));
        f[0][0][0]=1;
        bool cur=0;
        for(int i=0;i<n;++i){
          memset(f[cur^1],0,sizeof(f[cur^1]));
          for(int j=0;j<size;++j)
            for(int k=0;k<(1<<m);++k){
                if(!f[cur][j][k])
                  continue;
                if(i<n-1)
                for(int l=0;l<2;++l)
                  f[cur^1][child[j][l]][k|tag[child[j][l]]]=
                    (f[cur^1][child[j][l]][k|tag[child[j][l]]]+f[cur][j][k])%MOD;
                else{
                  for(int l=0;l<2;++l)
                    f[cur^1][child[j][l]][k|tag[child[j][l]]|tag2[child[j][l]]]=
                      (f[cur^1][child[j][l]][k|tag[child[j][l]]|tag2[child[j][l]]]+f[cur][j][k])%MOD;
                }
            }
          cur^=1;
        }
        int ans=0;
        for(int j=0;j<size;++j)
            ans=(ans+f[cur][j][(1<<m)-1])%MOD;
        printf("%d\n",ans);
      }
    return 0;
}

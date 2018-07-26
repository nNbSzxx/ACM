#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define idx(x) x - 'a';
using namespace std;
const int MAXN = 3e6;
struct Trie {
    int next[26];
    int val;
}tree[MAXN];
int nxt, T;
char str[200005];
char ss[500005];
char s1[500005];
char s2[500005];
int ans;
struct xx
{
    int l,r;
}a[100005];
struct xxx
{
    int l,r,num,ll,rr;
}b[100005];
int anss[100005];
int add()
{
    memset(&tree[nxt], 0, sizeof(Trie));
    return nxt++;
}

void Insert(char *s)
{
    int rt = 0, len = strlen(s);
    for(int i = 0; i < len; i++) {
        int c = idx(s[i]);
        tree[rt].val++;
        if(!tree[rt].next[c]) {
            tree[rt].next[c] = add();
        }
        rt = tree[rt].next[c];
    }
    tree[rt].val++;
}

int cmp1(xx p,xx q)
{
    return(p.r-p.l)<(q.r-q.l);
}
int cmp2(xxx p,xxx q)
{
    return(p.r+p.rr-p.ll-p.l)<(q.rr+q.r-q.ll-q.l);
}
void cal(int i,int len,int now)
{
    if(i==len) {
        ans+=tree[now].val;
        return ;
    }
    if(str[i]=='#'){
        for(int j=0;j<26;j++){
            if(tree[now].next[j]) cal(i+1,len,tree[now].next[j]);

        }
    }
    else{
        if(tree[now].next[str[i]-'a'])
            cal(i+1,len,tree[now].next[str[i]-'a']);
    }

}
void init1(int x)
{
    int l=a[x].l,r=a[x].r;
    int summ=0;
    for(int j=l;j<r;j++){
        str[summ++]=ss[j];
        str[summ++]=ss[r-j+l-1];
    }
    str[summ]=0;
}
int init2(int x)
{
    int len1=b[x].r-b[x].l;
    int len2=b[x].rr-b[x].ll;
    int nn=max(len1,len2);
    int sum=0;
    for(int j=0;j<nn;j++){
        if(j<len1) str[sum++]=s1[j+b[x].l];
        else{
            str[sum++]='#';
        }
        if(len2-j-1>=0) str[sum++]=s2[b[x].rr-j-1];
        else{
            str[sum++]='#';
        }
    }
    str[sum]=0;
    ans=0;
    return sum;
}
int main()
{

    scanf("%d", &T);
    while(T--) {
        memset(&tree[0], 0, sizeof(Trie));
        nxt = 1;
        int n,m;
        scanf("%d %d",&n,&m);
        int sum=0;
        for(int i=0;i<n;i++){
            scanf("%s",ss+sum);
            a[i].l=sum;
            sum+=strlen(ss+sum);
            a[i].r=sum;
        }
        sort(a,a+n,cmp1);
        int sum1=0,sum2=0;
        for(int i=0;i<m;i++){
            scanf("%s %s",s1+sum1,s2+sum2);
            b[i].l=sum1;
            sum1+=strlen(s1+sum1);
            b[i].r=sum1;
            b[i].ll=sum2;
            sum2+=strlen(s2+sum2);
            b[i].rr=sum2;
            b[i].num=i;
        }

        sort(b,b+m,cmp2);
        int noww=n-1;
        for(int i=m-1;i>=0;i--){

            while(a[noww].r-a[noww].l>=b[i].rr+b[i].r-b[i].l-b[i].ll&&noww<n){
                init1(noww);
                noww--;

                Insert(str);
            }
            sum=init2(i);
            ans=0;
            cal(0,sum,0);
            anss[b[i].num]=ans;
        }
        for(int i=0;i<m;i++) printf("%d\n",anss[i]);
    }
    return 0;
}


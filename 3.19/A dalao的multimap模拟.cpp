#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef multimap<string,string>::iterator It;
typedef pair<It,It> PItIt;
int n;
queue<string> Q;
multimap<string,string> mp;
set<string> vis;
string group1,buf,group,member;
inline void init() {
    mp.clear();
    vis.clear();
    while (!Q.empty()) Q.pop();
    int p1,p2;
    for (int i=0; i<n; i++) {
        cin>>buf;
        buf.at(buf.size()-1)=',';
        group=buf.substr(0,buf.find(':'));
        if (i==0) group1=group;
        p1=buf.find(':');
        p2=buf.find(',');
        while (p1!=string::npos && p2!=string::npos && p1!=p2) {
            member=buf.substr(p1+1,p2-p1-1);
            mp.insert(make_pair(group,member));
            buf.at(p1)='.';
            buf.at(p2)='.';
            p1=p2;
            p2=buf.find(',');
        }
    }
}
inline void solve() {
    PItIt memberrange;
    memberrange=mp.equal_range(group1);
    for (It i=memberrange.first; i!=memberrange.second; i++) {
        vis.insert((*i).second);
        Q.push((*i).second);
    }
    while (!Q.empty()) {
        member=Q.front(); Q.pop();
        memberrange=mp.equal_range(member);
        for (It i=memberrange.first; i!=memberrange.second; i++)
        if (vis.find((*i).second)==vis.end()) {
            vis.insert((*i).second);
            Q.push((*i).second);
        }
    }
    int cnt,ans=0;
    for (set<string>::iterator sit=vis.begin(); sit!=vis.end(); sit++) {
        cnt=mp.count(*sit);
        if (cnt==0) ans++;
    }
    printf("%d\n",ans);
}
int main() {
   // freopen("in.txt","r",stdin);
    while (~scanf("%d",&n) && n) {
        init();
        solve();
    }
}


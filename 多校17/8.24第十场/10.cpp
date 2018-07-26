#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
struct node{
    int s, e;
} a[MAX];
bool cmp(const node& a1, const node& a2){
    return a1.s < a2.s;
}
multiset<int> st;

int main(){
    int t, n;
    scanf("%d", &t);
    while(t --){
        scanf("%d", &n);
        st.clear();
        for(int i = 0; i < n; i ++)
            scanf("%d%d", &a[i].s, &a[i].e);
        sort(a, a + n, cmp);
        long long ans = 0;
        for(int i = 0; i < n; i ++) {
            auto it = st.upper_bound(a[i].s);
            if(it == st.begin()) {
                ans += a[i].e - a[i].s;
                st.insert(a[i].e);
            } else {
                it --;
                ans += a[i].e - *it;
                st.erase(it);
                st.insert(a[i].e);
            }
        }
        printf("%d %lld\n", st.size(), ans);
    }
    return 0;
}

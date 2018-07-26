#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 +10;
const int RANGE = 1e9;
struct Node {
    int rangeL, rangeR;
    int left, right;
    vector<int> id;
} tree[MAX << 5];
int n, xx[MAX], yy[MAX], cnt = 1, flag, ans;

void add(int x, int l, int r, int id)
{
    if (l <= tree[x].rangeL && tree[x].rangeR <= r) {
        tree[x].id.push_back(id);
        //printf("add %d %d %d %d\n", l, r, tree[x].rangeL, tree[x].rangeR);
        return;
    }
    int mid = (tree[x].rangeL + tree[x].rangeR) >> 1;
    if (l <= mid) {
        if (!tree[x].left) {
            tree[x].left = ++ cnt;
            tree[cnt].rangeL = tree[x].rangeL;
            tree[cnt].rangeR = mid;
        }
        add(tree[x].left, l, r, id);
    }
    if (mid < r) {
        if (!tree[x].right) {
            tree[x].right = ++ cnt;
            tree[cnt].rangeL = mid + 1;
            tree[cnt].rangeR = tree[x].rangeR;
        }
        add(tree[x].right, l, r, id);
    }
}

bool check(int rx, int ry, int tx, int ty)
{
    //printf("%d %d %d %d\n", rx, ry,tx, ty);
    return 1LL * (rx - tx) * (rx - tx) + 1LL * (ry - ty) * (ry - ty) < 1LL * ry * ry;
}

void query(int x, int tx, int ty)
{
    if (!x)
        return ;
    for (int i = 0; i < tree[x].id.size(); i ++) {
        if (check(xx[tree[x].id[i]], yy[tree[x].id[i]], tx, ty)) {
            ans = tree[x].id[i];
			return ;
        }
    }
    int mid = (tree[x].rangeL + tree[x].rangeR) >> 1;
    int ret;
    if (tx <= mid)
        query(tree[x].left, tx, ty);
    else
        query(tree[x].right, tx, ty);
    return ;
}

void del(int x, int l, int r, int id)
{
    if (!x)
        return ;
    if (l <= tree[x].rangeL && tree[x].rangeR <= r) {
    	
        auto it = lower_bound(tree[x].id.begin(), tree[x].id.end(), id);
        tree[x].id.erase(it);
        return ;
        
        /*
        vector<int>::iterator d = tree[x].id.end();
        for (auto it = tree[x].id.begin(); it != tree[x].id.end(); it ++) {
        	if (*it == id) {
        		d = it;
        		break;
			}
		}
		if (d != tree[x].id.end()) {
			tree[x].id.erase(d);
			return ;
		}
		*/
    }
    int mid = (tree[x].rangeL + tree[x].rangeR) >> 1;
    if (l <= mid)
        del(tree[x].left, l, r, id);
    if (mid < r)
        del(tree[x].right, l, r, id);
}

int main()
{
    // memset(tree, 0, sizeof tree);
    int t, tx, ty;
    scanf("%d", &n);
    tree[1].rangeL = -RANGE;
    tree[1].rangeR = RANGE;
    for (int i = 1; i <= n; i ++) {
        scanf("%d%d%d", &t, &tx, &ty);
        if (t == 1) {
            add(1, tx - ty, tx + ty, i);
            xx[i] = tx;
            yy[i] = ty;
        } else {
            ans = -1;
            query(1, tx, ty);
            if (ans != -1)
                del(1, xx[ans] - yy[ans], xx[ans] + yy[ans], ans);
            printf("%d\n", ans);
        }
    }
    return 0;
}

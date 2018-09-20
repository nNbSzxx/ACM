// 笛卡尔树，中序遍历得到原数组，从数组元素的值来看是堆
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
const int MAX = 5e4 + 10;

struct Node {
    int idx; // 在数组中的下标
    int v;   // 数组元素的值
    int id;  // 输入时的顺序
} node[MAX];

int n;
int l[MAX], r[MAX], p[MAX];
stack<Node> s;

bool cmp(const Node& n1, const Node& n2)
{
    return n1.idx < n2.idx;
}

// 单调栈，保存建树过程中的右链，这里是小根堆
// 最后栈底元素就是整棵树的根
void build()
{
    while (!s.empty()) {
        s.pop();
    }
    s.push(node[1]);
    int id = node[1].id;
    l[id] = r[id] = p[id] = 0;
    // 由于是按照下标排序，故每次插入一定是在树右链的末端
    for (int i = 2; i <= n; i ++) {
        Node now;    // 当前栈顶节点
        Node last;   // 最近一次弹出的节点
        last.id = 0; // 初始化
        // 寻找右链中第一个比待插入节点元素值小的节点
        while (!s.empty()) {
            now = s.top();
            if (now.v < node[i].v) {
                break;
            }
            last = s.top();
            s.pop();
        }

        if (s.empty()) {
            // 没有找到比待插入节点更小的元素，待插入的是当前最小的
            int curid = node[i].id;
            int lastid = last.id;
            // 把整棵树链到待插入节点的左儿子上，待插入的成为新的根
            p[curid] = r[curid] = 0;
            l[curid] = lastid;
            p[lastid] = curid;
        } else {
            // 找到了比待插入元素更小的节点
            int curid = node[i].id;
            int lastid = last.id;
            int fatherid = now.id;
            // 把待插入节点成为其右儿子
            p[curid] = fatherid;
            r[fatherid] = curid;
            // 原来的右子树变成待插入节点的左子树
            l[curid] = lastid;
            r[curid] = 0;
            p[lastid] = curid;
        }
        // 更新右链
        s.push(node[i]);
    }
}

int main()
{
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; i ++) {
            scanf("%d%d", &node[i].idx, &node[i].v);
            node[i].id = i;
        }
        // 按照下标从小到大排序
        sort(node + 1, node + 1 + n, cmp);
        build();
        puts("YES");
        for (int i = 1; i <= n; i ++) {
            printf("%d %d %d\n", p[i], l[i], r[i]);
        }
    }
    return 0;
}

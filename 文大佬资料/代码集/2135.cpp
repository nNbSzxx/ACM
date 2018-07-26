#include<bits/stdc++.h> 
using namespace std;
#define INFINITE 1 << 26
#define MAX_NODE 1005
#define MAX_EDGE_NUM 40005
struct Edge{
    int to;
    int vol;
    int cost;
    int next;
};
Edge gEdges[MAX_EDGE_NUM];
 
int gHead[MAX_NODE];
int gPre[MAX_NODE];
int gPath[MAX_NODE];
int gDist[MAX_NODE];
 
int gEdgeCount;
void InsertEdge(int u, int v, int vol, int cost){
    gEdges[gEdgeCount].to = v;
    gEdges[gEdgeCount].vol = vol;
    gEdges[gEdgeCount].cost = cost;
    gEdges[gEdgeCount].next = gHead[u];
    gHead[u] = gEdgeCount++;
 
    gEdges[gEdgeCount].to = u;
    gEdges[gEdgeCount].vol = 0;         //volΪ0����ʾ��ʼʱ�򣬸ñߵķ���ͨ
    gEdges[gEdgeCount].cost = -cost;    //cost Ϊ����ߵ�cost�෴��������Ϊ��
    gEdges[gEdgeCount].next = gHead[v];
    gHead[v] = gEdgeCount++;
}
 
//����ͼ�в����ڸ�Ȩ�ͻ�,SPFA�㷨�ҵ����·��/��Դ��s���յ�t�������ߵ�cost֮����С��·��
bool Spfa(int s, int t){
    memset(gPre, -1, sizeof(gPre));
    memset(gDist, 0x7F, sizeof(gDist));
    gDist[s] = 0;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()){//���ڲ����ڸ�Ȩ�ͻ������һ�������
        int u = Q.front();
        Q.pop();
 
        for (int e = gHead[u]; e != -1; e = gEdges[e].next){
            int v = gEdges[e].to;
            if (gEdges[e].vol > 0 && gDist[u] + gEdges[e].cost < gDist[v]){
                gDist[v] = gDist[u] + gEdges[e].cost;
                gPre[v] = u; //ǰһ����
                gPath[v] = e;//�õ����ӵ�ǰһ����
                Q.push(v);
            }
        }
    }
 
    if (gPre[t] == -1)  //���յ�tû������pre��˵�������ڵ����յ�t��·��
        return false;
    return true;
}
 
int MinCostFlow(int s, int t){
    int cost = 0;
    int flow = 0;
    while (Spfa(s, t)){
        int f = INFINITE;
        for (int u = t; u != s; u = gPre[u]){
            if (gEdges[gPath[u]].vol < f)
                f = gEdges[gPath[u]].vol;
        }
        flow += f;
        cost += gDist[t] * f;
        for (int u = t; u != s; u = gPre[u]){
            gEdges[gPath[u]].vol -= f;   //�������������
            gEdges[gPath[u]^1].vol += f; //�������������
        }
    }
    return cost;
}
int main(){
    int n, m, u, v, d;
    while (scanf("%d %d", &n, &m) != EOF){
        gEdgeCount = 0;
        memset(gHead, -1, sizeof(gHead));
        InsertEdge(0, 1, 2, 0);
        for (int i = 0; i < m; i++){
            scanf("%d %d %d", &u, &v, &d);
            InsertEdge(u, v, 1, d);
            InsertEdge(v, u, 1, d);
        }
        InsertEdge(n, n + 1, 2, 0);
 
        int ans = MinCostFlow(0, n + 1);
        printf("%d\n", ans);
    }
    return 0;
}

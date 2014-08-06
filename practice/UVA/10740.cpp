#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define Maxn 111
#define Maxm 1111
#define MOD 1000000007
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define SZ size()
int n, m;
vector<pair<int, int> > e[Maxn], e1[Maxn];
priority_queue<pair<int, int> > que;
priority_queue<pair<int, pair<int, int> > >Q;
vector<int> path;
int s, t, k;
int h[Maxn];

void spfa(int s, int t) {
    int i, j, u, v, tp, d;
    for(i = 1; i <= n; i++) {
        h[i] = MOD;
    }
    h[t] = 0;
    while(!que.empty()) que.pop();
    que.push(MP(0, t));
    while(!que.empty()) {
        u = que.top().BB;
        d = -que.top().AA;
        que.pop();
        if(h[u] != d) continue;
        for(j = 0; j < e1[u].SZ; j++) {
            v = e1[u][j].AA;
            tp = e1[u][j].BB + d;
            if(h[v] > tp) {
                h[v] = tp;
                que.push(MP(-h[v], v));
            }
        }
    }
}

void Astar(int s, int t) {
    int i, j, u, v, d, f, g, cur;
    while(!Q.empty()) Q.pop();
    path.clear();
    Q.push(MP(-h[s], MP(0, s)));
    for(cur = 0; cur < k && !Q.empty(); ) {
        u = Q.top().BB.BB;
        d = -Q.top().BB.AA;
        Q.pop();
        if(u == t) {
            cur++;
            path.PB(d);
        }
        for(j = 0; j < e[u].SZ; j++) {
            v = e[u][j].AA;
            g = e[u][j].BB + d;
            f = g + h[v];
            Q.push(MP(-f, MP(-g, v)));
        }
    }
}

int main() {
    int i, j, u, v, w;
    while(scanf("%d%d", &n, &m) != EOF && n && m) {
        scanf("%d%d%d", &s, &t, &k);
        for(i = 1; i <= n; i++) {
            e[i].clear(); e1[i].clear();
        }
        for(i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            e[u].PB(MP(v, w));
            e1[v].PB(MP(u, w));
        }
        spfa(s, t);
        Astar(s, t);
        if(path.SZ < k) printf("-1\n");
        else printf("%d\n", path[k - 1]);
    }
    return 0;
}

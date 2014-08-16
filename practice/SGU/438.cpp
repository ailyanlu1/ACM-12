#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
 
#define PB push_back
#define PF push_front
#define PPB pop_back
#define PPF pop_front
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define OP begin()
#define ED end()
#define SORT(x) sort(x.begin(), x.end())
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)
 
const double eps = 1e-8;
const LL MOD = 1000000007;
const LL USE = 20000;
const LL INF = 0x3f3f3f3f;
#define Maxn 11111
#define Maxm 611111
struct node {
    int u, v, c, next;
}e[Maxm];
int tot, last[Maxn];
int cur[Maxn], dist[Maxn], que[Maxn], sta[Maxn], head, tail, top;

void adde(int u, int v, int c, int c1) {
//    cout << "adde " << u << "->" << v << " " << c << endl;
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
    e[tot].u = v; e[tot].v = u; e[tot].c = c1; e[tot].next = last[v]; last[v] = tot++;
}

bool bfs(int s, int t, int n) {
    int i, j, u, v;
    for(i = 0; i < n; i++) dist[i] = MOD;
    dist[s] = 0;
    head = tail = 0;
    que[tail++] = s;
    while(head < tail) {
        u = que[head++];
        for(j = last[u]; j != -1; j = e[j].next) {
            if(e[j].c == 0) continue;
            v = e[j].v;
            if(dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                if(v == t) return true;
                que[tail++] = v;
            }
        }
    }
    return false;
}

int dinic(int s, int t, int n) {
    int i, j, u, v;
    int maxflow = 0;
    while(bfs(s, t, n)) {
        for(i = 0; i < n; i++) cur[i] = last[i];
        u = s; top = 0;
        while(cur[s] != -1) {
            if(u == t) {
                int tp = MOD;
                for(i = top - 1; i >= 0; i--) {
                    tp = min(tp, e[sta[i]].c);
                }
                maxflow += tp;
                for(i = top - 1; i >= 0; i--) {
                    e[sta[i]].c -= tp;
                    e[sta[i] ^ 1].c += tp;
                    if(e[sta[i]].c == 0) top = i;
                }
                u = e[sta[top]].u;
            }
            else if(cur[u] != -1 && e[cur[u]].c > 0 && dist[u] + 1 == dist[e[cur[u]].v]) {
                sta[top++] = cur[u];
                u = e[cur[u]].v;
            }
            else {
                while(u != s && cur[u] == -1) {
                    u = e[sta[--top]].u;
                }
                cur[u] = e[cur[u]].next;
            }
        }
    }
    return maxflow;
}
int x[100], y[100], f[55][55], C[100], mp[55][55], n, c, D, W, m;
int main() {
    int i, j, k, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    while(scanf("%d%d%d%d", &n, &c, &D, &W) != EOF) {
        for(i = 1; i <= n; i++)scanf("%d%d%d", &x[i], &y[i], &C[i]);
        if(D >= W) {
            printf("%d\n", 1);
            continue;
        }
        for(i = 0; i <= n + 3; i++) {
            for(j = 0; j <= n + 3; j++) {
                f[i][j] = USE;
                mp[i][j] = 0;
            }
        }
        for(i = 1; i <= n; i++) {
            for(j =1 ; j <= n; j++) {
                int d = SQ(x[i] - x[j]) + SQ(y[i] - y[j]);
                if(d <= SQ(D)) f[i][j] = 1, mp[i][j] = 1;
            }
            f[i][i] = 0;
            if(y[i] <= D) f[n + 1][i] = 1;
            if(W - y[i] <= D) f[i][n + 2] = 1;
        }
        m = n + 2;
        for(k = 1; k <= m; k++) {
            for(i = 1; i <= m; i++) {
                for(j = 1; j <= m; j++) {
                    cmin(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }
//        for(i = 1; i <= m; i++) {
//            for(j = 1; j <= m; j++) printf("%8d ", f[i][j]); printf("\n");
//        }
        int N = 1, S = 0, T = 1;
        int cur = 0;
        last[0] = last[1] = -1;
        tot = 0;
        for(k = 1; k <= n + m + 1; k++) {
            int nn = 2 * n;
            for(i = 1; i <= nn; i++) last[i + N] = -1;
            for(i = 1; i <= n; i++) {
                u = i + N; v = i + n + N;
                adde(u, v, C[i], 0);
                if(f[n + 1][i] == 1) adde(S, u, MOD, 0);
                if(f[i][n + 2] == 1) adde(v, T, MOD, 0);
            }
            if(k > 1) {
                for(i = 1; i <= n; i++) {
                    for(j = 1; j <= n; j++) {
                        if(mp[i][j]) adde(i + n + N - nn, j + N, MOD, 0);
                    }
                }
            }
            N += nn;
            int flow = dinic(S, T, N + 1);
            cur += flow;
//            cout << cur << " " << flow << endl;
            if(cur >= c) break;
        }
        if(cur >= c) 
            printf("%d\n", k+1);
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}


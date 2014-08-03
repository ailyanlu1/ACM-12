#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;
#define Maxn 50100
#define Maxm 105000
struct node {
    int u, v, next;
    LL l;
}e[Maxm];
int tot, last[Maxn];
LL dist[Maxn];
LL value[Maxn];
bool visit[Maxn];
queue<int> Q;
#define MOD (1LL<<60)
int n, m;

void adde(int u, int v, int l) {
    e[tot].u = u; e[tot].v = v; e[tot].l = l; e[tot].next = last[u]; last[u] = tot++;
    e[tot].u = v; e[tot].v = u; e[tot].l = l; e[tot].next = last[v]; last[v] = tot++;
}

void spfa() {
    int i, j, u, v;
    for(i = 1; i <= n; i++) {
        dist[i] = MOD;
        visit[i] = false;
    }
    while(!Q.empty()) Q.pop();
    Q.push(1);
    dist[1] = 0;
    visit[1] = true;
    while(!Q.empty()) {
        u = Q.front();
        Q.pop();
        visit[u] = false;
        for(j = last[u]; j != -1; j = e[j].next) {
            v = e[j].v;
            if(dist[v] > dist[u] + e[j].l) {
                dist[v] = dist[u] + e[j].l;
                if(!visit[v]) {
                    visit[v] = true;
                    Q.push(v);
                }
            }
        }
    }
}

int main() {
    int i, j;
    int u, v;
    int T;
    scanf("%d", &T);

    for(int CA = 1; CA <= T; CA++) {
        scanf("%d%d", &n, &m);
        tot = 0;
        for(i = 1; i <= n + 10; i++) last[i] = -1;
        for(i = 1; i <=n; i++) scanf("%I64d", &value[i]);
        for(i = 1; i <= m; i++) {
            scanf("%d%d%d", &u, &v, &j);
            adde(u, v, j);
        }
        spfa();
        LL ans = 0;
        for(i = 1; i <= n; i++) {
            if(dist[i] == MOD) break;
            ans += dist[i] * value[i];
        }
        if(i > n) printf("%I64d\n", ans);
        else printf("No Answer\n");
    }
    return 0;
}

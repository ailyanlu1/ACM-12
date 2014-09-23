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
const LL MOD = 10007;
const LL INF = 0x3f3f3f3f;
#define Maxn 311
#define Maxm 111111

#define eps 1e-10
#define fabs(x) ((x)>eps?(x):-(x))
#define ZERO(x) (fabs(x) > eps ? 0 : 1)
LL inv[MOD+5];
int tot;
LL gauss_tpivot (int n, LL a[][Maxn]) {
    LL ret = 1;
    int i, j, k;
    LL p , q;
    tot = 0;
    for (k = 0; k < n; k++) {
        if(!a[k][k]) {
            for(i = k + 1; i < n; i++) if(a[i][k]) break;
            if(i >= n) return 0;
            for(j = k; j < n; j++) {
                swap(a[k][j], a[i][j]);
            }
            ret *= -1;
        }
        if(a[k][k] < 0) {
            for(j = 0; j < n; j++) a[k][j] *= -1;
        }
        p = a[k][k];
        ret = ret * p % MOD;
        for(i = k + 1; i < n; i++) {
            q = a[i][k] * inv[a[k][k]] % MOD;
            for(j = k + 1; j < n; j++) {
                a[i][j] = (a[i][j] - a[k][j] * q) % MOD;
                if(a[i][j] < 0) a[i][j] += MOD;
            }
        }
    }
    return ret % MOD;
}

int fa[Maxn];
int getfa(int x) {return (fa[x] == x ? x : (fa[x] = getfa(fa[x])));}
LL a[Maxn][Maxn], b[Maxn][Maxn];
vector<PII> pt;
void Out(int n, LL a[][Maxn]) {
    int i, j;
    cout << endl;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int n, R;
int main() {
    int i, j, k, u, v, w;
    int xx0, xx1, yy0, yy1;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    for(inv[1]=1,i=2;i<MOD;i++)inv[i] = inv[MOD%i]*(MOD-MOD/i) % MOD;
    int te;
    scanf("%d", &te);
    for(int ca = 1; ca <= te; ca++) {
        scanf("%d%d", &n, &R);
        R *= R;
        pt.clear();
        for(i = 0; i < n; i++) {
            scanf("%d%d", &u, &v);
            pt.PB(MP(u, v));
        }
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                a[i][j] = b[i][j] = 0;
            }
        }
        sort(pt.OP,pt.ED);
        for(i = 0; i < n; i++) {
            for(j = i + 1; j < n; j++) {
                int dist = SQ(pt[i].AA - pt[j].AA) + SQ(pt[i].BB - pt[j].BB);
                if(dist <= R) {
                    xx0 = min(pt[i].AA, pt[j].AA); 
                    xx1 = max(pt[i].AA, pt[j].AA);
                    yy0 = min(pt[i].BB, pt[j].BB);
                    yy1 = max(pt[i].BB, pt[j].BB);
                    for(k = i + 1; k < j; k++) {
                        if(xx0 <= pt[k].AA && pt[k].AA <= xx1
                        && yy0 <= pt[k].BB && pt[k].BB <= yy1) {
                            if((pt[k].AA - pt[i].AA ) * (pt[j].BB - pt[i].BB) ==
                               (pt[k].BB - pt[i].BB ) * (pt[j].AA - pt[i].AA)) break;
                        }
                    }
                    if(k >= j){
                        a[i][i]++; a[j][j]++;
                        b[i][j] = b[j][i] = 1;
                    }
                }
            }
        }
        for(i = 0; i < n; i++) fa[i] = i;
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(b[i][j]) {
                    fa[getfa(j)] = getfa(i);
                }
            }
        }
//        Out(n, a);
//        Out(n, b);
        LL ans = 0;
        for(j = 0; j < n; j++) if(getfa(j) != getfa(0)) break;
        if(j < n) {
            printf("-1\n");
            continue;
        }
        for(i = 0; i < n; i++) {
            for(j = 0; j< n; j++) {
                a[i][j] -= b[i][j];
            }
        }
        printf("%I64d\n", gauss_tpivot(n - 1, a) % MOD);
    }
    return 0;
}

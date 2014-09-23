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
const LL MOD1 = 1000000007;
const LL MOD2 = 1000000009;
#define Maxn 55
#define Maxm 111111
//hdu 4305 MOD = 10007
//答案取模, 每一步需要取模处理
LL getinv(LL x, LL MOD) {
    LL ret = 1;
    LL M = MOD - 2;
    while(M > 0) {
        if(M & 1) ret = ret * x % MOD;
        x = x * x % MOD;
        M >>= 1;
    }
    return ret % MOD;
}
LL extGcd (LL a, LL b, LL &x, LL &y) {
    LL ret = a;
    if (b) {
        ret = extGcd (b, a % b, y, x);
        y -= (a / b) * x;
    } else x = 1, y = 0;
    return ret;
}
LL modInv (LL a, LL m) {
    LL x, y;
    extGcd(a,m,x,y);
    return (m+x%m)%m;
}
//a_i*x=b_i {%m_i}  m_i可以不互质
//pair<b,m>         x=b {%m}
pair<LL,LL> linearMod( vector<LL>&A,vector<LL>&B,vector<LL>&M ) {
    LL x=0,m=1;
    for ( int i=0; i<A.SZ; i++ ) {
        LL a=A[i]*m,b=B[i]-A[i]*x,d=__gcd( M[i],a );
        if ( b%d )return MP( 0,-1 );
        LL t=b/d*modInv( a/d,M[i]/d )%( M[i]/d );
        x+=m*t;
        m*=M[i]/d;
        x%=m;
    }
    return MP( ( ( x%m )+m )%m,m );
}
LL gauss_tpivot (int n, LL a[][Maxn], LL MOD) {
    LL ret = 1;
    int i, j, k;
    LL p , q;
    for (k = 0; k < n; k++) {
        if(!a[k][k]) {
            for(i = k + 1; i < n; i++) if(a[i][k]) break;
            if(i >= n) return 0;
            for(j = k; j < n; j++) {
                swap(a[k][j], a[i][j]);
            }
            ret *= -1;
        }
        p = a[k][k];
        ret = ret * p % MOD;
        for(i = k + 1; i < n; i++) {
            q = a[i][k] * getinv(a[k][k], MOD) % MOD;
            for(j = k + 1; j < n; j++) {
                a[i][j] = (a[i][j] - a[k][j] * q) % MOD;
                if(a[i][j] < 0) a[i][j] += MOD;
            }
        }
    }
    return ret % MOD;
}
LL a[Maxn][Maxn], b[Maxn][Maxn];
int c[Maxn][Maxn];
int n, m, k;
void Outit(int n, LL a[Maxn][Maxn]) {
    int i, j;
    cout << endl;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
int main() {
    int i, j, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
//    cout << getinv(1, MOD1) << endl;
//    cout << getinv(2, MOD1) << endl;
    while(scanf("%d%d%d", &n, &m, &k) != EOF) {
        for(i = 0; i <= n; i++) {
            for(j = 0; j <= n; j++){
               c[i][j] = a[i][j] = b[i][j] = 0;
            }
        }
        for(i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            u--, v--;
            c[u][v] = c[v][u] = 1;
        }
        for(i = 0; i < n; i++) {
            for(j = i + 1; j < n; j++) {
                if(!c[i][j]) {
                    a[i][i]++; a[j][j]++;
                    b[i][j] = b[j][i] = 1;
                }
            }
        }
//        Outit(n, a);
//        Outit(n, b);
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                b[i][j] = a[i][j] -= b[i][j];
            }
        }
//        Outit(n, a);
//        Outit(n, b);
        LL ans1 = gauss_tpivot(n - 1, a, MOD1);
        LL ans2 = gauss_tpivot(n - 1, b, MOD2);
        
        vector<LL> M; M.PB(MOD1); M.PB(MOD2);
        vector<LL> B; B.PB(ans1); B.PB(ans2);
        vector<LL> A; A.PB(1); A.PB(1);
        LL ans = linearMod(A, B, M).AA;
        cout << ans << endl;
    }
    return 0;
}


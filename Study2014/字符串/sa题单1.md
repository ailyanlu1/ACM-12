

 
		poj 2758 (不会玩儿... 等等在做) 
		poj 2406 (后缀数组做不了.....)
		poj 3261  
		poj 3415  
		poj 3294   
		poj 3693  
		poj 3581  
		poj 3623  
		poj 3450  
		poj 3080  
		ural 1517  
		ural 1297  
		spoj 220  
		spoj 694  
		spoj 705  
		spoj 687  
		uva 11475  

 
-----------------------------------------


		
		poj 1226  (谁说的sa!!!暴枚可以过....不过sa可以很快O(nlogn),n为所有字符串总长度...
		poj 2774 (求两个串的最长公共子串, 裸的sa, 注意调用da函数的长度要n+1 !!!!!) 



-----------------------------------------


		 
		poj 1743 (首先读懂题意, 然后后缀数组, 最后二分答案加check)


------------------------------------------

		//poj 3261
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
		const LL INF = 0x3f3f3f3f;
		#define Maxn 21111
		#define Maxm 1011111
		int num[Maxn], n, k;
		int sa[Maxn], rank[Maxn], height[Maxn];
		int wa[Maxn], wb[Maxn], wv[Maxn], wd[Maxn];
		int mp[Maxm];
		int st[Maxn][16];
		int cmp(int * r, int a, int b, int x) {
		    return r[a] == r[b] && r[a + x] == r[b + x];
		}
		
		void da(int * r, int n, int m){
		    int i, j, k, p, * x = wa, * y = wb, * t;
		    for(i = 0; i < m; i++) wd[i] = 0;
		    for(i = 0; i < n; i++) wd[x[i] = r[i]]++;
		    for(i = 1; i < m; i++) wd[i] += wd[i - 1];
		    for(i = n - 1; i >= 0; i--) sa[--wd[x[i]]] = i;
		    for(j = 1, p = 1; p < n; j <<= 1, m = p) {
		        for(p = 0, i = n - j; i < n; i++) y[p++] = i;
		        for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
		        for(i = 0; i < n; i++) wv[i] = x[y[i]];
		        for(i = 0; i < m; i++) wd[i] = 0;
		        for(i = 0; i < n; i++) wd[wv[i]]++;
		        for(i = 1; i < m; i++) wd[i] += wd[i - 1];
		        for(i = n - 1; i >= 0; i--) sa[--wd[wv[i]]] = y[i];
		        for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++) {
		            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
		        }
		    }
		    for(i = 0, k = 0; i < n; i++) rank[sa[i]] = i;
		    for(i = 0; i < n - 1; height[rank[i++]] = k) {
		        for(k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++);
		    }
		}
		vector<int> g;
		
		void pre() {
		    int i, j;
		    for(i = 1; i <= n; i++) st[i][0] = height[i];
		    for(j = 2; j <= n; j <<= 1) {
		        for(i = 1; i + j <= n; i++) {
		            st[i][j] = min(st[i][j - 1], st[i + (1<<(j - 1))][j - 1]);
		        }
		    }
		}
		
		bool check(int x) {
		    int i, j;
		    int kk = k - 1;
		    int y = (int)log2(kk);
		    cout << "check " << x << endl;
		    cout << kk << " " << y << endl;
		    for(i = 1; i + kk - 1<= n; i++) {
		        cout << i << " " << i + kk - (1<<y) << endl;
		        if(min(st[i][y], st[i + kk - (1<<y)][y]) >= x) return true;
		    }
		    return false;
		}
		
		int main() {
		    int i, j, u, v, w;
		    //freopen("", "r", stdin);
		    //freopen("", "w", stdout);
		    while(scanf("%d%d", &n, &k) != EOF) {
		        g.clear();
		        for(i = 0; i < n; i++) {
		            scanf("%d", &num[i]);
		            g.PB(num[i]);
		        }
		        SORT(g);
		        g.erase(unique(g.BG, g.ED), g.ED);
		        for(i = 0; i < g.SZ; i++) mp[g[i]] = i + 1;
		        for(i = 0; i < n; i++) num[i] = mp[num[i]];
		        num[n] = 0;
		        da(num, n + 1, g.SZ + 10);
		        pre();
		        int ans = 1;
		        int l = 2, r = n, mid;
		        while(l + 1 < r) {
		            mid = (l + r) >> 1;
		            if(check(mid)) l = mid;
		            else r = mid - 1;
		        }
		        if(check(r)) ans = r;
		        else if(check(l)) ans = l;
		        printf("%d\n", ans);
		    }
		    return 0;
		}
		



 
		poj 2758 (不会玩儿... 等等在做) 
		poj 2406 (后缀数组做不了.....)
		poj 3415  
		poj 3693  
		poj 3581  
		poj 3623  
		poj 3450  
		poj 3080  
		HDU 4436
		ural 1517  
		ural 1297  
		spoj 220  
		spoj 694  
		spoj 705  
		spoj 687  
		uva 11475  
		HDU 4426

 
-----------------------------------------
		
		poj 1226  (谁说的sa!!!暴枚可以过....不过sa可以很快O(nlogn),n为所有字符串总长度...
		poj 2774 (求两个串的最长公共子串, 裸的sa, 注意调用da函数的长度要n+1 !!!!!) 
		poj 3261  (二分答案, 从2~nfor语句判断连续>=k的有几个 110ms 太挫;
		改了用st记录height的区间最小值, 二分答案, for判断47ms, 可以接受)



-----------------------------------------
		 
		poj 1743 (首先读懂题意, 然后后缀数组, 最后二分答案加check)

		poj 3294  (二分答案, 最后求解, 不过注意插入的分隔符的处理和长度的处理... 一定是我写搓了, 以后重写一下..)


------------------------------------------

		//poj 3415
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
		#define Maxn 1111
		#define Maxm 111111
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
		char str[Maxn];
		
		int main() {
		    int i, j, u, v, w;
		    //freopen("", "r", stdin);
		    //freopen("", "w", stdout);
		    while(scanf("%d", &k) != EOF && k) {
		        n = 0;
		        scanf("%s", str);
		        for(i = 0; str[i]; i++) num[i] = str[i];
		        n = w = i;
		        num[n++] = '$';
		        scanf("%s", str);
		        for(i = 0; str[i]; i++) num[i + n] = str[i];
		        n += i;
		        num[n] = 0;
		        da(num, n + 1, 300);
		        for(i = 0; i <= n; i++) {
		            cout << i << ":";
		            for(j = sa[i]; j <= n; j++) cout << (char)num[j]; cout << endl;
		        }
		        LL ans = 0, a, b;
		        for(i = 2; i <= n; ) {
		            if(height[i] >= k && (sa[i - 1] != w && sa[i] != w) ) {
		                for(j = i + 1; j <= n && height[j] >= k; j++);
		                for(u = i - 1, a = 0, b = 0; u < j; u++) {
		                    if(sa[u] < w) a++;
		                    else b++;
		                }
		                cout << i - 1 << " " << j - 1 << " " << a << " " << b << endl;
		                ans += a * b;
		                i = j;
		            }
		            else i++;
		        }
		        cout << ans << endl;
		    }
		    return 0;
		}
		


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
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define OP begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)

const double eps = 1e-8;
const LL MOD = 1000000007;
#define Max 210000
int num[Max];
int sa[Max], rank[Max], height[Max];
int wa[Max], wb[Max], wv[Max], wd[Max];
int cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void da(int * r, int n, int m) {
    int i, j, k = 0, p , *x = wa, *y = wb, *t;
    for(int i = 0; i < m; i++) wd[i] = 0;
    for(int i = 0; i < n; i++) wd[x[i] = r[i]]++;
    for(int i = 1; i < m; i++) wd[i] += wd[i-1];
    for(int i = n - 1; i >= 0; i--) sa[--wd[x[i]]] = i;
    for(int j = 1, p = 1; p < n; j *= 2, m = p) {
        for(p = 0, i = n - j; i < n; i++) y[p++] = i;
        for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
        for(i = 0; i < n; i++) wv[i] = x[y[i]];
        for(i = 0; i < m; i++) wd[i] = 0;
        for(i = 0; i < n; i++) wd[wv[i]]++;
        for(i = 1; i < m; i++) wd[i] += wd[i-1];
        for(i = n - 1; i >= 0; i--) sa[--wd[wv[i]]] = y[i];
        for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++) {
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
        }
    }
    for(i = 0; i < n; i++) rank[sa[i]] = i;
    for(i = 0; i < n - 1; height[rank[i++]] = k) {
        for(k?k--:0, j = sa[rank[i]-1]; r[i+k] == r[j+k]; k++);
    }
}

int n, tot;
map<int, int > dmap;
int g[Max], f[Max];
vector<int> ans;
int main() {
    int i, j;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    while(scanf("%d", &n) != EOF) {
        for(i = 0; i < n; i++) {
            scanf("%d", &g[n - 1 - i]);
            f[n - i - 1] = g[n - i - 1];
        }
        sort(f, f + n);
        dmap.clear(); tot = 1;
        for(i = 0; i < n; i++) {
            if(dmap[f[i]] == 0) dmap[f[i]] = tot++;
        }
        for(i = 0; i < n; i++) num[i] = dmap[g[i]];
        da(num, n + 1, tot);
        int l1, l2;
        ans.clear();
        for(i = 1; i <= n; i++) {
            if(sa[i] > 1) {
                l1 = sa[i];
                for(j = l1; j < n; j++) ans.PB(g[j]);
            }
        }
        for(i = 0, n = l1; i < l1; i++, n++) {
            num[n] = num[i];
        }
        num[n] = 0;
        da(num, n + 1, tot);
        for(i = 0; i < n; i++) cout << "~ " << num[i] << " "; cout << endl;
        for(i = 1; i <= n; i++) {
            if(n / 2 > sa[i] && sa[i] > 0) {
                for(j = sa[i]; j < n / 2; j++) ans.PB(g[j]);
                for(j = 0; j < sa[i]; j++) ans.PB(g[j]);
                break;
            }
            
        }
//        printf("%d %d %d\n", a1, a2, a3);
        for(i = 0; i < ans.SZ; i++) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}

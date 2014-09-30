// BEGIN CUT HERE
/*

*/
// END CUT HERE
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>
using namespace std;
 
#define PB push_back
#define PPB pop_back
#define PF push_front
#define PPF pop_front
#define MP make_pair
#define AA first
#define BB second
#define BG begin()
#define ED end()
#define SZ size()
#define SQ(x) ((x)*(x))
#define SORT(p) sort(p.BGN,p.ED)
#define MEM(a, b) memset(a, (b), sizeof(a))
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef queue<int> QI;
typedef deque<int> DQI;
typedef set<int> SI;
typedef vector<PII> VII;
typedef queue<PII> QII;
typedef deque<PII> DQII;
typedef set<PII> SII;

typedef long long LL;
typedef pair<LL, LL> PLL;
typedef vector<LL> VL;
typedef queue<LL> QL;
typedef deque<LL> DQL;
typedef set<LL> SL;
typedef vector<PLL> VLL;
typedef queue<PLL> QLL;
typedef deque<PLL> DQLL;
typedef set<PLL> SLL;
#define Maxn 111111
#define Maxm 2111111
#define MOD 1000000007
    struct point {
        int x, y;
        point () {}
        point (int x, int y) : x(x), y(y) {}
        point operator - (const point & a) const {
            return point(x - a.x, y - a.y);
        }
    };
bool onsegment(point pi,point pj,point pk) //判断点pk是否在线段pi pj上   
{  
    if(min(pi.x,pj.x)<=pk.x&&pk.x<=max(pi.x,pj.x))  
    {  
        if(min(pi.y,pj.y)<=pk.y&&pk.y<=max(pi.y,pj.y))  
        {  
            return true;  
        }  
    }  
    return false;  
}  
double direction(point pi,point pj,point pk) //计算向量pkpi和向量pjpi的叉积   
{  
    return (pi.x-pk.x)*(pi.y-pj.y)-(pi.y-pk.y)*(pi.x-pj.x);  
}  
bool judge(point &p1,point &p2,point &p3,point &p4) //判断线段p1p2和p3p4是否相交   
{  
    double d1 = direction(p3,p4,p1);  
    double d2 = direction(p3,p4,p2);  
    double d3 = direction(p1,p2,p3);  
    double d4 = direction(p1,p2,p4);  
    if(d1*d2<0&&d3*d4<0)  
        return true;  
//    if(d1==0&&onsegment(p3,p4,p1))  
//        return true;  
//    if(d2==0&&onsegment(p3,p4,p2))  
//        return true;  
//    if(d3==0&&onsegment(p1,p2,p3))  
//        return true;  
//    if(d4==0&&onsegment(p1,p2,p4))  
//        return true;  
    return false;  
}  
struct node {
    int u, v, c, next;
}e[Maxm];
int tot, last[Maxn];
int cur[Maxn], dist[Maxn], que[Maxn], sta[Maxn], head, tail, top;

void adde(int u, int v, int c) {
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
    e[tot].u = v; e[tot].v = u; e[tot].c = 0; e[tot].next = last[v]; last[v] = tot++;
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

class SegmentDrawing
{
public:

    int n, m;
    int calcmap(int x, int y) {
        return ((x + 1) << 5) | (y + 1);
    }
    LL det(point p1, point p2) {
        return p1.x * p2.y - p1.y * p2.x;
    }
    int iscross(point & p1, point & p2, point & q1, point & q2) {
        int qxmx = max(q1.x, q2.x), qymx = max(q1.y, q2.y);
        int pxmx = max(p1.x, p2.x), pymx = max(p1.y, p2.y);
        int qxmn = min(q1.x, q2.x), qymn = min(q1.y, q2.y);
        int pxmn = min(p1.x, p2.x), pymn = min(p1.y, p2.y);
        if(qxmx < pxmn || qymx < pymn || pxmx < qxmn || pymx < qymn) return false;
        if(det(p2 - p1, q1 - p1) * det(p2 - p1, q2 - p1) < 0 && 
           det(q2 - q1, p1 - q1) * det(q2 - q1, p2 - q1) < 0)return true;
        return false;
    }
    
    void ready(vector <int> &x, vector <int> &y, vector <int> &rs, vector <int> &bs) {
        int i, j, ii, jj, u, v, w;
        point p1, p2, q1, q2;
        tot = 0;
        memset(last, -1, sizeof(last));
        for(i = 0; i < n; i++) {
            for(j = i + 1; j < n; j++) {
                u = calcmap(i, j);
                for(ii = 0; ii < n; ii++) {
                    for(jj = ii + 1; jj < n; jj++) {
                        v = calcmap(ii, jj) + m;
                        if(i == ii || j == jj || i == jj || j == ii) {
                            adde(u, v, MOD);
                        } 
                        else {
                            p1.x = x[i]; p1.y = y[i];
                            p2.x = x[j]; p2.y = y[j];
                            q1.x = x[ii]; q1.y = y[ii];
                            q2.x = x[jj]; q2.y = y[jj];
                            if(iscross(p1, p2, q1, q2)) {
                                adde(u, v, MOD);
                            }
                        }
                    }
                }
            }
        }
    }
    int maxScore (vector <int> x, vector <int> y, vector <int> rs, vector <int> bs)
    {
        int ret = 0;
        int i, j, ii, jj, u, v, w;
        n = x.SZ;
        m = calcmap(n, n);
//        cout << n << " " << m << endl;
        int S = 0, N = 2 * m + 2, T = N - 1;
        tot = 0;
        for(i = 0; i <= N; i++) last[i] = -1;
        ready(x, y, rs, bs);
        for(i = 0; i < n; i++) {
            for(j = i + 1; j < n; j++) {
                u = calcmap(i, j);
                v = u + m;
                adde(S, u, rs[i * n + j]);
                adde(v, T, bs[i * n + j]);
            }
        }
        int sum = 0;
        for(i = 0; i < n; i++) {
            for(j = i + 1; j < n; j++) {
                sum += rs[i * n + j] + bs[i * n + j];
            }
        }
        ret = dinic(S, T, N);
//        cout << sum << " " << ret << endl;
        return int(sum - ret);
    }
};
 
// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int x[]                   = {0,1,0,-1};
			int y[]                   = {1,0,-1,0};
			int redScore[]            = {0, 1, 2, 3, 1, 0, 6, 4, 2, 6, 0, 5, 3, 4, 5, 0};
			int blueScore[]           = {0, 2, 3, 7, 2, 0, 4, 6, 3, 4, 0, 5, 7, 6, 5, 0};
			int expected__            = 27;

			std::clock_t start__      = std::clock();
			int received__            = SegmentDrawing().maxScore(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(redScore, redScore + (sizeof redScore / sizeof redScore[0])), vector <int>(blueScore, blueScore + (sizeof blueScore / sizeof blueScore[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {0, 1};
			int y[]                   = {1, 0};
			int redScore[]            = {0, 101, 101, 0};
			int blueScore[]           = {0, 100, 100, 0};
			int expected__            = 101;

			std::clock_t start__      = std::clock();
			int received__            = SegmentDrawing().maxScore(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(redScore, redScore + (sizeof redScore / sizeof redScore[0])), vector <int>(blueScore, blueScore + (sizeof blueScore / sizeof blueScore[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {-3, -1, -1, 1, 1, 3};
			int y[]                   = { 0, -2, 2, -2, 2, 0};
			int redScore[]            = {0, 2, 1, 2, 1, 2, 2, 0, 2, 1, 2, 1, 1, 2, 0, 2, 1, 2, 2, 1, 2, 0, 2, 1, 1, 2, 1, 2, 0, 2, 2, 1, 2, 1, 2, 0};
			int blueScore[]           = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
			int expected__            = 25;

			std::clock_t start__      = std::clock();
			int received__            = SegmentDrawing().maxScore(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(redScore, redScore + (sizeof redScore / sizeof redScore[0])), vector <int>(blueScore, blueScore + (sizeof blueScore / sizeof blueScore[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int x[]                   = {-100, 100, 0, -10, 10, 0};
			int y[]                   = {0, 0, 100, 10, 10, 1};
			int redScore[]            = { 0, 96, 96, 25, 25, 25, 96, 0, 96, 25, 25, 25, 96, 96, 0, 25, 25, 25, 25, 25, 25, 0, 10, 10, 25, 25, 25, 10, 0, 10, 25, 25, 25, 10, 10, 0};
			int blueScore[]           = { 0, 30, 30, 20, 20, 20, 30, 0, 30, 20, 20, 20, 30, 30, 0, 20, 20, 20, 20, 20, 20, 0, 86, 86, 20, 20, 20, 86, 0, 86, 20, 20, 20, 86, 86, 0};
			int expected__            = 546;

			std::clock_t start__      = std::clock();
			int received__            = SegmentDrawing().maxScore(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(redScore, redScore + (sizeof redScore / sizeof redScore[0])), vector <int>(blueScore, blueScore + (sizeof blueScore / sizeof blueScore[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int x[]                   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			int y[]                   = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100};
			int redScore[]            = {0, 15, 2, 3, 4, 5, 6, 7, 8, 9, 15, 0, 15, 2, 3, 4, 5, 6, 7, 8, 2, 15, 0, 15, 2, 3, 4, 5, 6, 7, 3, 2, 15, 0, 15, 2, 3, 4, 5, 6, 4, 3, 2, 15, 0, 15, 2, 3, 4, 5, 5, 4, 3, 2, 15, 0, 15, 2, 3, 4, 6, 5, 4, 3, 2, 15, 0, 15, 2, 3, 7, 6, 5, 4, 3, 2, 15, 0, 15, 2, 8, 7, 6, 5, 4, 3, 2, 15, 0, 15, 9, 8, 7, 6, 5, 4, 3, 2, 15, 0} ;
			int blueScore[]           = {0, 0, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 2, 3, 4, 5, 6, 7, 8, 2, 0, 0, 0, 2, 3, 4, 5, 6, 7, 3, 2, 0, 0, 0, 2, 3, 4, 5, 6, 4, 3, 2, 0, 0, 100, 2, 3, 4, 5, 5, 4, 3, 2, 100, 0, 0, 2, 3, 4, 6, 5, 4, 3, 2, 0, 0, 0, 2, 3, 7, 6, 5, 4, 3, 2, 0, 0, 0, 2, 8, 7, 6, 5, 4, 3, 2, 0, 0, 0, 9, 8, 7, 6, 5, 4, 3, 2, 0, 0};
			int expected__            = 300;

			std::clock_t start__      = std::clock();
			int received__            = SegmentDrawing().maxScore(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(redScore, redScore + (sizeof redScore / sizeof redScore[0])), vector <int>(blueScore, blueScore + (sizeof blueScore / sizeof blueScore[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int x[]                   = {-760, 931, 662, 290, -741, 803, 569, -817, 595, -567, 130, -469, -273};
			int y[]                   = {336, 318, 532, 374, 556, 947, 296, -872, -145, 669, -35, 203, -646};
			int redScore[]            = {0, 2, 5, 4, 57, 1688, 115, 78, 428, 2340, 178, 81054, 3, 2, 0, 24, 56, 15, 4, 1972, 4585, 8, 5, 4, 58, 2498, 5, 24, 0, 65800, 60, 1, 3741, 2602, 4, 17729, 1, 352, 13, 4, 56, 65800, 0, 4, 1, 9671, 6286, 6, 2025, 15, 11396, 12, 57, 15, 60, 4, 0, 590, 34, 11, 348, 65521, 92985, 3117, 78456, 1688, 4, 1, 1, 590, 0, 37, 1, 11, 224, 104, 6493, 2956, 115, 1972, 3741, 9671, 34, 37, 0, 1, 9401, 91, 7, 367, 816, 78, 4585, 2602, 6286, 11, 1, 1, 0, 2, 43, 19148, 81, 273, 428, 8, 4, 6, 348, 11, 9401, 2, 0, 4077, 679, 169, 2, 2340, 5, 17729, 2025, 65521, 224, 91, 43, 4077, 0, 59, 5, 869, 178, 4, 1, 15, 92985, 104, 7, 19148, 679, 59, 0, 14924, 2870, 81054, 58, 352, 11396, 3117, 6493, 367, 81, 169, 5, 14924, 0, 1674, 3, 2498, 13, 12, 78456, 2956, 816, 273, 2, 869, 2870, 1674, 0};
			int blueScore[]           = {0, 23874, 75, 1, 4478, 26, 56436, 8337, 2, 78, 16, 14966, 88, 23874, 0, 63960, 57981, 35, 42701, 13443, 131, 36343, 14, 1142, 279, 62, 75, 63960, 0, 1, 1, 4, 6, 592, 359, 66919, 14, 360, 145, 1, 57981, 1, 0, 105, 17753, 288, 3, 5574, 1641, 1, 361, 97, 4478, 35, 1, 105, 0, 128, 570, 28, 7, 788, 177, 48569, 2, 26, 42701, 4, 17753, 128, 0, 16, 4368, 1, 2, 274, 1, 1293, 56436, 13443, 6, 288, 570, 16, 0, 259, 892, 82, 1304, 1, 9, 8337, 131, 592, 3, 28, 4368, 259, 0, 28802, 4595, 31, 11, 2179, 2, 36343, 359, 5574, 7, 1, 892, 28802, 0, 4, 8226, 25119, 4, 78, 14, 66919, 1641, 788, 2, 82, 4595, 4, 0, 1, 38017, 7, 16, 1142, 14, 1, 177, 274, 1304, 31, 8226, 1, 0, 49, 1, 14966, 279, 360, 361, 48569, 1, 1, 11, 25119, 38017, 49, 0, 1, 88, 62, 145, 97, 2, 1293, 9, 2179, 4, 7, 1, 1, 0};
			int expected__            = 603068;

			std::clock_t start__      = std::clock();
			int received__            = SegmentDrawing().maxScore(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(redScore, redScore + (sizeof redScore / sizeof redScore[0])), vector <int>(blueScore, blueScore + (sizeof blueScore / sizeof blueScore[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int x[]                   = ;
			int y[]                   = ;
			int redScore[]            = ;
			int blueScore[]           = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SegmentDrawing().maxScore(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(redScore, redScore + (sizeof redScore / sizeof redScore[0])), vector <int>(blueScore, blueScore + (sizeof blueScore / sizeof blueScore[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int x[]                   = ;
			int y[]                   = ;
			int redScore[]            = ;
			int blueScore[]           = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SegmentDrawing().maxScore(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), vector <int>(redScore, redScore + (sizeof redScore / sizeof redScore[0])), vector <int>(blueScore, blueScore + (sizeof blueScore / sizeof blueScore[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}

 
#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE

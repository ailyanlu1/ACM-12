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
map<VI, LL> mp;
set<VI> S;
queue<pair<VI, LL> > que[111];
vector<VI> gg;
#define Maxn 1111111
#define Maxm 1111111
#define MOD 1000000007
VL pri;
int ispri[Maxn];
VII has[111], gvhas;
class GoodSubset
{
public:
    int n, m;
    void getpri() {
        int i, j;
        memset(ispri, 0, sizeof(ispri));
        pri.clear();
        for(i = 2; i < Maxn; i++) {
            if(!ispri[i]) {
                for(j = i; j < Maxn; j += i) {
                    ispri[i] = 1;
                }
                pri.PB(i);
            }
        }
    }
    void gethas(LL gv, VII & has) {
        has.clear();
        int i, j;
        LL k;
        for(i = 0; i < pri.SZ; i++) {
            k = pri[i];
            if(k * k > gv) break;
            if(gv % k == 0) {
                j = 0;
                while(gv % k == 0) {
                    j++;
                    gv /= k;
                }
                has.PB(MP(k, j));
            }
        }
        if(gv > 1) has.PB(MP(gv, 1));
    }
    void gethas1(LL v, VII & has) {
        has.clear();
        int i, j;
        LL k;
        for(i = 0; i < gvhas.SZ; i++) {
            k = gvhas[i].AA;
            j = 0;
            while(v % k == 0) {
                j++; v /= k;
            }
            has.PB(MP(k, j));
        }
    }
    int numberOfSubsets (int gv, vector <int> d)
    {
        LL ret = 0;
        int i, j, u, v, w;
        VI dd;
        getpri();
        gethas(gv, gvhas);
////        for(i = 0; i < gvhas.SZ; i++) cout << gvhas[i].AA << " ~ " << gvhas[i].BB << endl;
//        cout << endl;
        dd.clear();
        w = 0;
        for(i = 0; i < d.SZ; i++) {
            if(d[i] == 1) {
                w++;
                continue;
            }
            int u = d[i];
            for(j = 0; j < gvhas.SZ; j++) {
                v = gvhas[j].AA;
                while(u % v == 0) u /= v;
            }
            if(u == 1) {
                dd.PB(d[i]);
            }
        }
        d = dd;
        for(i = 0; i < d.SZ; i++) gethas1(d[i], has[i]);
        VI sta, sta1, sta2;
        for(i = 0; i < gvhas.SZ; i++) sta.PB(0);
        while(!que[0].empty()) que[0].pop();
        que[0].push(MP(sta, 1));
        LL tp, va;
        for(i = 0; i < d.SZ; i++) {
//            cout << i << endl;
            mp.clear();
            gg.clear();
            while(!que[i].empty()) {
                tp = que[i].front().BB;
                sta2 = sta1 = que[i].front().AA; que[i].pop();
                if(mp[sta1] == 0) gg.PB(sta1);
                LL & va = mp[sta1];
                va = (va + tp) % MOD;
//                cout << "sta1 " << mp[sta1] <<" ";
//                for(int i = 0; i < sta1.SZ; i++) cout << sta1[i] << " "; cout << endl;
                for(j = 0; j < has[i].SZ; j++) if(sta1[j] + has[i][j].BB > gvhas[j].BB) break;
                if(j >= has[i].SZ) {
//                    cout << "gao " << endl;
                    for(j = 0; j < has[i].SZ; j++) {
                        sta2[j] += has[i][j].BB;
                    }
                    if(mp[sta2] == 0) gg.PB(sta2);
                    LL & va = mp[sta2];
                    va = (va + tp) % MOD;
//                    cout << "sta2 " << mp[sta2] <<" ";
//                    for(int i = 0; i < sta2.SZ; i++) cout << sta2[i] << " "; cout << endl;
                }
            }
            while(!que[i + 1].empty()) que[i + 1].pop();
            for(j = 0; j < gg.SZ; j++) {
                que[i + 1].push(MP(gg[j], mp[gg[j]]));
            }
        }
        for(i = 0; i < gvhas.SZ; i++) sta[i] = gvhas[i].BB;
        ret = mp[sta];
        if(gv == 1) {
            if(w) {
                ret = 1;
                for(i = 0; i < w; i++) ret = (ret * 2LL) % MOD;
                ret = (ret - 1 + MOD) % MOD;
            }
            else ret = 0;
        }
        else {
            for(i = 0; i < w; i++) {
                ret *= 2LL;
                ret %= MOD;
            }
        }
        return int(ret);
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
			int goodValue             = 10;
			int d[]                   = {2,3,4,5};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = GoodSubset().numberOfSubsets(goodValue, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int goodValue             = 6;
			int d[]                   = {2,3,4,5,6};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = GoodSubset().numberOfSubsets(goodValue, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int goodValue             = 1;
			int d[]                   = {1,1,1};
			int expected__            = 7;

			std::clock_t start__      = std::clock();
			int received__            = GoodSubset().numberOfSubsets(goodValue, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int goodValue             = 12;
			int d[]                   = {1,2,3,4,5,6,7,8,9,10,11,12};
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = GoodSubset().numberOfSubsets(goodValue, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int goodValue             = 5;
			int d[]                   = {1,2,3,4};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = GoodSubset().numberOfSubsets(goodValue, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int goodValue             = 2;
			int d[]                   = {2, 2, 1, 1};
			int expected__            = 8;

			std::clock_t start__      = std::clock();
			int received__            = GoodSubset().numberOfSubsets(goodValue, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 6: {
			int goodValue             = 479001600;
			int d[]                   = {1, 2, 3, 5, 7, 9, 11, 13, 15, 17, 4, 6, 8, 10, 12};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = GoodSubset().numberOfSubsets(goodValue, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 7: {
			int goodValue             = ;
			int d[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = GoodSubset().numberOfSubsets(goodValue, vector <int>(d, d + (sizeof d / sizeof d[0])));
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

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
#define Maxn 111
#define Maxm 111
#define MOD 1000000007
int a[Maxn][Maxm], sum[Maxn][Maxm];
class ChocolateDividingEasy
{
public:
    int n, m;
    int check(int x) {
        int i, j, u, v, w;
        for(i = 1; i < n - 1; i++) {
            for(u = i + 1; u < n; u++) {
                for(j = 1; j < m - 1; j++) {
                    for(v = j + 1; v < m; v++) {
                        if(sum[i][j] < x || sum[i][v] - sum[i][j] < x || sum[i][m] - sum[i][v] < x) continue;
                        if(sum[u][j] - sum[i][j] < x || sum[u][v] - sum[i][v] - (sum[u][j] - sum[i][j]) < x
                           || sum[u][m] - sum[i][m] - (sum[u][v] - sum[i][v]) < x) continue;
                        if(sum[n][j] - sum[u][j] < x || sum[n][v] - sum[u][v] - (sum[n][j] - sum[u][j]) < x
                           || sum[n][m] - sum[u][m] - (sum[n][v] - sum[u][v]) < x) continue;
//                        cout << "\t " << i << " " << j << " " << u << " " << v << endl;
                        return true;
                    }
                }
            }
        }
        return false;
    }
    int findBest (vector <string> ch)
    {
        int ret = 0;
        int i, j, u, v, w;
        n = ch.size(); m = ch[0].length();
        memset(a, 0, sizeof(a));
        memset(sum, 0, sizeof(sum));
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= m; j++) {
                a[i][j] = ch[i - 1][j - 1] - '0';
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
            }
        }
//        for(i = 1; i <= n; i++) {
//            for(j = 1; j <= m; j++) cout << sum[i][j] << " "; cout << endl;
//        }
        int l = 0, r = MOD >> 2, mid;
        while(l + 1 < r) {
            mid = (l + r) >> 1;
//            cout << l << " " << mid << " " << r << " " << check(mid) << endl;
            if(check(mid)) l = mid;
            else r = mid - 1;
        }
        if(check(r)) return r;
        else if(check(l)) return l;
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
			string chocolate[]        = {
"9768",
"6767",
"5313"
};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = ChocolateDividingEasy().findBest(vector <string>(chocolate, chocolate + (sizeof chocolate / sizeof chocolate[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string chocolate[]        = {
"36753562",
"91270936",
"06261879",
"20237592",
"28973612",
"93194784"
};
			int expected__            = 15;

			std::clock_t start__      = std::clock();
			int received__            = ChocolateDividingEasy().findBest(vector <string>(chocolate, chocolate + (sizeof chocolate / sizeof chocolate[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string chocolate[]        = {
"012",
"345",
"678"
};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = ChocolateDividingEasy().findBest(vector <string>(chocolate, chocolate + (sizeof chocolate / sizeof chocolate[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 3: {
			string chocolate[]        = {
"993",			
"939",
"299"
			};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = ChocolateDividingEasy().findBest(vector <string>(chocolate, chocolate + (sizeof chocolate / sizeof chocolate[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 4: {
			string chocolate[]        = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ChocolateDividingEasy().findBest(vector <string>(chocolate, chocolate + (sizeof chocolate / sizeof chocolate[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string chocolate[]        = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = ChocolateDividingEasy().findBest(vector <string>(chocolate, chocolate + (sizeof chocolate / sizeof chocolate[0])));
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

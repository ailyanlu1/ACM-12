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
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
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
#define Maxm 111111
const LL MOD = 2000000007LL;
LL sum[100];
class PeriodicJumping
{
public:
    int n, m;
    int minimalTime (int x, vector <int> jp)
    {
        n = jp.SZ;
        x = abs(x);
        if(x == 0) return 0;
        if(n == 1) {
            if(x == jp[0]) return 1;
            if(x < jp[0]) return 2;
            return x / jp[0] + (x % jp[0] == 0? 0: 1);
        }
        int ret = 0;
        LL cur = 0;
        int i, j, u, v, w, q;
        LL dmax = 0, pp = 0;
        for(i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + jp[i];
            cmax(dmax, (LL)jp[i]);
            if(sum[i + 1] == x) return i + 1;
            if(sum[i + 1] > x) {
                if(sum[i + 1] - dmax >= dmax) return i + 1;
                else if(x >= 2 * dmax - sum[i + 1]) return i + 1;
            }
        }
        for(i = n + 1; i <= 2 * n; i++) {
            if(sum[n] + sum[i - n] == x) return i;
            if(sum[n] + sum[i - n] > x) {
                if(sum[n] + sum[i - n] - dmax >= dmax) return i;
                else if(x >= 2 * dmax - sum[n] - sum[i - n]) return i;
            }
        }
        int l = 0, r = MOD, mid;
        while(l + 1 < r) {
            mid = (l + r) >> 1;
            cur = mid / n * sum[n] + sum[mid % n];
            if(cur == x) return mid;
            if(cur < x)l = mid + 1;
            else r = mid;
        }
        cur = l / n * sum[n] + sum[l % n];
        if(cur >= x) return l;
        cur = r / n * sum[n] + sum[r % n];
        if(cur >= x) return r;
        return r + 1;
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
			int x                     = 15;
			int jumpLengths[]         = {1,2,3,4,5,6,7,8,9,10};
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = PeriodicJumping().minimalTime(x, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x                     = 5;
			int jumpLengths[]         = {5};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = PeriodicJumping().minimalTime(x, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int x                     = 1;
			int jumpLengths[]         = {10};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = PeriodicJumping().minimalTime(x, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int x                     = -10;
			int jumpLengths[]         = {2,3,4,500,6,7,8};
			int expected__            = 11;

			std::clock_t start__      = std::clock();
			int received__            = PeriodicJumping().minimalTime(x, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int x                     = -1000000000;
			int jumpLengths[]         = {1};
			int expected__            = 1000000000;

			std::clock_t start__      = std::clock();
			int received__            = PeriodicJumping().minimalTime(x, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int x                     = 0;
			int jumpLengths[]         = {19911120};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = PeriodicJumping().minimalTime(x, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 6: {
			int x                     = 1;
			int jumpLengths[]         = {2, 4, 8 , 16, 32, 64, 128, 256, 512, 1024};
			int expected__            = 11;

			std::clock_t start__      = std::clock();
			int received__            = PeriodicJumping().minimalTime(x, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 7: {
			int x                     = -6;
			int jumpLengths[]         = {24, 3, 5, 37, 51, 36, 26, 29, 65, 27, 66, 76, 5, 65, 74, 59, 25, 22};
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = PeriodicJumping().minimalTime(x, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 8: {
			int x                     = ;
			int jumpLengths[]         = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = PeriodicJumping().minimalTime(x, vector <int>(jumpLengths, jumpLengths + (sizeof jumpLengths / sizeof jumpLengths[0])));
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

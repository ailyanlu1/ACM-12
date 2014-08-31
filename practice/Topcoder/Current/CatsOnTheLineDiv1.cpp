// BEGIN CUT HERE
/*

*/
// END CUT HERE
#include <cctype>
#include <ctime>
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
typedef pair<int, PII> PIII;
typedef vector <int> VI;
typedef queue <int> QI;
typedef stack <int> StaI;
typedef vector <PII> VII;
typedef queue <PII> QII;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)

const double eps = 1e-8;
const LL MOD = 1000000007;
int dp[1111][1111][e];
class CatsOnTheLineDiv1 {
public:
    vector<PII> G;
    int n, m;
    void doit(int l, int r) {
        if(visit[l][r]) return;
        visit[l][r] = true;
        if(l == r) {
            dp[l][r][0] = 1;
            dp[l][r][1] = 0;
            dp[l][r][2] = 0;
            return;
        }
        doit(l + 1, r);
        doit(l, r - 1);

        int i, j, u, v, w;
        u = G[l + 1].AA - G[l].AA + 1;
        v = G[r].AA - G[r - 1].AA + 1;
        if(u <= m) {
            cmin(dp[l][r][0], dp[l + 1][r][1] + 1);
            cmin(dp[l][r][0], dp[l + 1][r][2] + 1);
            cmin(dp[l][r][0], dp[l + 1][r][0] + 1);
        }
        if(v <= m) {
            cmin(dp[l][r][0], dp[l][r - 1][0] + 1);
            cmin(dp[l][r][0], dp[l][r - 1][1] + 1);
            cmin(dp[l][r][0], dp[l][r - 1][2] + 1);
        }
        if(u < 2 * m) {
            cmin(dp[l][r][1], dp[l][r - 1][0]
        }
    }
    int getNumber (vector <int> pos, vector <int> cnt, int ti) {
        int i, j;
        int ret = MOD;
        n = pos.SZ;
        m = ti;
        for(i = 0; i < n; i++) G.PB(MP(pos[i], cnt[i]));
        sort(G.BG, G.ED);
        for(i = 0; i < n; i++) cout << G[i].AA << " " << G[i].BB << endl;
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = MOD;
                visit[i][j] = false;
            }
        }
        doit(0, n - 1);
        return (int)(ret);
    }
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if ( casenum != -1 ) {
			if ( run_test_case( casenum ) == -1 && !quiet )
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			return;
		}
		
		int correct = 0, total = 0;
		for ( int i=0;; ++i ) {
			int x = run_test_case(i);
			if ( x == -1 ) {
				if ( i >= 100 ) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if ( total == 0 ) {
			cerr << "No test cases run." << endl;
		} else if ( correct < total ) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if ( expected == received ) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			int position[]            = {0};
			int count[]               = {7};
			int time                  = 3;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = CatsOnTheLineDiv1().getNumber( vector <int>( position, position + ( sizeof position / sizeof position[0] ) ), vector <int>( count, count + ( sizeof count / sizeof count[0] ) ), time );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 1: {
			int position[]            = {0};
			int count[]               = {6};
			int time                  = 2;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = CatsOnTheLineDiv1().getNumber( vector <int>( position, position + ( sizeof position / sizeof position[0] ) ), vector <int>( count, count + ( sizeof count / sizeof count[0] ) ), time );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 2: {
			int position[]            = {4, 7, 47};
			int count[]               = {4, 7, 4};
			int time                  = 1;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = CatsOnTheLineDiv1().getNumber( vector <int>( position, position + ( sizeof position / sizeof position[0] ) ), vector <int>( count, count + ( sizeof count / sizeof count[0] ) ), time );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 3: {
			int position[]            = {3, 0, 7, 10};
			int count[]               = {3, 7, 4, 5};
			int time                  = 2;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = CatsOnTheLineDiv1().getNumber( vector <int>( position, position + ( sizeof position / sizeof position[0] ) ), vector <int>( count, count + ( sizeof count / sizeof count[0] ) ), time );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 4: {
			int position[]            = {-5, 0, 7};
			int count[]               = {47, 85, 10};
			int time                  = 6;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = CatsOnTheLineDiv1().getNumber( vector <int>( position, position + ( sizeof position / sizeof position[0] ) ), vector <int>( count, count + ( sizeof count / sizeof count[0] ) ), time );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}
		case 5: {
			int position[]            = {-8, 12, -15, -20, 17, -5, 7, 10};
			int count[]               = {20, 10, 7, 9, 2, 8, 11, 10};
			int time                  = 2;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = CatsOnTheLineDiv1().getNumber( vector <int>( position, position + ( sizeof position / sizeof position[0] ) ), vector <int>( count, count + ( sizeof count / sizeof count[0] ) ), time );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}

		// custom cases

/*      case 6: {
			int position[]            = ;
			int count[]               = ;
			int time                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CatsOnTheLineDiv1().getNumber( vector <int>( position, position + ( sizeof position / sizeof position[0] ) ), vector <int>( count, count + ( sizeof count / sizeof count[0] ) ), time );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 7: {
			int position[]            = ;
			int count[]               = ;
			int time                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CatsOnTheLineDiv1().getNumber( vector <int>( position, position + ( sizeof position / sizeof position[0] ) ), vector <int>( count, count + ( sizeof count / sizeof count[0] ) ), time );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
/*      case 8: {
			int position[]            = ;
			int count[]               = ;
			int time                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CatsOnTheLineDiv1().getNumber( vector <int>( position, position + ( sizeof position / sizeof position[0] ) ), vector <int>( count, count + ( sizeof count / sizeof count[0] ) ), time );
			return verify_case( casenum, expected__, received__, clock()-start__ );
		}*/
		default:
			return -1;
		}
	}
}


int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE


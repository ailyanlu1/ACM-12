
####    01. **生成树**  

*	Prim  

*	Kruskal  

*	Borůvka算法

*	次小生成树  

*	最小瓶颈生成树

*	直径最短生成树

*	度数最多的点, 度数最少的生成树

*	两点之间路径, 权重总和最小的生成树

*	有两种权重, 权重比值最小的生成树(最优比例生成树)

*	边不重叠, 权重最小的k棵树

*	重叠边增加额外权重, 权重最小的k棵树

*	权重最小的生成子树, 刚好k个点

*	权重最小的生成子树, 刚好是给定的K个点

*   度限制最小生成树  

*   动态最小生成树  

*	有向图最小生成树(最小树形图)

*	任意两点间路径的瓶颈, 形成两点间最小割的无向生成树

*	dfs树

*	bfs树

*	最短路径树

*   斯坦纳树 

*	生成树计数

	Matrix-Tree定理(Kirchhoff矩阵-树定理)   
	Kirchhoff矩阵C[G]=D[G]-A[G] (度数矩阵-邻接矩阵)  
	求C[G]任意一个n-1阶主子式的行列式(取出第i行和第i列)
		
		//spoj 104 Highways
		//朴素求解, ans是double用printf("%0.0f\n",ans)输出成int
		//返回是否有解,若有解ans*=a[i][i]中
		#define eps 1e-10
		#define fabs(x) ((x)>eps?(x):-(x))
		#define ZERO(x) (fabs(x) > eps ? 0 : 1)
		int gauss_tpivot (int n, double a[][Maxn]) {
		    int i, j, k, p;
		    double maxp, t;
		    for (k = 0; k < n; k++) {
		        if(ZERO(a[k][k])) {
		            for(i = k + 1; i < n; i++) if(!ZERO(a[i][i])) break;
		            if(i >= n) return 0;
		            for(j = k; j < n; j++) {
		                swap(a[k][j], a[i][j]);
		            }
		        }
		        maxp = a[k][k];
		        for (j = k + 1; j < n; j++) {
		            a[k][j] /= maxp;
		            for (i = k + 1; i < n; i++)
		                a[i][j] -= a[i][k] * a[k][j];
		        }
		    }
		    return 1;
		}
		
		int main() {
	        for(i = 0; i <= n; i++) {
	            for(j = 0; j <= n; j++) {
	                a[i][j] = b[i][j] = 0;
	            }
	        }
	        for(i = 0; i < m; i++) {
	            scanf("%d%d", &u, &v);
	            if(u == v) continue;
	            u--; v--;
	            a[u][u]++; a[v][v]++;
	            b[u][v] = b[v][u] = 1;
	        }
	        for(i = 0; i < n; i++) {
	            for(j = 0; j < n; j++) {
	                a[i][j] = a[i][j] - b[i][j];
	            }
	        }
	        double ans = 0;
	        if(gauss_tpivot(n - 1, a)) {
	            ans = 1;
	            for(i = 0; i < n - 1; i++) ans *= a[i][i];
	        }
	        else ans = 0;
	        printf("%0.0f\n", ans);
		}

		//hdu 4305 MOD = 10007
		//答案取模, 每一步需要取模处理
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

*	*最小树形图(有向图的最小生成树)*   

		hdu4009 hdu2121 poj3164 UVa11865

		本题为不是固定根的最小树形图，我们可以虚拟出一根来，然后在把这个根跟每个点相连，相连的点可以设为无穷大，或者设为所有边和大一点，比如为r，然后就可以利用最小树形图进行计算了，计算出的结果减去r,如果比r还大就可以认为通过这个虚拟节点我们连过原图中两个点，即原图是不连通的，我们就可以认为不存在最小树形图。关于输出最小根也挺简单，在找最小入弧时，如果这条弧的起点是虚拟根，那么这条弧的终点就是要求的根

	*	朱刘算法
	
		验题:POJ3164 HDU2121
	
			/* 
			 * 最小树形图（根固定）     O(VE)
			 * 有向图最小生成树
			 * 根不固定，添加一个根节点与所有点连无穷大的边！
			 * 如果求出比2*MOD大, 则不连通; 求根, 则求和虚拟根相连的结点
			 * 根据pre的信息能构造出这棵树！
			 * 注意结点必须从0~n-1, 因为要考虑重新标号建图的统一
			 * mytype 根据实际情况确定
			 */
			typedef int mytype;
			int visit[Maxn], pre[Maxn], belong[Maxn], ROOT;
			mytype inv[Maxn]; 
			mytype dirtree(int n, int m, int root) {
			    mytype sum = 0;
			    int i, j, k, u, v;
			    while (1) {
			        for (i = 0; i < n; i++) {
			            inv[i] = MOD;
			            pre[i] = -1;
			            belong[i] = -1;
			            visit[i] = -1;
			        }
			        inv[root] = 0;
			        for (i = 0; i < m; i++) {//除原点外，找每个点的最小入边
			            u = e[i].u; v = e[i].v;
			            if (u != v) {
			                if (e[i].w < inv[v]) {
			                    inv[v] = e[i].w;
			                    pre[v] = u;
			                    if(u == root) ROOT = i; //记录根所在的边
			                                            //输出根时利用ROOT-m计算是原图哪个结点
			                }
			            }
			        }
			        for (i = 0; i < n; i++) {
			            
			            if (inv[i] == MOD) return -1;
			        }
			        int num = 0;
			        for (i = 0; i < n; i++) { //找圈，收缩圈
			            if (visit[i] == -1) {
			                j = i;
			                for(j = i; j != -1 && visit[j] == -1 && j != root; j = pre[j]) {
			                    visit[j] = i;
			                }
			                if (j != -1 && visit[j] == i) {
			                    for (k = pre[j]; k != j; k = pre[k]) {
			                        belong[k] = num;
			                    }
			                    belong[j] = num ++ ;
			                }
			            }
			            sum += inv[i];
			        }
			        if (num == 0) return sum;
			        for (i = 0; i < n; i++){
			            if (belong[i] == -1) {
			                belong[i] = num ++ ;
			            }
			        }
			        for (i = 0; i < m; i++) { //重新构图
			            e[i].w = e[i].w - inv[e[i].v];
			            e[i].v = belong[e[i].v];
			            e[i].u = belong[e[i].u];
			        }
			        n = num;
			        root = belong[root];
			    }
			}



		
####    02.	*最短路*  

*	floyd  

*	dijkstra  

*	spfa  

	普通入队列方式可以被cha  

	deque判当前节点和队首节点可以被三角形数据cha  

	priority_queue优化(本质dijkstra靠谱!)

*	K短路  

	练手: POJ2449 UVA10740   
	提高: SGU145 SGU314

	最短路+A*

		f[x] = g[x] + h[x]
		其中h[x]以从t到x的最短路
		g[x]为从s到x的当前路径长度

	YEN算法

	MPS算法

	最短路树+回溯

	带环K短路

	无环K短路
	
	不重复k短路
		
		费用流~.~

*	求字典序最小的路径

	无重复标号(如给定边长度, 输出最短路径上经过的结点的最小字典序):hdu1385

	有重复标号(如边长度都为d, 每条边给定标号, 输出最短路径上边标号的最小字典序)http://codeforces.com/gym/100084 (I题)

	有重复标号(如给定边长度和边标号, 输出最短路径上每条边给定的标号的最小字典序)???


####    03.  *最小环&最大环* 

*	最小环  

	验题: POJ1734 
			    
		//floyd算法
		//g[][] 边
		//f[][] 最短路
		//pre[][] 记录路径
		int MinCircle() {
		    int i, j, k, p;
		    int mc = MOD;
		    for(i = 1; i <= n; ++i) {
		        for(j = 1; j <= n; ++j) {
		            f[i][j] = g[i][j];
		            if(g[i][j] < MOD && i != j) {
		                pre[i][j] = j; //记录初始长度为1的路径
		            }
		            else {
		                pre[i][j] = -1;
		            }
		        }
		    }
		    for(k = 1; k <= n; ++k) {
		        for(i = 1; i < k ; ++i) {
		            for(j = i + 1; j < k; ++j) {
		                int tp = g[k][i] + f[i][j] + g[j][k];
		                if(tp < mc) { //更新最小环和路径
		                    mc = tp;
		                    for(p = i, len = 0; p != -1; p = pre[p][j], len++) {
		                        path[len] = p;
		                    }
		                    path[len++] = k;
		                }
		            } 
		        }
		        for(i = 1; i <= n; ++i) { //普通floyd过程
		            for(j = 1; j <= n; ++j) {
		                if(f[i][j] > f[i][k] + f[k][j]) {
		                    f[i][j] = f[i][k] + f[k][j];
		                    pre[i][j] = pre[i][k];
		                }
		            }
		        }
		    }
		    return mc;
		}

	未验题:

		//http://www.cnblogs.com/Yz81128/archive/2012/08/15/2640940.html
		//dijkstra
		//求一条边的两段的结点之间最短路(不包含这条边)和这条边之和
		//O(m*m*logn)


*	 最大环(??? 可做)

		poj2240
		//这一题, 货币兑换, 看看是否存在能使自己增值的方案, 感官上并不能算最大环问题, 而更贴切的看法是转换为最长路, 由BellmanFord思想判断存在>1的环的问题, 不过可以通过floyd的**松弛操作**同样解决掉 




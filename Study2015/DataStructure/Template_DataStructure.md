
##  DataStructure Template

### **Contents** 

1.  **BIT(树状数组)**    
2.  **SEGT(线段树)**  
3.  **函数式线段树(主席树)**   
10. **Other**
11. **待解决的问题**

----------------------------------------------------------

####    01. **BIT(树状数组)**  

*	一维BIT

		/*一维BIT,注意设置Maxn和Step(1<<Step), 注意查找第k大可能存在bug*/
		inline int LB(int x){return x&(-x);}
		struct BIT {
		    LL _[Maxn];
		    int n;
		    const int STEP = 20;
		    void init(int m) {
		        n = m + 5;
		        for(int i = 0; i <= n; i++) _[i] = 0;
		    }
		    LL query(int w) {
		        LL ret = 0;
		        for(w += 3; w > 0; w -= LB(w)) ret += _[w];
		        return ret;
		    }
		    void update(int w, LL d) {
		        for(w += e; w < n; w += LB(w)) _[w] += d;
		    }
		    int find_kth(int k) {   //UESTC_Dagon
		        int idx = 0;
		        for(int i = STEP; i >= 0; i--) {
		            idx |= 1<<i;
		            if(idx <= n && _[idx] < k) k -= _[idx];
		            else idx ^= 1<<i;
		        }
		        return idx - 2;
		    }
		};


*	二维BIT  
	


####    02. **SEGT(线段树)**  

*	函数版



*	KMP类



####    03. **函数式线段树(主席树)**  


####	04. **树链剖分(轻重链划分)**

*	bfs+手写栈

		//siz, dep, son, top, parent, mp, emp(边是谁的父边), ncnt线段树映射计数器
		int siz[Maxn], dep[Maxn], son[Maxn], top[Maxn], parent[Maxn], lv[Maxn], mp[Maxn], emp[Maxn], ncnt;
		//que用于bfsinit, sta, cur用于手写栈, head代替top
		int que[Maxn], head, tail;
		PII sta[Maxn];
		int cur[Maxn];
		int llv[Maxn];	//将v点或其指向父结点的边的权值映射记录用于求lv[]
		
		void bfsinit(int root = 1) {//siz[], dep[], son[], parent[], llv[], emp[]
		    int i, j, k, u, v, w;
		    int dmax;
		    head = tail = 0;
		    dep[root] = 0;
		    parent[root] = -1;
		    que[tail++] = root;
		    while(head < tail) {
		        u = que[head++];
		        siz[u] = 1;
		        for(j = last[u]; j != -1; j = e[j].next) {
		            v = e[j].v;
		            if(v == parent[u]) continue;
		            parent[v] = u;
		            dep[v] = dep[u] + 1;
		            //记录结点v初始值OR其父边的值
		            llv[v] = e[j].c;
		            emp[j / 2] = v;
		            que[tail++] = v;
		        }
		    }    
		    for(i = tail - 1; i >= 0; --i) {
		        u = que[i];
		        dmax = -1;
		        for(j = last[u]; j != -1; j = e[j].next) {
		            v = e[j].v;
		            if(v == parent[u]) continue;
		            siz[u] += siz[v];
		            if(dmax == -1 || siz[dmax] < siz[v]) dmax = v;
		        }
		        son[u] = dmax;
		    }
		}
		
		void split(int root = 1) { // 手写栈 top[], lv[], mp[]
		    int i, j, k, u, v, w;
		    int fa;
		    for(i = 0; i <= n; ++i) cur[i] = last[i];
		    head = 0;
		    sta[head++] = MP(root, root);
		    ncnt = 0;
		    while(head) {
		        head--;
		        u = sta[head].AA; fa = sta[head].BB;        
		        top[u] = fa;
		        mp[u] = ++ncnt;
		        lv[ncnt] = llv[u];
		        for(j = last[u]; j != -1; j = e[j].next) {
		            v = e[j].v;
		            if(v == parent[u]) continue;
		            if(v != son[u]) {
		                sta[head++] = MP(v, v);
		            }
		        }
		        if(son[u] != -1) {
		            sta[head++] = MP(son[u], fa);
		        }
		    }
		}

	    void split(int u, int t) {//dfs mp[], top[], lv[]
	        int j, v;
	        top[u] = t;
	        mp[u] = ++ncnt;
	        lv[ncnt] = llv[u];
	
	        if(son[u] != -1) split(son[u], t);
	        for(j = last[u]; j != -1; j = e[j].next) {
	            v = e[j].v;
	            if(v == fa[u]) continue;
	            if(v != son[u]) {
	                split(v, v);
	            }
	        }
	    }

		
		void debug() {
		    for(int i = 1; i <= n; ++i) {
		        int u = i;
		        printf("node[%d]: siz %d dep %d parent %d son %d top %d mp %d lv %d\n", 
				u, siz[u], dep[u], parent[u], son[u], top[u], mp[u], lv[u]);
		        
		    }
		}


*	



####    10. **Other**  




####    11. **待解决的问题**  

* 	整数Hash需要?
*	KMP下标需要平移至1为起点吗?
* 	exkmp模板有点虚....
* 	manacher找找需要改板子的题目
* 	AC自动机模板?刷dp还不够啊!!!
*	后缀数组O(n)模板带不?
* 	字符串最小表示法 ZOJ2006 ZOJ1729 HDU3374
* 	后缀树, 后缀自动机**板子**, **用途**, 常见题型
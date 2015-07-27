
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
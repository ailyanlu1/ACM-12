##  String Template
**********
### **Contents** 

1.  **Hash**   
2.  **KMP**  
3.  **拓展KMP**  
4.  **Manacher**  
5.  **AC自动机**  
6.  **后缀数组**  
7.  **后缀树**
8.	**后缀自动机**
9.	**字符串最小表示法** 
10. **Other**

----------------------------------------------------------

####    01. **Hash**  

*	一般字符串Hash  





####    02. **KMP**  

####    03. **拓展KMP**  

####    04. **Manacher**  

####    05. **AC自动机**  

####    06. **后缀数组**  

*	模板(O(nlogn))
	
	论文模板, 使用时注意num[]有效位为0~n-1, 但是需要将num[n]=0, 否则RE;另外, 对于模板的处理将空串也处理了, 作为rank最小的串, 因此有效串为0~n共, n-1个, 在调用da()函数时, 需要调用da(num, n + 1, m); 对于sa[], rank[]和height[]数组都将空串考虑在内, 作为rank最小的后缀!
		
		//O(nlogn)
		int n;
		int num[Maxn];  //待处理的串
		int sa[Maxn], rank[Maxn], height[Maxn];    //sa[1~n]value(0~n-1); rank[0..n-1]value(1..n); height[2..n]
		int wa[Maxn], wb[Maxn], wv[Maxn], wd[Maxn];
		
		int cmp(int *r, int a, int b, int x) {
			return r[a] == r[b] && r[a + x] == r[b + x];
		}
		
		void da(int *r, int n, int m) {       //  倍增算法 r为待匹配数组  n为总长度+1 m为字符范围
			int i, j, k, p, *x = wa, *y = wb, *t;
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


*	

####    07. **后缀树**  

####    08. **后缀自动机**  

####    09. **字符串最小表示法**  

####    10. **Other**  

####    11. **待解决的问题**  
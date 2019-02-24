/*input

*/
/**
 * C - Vacation
 * @author: Raj
 */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#define endl '\n'
#define lli long long int
#define vi vector<int>
#define vlli vector<lli>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define MOD 1000000007
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb(n) emplace_back(n)
#define pb(n) push_back(n)
#define F first
#define S second
#define int long long int
#define double long double
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set;
void note_to_myself(){
	//new_data_set s;
	//logn operations
	//cout << *(s.find_by_order(i)) << " ";
	//cout << "The index of number 6::" << p.order_of_key(6) << endl; 
}
int add(int x, int y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
int sub(int x, int y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
int mul(int x, int y) {
	return ((long long)x * y) % MOD;
}
inline int power(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
inline int inv(int a) {
	a %= MOD;
	if (a < 0) a += MOD;
	int b = MOD, u = 0, v = 1;
	while (a) {
		int t = b / a;
		b -= t * a; swap(a, b);
		u -= t * v; swap(u, v);
	}
	assert(b == 1);
	if (u < 0) u += MOD;
	return u;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> dp(3,0);
	for (int day = 0; day < n; ++day){
		vector<int> ndp(3,0);
		vector<int> hap(3,0);
		for (int i = 0; i < 3; ++i){
			cin >> hap[i];
		}
		for (int i = 0; i < 3; ++i){
			for (int j = 0; j < 3; ++j){
				if (i!=j){
					ndp[j] = max(ndp[j],hap[j]+dp[i]);
				}
			}
		}
		// cout << "\n------------------------";
		// cout << "\ndp    -> ";
		// for (int i = 0; i < 3; ++i)cout << dp[i] <<" ";
		// cout << "\nndp   -> ";
		// for (int i = 0; i < 3; ++i)cout << ndp[i] <<" ";
		dp = ndp;
	}
	cout << max({dp[0],dp[1],dp[2]}) << endl;
	return 0;
}
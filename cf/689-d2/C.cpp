#include<bits/stdc++.h> 
#include <chrono> 
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp> 
#define mod 1000000007
#define mod2 998244353
#define int long long
#define endl '\n'
#define p_b push_back
#define m_p make_pair
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
using namespace __gnu_pbds;
using namespace std::chrono; 
 
template <class T> 
using _ost = tree<
        T, 
        null_type, 
        less_equal<T>, 
        rb_tree_tag, 
        tree_order_statistics_node_update>;
 
// char alphabet[26] = {'a','b','c','d','e','f','g','h','i',
//        'j','k','l','m','n','o','p','q','r','s','t','u','v',
//        'w','x','y','z'};
 
// rectangle intersection
// x5 = max(x1, x3);
// y5 = max(y1, y3);
// x6 = min(x2, x4);
// y6 = min(y2, y4); 
 
// const int mx = 1000005;
 
// char get_next(char c) {
// 	for(int i=0; i<25; i++) if(c == alphabet[i]) return alphabet[i+1];
// 	return 'a';
// }
 
int32_t main() {
    fastIO;
 
    int tc;
    tc = 1;
    cin >> tc;
    // int ct = 0;
    while(tc --) {
        int n, m;
        cin >> n >> m;
        int a[n]; for(int i=0; i<n; i++) cin >> a[i];
        int i=n-1;
        for(; i>=0; i--) {
        	if(a[i] != i+1) break;
        }
        int k = i+1;
        // cout << k << endl;
        int r[m];
        double p[m];
        vector<int> v;
        for(int i=0; i<m; i++){
        	cin >> r[i] >> p[i];
        	if(r[i] >= k){
        		v.p_b(i);
        	}
        }
        if(k == 0){
        	cout << 1 << endl;
        	continue;
        }
        double res = 0.0;
        double cum = 1.0;
        for(int i=0; i<v.size(); i++){
        	res += cum * p[v[i]];
        	cum *= (1-p[v[i]]); 
        }
        cout << fixed << setprecision(9) << res << endl;
    }     
}


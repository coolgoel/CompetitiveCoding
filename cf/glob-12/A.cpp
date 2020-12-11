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
        int n, k;
        cin >> n >> k;
        int x[n], y[n];
        for(int i=0; i<n; i++) cin >> x[i] >> y[i];
        bool f = 1, g = 1;
    	for(int i=0; i<n; i++){
    		for(int j=0; j<n; j++){
    			if(j == i)continue;
    			if(abs(x[i] - x[j]) + abs(y[i] - y[j]) > k){
    				f = 0;
    				break;
    			}
    		}
    		g = f;
    		if(f) break;
    		f = 1;
    	}
    	if(g) cout << 1 << endl;
    	else cout << -1 << endl;
    }     
}

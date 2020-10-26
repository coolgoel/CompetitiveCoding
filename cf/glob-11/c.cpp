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
 
struct trip 
{
    int t, x, y;
    int mx;
};
int32_t main() {
    fastIO;
 
    int tc;
    tc = 1;
    // cin >> tc;
    // int ct = 0;
    while(tc --) {
        int r, n;
        cin >> r >> n;
        trip dp[n+1];
        dp[0].x = dp[0].y = 1;
        dp[0].t = 0;
        dp[0].mx = 0;
        int maxnow[n+1] = {0};
        for(int i=1; i<=n; i++) 
        {
            cin >> dp[i].t >> dp[i].x >> dp[i].y;
            dp[i].mx = -1e9;
            for(int j=max(0LL, i-2*r); j<i; j++)
            {
                if(dp[i].t - dp[j].t >= abs(dp[i].x - dp[j].x) + abs(dp[i].y - dp[j].y) and dp[j].mx >= 0) dp[i].mx = max(dp[i].mx, 1 + dp[j].mx);
            }
            if(i > 2*r)
            {
                dp[i].mx = max(dp[i].mx, 1 + maxnow[i-2*r]);
            }
            maxnow[i] = max(maxnow[i-1], dp[i].mx);      
        }
        cout << maxnow[n] << endl;
    }     
}

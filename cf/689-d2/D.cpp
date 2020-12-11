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

 
void perform(vector<int> &a, map<int, bool> &mep, int pre[], int l, int r){
	int sum = 0;
	if(l == 0) sum = pre[r];
	else sum = pre[r] - pre[l-1];
	mep[sum] = 1;
	if(a[l] == a[r]) {
		return;
	}
	else{
		int mid = (a[l] + a[r]) / 2;
		int k = upper_bound(a.begin(), a.end(), mid) - a.begin();
		perform(a, mep, pre, l, k-1);
		perform(a, mep, pre, k, r);
	}
}

int32_t main() {
    fastIO;
 
    int tc;
    tc = 1;
    cin >> tc;
    // int ct = 0;
    while(tc --) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
       	sort(a.begin(), a.end());
       	int pre[n];
       	pre[0] = a[0];
       	for(int i=1; i<n; i++) pre[i] = pre[i-1] + a[i];
        map<int,bool> mep;
       	perform(a, mep, pre, 0, n-1);
       	int k;
       	vector<string> res;
       	for(int i=0; i<q; i++){
       		cin >> k;
       		if(mep[k]) res.p_b("Yes");
       		else res.p_b("No");
       	}
       	for(auto s: res) cout << s << endl;
    }     
}

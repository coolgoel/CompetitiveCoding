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
 
void bit_add(int Bit[], int n, int id, int val)
{
    id++;
    while(id <= n)
    {
        Bit[id] += val;
        id += id & (-id);
    }
}
int bit_sum(int Bit[], int id)
{
    id++;
    int res = 0;
    while(id)
    {
        res += Bit[id];
        id -= id & (-id);
    }
    return res;
}
int BIT(vector<int> v)
{
    int res = 0;
    int n = v.size();
    int Bit[n+1];
    for(int i=0; i<=n; i++)
    {
        Bit[i] = 0;
    }
    for(int i=n-1; i>=0; i--)
    {
        res += bit_sum(Bit, v[i]);
        bit_add(Bit, n, v[i], 1);
    }
    return res;
}
int inv_count(vector<int> &v)
{
    return BIT(v);
}
int32_t main() {
 	// fastIO;
 
	int tc;
	tc = 1;
	// cin >> tc;
	while(tc --) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        queue<int> q[26];
        for(int i=0; i<n; i++) 
        {
            q[s[i] - 'a'].push(i);
        }
        vector<int> v(n);
        for(int i=n-1; i>=0; i--) 
        {
            v[(q[s[i] - 'a'].front())] = n-i-1;
            q[s[i] - 'a'].pop();
        }
        // for(int i=0; i<n; i++) cout << v[i] << " "; cout << endl;
        cout << inv_count(v) << endl;
  	}     
}
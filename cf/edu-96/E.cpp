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
 
int merge(vector<int> &v, int l, int r, int md)
{   
    int res = 0;
    if(r > l)
    {
        vector<int> lf, rg, f;
        for(int i=l; i<=md; i++)
        {
            lf.p_b(v[i]);
        }
        for(int i=md+1; i<=r; i++)
        {
            rg.p_b(v[i]);
        }
        int i=0, j=0;
        while(i < md-l+1 && j < r-md)
        {
            if(lf[i] <= rg[j])
            {
                f.p_b(lf[i]);
                i++;
            }
            else
            {
                f.p_b(rg[j]);
                res += md - l - i + 1;
                j++;
            }
            
        }
        while(i < md-l+1)
        {
            f.p_b(lf[i]);
            i++;
        }
        while(j < r-md)
        {
            f.p_b(rg[j]);
            j++;
        }
        for(int i=l; i<=r; i++)
        {
            v[i] = f[i-l];
        }
    }
    return res;
}
int merge_sort(vector<int> &v, int l, int r)
{
    int res=0;
    if(r > l)
    {
        int md = (l+r)/2;
        res += merge_sort(v, l, md);
        res += merge_sort(v, md+1, r);
        res += merge(v, l, r, md);
    }
    return res;
}

int inv_count(vector<int> &v)
{
    return merge_sort(v, 0, v.size()-1);
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
        cout << inv_count(v) << endl;
  	}     
}
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

int mat[505][505][300];
int32_t main() {
    fastIO;
 
    int tc;
    tc = 1;
    cin >> tc;
    // int ct = 0;
    while(tc --) {
    	int n,m;
    	cin >> n >> m;
    	string s[n];
    	for(int i=0; i<n; i++) cin >> s[i];
    	for(int i=0; i<n; i++) for(int j=0; j<m; j++) for(int l=0; l<300; l++) {if(l == 0) mat[i][j][l] = 1; else mat[i][j][l] = 0;}
        int lf[n][m], rg[n][m];
    	for(int i=0; i<n; i++) for(int j=0; j<m; j++) {lf[i][j]=0; rg[i][j]=0;}
        for(int i=0; i<n; i++) {lf[i][0] = s[i][0] == '*'; rg[i][m-1] = s[i][m-1] == '*';}
		for(int i=0; i<n; i++){
			for(int j=1; j<m; j++){
				if(s[i][j] == '*'){
					lf[i][j] = lf[i][j-1] + 1;
				}
				else lf[i][j] = 0;
			}
		}        
		for(int i=0; i<n; i++){
			for(int j=m-2; j>=0; j--){
				if(s[i][j] == '*'){
					rg[i][j] = rg[i][j+1] + 1;
				}
				else rg[i][j] = 0;
			}
		}
		
		int cnt = 0;
        for(int h=1; h<300; h++){
        	for(int i=0; i<n; i++){
        		for(int j=0; j<m; j++){
        			if(s[i][j] == '*' && lf[i][j] >= h && rg[i][j] >= h){
        				if(i == 0){
        					if(h == 1) {
        						mat[i][j][h] = 1;
        						cnt++;
        					}	
        				}
        				else {
        					if(mat[i-1][j][h-1]) {
        						mat[i][j][h] = 1;
        						cnt++;
        					}	
        				}
        			}
        		}
        	}
        }
        cout << cnt << endl;
    }     
}

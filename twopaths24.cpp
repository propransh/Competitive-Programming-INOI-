#include <bits/stdc++.h>
using namespace std;
#define boost  ios_base::sync_with_stdio(0);
#define ll long long int
#define pb push_back
#define tc long long int t; cin >> t; while(t--)
#define vpll vector<pair<ll,ll>>
#define MOD 1000000007
#define vl vector<ll>
#define vi vector<int>
#define ff first
#define ss second
const int N = 100010;

int main() {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
	boost;
	ll i,j;
	tc{
	    ll n, m, k; 
	    cin >> n >> m >> k;
	    ll arr[n][m], dp[n][m][k + 1], dp1[n][m][k + 1], pref[n][m];
	    for(i = 0; i < n; i++){
	        for(j = 0; j < m; j++){
	            cin >> arr[i][j];
	        }
	    }
	    for(i = 0; i < n; i++){
	        for(j = 0; j < m; j++){
	            if(j == 0){ 
	            	pref[i][j] = arr[i][j];
	            }
	            else{
	                pref[i][j] = pref[i][j - 1] + arr[i][j];
	            }
	        }
	    }
	    for(i = 0; i < n; i++){
	        for(j = 0; j < m; j++){
	            for(ll c = 0; c <= k; c++){
	                dp[i][j][c] = pref[i][j];
	                if(!i){
	                    continue;
	                }
	                if(!j || !c){
	                    dp[i][j][c] += dp[i - 1][j][c];
	                }
	                else{
	                    dp[i][j][c] += max(dp[i - 1][j][c], dp[i - 1][j - 1][c - 1]);
	                }
	            }
	        }
	    }
	    for(i = 0; i < n; i++){
	        for(j = 0; j < m; j++){
	            for(ll c = 0; c <= k; c++){
	                dp1[i][j][c] = pref[i][j] - arr[i][j];
	                if(!i){
	                    continue;
	                }
	                if(!j || !c){
	                    dp1[i][j][c] += dp1[i - 1][j][c];
	                }
	                else{
	                    dp1[i][j][c] += min(dp1[i - 1][j][c], dp1[i - 1][j - 1][c - 1]);
	                }
	            }
	        }
	    }
	    ll ans = INT_MIN;
	    for(i = 0; i < m; i++){
	        for(j = i + k + 1; j < m; j++){
	            ans = max(ans, dp[n - 1][j][k] - dp1[n - 1][i][k]);
	        }
	    }
	    cout << ans << endl;
	}
	return 0;
}
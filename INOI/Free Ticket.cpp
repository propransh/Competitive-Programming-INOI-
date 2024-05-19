#include <bits/stdc++.h>
using namespace std;
#define boost  ios_base::sync_with_stdio(0);
#define ll long long int
#define pb push_back
#define tc long long int t; cin >> t; while(t--)
#define vpll vector<pair<ll,ll>>
#define MOD 1000000007

int main(){
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
	boost;
	ll i;
	ll n,m;
	cin >> n >> m;
	vector<pair<ll,ll>> adj[n+3];
	ll x,y,z;
	for(i = 0; i < m; i++){
		cin >> x >> y >> z;
		adj[x].pb({z,y});
		adj[y].pb({z,x});
	}
	ll dp[n+3][n+3];
	ll j,k;
	for(i = 1; i <= n ; i++){
		for(j = 1; j <= n ; j++){
			dp[i][j] = 1e17;
		}
	}
	for(i = 1 ;i <= n ; i++){
		for(auto it : adj[i]){
			ll a = it.first;
			ll b = it.second;
			dp[i][b] = a;
		}
	}
	for(k = 1; k <= n; k++){
		for(i = 1; i <= n; i++){
			for(j = 1; j <= n; j++){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	ll ma = 0;
	for(i = 1; i <= n; i++){
		for(j = i+1; j <= n; j++){
			ma = max(ma,dp[i][j]);
		}
	}
	cout << ma <<endl;
	return 0;
} 

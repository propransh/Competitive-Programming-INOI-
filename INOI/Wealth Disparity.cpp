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
ll n;
ll p[N], a[N];
vector<ll> adj[N];
ll ans = 0; 
ll dp[N];
ll f(ll i, ll p){
	ll cnt = 0;
	for(auto it : adj[i]){
		if(it != p){
			cnt = max(cnt, f(it, i));
		}
	}
	return dp[i] = cnt + a[p] - a[i];
}

int main(){
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
	boost;
	ll i;
	cin >> n;
	for(i = 1 ;i <= n; i++){
		cin >> a[i];
	}
	ll b = -1;
	for(i = 1; i <= n; i++){
		cin >> p[i];
		if(p[i] != -1){
			adj[p[i]].pb(i);
		}
		else{
			b = i;
		}
	}
	f(b,b);
	for(i = 1; i <= n; i++){
		ans = max(ans,dp[i]);
	}
	cout << ans << endl;
	return 0;
} 	

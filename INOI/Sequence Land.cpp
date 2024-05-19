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
const int N = 301; 
vector<vl> v(N);
vector<ll> adj[N];
bool vis[N] = {false};
ll n, K; 

bool check(ll i, ll j) {
    unordered_set<ll> elements(v[i].begin(), v[i].end());
    ll common = 0;
    for (auto &el : v[j]) {
        if (elements.find(el) != elements.end()) {
            common++;
            if (common >= K) return true; // Early return if K common elements found
        }
    }
    return false;
}

ll f(ll i){
	vis[i] = 1;
	ll ans = 1;
	for(auto it : adj[i]){
		if(vis[it] == 0){
			ans += f(it);
		}
	}
	return ans;
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
	cin >> n >> K;
	for(i = 0; i < n; i++){
		ll p;
		cin >> p;
		while(p--){
			ll x;
			cin >> x;
			v[i].pb(x);
		}
	}

	for(i = 0; i < n; i++){
		for(ll j = i+1; j < n; j++){
			if(check(i,j)){
				adj[i].pb(j);
				adj[j].pb(i);
			}
		}
	}
	memset(vis,0,sizeof(vis));
	cout << f(0) << endl;
	return 0;
} 	

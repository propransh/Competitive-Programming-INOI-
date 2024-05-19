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
 
int main(){
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
	boost;
	ll i;
	ll n, k;
    cin >> n >> k;

    vector<ll> arr(n + 1), fwd(n + 1), bck(n + 1);

    /*
    lets consider this scenario

	0------------kth----------ith

	there are two path
	1- [kth,ith]
	2- [ith, 0 ] 

	since max path sum is symmetric we can say 

	1- [kth, ith] ( can be found using fwd[i] )
	2- [0, ith]   ( can be found using bck[i] ) 
	*/

    for(i = 1; i <= n; i++){
        cin >> arr[i];
    }

    for(i = k + 1; i <= n; i++){
        fwd[i] = arr[i] + max(fwd[i - 1], fwd[i - 2]);
    }

    bck[1] = arr[1];
    bck[2] = arr[1] + arr[2];

    for(i = 3; i <= n; i++){
        bck[i] = arr[i] + max(bck[i - 1], bck[i - 2]);
    }

    ll ans = -INT_MAX;
    
    for(i = k; i <= n; i++){
        ans = max(ans, bck[i] + fwd[i] - arr[i]);
    }

    cout << ans << endl;
	return 0;
} 	

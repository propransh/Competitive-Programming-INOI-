#include <bits/stdc++.h>
using namespace std;
#define boost  ios_base::sync_with_stdio(0);
#define N 1000
#define ll long long int
#define pb push_back
#define f first
#define s second
#define fo(i,a,b) for(i = a; i < b; i++)
#define foe(i, a,b) for(i = a; i <= b; i++)
#define tc long long int t; cin >> t; while(t--)
#define vect vector <ll>
#define pll pair<ll,ll>
#define vpll vector<pair<ll,ll>>
#define be begin
#define en end


int main(){
	boost;
	ll i;
	ll n;
	cin >> n;
	ll a,b,c;
	ll sum = 0, mini = 1000000, z = 0 , maxi = 0, x = 0;
	for(i = 0; i < n; i++){
		cin >> a >> b >> c;
		x=(a+b+c);
		maxi = max(maxi, x);
		sum += a;
		z =  b+c;
		mini = min(mini,z);
	}
	cout << max(maxi, mini +sum) <<endl;
	return 0;
} 

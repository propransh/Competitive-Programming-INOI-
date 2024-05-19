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
	ll n,j,x;
   	cin >> n;
    vector<ll> a(n),b(n+1,0),c(n+1,0);
    for(i=0;i<n;i++){
        cin >> x;
        a[i]=x+i+1;
    }
    b[0]=a[0];
    c[n-1]=a[n-1];
    for(i=1;i<n;i++){
        b[i]=max(b[i-1],a[i]);
        c[n-1-i]=max(c[n-1-i+1],a[n-1-i]);
    }
    for(i=0;i<n;i++){
       	cout << max(i+b[n-1-i],i+c[n-i]-n) << endl;;
    }
	
	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
	return 0;
}
#include <bits/stdc++.h>
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i)

#define pb push_back
#define fi first
#define se second

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()

#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define sz(a) int((a).size())

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

ll _10mu(ll x){
    ll a =1;
    for(int i = 0; i< x; i++) a *= 10;
    return a;
}
ll dem(ll x){
    ll a = 1;
    while(x > 9) {
        a *= x%10 + 1;
        x /= 10;
    }
    return a*x;
}

void solve(){
    ll n;
    cin >> n;
    ll num = 0;
    ll m = n;
    while(m > 0){
        num++;
        m /= 10;
    }

    if(num%2 != 0){
        cout << _10mu(num/2) - 1;
        return;
    }

    ll half = _10mu(num/2);
    ll ans = half/10 - 1;
    ll a = n/half;
    ll b = n%half;

    if(a>b) {
        ans += dem(a-1);
        
    }
    else ans+= dem(a);
    cout << ans;

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();

    return 0;
}


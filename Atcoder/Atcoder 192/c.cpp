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

int to_int(vector<int>&a){
    int cnt = 1;
    int res = 0;
    for(int i = a.size()-1; i>=0; i--){
        res += a[i] * cnt;
        cnt *= 10;
    }
    return res;

}

void solve(int &n){
    vector<int>a;
    while(n > 0){
        a.push_back(n%10);
        n /= 10;
    }
    sort(a.begin(), a.end());
    vector<int>b = a;
    reverse(b.begin(), b.end());
    n = to_int(b) - to_int(a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i =0 ;i<k ;i++){
        solve(n);
    }
    cout<<n<<endl;
    return 0;
}
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

const int N = 2e5 + 1;
int n;
int a[N], t[N];

void solve(int& x){
    for(int i = 0; i<n; i++){
        if(t[i] == 1){
            x += a[i];
        }else if(t[i] == 2){
            x = max(x,a[i]);
        }else{
            x = min(x, a[i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>a[i]>>t[i];
    }
    int q;
    cin>>q;
    for(int i = 0; i<q;i++){
        int x;
        cin>>x;
        // cout<<solve(x)<<endl;
        solve(x);
        cout<<x<<endl;
    }
    return 0;
}

//O(n*w)
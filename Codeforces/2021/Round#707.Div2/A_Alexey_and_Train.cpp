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
typedef pair<int, int> ii;W
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n),b(n),tm(n);
        for(int i = 0; i<n; i++){
            cin>>a[i]>>b[i];
        }
        for(int i = 0; i<n; i++){
            cin>>tm[i];
        }
        int curr = 0;
        for(int i = 0; i<n; i++){
            if(i == 0) curr += tm[i] + a[i];
            else curr += tm[i] + a[i] - b[i-1];

            if(i == n-1) break;
            if(curr + ceil((double)(b[i] - a[i])/2) > b[i]){
                curr += ceil((double)(b[i] - a[i])/2);
            }else{
                curr = b[i];
            }
        }
        cout<<curr<<endl;
    }
    return 0;
}
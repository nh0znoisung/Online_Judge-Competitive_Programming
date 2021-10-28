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

int h,w,a,b;
int s[20][20];
int ans = 0;


void solve(int a, int b){
    if(a == 0 && b== 0){
        ++ans;
        // printArr();
        return;
    }
    for(int i = 0; i<h; i++){
        for(int j = 0; j<w; j++){
            if(s[i][j] == 0){
                // if(a > 0){
                    if(i+1 < h && s[i+1][j] == 0){
                        s[i][j] = 2;
                        s[i+1][j] = 2;
                        solve(a-1,b);
                        s[i][j] = 0;
                        s[i+1][j] = 0;
                    }
                    if(j+1 < w && s[i][j+1] == 0){
                        s[i][j] = 2;
                        s[i][j+1] = 2;
                        solve(a-1,b);
                        s[i][j] = 0;
                        s[i][j + 1] = 0;
                    }
                // }
                if(b > 0){
                    s[i][j] = 1;
                    solve(a, b-1);
                    s[i][j] = 0;
                }
                return;
            }
        }
    }
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>h>>w>>a>>b;
    solve(a,b);
    cout<<ans<<endl;

    return 0;
}


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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    const int Mxn = 1e9;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        // map<int,int>check;
        map<int,int>check;
        // vector<int>check(Mxn+1, 0);
        int mx = 0;
        int mex = 0;        
        for(int i = 0; i<n ;i++){
            cin>>a[i];
            check[a[i]] = 1;
            mx = max(mx, a[i]);
        }
        // vector<int>check(mx+1);
        

        for(int i = 0; i<= Mxn; i++){
            if(!check[i]){
                mex = i;
                break;
            }
        }
        // n is count
        // cout<<mx<<mex<<endl;

        int l = 0;
        while(k--){
            // cout<<"Hello"<<endl;
            // cout<<k<<endl;
            if(mex == mx +1){
                n += k+1;
                break;
            }
            l = ceil((double) (mx + mex)/2);
            if(check[l]){
                continue;
            }else{
                check[l] = 1;
                if(l == mex){
                    while(check[mex]){
                        mex++;
                    }
                }
                if(l > mx) mx = l;
                n++;
            }
        }
        cout<<n<<endl;

        
    }
    return 0;
}
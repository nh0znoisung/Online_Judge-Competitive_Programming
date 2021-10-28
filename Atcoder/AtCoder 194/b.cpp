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
    int n;
    cin>>n;
    
    vector<pair<int,int>>a;
    for(int i = 0; i<n; i++){
        int x,y;
        cin>>x>>y;
        a.push_back({x,i});
        a.push_back({y, i});
    } 
    int ans=0;
    sort(a.begin(), a.end());
    if(a[0].second !=a[1].second){
        ans = max(a[0].first , a[1].first);
    }else{
        ans = min(a[0].first + a[1].first, max(a[0].first, a[2].first));
    }
    // int ans = 1e6 + 5;
    // int mn = 1e5 + 3, idx = 0;
    // for(int i =0 ; i<n; i++){
    //     if(a[i] < mn){
    //         mn = a[i];
    //         idx = i;
    //     }
    // }
    // int mn1 = 1e5 + 3;
    // for(int i =0; i<n; i++){
    //     if(i == idx) continue;
    //     if(b[i] < mn1){
    //         mn1 = b[i];
    //     }
    // }
    // if(b[idx] <= mn1) ans = max(mn, mn1);
    // else{
    //     ans = min(ans, mn1 + mn);
    //     int mn2 = 1e5 + 3;
    //     for(int i = 0; i < n; i++){
    //         if(i == idx) continue;
    //         if(a[i] < mn2){
    //             mn2 = a[i];
    //         }
    //     }
    //     if(mn2 == mn){
    //         ans = min(ans, max(mn1, mn2));
    //     }else{
    //         ans = min(ans, max(mn2, mn1));
    //     }
    // }
    cout<<ans<<endl;
    return 0;
}
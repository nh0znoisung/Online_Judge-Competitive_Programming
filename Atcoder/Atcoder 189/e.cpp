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
    vector<pair<ll,ll>>a;
    for(int i =0 ; i<n; i++){
        ll x,y;
        cin>>x>>y;
        a.push_back({x,y});
    }
    vector<pair<ll,ll>>b;
    int m;
    cin>>m;
    for(int i =0 ;i<m; i++){
        ll x;
        cin>>x;
        if(x == 1 || x == 2){
            b.push_back({x,0});
        }else{
            ll p;
            cin>>p;
            b.push_back({x,p});
        }
        // b.push_back(x);

    }
    ll q;
    cin>>q;
    vector<pair<ll,ll>>c;
    map<ll,ll>d;
    for(int i =0; i<q; i++){
        ll x,y;
        cin>>x>>y;
        c.push_back({x,y});
        d[y] ++;
    }
    vector<vector<pair<ll,ll>>>ans(m+1);
    for(auto l: d){
        // i.first
        ans[l.first].push_back(a[l.first-1]);
        pair<ll,ll>i = ans[l.first].back();
        for(int k = 0; k<m; k++){
            if(b[k].first == 1){
                ll temp = i.first;
                i.first = i.second;
                i.second = -temp;
            }else if(b[k].first == 2){
                ll temp = i.first;
                i.first = -i.second;
                i.second = temp;
            }else if(b[k].first == 3){
                i.first = 2*b[k].second - i.first;
            }else if(b[k].first == 4){
                i.second = 2*b[k].second - i.second;
            }
            ans[l.first].push_back(i);
        }
    }
    for(int i =0; i<q; i++){
        cout<<ans[c[i].second][c[i].first].first<<" "<<ans[c[i].second][c[i].first].second<<endl;
    }

    return 0;
}
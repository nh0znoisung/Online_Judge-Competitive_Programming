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
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>a;
    for(int i =0 ; i<m ;i++){
        int x,y;
        cin>>x>>y;
        a.push_back({x,y});
    }
    int k;
    cin>>k;
    vector<pair<int,int>>b;
    for(int i = 0; i<k; i++){
        int c,d;
        cin>>c>>d;
        b.push_back({c,d});
    }
    int res = 0;
    vector<int>e(k);
    for(int i = 0; i<((1<<k)-1); i++){
        vector<int>check(n+1, 0);
        int temp = i;
        for(int j =0 ; j <k; j++){
            e[j] = temp%2;
            temp /=2;
            if(e[j] == 0){
                check[b[j].first] = 1;
            }else{
                check[b[j].second] = 1;
            }
        }
        //check
        int cnt = 0;
        for(int j = 0; j<m; j++){
            if(check[a[j].first] == 1 && check[a[j].second] == 1){
                cnt ++;
            }
        }
        res = max(res, cnt);
        

    }
    cout<<res<<endl;


    return 0;
}
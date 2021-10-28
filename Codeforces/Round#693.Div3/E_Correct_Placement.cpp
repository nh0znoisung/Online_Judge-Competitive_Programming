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
    while(t--){
        int n;
        cin>>n;
        map<int,vector<pair<int,int>>>a;
        map<int,pair<int,int>>b;
        map<int,pair<int,int>>dp;
        for(int i = 0; i<n ;i++){
            int x,y;
            cin>>x>>y;
            if(y > x){
                int temp = y;
                y = x;
                x = temp;
            }
            
            if(a[x].size() == 0){
                a[x].push_back({y,i});
                b[x] = {y,i};
            }else{
                a[x].push_back({y,i});
                if(y < b[x].first){
                    b[x] = {y,i};
                }
            }
            
           
        }
        pair<int,int>k = {0,0};
        for(auto i: b){
            if(k == {0,0}){
                dp[i.first] = b[i.first];
                k = b[i.first];
            }else{
                if(k.first <= b[i.first].first){
                    dp[i.first] = k;
                }else{
                    dp[i.first] = b[i.first];
                    k = b[i.first];
                }
            }
        }
        vector<int>l(n);
        for(auto i: a){
            for(int j = 0; j<i.second.size(); j++){
                if(l[i.second[j].first] <= dp[i.first]) l[i.second[j].first] = -1;
            }
        }

        for(int i = 0; i<n; i++){
            cout<<l[i]<<" ";
        }
        cout<<endl;

    }
    return 0;
    
}
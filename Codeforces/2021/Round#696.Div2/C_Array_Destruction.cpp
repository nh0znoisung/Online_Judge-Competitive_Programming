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
        vector<int>a(2*n);
        for(int i =0 ; i<2*n; i++){
            cin>>a[i];
        }
        sort(a.begin() , a.end());
        // for(int i = 0; i<a.size(); i++){
        //     cout<<a[i] <<" ";
        // }
        // cout<<endl;
        bool good = 0;
        for(int i = 2*n-2; i>=0; i--){
            vector<int>vis(2*n, false);
            vector<pair<int,int>>c;
            vis[2*n-1] = true;
            vis[i] = true;
            int curr = a[2*n-1];
            bool ok = 1;
            for(int j = 2*n -2; j>=0; j--){
                if(vis[j]) continue;
                else{
                    vis[j]  =true;
                    int k = lower_bound(a.begin(), a.begin() + j, curr - a[j]) - a.begin();
                    if(a[k] == curr-a[j]){
                        // cout<<"HEllo";
                        bool fine = 0;
                        while(a[k] == curr -a[j]){
                            if(!vis[k]){
                                vis[k] = true;
                                c.push_back({a[k], a[j]});
                                fine = 1;
                                break;
                            }
                            k++;
                        }
                        if(!fine){
                            ok = 0;
                            break;
                        }
                        // vis[k] = true;
                        // c.push_back({a[k], a[j]});
                    }else{
                        ok = 0;
                        break;
                    }
                    curr = a[j];
                }
            }
            if(ok){
                //result
                // cout<<i<<endl;
                cout<<"YES"<<endl;
                cout<<a[2*n-1] + a[i]<<endl;
                cout<<a[i]<<" "<<a[2*n - 1]<<endl;
                for(int i = 0; i<c.size(); i++){
                    cout<<c[i].first<<" "<<c[i].second<<endl;
                }
                
                good = 1;
                break;
            }
        }
        if(good == 0){
            cout<<"NO"<<endl;
        }
        
    }   
    return 0;
}
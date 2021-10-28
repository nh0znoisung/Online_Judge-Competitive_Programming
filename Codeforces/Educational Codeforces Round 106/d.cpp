#include <bits/stdc++.h>
using namespace std;
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;

// int x[N],y[N];
long long n,m,k;

void init(){
    //sieve erathos: prime from 1 to 2*10^7
}

int calc(int tar){
    //how many prime division
    int ans = 0;
    for(int i = 2; i<=tar; i++){
        bool ok = 1;
        for(int j = 2; j*j <= i; j++){
            if(i%j == 0){
                ok = 0;
                break;
            }
        }
        if(ok){
            if(tar%i == 0) ans++;
            
            while(tar%i == 0){
                tar /= i;
            }
        }
    }
    return ans;

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int c,d,x;
        cin>>c>>d>>x;
        int ans = 0;
        for(int i = 1; i<=x; i++){
            if(x%i == 0){
                int tar = x/i + d;
                // cout<<c<<endl;
                if(tar%c == 0){
                    tar /= c;
                    //(A.B) = 1
                    // cout<<tar<<endl;
                    ans += (1 << calc(tar));
                    // cout<<i<<endl;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
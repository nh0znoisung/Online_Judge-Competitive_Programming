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
    ll n;
    cin>>n;
    //check prime
   // cout<<sqrtl(n)<<endl;
    bool ok =  0;
    if(n <= 2) ok = 1;
    else{
      //  cout<<"ehllo "<<endl;
      //  cout<<sqrtl(n)<<endl;
        for(int i = 2; i<=sqrtl(n); i++){
           // cout<<i<<endl;
            if(n%i == 0){
                ok = 1;
                break;
            }
        }
    }
    if(!ok){
        cout<<4<<endl;
    }else{
        map<int,int>m;
        // ll temp = n;
        for(int i = 2; i<=n; i++){
            while(n%i == 0){
                m[i]++;
                n /= i;
            }
        }
        //   cout<<n<<endl;
        // for(auto i : m){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        ll cnt = 2;
        for(auto i : m){
            if(i.first != 2){
                cnt *= (i.second + 1);
            }
        }
        cout<<cnt<<endl;
    }

    return 0;
}
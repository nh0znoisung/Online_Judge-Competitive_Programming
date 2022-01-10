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

bool solve(vector<int>a){
    int n = a.size();
    int curr = a[0];
    bool ok = 1;
    for(int i = 1 ; i<n-1 ;i++){
        curr = a[i] - curr;
        if(curr < 0){
            ok = 0;
            break;
        }
    }
    if(curr != a[n-1] || !ok){
        return false;
    } 
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool odd = 1;
        vector<int>a(n);
        int sum = 0;
        for(int i =0 ; i<n; i++){
            cin>>a[i];
            a[i] = a[i] % 11;
            if(odd){
                sum += a[i];
                odd = 0;
            }else{
                sum -= a[i];
                odd = 1;
            }
            
        }
        if(sum %11 == 0){
            cout<<"YES"<<endl;
            continue;
        }
        // for(int i = 0; i<n ;i ++){
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;
     //   cout<<sum<<endl;
        bool good = 0;
        odd = 1;
        for(int i = n-1; i>= 1; i--){
            if(odd){
                if((sum - (a[i-1] - a[i]) * 9) % 11 == 0){
                    good = 1;
                    break;
                }
                odd = 0;
            }else{
                if((sum + (a[i-1] - a[i]) * 9) % 11 == 0){
                    good = 1;
                    break;
                }
                odd = 1;
            }
            
        }
        if(good){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }


    }
    return 0;   
}

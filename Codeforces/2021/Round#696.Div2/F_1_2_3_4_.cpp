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
const ll mxN = 998244353;

int lis(vector<int>arr)  
{  
    int lis[n]; 
   
    lis[0] = 1;    
    int ans = 0;
    for (int i = 1; i < n; i++ )  
    { 
        lis[i] = 1; 
        for (int j = 0; j < i; j++ )   
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)  
                lis[i] = lis[j] + 1;  
        ans = max(ans, lis[i]);
    } 
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin>>n>>x;
    vector<int>a(n);
    for(int i = 0; i<n ;i ++){
        cin>>a[i];
    }
    vector<int>b;
    b.push_back(x);
    bool ok = 0;
    for(int i = 0; i<n; i++){
        if(a[i] >=0){
            ok = 1
        }else{
            ok =0;
        }
        for(int j =0; j<abs(a[i]) ;j++){
            if(ok){
                 b.push_back(b[b.size()-1] + 1);
            }else{
                 b.push_back(b[b.size()-1] - 1);
            }           
        }
    }
    cout<<lis(b)<<" "<<


    return 0;
}
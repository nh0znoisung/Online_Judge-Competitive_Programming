#include <bits/stdc++.h>
#include <iostream>
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


void init_code(){
    ios_base::sync_with_stdio(false);
    #ifndef NEAL_DEBUG
        cin.tie(0);
    #endif
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

const int N=3e5 + 11;

int n, a[N];
//TODO: make sure all variables get reset
void run_case(){
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    sort(a, a+n);

    // spilt the vector 2 parts
    vector<int>f,s,res;
    for(int i = 0; i<n/2; i++){
        f.push_back(a[i]);
    }
    for(int i = n/2+1; i<n; i++){
        s.push_back(a[i]);
    }

    int x = 0;
    while(x <= n/2 + 1){
        if (x < f.size()) res.push_back(f[x]);
        if (x < s.size()) res.push_back(s[x]);
        x ++;
    }

    // for(int i = 0; i < n; i++){
    //     cout<<res[i]<< " ";
    // }
    // cout<<endl;

    bool ok = true;
    for(int i = 0; i < n-1; i++){
        if(res[i] == res[i+1]){
            ok = false;
            break;
        }
    }
    if(!ok){
        cout<<"-1"<<endl;
        return;
    }

    for(int i = 0; i < n; i++){
        cout<<res[i]<< " ";
    }
    cout<<endl;
}
int main() {
    init_code();
    int t;
    cin>>t;
    while(t--){
        run_case();
    }
    return 0;
}
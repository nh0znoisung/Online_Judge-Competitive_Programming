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
    vector<int>a(n);
    vector<int>b;
    int cnt = 1;
    for(int i =0; i<n; i++){
        cin>>a[i];
    }
    if(a[1] < a[0]) cnt = -1;
    for(int i = 1; i<n; i++){
        if((a[i] - a[i-1]) * cnt > 0){
            //true
            if(cnt > 0) cnt++;
            else cnt--;
        }else{
            //false
            b.push_back(cnt);
           if(cnt > 0) cnt = -1;
           else cnt = 1;
        }
    }
    b.push_back(cnt);
    for(int i = 0; i<b.size(); i++){
        cout<<b[i]<<endl;
        if(b[i] > 0){
            
        }
    }
    return 0;
}
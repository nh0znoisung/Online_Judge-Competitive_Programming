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

unsigned long long solve(vector<int>&a, int k){
    unsigned long long res = 0;
    unsigned long long cnt = 1;
    for(int i = a.size()-1; i>=0; i--){
        res += a[i]*cnt;
        cnt *= k;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    unsigned long long m;
    cin>>m;
    vector<int>a;
    int mx = 0;
    int n = s.size();
    for(int i =0 ;i<s.size(); i++){
        int k = s[i] - '0';
        mx = max(mx, k);
        a.push_back(k);
    }
    //calculate high
    unsigned long long l = (unsigned long long)m/mx;
    // log n-1 (l)
    unsigned long long k = log2(l)/(n-1);
    unsigned long long high = 1;
    while(k--){
        high *= 2;
    }
    high += 12;
    unsigned long long low = mx + 1;
    // cout<<low<<endl;
    // cout<<high<<endl;
    unsigned long long mid = 0;
    while(low < high){
        mid = low +(high - low)/2;
        if(m == solve(a, mid)){
            low = mid;
            break;
        }else if(m < solve(a, mid)){
            high = mid;
        }else{
            low = mid + 1;
        }
    }
    //low;
    // cout<<m<<endl;
    // cout<<solve(a,low -1)<<endl;
    // cout<<low<<endl;
    cout<<low - mx<<endl;

    return 0;
}
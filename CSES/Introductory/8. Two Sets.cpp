#include <bits/stdc++.h>
#define for0(i, n) for (long long i = 0; i < (long long)(n); ++i) // 0 based indexing
#define for1(i, n) for (long long i = 1; i <= (long long)(n); ++i) // 1 based indexing
#define forc(i, l, r) for (long long i = (long long)(l); i <= (long long)(r); ++i) // closed long longerver from l to r r inclusive
#define forr0(i, n) for (long long i = (long long)(n) - 1; i >= 0; --i) // reverse 0 based.
#define forr1(i, n) for (long long i = (long long)(n); i >= 1; --i) // reverse 1 based

//short hand for usual tokens
#define pb push_back
#define fi first
#define se second

// to be used with algorithms that processes a container Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end() //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal

// traversal function to avoid long template definition. Now with C++11 auto alleviates the pain.
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)

// find if a given value is present in a container. Container version. Runs in log(n) for set and map
#define present(c,x) ((c).find(x) != (c).end())

//find version works for all containers. This is present in std namespace.
#define cpresent(c,x) (find(all(c),x) != (c).end())

// Avoiding wrap around of size()-1 where size is a unsigned long long.
#define sz(a) long long((a).size())

using namespace std;

// Shorthand for commonly used types
typedef vector<long long> vi;
typedef vector<vi> vvi;
typedef pair<long long, long long> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin>>n;
    long long k = n*(n+1)/2;
    if(k%2 == 0){
        cout<<"YES"<<endl;
        k /= 2;
        vector<long long>a;
        long long i = n;
        while(k>=i){
            k -= i;
            a.push_back(i);
            i--;
        }
        if(k != 0) a.push_back(k);
        cout<<a.size()<<endl;
        for(long long i =0; i<(long long int)a.size(); i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        cout<<n - a.size()<<endl;
        for(long long i =1 ; i<a[a.size()-2]; i++){
            if(i != a[a.size()-1]){
                cout<<i<<" ";
            }
        }

    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}

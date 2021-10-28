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
        priority_queue<int>a;
        priority_queue<int>b;
        for(int i = 0; i<n; i++){
            int x;
            cin>>x;
            if(x%2 == 0) a.push(x);
            else b.push(x);
        }
        long long c = 0;
        ll d = 0;
        bool e = 0;
        while(!a.empty() || !b.empty()){
            if(!e){
                //a
                if(a.empty()){
                    b.pop();
                }
                // cout<<"adfas"<<endl;
                else if(b.empty()){
                    c += a.top();
                    a.pop();
                }
                else if(a.top() >= b.top()){
                    c += a.top();
                    a.pop();
                }else{
                    b.pop();
                }
                e=1;

            }else{
                //b
                if(a.empty()){
                    d += b.top();
                    b.pop();
                }
                else if(b.empty()){
                    a.pop();
                }
                else if(b.top() >= a.top()){
                    d += b.top();
                    b.pop();
                }else{
                    a.pop();
                }
                e=0;
            }
        }
        if(c>d) cout<<"Alice"<<endl;
        else if(c<d) cout<<"Bob"<<endl;
        else cout<<"Tie"<<endl;
    }
    return 0;
}
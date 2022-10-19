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

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' <<p.first<<", "<<p.second<<')';}

void dbg_out(){cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr<<' '<<H; dbg_out(T...);}
#ifdef NEAL_DEBUG
#define dbg(...) cerr<<"("<<#__VA_ARGS__<<"):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

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
const int M=998244353;
const int N=1000005,E=524288;

//in 1
string s;
ll ele;

int main() {
    init_code();
    int t;
    cin>>t;
    multiset<ll, greater<ll>>  left; //left : max-heap : begin
    multiset<ll> right; //right : min-heap: begin
    while(t--){
        cin>>s;
        // insert, erase, size, begin
        if(s[0]=='I'){
            // t--;
            cin>>ele;
            if(left.size() == 0){
                left.insert(ele);
            }
            else if(ele < *left.begin()){
                left.insert(ele);
            }
            else{
                right.insert(ele);
            }

            if(left.size() > right.size()+1){
                // cout<<"aseasd"<<endl;
                right.insert(*left.begin());
                left.erase(left.begin());
            }else if(right.size() > left.size()){
                // cout<<"123aseasd"<<endl;
                left.insert(*right.begin());
                right.erase(right.begin());
            }
        }else if (s[0] == 'O'){
            cin>>ele;
            // t--;
            if(ele <= *left.begin()){
                left.erase(ele);
            }else{
                right.erase(ele);
            }

            if(left.size() > right.size()+1){
                right.insert(*left.begin());
                left.erase(left.begin());
            }else if(right.size() > left.size()){
                left.insert(*right.begin());
                right.erase(right.begin());
            }
        }else if (s[0] == 'M'){
            //median
            // multiset<int, greater<int> >::iterator itr;
            // cout<<"Left:  ";
            // for (itr = left.begin(); itr != left.end(); ++itr) {
            //     cout << *itr << " ";
            // }
            // cout<<endl;
            // cout<<"Right: ";
            // for (itr = right.begin(); itr != right.end(); ++itr) {
            //     cout << *itr << " ";
            // }
            // cout<<endl;
            if(left.size() == 0){
                cout<<-1<<endl;
            }
            else if(left.size() == right.size()){
                cout<<(double)(*left.begin() + *right.begin())/2<<endl;
            }
            else{
                // cout<<"CCCC"<<endl;
                cout<<*left.begin()<<endl;
            }
        }
    }
    return 0;
}
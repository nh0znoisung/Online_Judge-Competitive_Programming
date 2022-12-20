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
const int N=5e4 + 1,E=524288;
int n,r,c,sr,sc;

string s;

class Node{
public:
    Node*up, *down, *left, *right;
    int r,c;
    Node(int r, int c){
        this->r=r;
        this->c=c;
        up=down=left=right=NULL;
    }
};

//TODO: make sure all variables get reset
void run_case(int l){

    cout<<"Case #"<<l<<": ";
    cin>>n>>r>>c>>sr>>sc;
    sr--; sc--;
    cin>>s;
    vector<vector<Node*>>g(r, vector<Node*>(c, NULL));
    // build Node grid
    for0(i,r){
        for0(j,c){
            g[i][j]=new Node(i,j);
        }
    }
    for0(i,r){
        for0(j,c){
            if(i > 0) g[i][j]->up=g[i-1][j];
            if(i < r-1) g[i][j]->down=g[i+1][j];
            if(j > 0) g[i][j]->left=g[i][j-1];
            if(j < c-1) g[i][j]->right=g[i][j+1];
        }
    }
    Node* curr = g[sr][sc];
    for0(i, n){
        Node* u = curr->up;
        Node* d = curr->down;
        Node* r = curr->right;
        Node* l = curr->left;
        if(u) u->down = d;
        if(d) d->up = u;
        if(r) r->left = l;
        if(l) l->right = r;
        if(s[i] == 'E'){ //right
            curr = r;
        } else if(s[i] == 'W') { //left
            curr = l;
        } else if(s[i] == 'N') { //up
            curr = u;
        } else if(s[i] == 'S') { //down
            curr = d;
        }
    }

    cout<<curr->r + 1<<" "<< curr->c + 1<<endl;
    for0(i,r){
        for0(j,c){
            delete g[i][j];
        }
    }
}

int main() {
    init_code();
    int t;
    cin>>t;
    for1(i,t){
        run_case(i);
    }
    return 0;
}
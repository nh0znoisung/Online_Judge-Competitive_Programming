#include <bits/stdc++.h>
using namespace std;
const int M=998244353;
const int N=1000005,E=524288;
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
int x[N],y[N],i,mp,c,t,f[N],a[N];
long long n,m,k;

int main() {
#ifndef ONLINE_JUDGE
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.size();
        bool yes = false;
        // int i = 0;
        for(int i = 0; i<=n; i++){
            // >= i == 1 && <i == 0
            bool ok = true;
            int curr = -2;
            for(int j = 0; j<i; j++){
                // = =0
                if(s[j] == '1'){
                    if(j - curr > 1){
                        curr = j;
                    }else{
                        ok = false;
                        break;
                    }
                }
            }
            // cout<<"asdfa"<<endl;
            curr = i-2;
            for(int j = i; j<n; j++){
                
                if(s[j] == '0'){
                    if(j - curr > 1){
                        curr = j;
                    }else{
                        ok = false;
                        break;
                    }
                }
            }
            
            if(ok){
                
                yes = true;
                break;
            }
        }
        if(yes){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}